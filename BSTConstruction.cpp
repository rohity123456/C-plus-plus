#include <bits/stdc++.h>
using namespace std;
#define SN struct Node
SN
{
    int data;
    SN *left;
    SN *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
SN *insertNodeInBSTree(SN *currNode, int data)
{
    if (currNode == NULL)
    {
        currNode = new Node(data);
        return currNode;
    }
    else if (data > currNode->data)
        currNode->right = insertNodeInBSTree(currNode->right, data);
    else
        currNode->left = insertNodeInBSTree(currNode->left, data);
    return currNode;
}
void printTree(SN *currNode)
{
    if (currNode == NULL)
        return;

    cout << currNode->data << endl;
    printTree(currNode->left);
    printTree(currNode->right);
}
SN *contains(SN *root, int searchVal)
{
    if (root == NULL)
        return NULL;
    if (searchVal == root->data)
        return root;
    if (searchVal < root->data)
        return contains(root->left, searchVal);
    return contains(root->right, searchVal);
}
SN *getInorderSuccessor(SN *root)
{
    if (root->left == NULL)
        return root;
    return getInorderSuccessor(root->left);
}
SN *removeNodeHelper(SN *root, int toRemove)
{
    if (root == NULL)
        return root;
    if (toRemove > root->data)
        root->right = removeNodeHelper(root->right, toRemove);
    else if (toRemove < root->data)
        root->left = removeNodeHelper(root->left, toRemove);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (root->left == NULL)
        {
            SN *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            SN *temp = root->left;
            free(root);
            return temp;
        }

        SN *temp = getInorderSuccessor(root->right);
        cout << "DATA for temp : " << temp->data << endl;
        root->data = temp->data;
        root->right = removeNodeHelper(root->right, temp->data);
    }
    return root;
}
void removeNode(SN *root, int toRemove)
{
    SN *searchVal = contains(root, toRemove);
    if (searchVal == NULL)
        return;
    removeNodeHelper(root, toRemove);
}
int main()
{
    SN *root = new Node(10);
    insertNodeInBSTree(root, 15);
    insertNodeInBSTree(root, 5);
    insertNodeInBSTree(root, 17);
    cout << "Your tree is here : " << endl;
    printTree(root);
    cout << "is contains 17 ? : ";
    SN *searchVal = contains(root, 17);
    if (searchVal == NULL)
        cout << "False" << endl;
    else
        cout << searchVal->data << endl;
    cout << "Deleting 10 " << endl;
    removeNode(root, 10);
    cout << "Your tree is here : " << endl;
    printTree(root);
}