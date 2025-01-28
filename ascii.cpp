#include <iostream>
#include <vector>
#include <string>


struct Node {
    string name;
    vector<Node*> children;

    Node(const string& n) : name(n) {}
};

void printTree(Node* node, int depth = 0) {
    if (!node) return;

    std::cout << string(depth * 4, ' ') << "├── " << node->name << endl;
    for (size_t i = 0; i < node->children.size(); ++i) {
        // Vérifie si ce n'est pas le dernier enfant pour décider quel symbole afficher
        if (i == node->children.size() - 1) {
            std::cout << string(depth * 4, ' ') << "    "; // définition de l’espace pour le dernier enfant
            printTree(node->children[i], depth + 1);
        } else {
            printTree(node->children[i], depth + 1);
        }
    }
}

Node* addBranch(Node* parent, const string& name) {
    Node* newNode = new Node(name);
    parent->children.push_back(newNode);
    return newNode;
}

void deleteBranch(Node* parent, const string& name) {
    auto& children = parent->children;
    for (auto it = children.begin(); it != children.end(); ) {
        if ((*it)->name == name) {
            delete *it; // Libération de la mémoire
            it = children.erase(it); // Suppression d’un nœud
        } else {
            deleteBranch(*it, name);
            ++it;
        }
    }
}

int main() {
    Node* root = new Node("Chaîne Alimentaire");

    // Ajout d'exemples de groupes
    Node* producteurs = addBranch(root, "Producteurs");
    addBranch(producteurs, "Plantes");
    addBranch(producteurs, "Algues");

    Node* herbivores = addBranch(root, "Herbivores");
    addBranch(herbivores, "Lapin");
    addBranch(herbivores, "Cerf");

    Node* carnivores = addBranch(root, "Carnivores");
    addBranch(carnivores, "Loup");
    addBranch(carnivores, "Aigle");

    Node* omnivores = addBranch(root, "Omnivores");
    addBranch(omnivores, "Homme");
    addBranch(omnivores, "Singe");

    int choice;
    string name;

    do {
        std::cout << "\nBienvenue, nous avons défini un arbre ASCII qui décrit la chaîne alimentaire. Vous pouvez interagir grâce au menu suivant :\n";
        std::cout << "1. Afficher l'arbre\n";
        std::cout << "2. Ajouter un nœud\n";
        std::cout << "3. Supprimer un nœud\n";
        std::cout << "0. Quitter\n";
        std::cout << "Choisissez une option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                printTree(root);
                break;
            case 2:
                std::cout << "Entrez le nom de la branche à ajouter: ";
                std::cin >> name;
                addBranch(root, name);
                break;
            case 3:
                std::cout << "Nom de la branche à supprimer: ";
                std::cin >> name;
                deleteBranch(root, name);
                break;
            case 0:
                std::cout << "Merci d’avoir participé !" << endl;
                break;
            default:
                std::cout << "Choix non valide. Entrez une valeur entre 0 et 3 selon les indications du menu et veuillez réessayer.\n";
        }
    } while (choice != 0);

    // Libération de mémoire
    delete root;

    return 0;
}

