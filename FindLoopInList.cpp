#include <bits/stdc++.h>
using namespace std;
#define SN struct Node
SN
{
    int data;
    SN *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void makeLinkList(vector<SN *> &storeArray)
{
    int data;
    bool ch, isStartLoopNode = false;
    cout << "Enter data for first node : " << endl;
    cin >> data;
    SN *head = new Node(data);
    SN *temp = head;
    SN *startLoopNode;
    do
    {
        cout << "Enter next node : " << endl;
        cin >> data;
        temp->next = new Node(data);
        temp = temp->next;
        if (!isStartLoopNode)
        {
            cout << "Is this node is start of the loop ? : " << endl;
            cin >> isStartLoopNode;
            startLoopNode = temp;
        }
        cout << "Do you want to enter more nodes the enter 1 else 0 : " << endl;
        cin >> ch;

    } while (ch);
    temp->next = startLoopNode;
    storeArray.push_back(head);
    storeArray.push_back(startLoopNode);
}
void printLinkedList(SN *head, SN *startLoopNode)
{
    SN *temp = head;
    int isIterated = 0;
    while (isIterated != 2)
    {
        cout << temp->data << "-";
        temp = temp->next;
        if (temp == startLoopNode)
            isIterated++;
    }
    cout << temp->data;
}
SN *findLoopNode(SN *head)
{
    SN *firstPointer = head->next;
    SN *secondPointer = head->next->next;
    while (firstPointer != secondPointer)
    {
        firstPointer = firstPointer->next;
        secondPointer = secondPointer->next->next;
    }
    firstPointer = head;
    while (firstPointer != secondPointer)
    {
        firstPointer = firstPointer->next;
        secondPointer = secondPointer->next;
    }
    return firstPointer;
}
int main()
{
    vector<SN *> storeArray;
    makeLinkList(storeArray);
    printLinkedList(storeArray[0], storeArray[1]);
    SN *loopNode = findLoopNode(storeArray[0]);
    cout << endl
         << "Your Loop Node is : - " << loopNode->data;
}