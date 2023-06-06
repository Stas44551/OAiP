#include <iostream>
#include <windows.h>
#include <stack>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
};

typedef Node* PNode;

struct Stack {
    string a;
    Stack* next;
};

typedef Stack* PStack;

void see_1(PNode seeTree, int u);
void nodesWithA(PNode* root, PStack* s);
void seeStack(PStack s);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PNode root = new Node{ "ABCD", new Node{"BCD", new Node{"BCDG", nullptr, nullptr}, nullptr}, new Node{"CABD", nullptr, nullptr} };
    cout << "Дерево" << endl;
    see_1(root, 0);
    PStack nodesA = nullptr;
    cout << endl << "Стэк" << endl;
    nodesWithA(&root, &nodesA);
    seeStack(nodesA); cout << endl;
    cout << "Дерево измененное" << endl;
    see_1(root, 0);
    return 0;
}

void seeStack(PStack s) {
    PStack see = s;
    do
    {
        cout << see->a << endl;
        see = see->next;
    } while (see!= nullptr);
    cout << endl;
    return;
}

void see_1(Node* seeTree, int u) {
    if (!seeTree) {

        return;
    }
    else {
        see_1(seeTree->left, ++u);
        for (int i = 0; i < u; ++i) cout << "|";
        cout << "->" << seeTree->data << endl;
        u--;
    }
    see_1(seeTree->right, ++u);
}

void nodesWithA(PNode* root, PStack* s) {
    if ((*root) == nullptr) {
        return;
    }
    
        bool proov = false;
        
        PStack save;
        for (int i = 0; i < (*root)->data.size();i++) {
            if ((*root)->data[i] == 'A') {
                proov = true;
                break;
            }
        }
        if (proov==true) {
            save = (*s);
            (*s) = new Stack;
            (*s)->a = (*root)->data;
            (*s)->next = save;
            if ((*root)->left) {
                (*root) = (*root)->left;

                nodesWithA(&(*root), &(*s));
            }
            else if ((*root)->right) {
                (*root) = (*root)->right;

                nodesWithA(&(*root), &(*s));
            }
            else
            {
                (*root) = nullptr;
            }
        }
        else if ((*root)->left) {
            nodesWithA(&(*root)->left, &(*s));
            if ((*root)->right) {
                nodesWithA(&(*root)->right, &(*s));
            }
        }
        
}

