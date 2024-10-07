#include <iostream>
#include <cmath>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};
class Stack
{
    Node *top;
    int length;

public:
    Stack()
    {
        top = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int val)
    {
        Node *temp = new Node(val);
        temp->next = top;
        top = temp;
        length++;
        cout << "Element :" << val << " is pushed." << endl;
    }
    int pop()
    {
        Node *temp = top;
        int val = top->val;
        top = top->next;
        delete temp;
        temp = NULL;
        length--;
        return val;
    }
    void peek()
    {
        if (!isEmpty())
        {
            cout << "Top of the stack: " << top->val << endl;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->val;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

void operate_exp(string exp)
{
    Stack exp_stack;

    for (int i = 0; i < exp.size(); i++){
        char c = exp[i];

        if (isdigit(c)){
            int int_char=c-'0';
            exp_stack.push(int_char);
        }
        else{
            int temp1=exp_stack.pop();
            int temp2=exp_stack.pop();

            switch (c){
            case '+':
                exp_stack.push(temp2+temp1);
                break;
            case '-':
                exp_stack.push(temp2-temp1);
                break;
            case '*':
                exp_stack.push(temp2*temp1);
                break;
            case '/':
                if (temp1==0){
                    cout << "Cannot divide by zero" << endl;
                }else{
                    exp_stack.push(temp2/temp1);
                }
                break;
            case '^':{
                int val=1;
                for (int i=0; i<temp1; i++){
                    val *=temp2;
                }
                exp_stack.push(val);
                break;
            }
            default:
                cout<<"Unknown operator: "<<c<<endl;
                break;
            }
        }
    }
    if (!exp_stack.isEmpty()){
        cout<<"Final answer: "<<exp_stack.pop()<<endl;
    }
}

int main()
{
    string expression;
    cout << "Enter expression: ";
    cin >> expression;

    operate_exp(expression);

    return 0;
}