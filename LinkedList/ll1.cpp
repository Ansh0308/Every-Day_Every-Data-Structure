#include<iostream>
#include <bits/stdc++.h>

using namespace std;
#define forLL(temp,head) for(Node *temp=head;temp !=nullptr;temp=temp->next)
struct Node{
    int data;
    Node *next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int val){
        data=val;
        next=nullptr;

    }
    Node(int val, Node *ptr){
        data=val;
        next=ptr;
    }



};
class LinkedList{
    Node *head;
    public:
    LinkedList(){
        head=nullptr;
    }
    LinkedList(int val){
        head=new Node(val);
    }
    void insert_at_head(int val);
    void insert_at_tail(int val);
    void display();
    int size();
    void deleteNode(int pos);

};

void LinkedList::insert_at_head(int val){
    Node *newnode=new Node(val);
    if(head==nullptr){
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}
int LinkedList::size(){
int count=0;
for(Node *temp=head;temp !=nullptr;temp=temp->next){
    count++;
}
return count;

}
void LinkedList::insert_at_tail(int val){
     Node *newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            return;
        }
        Node *temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    
}
void LinkedList::display(){
    if(head==nullptr){
    cout<<"LL Does not exits";
    return;
    }
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void LinkedList::deleteNode(int pos)
{
    if (!head)
    {
        cout << "LL is empty.\n";
        return;
    }

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    int _size = size();
    if (pos > _size)
    {
        cout << "Pos > size of LL.\n";
        return;
    }

    Node *prev;
    for (prev = head; pos > 2; prev = prev->next, pos--)
    {
        // code should break at prev
    }
    // cout << prev->data << "\n";
    Node *temp = prev->next;
    prev->next = prev->next->next;
    delete temp;
}
void creat_constructor(){
    Node *node4= new Node(4);
    Node *node3= new Node(3,node4);
    Node *node2= new Node(2,node3);

}
void loop_shift_head(){
    Node *head=nullptr;
    
}

int main(){
    //struct Node node1;//compile time
    
    // Node *node1= new Node(1,node1);// run time
    
    



    return 0;
}//struct and class diff,stuct is defalut public,class is private
//diff between NULL and nullptr(void vs void *)
//2 19 24 61 83 237 2807    206 