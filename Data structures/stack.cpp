// linked list implementation

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define loop(k, n) for (ll i = k; i < n; i++)

struct node{
    int data;
    node *next;
};

struct stack{
    node *top=0;

    void push(int x){
        node *t=new node;
        if(t==0)
            cout<<"overflow"<<endl;
        else{
            t->data=x;
            t->next=top;
            top=t;
        }
    }

    void pop(){
        node *t;
        if(top==0)
            cout<<"stack is empty"<<endl;
        else{
            t=top;
            top=top->next;
            delete t;
        }
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
            return -1;
    }

    bool isempty(){
        if(top==0)
            return true;
        return false;
    }
};


int main(){
    // string a;
    // while(getline(cin,a)){
    //     cout<<a<<endl;
    // }
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.stacktop()<<endl;
    s.pop();
    cout<<s.stacktop()<<endl;
    cout<<boolalpha<<s.isempty()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.isempty();

    stack w;
    w.push(10);
    w.push(20);
    w.push(30);
    w.push(40);
    cout<<w.stacktop()<<endl;
    w.pop();
    cout<<w.stacktop()<<endl;
    cout<<boolalpha<<w.isempty()<<endl;
    w.pop();
    w.pop();
    w.pop();
    cout<<w.isempty();
}

//queue implementaion


#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define loop(k, n) for (ll i = k; i < n; i++)

struct stack{
    int size;
    int top;
    int *s;
};

void create(stack *st){
    st->top=-1;
    cin>>st->size;
    st->s=new int[st->size];
}

void display(stack st){
    for(int i=st.top;i>=0;i--)
        cout<<st.s[i]<<" ";
    cout<<endl;
}

void push(stack *st,int x){
    if(st->top==(st->size-1))
        cout<<"stack overflow"<<endl;
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(stack *st){
    int x=-1;
    if(st->top==-1)
        cout<<"stack underflow"<<endl;
    else{
        x=st->s[st->top];
        st->top--;
    }
    return x;
}

bool isempty(stack st){
    if(st.top==-1)
        return true;
    return false;
}

bool isfull(stack st){
    if(st.top==(st.size-1))
        return true;
    return false;
}

int stacktop(stack st){
    if(st.top==-1)
        return -1;
    return st.s[st.top];
}

int main(){
    stack st;
    create(&st);
    push(&st,1);
    push(&st,2);
    push(&st,3);
    cout<<stacktop(st)<<endl;
    pop(&st);
    cout<<stacktop(st)<<endl;
    display(st);
    push(&st,6);
    push(&st,7);
}


//////////////////////////////////////////////////////

struct node{
    int data;
    node *next;
};

node *push(node *top,int x){
    node *t=new node;
    if(t==0)
        cout<<"overflow"<<endl;
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
    return top;
}

node *pop(node *top){
    node *t;
    int x=-1;
    if(top==0)
        cout<<"stack is empty"<<endl;
    else{
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return top;
}

void display(node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int stacktop(node *top){
    if(top!=0)
        return top->data;
    else
        return -1;
}

int main(){
    node *top=NULL;
    top=push(top,1);
    top=push(top,2);
    top=push(top,3);
    display(top);
}