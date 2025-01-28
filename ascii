
#include <iostream>
#include <string>

using namespace std;

struct Node {
 int valeur;
 Node* gauche;
 Node* droit;
};

void printTree(Node* node, int niveau = 0) {
 if (node == nullptr) return;

 printTree(node->droit, niveau + 1);

 for (int i = 0; i < niveau; i++) {
  cout << " ";
 }
 cout << node->valeur << endl;

 printTree(node->gauche, niveau + 1);
}

int main() {
 Node* racine = new Node{1};
 racine->gauche = new Node{2};
 racine->droit = new Node{3};
 racine->gauche->gauche = new Node{4};
 racine->gauche->droit = new Node{5};
 racine->droit->gauche = new Node{6};
 racine->droit->droit = new Node{7};

 printTree(racine);

 return 0;
}
