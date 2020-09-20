#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
struct Node *generateTree(struct Node *currNode)
{
    int data;
    //left subtree
    cout << "Do you want to enter left node so enter its data if not enter 0 : ";
    cin >> data;
    if (data != 0)
    {
        currNode->left = new Node(data);
        generateTree(currNode->left);
    }
    //right sub Tree
    cout << "Do you want to enter right node so enter its data if not enter 0 : ";
    cin >> data;
    if (data != 0)
    {
        currNode->right = new Node(data);
        generateTree(currNode->right);
    }
    return currNode;
}
void printTree(struct Node *currNode)
{
    if (currNode == NULL)
        return;

    cout << currNode->data << endl;
    printTree(currNode->left);
    printTree(currNode->right);
}
void printBrancSums(struct Node *root, int branchSums)
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
int main()
{
    struct Node *root = new Node(10);
    generateTree(root);
    cout << "Your tree is here : " << endl;
    printTree(root);
    cout << "Finding Branch Sums Now : " << endl;
    printBrancSums(root, 0);
}