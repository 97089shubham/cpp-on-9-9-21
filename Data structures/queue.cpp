#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
}*front=0,*rear=0;

void enqueue(int x){
    node *t=new node;
    if(t==0)
        cout<<"Queue is full";
    else{
        t->data=x;
        t->next=0;
        if(front==0)
            front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    node *t;
    if(front==0)
        cout<<"Queue is empty";
    else{
        x=front->data;
        t=front;
        front=front->next;
        delete t;
    }
    return x;
}

void display(node *front){
    node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display(front);
}

// array implementation

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void create(queue *q,int n){
    q->size=n;
    q->front=q->rear=0;
    q->arr=new int[q->size];
}

void enqueue(queue *q,int x){
    if((q->rear+1)%q->size==q->front)
        cout<<"Queue is full"<<endl;
    else{
        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear]=x;
    }
}

int dequeue(queue *q){
    int x=-1;
    if(q->front==q->rear)
        return x;
    else{
        q->front=(q->front+1)%q->size;
        x=q->arr[q->front];
        return x;
    }
}

void display(queue q){
    int i=q.front;
    do{
        i=(i+1)%q.size;
        cout<<q.arr[i]<<" ";
    }while(i!=(q.rear));
    cout<<endl;
}

int main(){
    queue q;
    create(&q,5);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,5);
    enqueue(&q,6);
    display(q);
}


//circular linked list implementation

#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
}*rear=0;

void enqueue(int x){
    node *t=new node;
    t->data=x;
    t->next=0;
    if(rear==0){
        rear=t;
        rear->next=rear;
    }
    else{
        node *q;
        q=rear->next;
        rear->next=t;
        t->next=q;
        rear=t;
    }
}

int dequeue(){
    int x=-1;
    node *t;
    if(rear==0)
        return -1;
    else if(rear->next==rear){
        x=rear->data;
        t=rear;
        rear=0;
        delete t;
        return x;
    }
    else{
        x=rear->next->data;
        t=rear->next;
        rear->next=t->next;
        delete t;
    }
    return x;
}

void display(node *rear){
    node *t=rear;
    do{
        t=t->next;
        cout<<t->data<<" ";
    }while(t!=rear);
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    cout<<dequeue()<<endl;
    dequeue();
    dequeue();
    dequeue();
    display(rear);
}

// best implementation
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

struct queue{
    node *front=0,*rear=0;

    void enqueue(int x){
        node *t=new node;
        if(t==0)
            cout<<"Queue is full";
        else{
            t->data=x;
            t->next=0;
            if(front==0)
                front=rear=t;
            else{
                rear->next=t;
                rear=t;
            }
        }
    }

    void dequeue(){
        node *t;
        if(front==0)
            cout<<"Queue is empty";
        else{
            t=front;
            front=front->next;
            delete t;
        }
    }

    int Rear(){
        if(rear==0)
            return -1;
        return rear->data;
    }

    int Front(){
        if(front==0)
            return -1;
        return front->data;
    }

    void display(){
        node *p=front;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};


int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.Rear()<<endl;
    cout<<q.Front()<<endl;
    // q.dequeue();
    cout<<q.Front()<<endl;
    cout<<q.Rear()<<endl;
    q.display();

    queue w;
    w.enqueue(10);
    w.enqueue(20);
    w.enqueue(30);
    cout<<w.Rear()<<endl;
    cout<<w.Front()<<endl;
    w.dequeue();
    cout<<w.Front()<<endl;
    cout<<w.Rear();
}