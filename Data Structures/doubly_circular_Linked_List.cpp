#include<iostream>
using namespace std;
class Node{
    private:
    Node *next;
    Node *prev;
    int data;

    public:
    Node(int data){
        next=NULL;
        prev=NULL;
        this->data=data;
    }
    friend class D_linkedlist;

};
class D_linkedlist{
    Node *head;
    public:
    D_linkedlist(){
        head=NULL;
    }

    void insert(int val){
        Node *newnode=new Node (val);
        if(head==NULL){
            head=newnode;
            head->next=head;
            head->prev=head;
        }else{
            Node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=head;
            head->prev=newnode;
        }
    }

    void display(){
        Node* temp=head;
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<endl;
    }
    friend class Node;
};

int main(){
    D_linkedlist l1;

    l1.insert(1);
    l1.insert(2);
    l1.insert(3);

    l1.display();

    return 0;
}