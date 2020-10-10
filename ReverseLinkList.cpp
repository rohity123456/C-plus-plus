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
SN *makeLinkList()
{
    int data;
    bool ch;
    cout << "Enter data for first node : " << endl;
    cin >> data;
    SN *head = new Node(data);
    SN *temp = head;
    do
    {
        cout << "Enter next node : " << endl;
        cin >> data;
        temp->next = new Node(data);
        temp = temp->next;
        cout << "Do you want to enter more nodes the enter 1 else 0 : " << endl;
        cin >> ch;

    } while (ch);
    return head;
}
void printLinkedList(SN *head)
{
    SN *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
}
SN *reverseLinkList(SN *head)
{
    SN *p1 = NULL;
    SN *p2 = head;
    SN *p3;
    while (p2 != NULL)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    return p1;
}
int main()
{

    SN *head = makeLinkList();
    printLinkedList(head);
    head = reverseLinkList(head);
    cout << endl
         << "Your Reversed Linked List is : - " << endl;
    printLinkedList(head);
}