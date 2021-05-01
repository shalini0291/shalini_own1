/* Add one to a number represented by  a linked list.*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node *newnode(int data)
{
    Node *newnode=new Node;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *addOneUtil(Node * head)
{
    Node *res=head;
    Node *temp,*prev=NULL;
    int carry=1, sum;
    while(head!=NULL)
    {
        sum = carry+head->data;
        carry = (sum>=10)?1:0;
        sum = sum % 10;
        head->data = sum;
        temp = head;
        head=head->next;
    }
    if(carry>0)
        temp->next = newnode(carry);
    return res;
}

Node *addOne(Node *head)
{
    head = reverse(head);
    head = addOneUtil(head);
    return reverse(head);
}

void printList(Node *node)
{
    while(node!=NULL)
    {
        cout<<" -> ";
        cout<<node->data;
        node = node->next;
    }
    cout<<endl;
}

int main()
{
    Node *head = newnode(1);
    head->next = newnode(9);
    head->next->next = newnode(9);
    head->next->next->next = newnode(9);
    cout<<"List is: ";
    printList(head);

    head = addOne(head);

    cout<<"Resultant linked list: ";
    printList(head);

    return 0;
}
