#include<iostream>
#include<string>
using namespace std;

struct node{
    char data;
    node *next;
}*top=0;

void push(char x){
    node *t=new node;
    if(t==0)
        cout<<"overflow"<<endl;
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

char pop(){
    node *t;
    int x='\0';
    if(top==0)
        cout<<"stack is empty"<<endl;
    else{
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}

void display(){
    node *p;
    p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int stacktop(){
    if(top!=0)
        return top->data;
    else
        return '\0';
}

int pre(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

int isoperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')')
        return 0;
    else
        return 1;
}

string intopos(string infix){
    string postfix=infix;
    int len=infix.length();
    int j=0;
    for(int i=0;i<len;){
        if(isoperand(infix[i]))
            postfix[j++]=infix[i++];
        else{
            if(top==0 || pre(infix[i]) > pre(top->data) || infix[i]=='(')
                push(infix[i++]);
            else if(infix[i]==')'){
                while(stacktop()!='('){
                    postfix[j++]=pop();
                }
                pop();
                i++;
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=0)
        postfix[j++]=pop();
    return postfix;
}

int count(string infix){
    int res=0;
    for(int i=0;i<infix.length();i++){
        if(infix[i]=='(')
            res++;
    }
    return res;
}

int main(){
    string infix;
    cin>>infix;
    string postfix=intopos(infix);
    int reqlen=infix.length()-2*count(infix);
    for(int i=0;i<reqlen;i++)
        cout<<postfix[i];
}



/////////////////////////

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct node{
    char data;
    node *next;
}*top=0;

void push(char x){
    node *t=new node;
    if(t==0)
        cout<<"overflow"<<endl;
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

char pop(){
    node *t;
    int x='\0';
    if(top==0)
        cout<<"stack is empty"<<endl;
    else{
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}

void display(){
    node *p;
    p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int stacktop(){
    if(top!=0)
        return top->data;
    else
        return '\0';
}

int pre(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='^' || x=='<' || x=='>')
        return 3;
    return 0;
}

int isoperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')' || x=='^' || x=='>' || x=='<')
        return 0;
    else
        return 1;
}

string intopos(string infix){
    string postfix=infix;
    int len=infix.length();
    int j=0;
    for(int i=0;i<len;){
        if(isoperand(infix[i]))
            postfix[j++]=infix[i++];
        else{
            if(top==0 || pre(infix[i]) > pre(top->data) || infix[i]=='(' || (stacktop()=='<') || stacktop()=='>')
                push(infix[i++]);
            else if(infix[i]==')'){
                while(stacktop()!='('){
                    postfix[j++]=pop();
                }
                pop();
                i++;
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=0)
        postfix[j++]=pop();
    return postfix;
}

int count(string infix){
    int res=0;
    for(int i=0;i<infix.length();i++){
        if(infix[i]=='(')
            res++;
    }
    return res;
}

int evaluate(string postfix){
    int res=0;
    for(int i=0;i<postfix.length();i++){
        if(isoperand(postfix[i]))
            push(postfix[i]-'0');
        else{
            int x2=pop();
            int x1=pop();
            switch(postfix[i]){
                case '+':res=x1+x2;push(res);break;
                case '-':res=x1-x2;push(res);break;
                case '*':res=x1*x2;push(res);break;
                case '/':res=x1/x2;push(res);break;
                case '^':res=pow(x1,x2);push(res);break;
                case '<':res=x1<<x2;push(res);i++;break;
                case '>':res=x1>>x2;push(res);i++;break;
            }
        }
    }
    return pop();
}

int main(){
    string infix;
    cin>>infix;
    string postfix=intopos(infix);
    int reqlen=infix.length()-2*count(infix);
    postfix=postfix.substr(0,reqlen);
    for(int i=0;i<reqlen;i++){
        if(postfix[i]=='<'){
            cout<<"<<"<<" ";
            i++;
        }
        if(postfix[i]=='>'){
            cout<<">>"<<" ";
            i++;
        }
        else
            cout<<postfix[i]<<" ";
    }
    cout<<endl;
    int value=evaluate(postfix);
    cout<<value;
}