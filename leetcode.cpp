#include <iostream>
#include<string>
using namespace std;

//creating the stack 

//in this code stack is used to store the runtime of executed codes which can be further used for creating graph of runtime of every person
int stack[100];
int total = 100;          //total is the maximum elements that can be put in the stack
int top = -1;             //stack top

//implementing priority using singly linked list
class node {
public:
    string code;                    //contains the code of user
    int pri;                        //contains the priority of the user i.e if the user has leetcode premium then priority is 1 else priority is 0
    node* next;                     //pointer that points to next node

    node() {                        //default constructor
        code = "NA";
        pri = 0;
        next = NULL;
    }
    node(string c, int pr) {        //parameterized constructor
        code = c;
        pri = pr;
        next = NULL;
    }
};

class LL {                             //class linked list
public:                
    node* front;                        //front
    node* rear;                        //rear

    LL() {
        // head = NULL;
        front = NULL;
        rear = NULL;
    }

//insert()  adds the element in the priority queue if the priority is 1 then the peron has leetcode premium
//if the priority is 0 then the person does not have leetcode premium and is placed accordingly in the priority queue

    void insert(string s, int p) {                      
        node* nn = new node(s, p);
        if (p == 1) {
            if (front == NULL || front->pri == 0) {
                nn->next = front;
                front = nn;
                if (front == NULL) {
                    front = nn;
                    rear = nn;
                }
            } else {
                node* temp = front;
                while (temp->next != NULL && temp->next->pri == 1) {
                    temp = temp->next;
                }
                nn->next = temp->next;
                temp->next = nn;
                if (nn->next == NULL) {
                    rear = nn;
                }
            }
        } else if (p == 0) {
            if (rear == NULL) {
                front = nn;
                rear = nn;
            } else {
                rear->next = nn;
                rear = nn;
            }
        }
    }
    //execute() checks the runtime of the function and the places the runtime of the executed code in the stack which can be further used by leetcode to generate graph
    void execute(string c)
    {
        int runtime = c.length();
        if(top == total-1)
        {
            cout<<"Stack Overflow"<<endl;
        }else{
            stack[++top] = runtime;
        }
    }

    //displaystack()  displays the runtime of the executed codes in the stack
    void displaystack()
    {
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }else{
        for(int i=0;i<=top;i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
        }
    }

    //compile() removes the front element of the queue and sends it to execute()
    void complie()
    {
        if(front == NULL){
            cout<<"Linked List is Emptty"<<endl;
        }
        else if(front == rear){
            node* temp = front;
            front = front->next;
            execute(temp->code);
            delete temp;
            front = NULL;
            rear = NULL;
        }else{
            node* temp = front;
            front = front->next;
            execute(temp->code);
            delete temp;
        }
    }
    //display() displays the remaining requests in the queue

    void display() {
        node* temp = front; 
        if (temp == NULL) { 
            cout << "Linked List is Empty" << endl;
            return;
        }
        while (temp != NULL) { 
            cout << temp->code << " "; 
            temp = temp->next;
        }
        cout << endl; 
    }
    
};

int main() {
    LL n;
    int flip = 0;
    while(flip ==0)
    {
        cout<<"1.Generate a compilation request\n2.Accept the compilation request\n3.view remaining compilation requests\n4.view runtime of executed codes\n5.Exit program"<<endl;
        cout<<"Enter your choice:";
        int choice;
        cin>>choice;
        string temp;
        switch(choice)
        {
            case 1:
            cout<<"Enter your code:";
            cin>>temp;
            cout<<"Do you have leetcode premium(y/n):";
            char p;
            cin>>p;
            if(p=='y') n.insert(temp,1);
            else if (p=='n') n.insert(temp,0);
            else cout<<"Enter a valid option!!"<<endl;
            break;
            
            case 2:
            n.complie();
            break;

            case 3:
            n.display();
            break;

            case 4:
            n.displaystack();
            break;

            case 5:
            flip = 1;
            break;

            default:
            cout<<"Enter a valid option!!"<<endl;
        }
    }
}
