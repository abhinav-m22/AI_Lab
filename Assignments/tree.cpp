#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;

    Tree(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
    ~Tree()
    {
        delete left;
        delete right;
    }
};

void inorder(Tree *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Tree *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void preorder(Tree *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

Tree *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;

    Tree *root = new Tree(rootData);
    Tree *leftChild = takeInput();
    Tree *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;

    return root;
}

Tree *BST(int data, Tree *node)
{
    if (!node)
    {
        Tree *newNode = new Tree(data);
        return newNode;
    }

    if (data < node->val)
    {
        node->left = BST(data, node->left);
    }
    else
    {
        node->right = BST(data, node->right);
    }

    return node;
}

int main()
{
    // Tree* root = takeInput();
    // cout << "Inorder: " << endl;
    // inorder(root);
    // cout << endl;
    // cout << "Postorder: " << endl;
    // postorder(root);
    // cout << endl;
    // cout << "Preorder: " << endl;
    // preorder(root);

    Tree *node = NULL;

    int arr[] = {3, 1, 6, 2, 5};
    for (int i : arr)
    {
        node = BST(i, node);
    }

    cout << "Inorder:" << endl;
    inorder(node);
    cout << endl;
    cout << "Postorder: " << endl;
    postorder(node);
    cout << endl;
    cout << "Preorder: " << endl;
    preorder(node);
}