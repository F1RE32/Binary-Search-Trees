#include <iostream>
using namespace std;

struct BSTNode
{
    int value;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode** node, int inp)
{
    if (*node == NULL)
    {
        BSTNode* curr = new BSTNode;
        curr->value = inp;
        curr->left = curr->right = NULL;
        return curr;
    }
    if (inp < (*node)->value)
    {
        (*node)->left = insert(&((*node)->left), inp);
    }
    else
    {
        (*node)->right = insert(&((*node)->right), inp);    
    }
    return *node;
}

void searchtree(BSTNode*  node, int inp)
{
    if (node == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }
    if (inp == node->value)
    {
        cout << "Value Found"  << endl;
        return;
    }
    if (inp < node->value)
    {
        searchtree(node->left, inp);
    }
    else 
    {
        searchtree(node->right, inp);
    }
}

int main ()
{
    BSTNode* Root = NULL;
    int inp;
    cout << "Tree is initially empty, Insert a value: ";
    cin >> inp;
    Root = insert(&Root, inp);
    cout << "Press 1 to Insert, 2 to Search, 0 to Exit" << endl;
    int select;
    cin >> select;
    while (select != 0)
    {
        if (select == 1)
        {
            cout << "Insert the value: ";
            cin >> inp;
            insert(&Root, inp);
        }
        if (select == 2)
        {
        	cout << "Insert the value: ";
            cin >> inp;
            searchtree(Root, inp);
        }
        cout << "Press 1 to Insert, 2 to Search, 0 to Exit" << endl;
        cin >> select;
    }
    return 0;
}
