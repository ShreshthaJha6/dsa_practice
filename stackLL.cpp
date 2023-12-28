#include <iostream>
#include <cstring>
#include<stack>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
private:
    Node *top;
public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int stackTop();
    int isEmpty();
    int isFull();
};

Stack::Stack(){
    top= nullptr;
}

Stack::~Stack(){
    Node *p=top;
    while(top){
        top=top->next;
        delete p;
        p=top;
    }
}

void Stack::push(int x){
    Node *t=new Node;
    if(t==nullptr){
        cout<<"STACK OVERFLOW"<<endl;
    }else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop(){
    Node *p;
    int x=-1;
    if(top==nullptr){
        cout<<"STACK UNDERFLOW"<<endl;
    }else{
        p=top;
        x=p->data;
        top=top->next;
        delete p;
    }
    return x;
}

int Stack::isFull(){
    Node *t=new Node;
    int r= t?1:0;
    delete t;
    return r;
}

int Stack::isEmpty(){
    return top?0:1;
}

int Stack::stackTop(){
    if(top){
        return top->data;
    }else{
        return -1;
    }
}

int Stack::peek(int index){
    if(isEmpty()){
        return -1;
    }else{
        Node *p= top;

        for(int i=0;p!=nullptr && i<index-1;i++){
            p=p->next;
        }

        if(p!=nullptr){
            return p->data;
        }else{return -1;}
    }
}
 
int isBalanced(char* exp){
    Stack stk;
 
    for (int i=0; i<strlen(exp); i++){
        if (exp[i] == '('){
            stk.push(exp[i]);
        } else if (exp[i] == ')'){
            if (stk.isEmpty()){
                return false;
            } else {
                stk.pop();
            }
        }
    }
    return stk.isEmpty() ? true : false;
}

int pre(char x){
    if(x=='+'||x=='-') return 1;
    else if (x=='*'||x=='/') return 2;
    return 0;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/') return 0;
    else return 1;
}

int Operation(char op, int x, int y){
    if(op=='+') return x+y;
    else if(op=='-') return x-y;
    else if(op=='*') return x*y;
    else if(op=='/') return x/y;
    else return 0;
}

int postfixEvaluate(char *postfix){
    stack<int> stk;
    int x,y;
    int result;
    for(int i=0; postfix[i]='\0';i++){
        if(isOperand(postfix[i])){
            //here typecast would not work because of ASCII values of character,
            //so using '0'
            stk.push(postfix[i]-'0');
        }
        else{
            y=stk.top();stk.pop();
            x=stk.top();stk.pop();
            result = Operation(postfix[i],x,y);
            stk.push(result);
        }
    }
    result = stk.top(); stk.pop();
    return result;
}

int Evaluate(char *postfix){
    Stack stk;
    int x,y;
    int result;
    for (int i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            stk.push(postfix[i]-'0');
        }else{
            y=stk.pop();
            x=stk.pop();
            result = Operation(postfix[i],x,y);
            stk.push(result);
        }
    }
    result = stk.pop();
    return result;
}

/* char* InToPost(char *infix){
    Stack stk;
    int i=0,j=0;
    int len=strlen(infix);
    char *postfix = new char[strlen(infix)+1];

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(infix[i]>pre(stk.stackTop())))
                stk.push(infix[i++]);
            else{postfix[j++]=infix[i++];}
        }
    }
    while(stk.stackTop()!=NULL)postfix[j++]=stk.pop();
} */

int main() {
 
    char postfix[] = "35*62/+4-";
    cout << Evaluate(postfix) << endl;
    cout << postfixEvaluate(postfix) << endl;
    return 0;
}