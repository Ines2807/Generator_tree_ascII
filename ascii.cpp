#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    string name;
    vector<Node*> children;

    Node(const string& n) : name(n) {}
};

void printTree(Node* node, int depth = 0) {
    if (!node) return;
    cout << string(depth * 2, ' ') << node->name << endl;
    for (auto child : node->children) {
        printTree(child, depth + 1);
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
            delete *it; // Libérer la mémoire
            it = children.erase(it); // Supprimer le noeud
        } else {
            deleteBranch(*it, name);
            ++it;
        }
    }
}

int main() {
    Node* root = new Node("Chaîne Alimentaire");

    // Ajout d'exemples de branches
    Node* herbivore = addBranch(root, "Herbivore");
    addBranch(herbivore, "Lapin");
    addBranch(herbivore, "Cerf");

    Node* carnivore = addBranch(root, "Carnivore");
    addBranch(carnivore, "Loup");
    addBranch(carnivore, "Aigle");

    int choice;
    string name;

    do {
        cout << "\nMenu:\n";
        cout << "1. Afficher l'arbre\n";
        cout << "2. Ajouter une branche\n";
        cout << "3. Supprimer une branche\n";
        cout << "0. Quitter\n";
        cout << "Choisissez une option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printTree(root);
                break;
            case 2:
                cout << "Nom de la branche à ajouter: ";
                cin >> name;
                addBranch(root, name);
                break;
            case 3:
                cout << "Nom de la branche à supprimer: ";
                cin >> name;
                deleteBranch(root, name);
                break;
            case 0:
                break;
            default:
                cout << "Choix non valide.\n";
        }
    } while (choice != 0);

    // Libération de mémoire
    delete root;

    return 0;
}
