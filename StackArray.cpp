#include <iostream>
using namespace std;

class Stack{
private:
    int size;
    int top;
    int* s;
public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    int stackTop();
    void display();
};

Stack::Stack(int size){
    //to sotre the stack as array
    this->size= size;
    top=-1;
    s= new int[size]; //pointer to the array that stores the stack
}

Stack::~Stack(){
    delete[] s;//to destruct the stack after use.
}

void Stack::push(int x){
    if(isFull()){
        cout<<"STACK OVERFLOW"<<endl;
    }
    else{top++; s[top] = x;}
}

int Stack::pop(){
    int x = -1;
    if(isEmpty()){cout<<"STACK UNDERFLOW"<<endl;}
    else{x = s[top]; top--;}
    return x;
}

int Stack::peek(int index){
    int x = -1;
    if(top-index+1<0||top-index+1==size){
        cout<<"Invalid Position"<<endl;
    }
    else{x = s[top-index+1];}
    return x;
}

int Stack::isFull(){
    if(top == size-1){return 1;}
    else{return 0;}
}

int Stack::isEmpty(){
    if(top == -1){return 1;}
    else{return 0;}
}

int Stack::stackTop(){
    if(isEmpty()){return -1;}
    else{return s[top];}
}

void Stack::display(){
    for(int i=top;i>=0;i--){
        cout<<s[i]<<" | "<<flush;
    }
    cout<<endl;
}

int main(){

    int A[] = {1,3,5,7,9};

    Stack stk(sizeof(A)/sizeof(A[0]));

    //populate stack with array elements
    for(int i=0; i<sizeof(A)/sizeof(A[0]);i++){
        stk.push(A[i]);
    }
    stk.push(11);
    cout<<"Stack full: "<<stk.isFull()<<endl;

    //Display stack
    cout<<"Stack: "<<flush;
    stk.display();

    //peek
    cout<<"peek at 0th: "<< stk.peek(0)<<endl;
    cout<<"peek at 3rd: "<< stk.peek(3)<<endl;
    cout<<"peek at 10th: "<<stk.peek(10)<<endl;

    //top element
    cout<<"Top element: "<<stk.stackTop()<<endl;

    //pop out elements from stack
    cout<<"popped out elements: "<<flush;
    for(int i=0; i<sizeof(A)/sizeof(A[0]);i++){
        cout<<stk.pop()<<" , "<<flush;
    }
    cout<<endl;
    stk.pop();

    cout<<"stack empty: "<<stk.isEmpty()<<endl;

    return 0;
}