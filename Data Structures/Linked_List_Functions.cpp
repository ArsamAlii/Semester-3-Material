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
    int length;

    public:

    Linkedlist(){
        head=NULL;
        length=0;
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

    void add(int val){
        Node *newnode = new Node(val);
        if (head==NULL) {
            head=newnode;
        } else {
            Node* curr=head;
            while(curr->next!=NULL) {
                curr=curr->next;
            }
            curr->next=newnode;
        }
        length++;
    }

    void insert(int val, int pos){
        if(pos<1||pos>length+1){
            cout<<"invalid position";
            return;
        }
        else{
            Node * newnode=new Node (val);
            if(pos==1){
                newnode->next=head;
                head=newnode;
            }
            else{
                Node *curr=head;
                for(int i = 1;i<pos-1;i++){
                    curr=curr->next;
                }
                newnode->next=curr->next;
                curr->next=newnode;
                
            }
            length++;
        }
    }

    void update(int pos, int newValue){
        if (pos<1||pos>length){
            cout<<"Invalid position"<<endl;
            return;
        }
        Node *curr=head;
        for (int i=1;i<pos;i++){
            curr=curr->next;
        }
        curr->data=newValue;
        cout<<"Node at position "<<pos<<" updated to "<<newValue<<endl;
    }    

    void remove(int pos){
        if(length==0){
            cout<<"invalid position";
            return;
        }
        if(pos<1||pos>length){
            cout<<"invalid position";
            return;
        }
        Node* curr=head;
        if(pos==1){
            head=head->next;
            delete curr;
        }
        else{
            Node *slow=NULL;
            for(int i =1;i<pos;i++){
                slow=curr;
                curr=curr->next;
            }
            slow->next=curr->next;
            delete curr;
        }
        length--;
    }

    bool find(int val){
        if(length==0){
            cout<<"array is empty";
            return false;
        }
        Node *temp=head;
        while(temp!=NULL){
              if(temp->data==val){
                return true;
            }
            temp=temp->next;
        } 
        return false;
    }

    void display() {
        if (head==NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp=head;
        while (temp!=NULL) {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }    

};


int main(){
    Linkedlist l1;

    l1.add(2);
    l1.add(6);
    l1.add(8);
    l1.display();

   
    l1.insert(4,2);
    l1.display(); 

    
    l1.remove(3);
    l1.display();

    
    if(l1.find(8)){
        cout<<"Value 8 found in the list."<<endl;
    }
    else{
        cout<<"Value 8 not found in the list."<<endl;
    }
    l1.update(2, 10);
    l1.display();    

    return 0;
}
