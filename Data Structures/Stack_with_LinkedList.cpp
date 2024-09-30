#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    public:

    Node(int data){
        this->data=data;
        next=NULL;
    }
};
class Linkedlist{
    Node *head;
    int legnth;

    public:

    Linkedlist(){
        head=NULL;
        legnth=0;
    }

    ~Linkedlist() {
        Node *current = head;
        while (current != NULL) { 
            delete current; 
            current = current->next;
        }
        head = NULL; 
        cout << "Linked list deleted." << endl;
    }    

    bool is_empty(){
        Node *temp=head;

        if(temp==NULL){
            return true;
        }
        else{
            return false;
        }
        
    }

    void push(int val){
        Node *newnode=new Node (val);
        
        if(head==NULL){
            head=newnode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        
    }

    void pop(){
        if(is_empty()){
            cout<<"stack is empty already";
            return;
        }
        else{
            if(head->next==NULL){
                delete head;
                head=NULL;
            }else{
                Node *temp=head;
                while(temp->next->next!=NULL){
                    temp=temp->next;
                }
                delete temp->next;
                temp->next=NULL;                
            }

        }
    }
    int peak(){
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        return temp->data;
    }

    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }




};


int main(){
    Linkedlist l1;

    l1.push(1);
    l1.push(2);
    l1.push(3);
    l1.push(4);
    l1.push(5);

    cout<<"After using push function : ";
    l1.display();

    l1.pop();
    cout<<"After using pop function : ";
    l1.display();

    cout<<"Element at top of stack is : "<<l1.peak();


    return 0;
}