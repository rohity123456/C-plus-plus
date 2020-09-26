#include <bits/stdc++.h>
using namespace std;
#define sn struct Node

sn
{
    int data;
    sn *left;
    sn *right;
    sn *parent;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
sn *generateTree(sn *currNode)
{
    int data;
    //left subtree
    cout << "Do you want to enter left node so enter its data if not enter 0 : ";
    cin >> data;
    if (data != 0)
    {
        currNode->left = new Node(data);
        currNode->left->parent = currNode;
        generateTree(currNode->left);
    }
    //right sub Tree
    cout << "Do you want to enter right node so enter its data if not enter 0 : ";
    cin >> data;
    if (data != 0)
    {
        currNode->right = new Node(data);
        currNode->right->parent = currNode;
        generateTree(currNode->right);
    }
    return currNode;
}
void printTree(sn *currNode)
{
    if (currNode == NULL)
        return;

    cout << "Value : " << currNode->data << " Parent : " << (!(currNode->parent == NULL) ? currNode->parent->data : NULL) << endl;
    printTree(currNode->left);
    printTree(currNode->right);
}
void printBrancSums(sn *root, int branchSums)
{
    if (root == NULL)
        return;
    branchSums += root->data;
    cout << root->data << endl;
    if (root->left == NULL && root->right == NULL)
        cout << "Sum of Above branch is : " << branchSums << endl;
    printBrancSums(root->left, branchSums);
    printBrancSums(root->right, branchSums);
}
void InOrderTraversal(sn *currentNode)
{
    sn *prevNode = currentNode->parent;
    sn *nextNode = currentNode;
    while (nextNode != NULL)
    {

        if (currentNode->left != NULL && prevNode == currentNode->parent)
            nextNode = currentNode->left;
        else if (currentNode->right != NULL && prevNode != currentNode->right)
        {
            cout << currentNode->data << endl;
            nextNode = currentNode->right;
        }
        else if (prevNode == currentNode->right)
            nextNode = currentNode->parent;
        else
        {
            cout << currentNode->data << endl;
            nextNode = currentNode->parent;
        }
        prevNode = currentNode;
        currentNode = nextNode;
    }
}
int main()
{
    sn *root = new Node(10);
    generateTree(root);
    cout << "Your tree is here : " << endl;
    printTree(root);
    InOrderTraversal(root);
}