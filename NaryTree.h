#pragma once
using namespace std;
#include <iostream>
#include <vector>
struct TreeNode {
    int data;
    vector<TreeNode*> children;

    TreeNode(int value) : data(value) {}
};
class NaryTree {
private:
    TreeNode* root;

public:
    NaryTree(int value) {
        root = new TreeNode(value);
    }

    void insert(int parentValue, int value) {
        TreeNode* newNode = new TreeNode(value);
        insertNode(root, parentValue, newNode);
    }
    void insertNode(TreeNode* node, int parentValue, TreeNode* newNode) {
        if (node == nullptr) {
            return;
        }

        if (node->data == parentValue) {
            node->children.push_back(newNode);
            return;

        }
        
        for (auto child : node->children) {
                insertNode(child, parentValue, newNode);
        }
        
    }
    void printExtension(TreeNode* node, bool primero =true) {
       
        if (node == nullptr) {
            return;
        }
        if (primero) {
            cout << "{"; 
        }
        else {
            cout << "; ";
        }
        cout << node->data;

        for (auto child : node->children) {
            cout << " ";
            printExtension(child, false);
        }

        if (primero) {
            cout << "}"; 
        }
        
    }
    // Recorrido en preorden
    void preOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->data << " "; 

        for (auto child : node->children) {
            preOrderTraversal(child);
        }
    }

    // Recorrido en inorden
    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        if (!node->children.empty()) {
            inOrderTraversal(node->children[0]); 
        }

        cout << node->data << " "; 

        for (size_t i = 1; i < node->children.size(); ++i) {
            inOrderTraversal(node->children[i]); 
        }
    }

    // Recorrido en postorden
    void postOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        for (auto child : node->children) {
            postOrderTraversal(child);
        }

        cout << node->data << " "; 
    }

    void printDigraph(TreeNode* node, int level = 0) {
       
        if (node == nullptr) {
            return;
        }

       
        cout << string(level * 4, ' ') << node->data << endl;

       
        if (!node->children.empty()) {
            cout << string(level * 4, ' ') << " / \\" << endl;
            if (node->children.size() == 1) {
                cout << string(level * 4, ' ') << " |" << endl;
            }
        }

        
        for (auto child : node->children) {
            printDigraph(child, level + 1);
        }
    }

    TreeNode* getBTree(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        TreeNode* bTree = new TreeNode(node->data);

        for (auto child : node->children) {
            TreeNode* bChild = getBTree(child);
            bTree->children.push_back(bChild);
        }

        return bTree;
    }

    void printBTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->data << " -> ";
        for (auto child : node->children) {
            cout << child->data << " ";
        }
        cout << endl;

        for (auto child : node->children) {
            printBTree(child);
        }
    }
    TreeNode* getRoot() {
        return root;
    }
};