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
    int length=0;
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
            Node *temp=head->prev;
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=head;
            head->prev=newnode;
        }
        length++;
    }

    void remove(int pos){
        if(head==NULL){
            cout<<"list is empty nothing to remove"<<endl;
            return;
        }
        else if(pos<1||pos>length){
            cout<<"Invalid position cannot remove ..."<<endl;
            return;
        }
        else{
            Node *curr=head;
            if(pos==1){
                Node *temp=head->prev;
                if(head->next==head){
                    delete head;
                    head=NULL;
                }else{
                    head=head->next;
                    head->prev=temp;
                    temp->next=head;
                    delete curr;
                }
            }else{
                for(int i = 1 ; i<pos;i++){
                    curr=curr->next;
                }
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }            
            length--;
        }

    }

    void display(){
        if(head==NULL){
            cout<<"List is empty nothing to display.."<<endl;
            return;
        }
        Node* temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
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


    l1.remove(3);

    l1.display();
    return 0;
}
