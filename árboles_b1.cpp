using namespace std;
#include <iostream>
#include "NaryTree.h"
int main()
{
    int n;

    cout << "-------------------------| BIENVENIDO |------------------------------" << endl;
    cout << "Por favor, sigue las instrucciones para ingresar los datos del arbol" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Ingresa el numero de nodos del arbol (entre 10 y 15): ";
    cin >> n;

    if (n < 10 || n > 15) {
        cout << "El numero de nodos debe estar entre 10 y 15." << endl;
        return 1;
    }

    NaryTree tree(1);
    cout << "Ingrese los valores de los nodos y sus relaciones (padre hijo):" << endl;
    cout << endl;
    cout << "Recuerda que el primer padre sera la raiz del arbol" << endl;;
    cout << endl;
    for (int i = 0; i < n - 1; ++i) {
        int parent, child;
   
            cout << "Padre: ";
            cin >> parent;
            cout << "Hijo: ";
            cin >> child;
        

        tree.insert(parent, child);
    }

    TreeNode* root = tree.getRoot();
    cout << endl;
    cout<<"-------------------------------------------------------------------------------" << endl;
    cout << "Elementos de T por extension: ";
    tree.printExtension(root);
    cout << endl;
    cout<<"-------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Elementos de T en preorden: ";
    tree.preOrderTraversal(root);
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Elementos de T en inorder: ";
    tree.inOrderTraversal(root);
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Elementos de T en postorden: ";
    tree.postOrderTraversal(root);
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout <<"-------------------------------" << endl;
    cout << "Digrafo de T:" << endl;
    tree.printDigraph(root);
    cout <<"-------------------------------" << endl;

    cout << endl;

    TreeNode* bTree = tree.getBTree(root);

}


