#include<iostream>
#include<stdlib.h>
using namespace std;

class Array{
	private:
		int *arr;
		int capacity;
		int top;
		
	public:
		Array(int size){
			arr=new int [size];
			capacity=size;
			top=-1;//this will point at the index number 
		}

        ~Array(){
            delete[] arr; // free allocated memory
        }
		
		bool is_empty(){//check if array is empty
			if(top==-1){
				return true;
			}
			else {
				return false;
			}
		}
		
		bool is_full(){//check if array is full
			if(top==capacity-1){
				return true;
			}
			else{
				return false;
			}
		}
		
		void push(int val){// insert/add a value in stack
			if(is_full()){
				cout<<"stack is full cannot add more elements"<<endl;
				return;
			}
			else{
				top++;
				arr[top]=val;
			}
		}
		
		int pop(){//return top val and returns it
			if(is_empty()){
				cout<<"stack is empty nothing to remove"<<endl;
				return 0;
			}
			else{
				int val=arr[top];
				top--;
				return val;
			}
		}
		
		int peak(){//returns the value at top
			if(is_empty()){
				cout<<"array is empty nothing to return "<<endl;
				return 0;
			}else{
				return arr[top];
			}
		}
		
		void display(){
			for(int i=0;i<=top;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
};


int main(){
	
	Array a1(5);
	
	a1.push(1);
	a1.push(2);
	a1.push(3);
	a1.push(4);
	a1.push(5);
//	a1.push(6); //adding this line would give error is max limit reached
	
	cout<<"After using push : ";
	a1.display();
	
	a1.pop();
	
	cout<<"After using pop function : ";
	a1.display();
	
	int peak_val=a1.peak();
	
	cout<<"After using peak function : "<<peak_val;
	
	
	return 0;
}