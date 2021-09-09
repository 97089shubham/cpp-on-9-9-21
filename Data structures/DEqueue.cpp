#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

struct DEqueue{
    node *front=0,*rear=0;

    void insert_front(int x){
        node *t=new node;
        t->data=x;
        t->next=t->prev=0;
        if(front==0 && rear==0){
            front=t;
            rear=t;
        }
        else{
            front->prev=t;
            t->next=front;
            front=t;
        }
    }

    void insert_rear(int x){
        node *t=new node;
        t->data=x;
        t->next=t->prev=0;
        if(front==0 && rear==0){
            front=t;
            rear=t;
        }
        else{
            rear->next=t;
            t->prev=rear;
            rear=t;
        }
    }

    int delete_front(){
        int x=-1;
        if(front == rear && front==0){
            return x;
        }
        else if(front == rear){
            x=front->data;
            front=0;
            rear=0;
            return x;
        }
        else{
            x=front->data;
            node *t=front;
            front->next->prev=0;
            front=front->next;
            delete t;
        }
        return x;
    }

    int delete_rear(){
        int x=-1;
        if(front == rear && front==0){
            return x;
        }
        else if(front == rear){
            x=front->data;
            front=0;
            rear=0;
            return x;
        }
        else{
            x=rear->data;
            node *t=rear;
            rear->prev->next=0;
            rear=rear->prev;
            delete t;
        }
        return x;
    }

    bool isempty(){
        if(front==rear and front==0)
            return true;
        return false;
    }

    int get_front(){
        if(front==0)
            return 0;
        return front->data;
    }

    int get_rear(){
        if(rear==0)
            return 0;
        return rear->data;
    }
};

int main(){
    DEqueue q;
    cout<<q.delete_front()<<endl;
    cout<<q.get_front()<<endl;
    cout<<q.get_rear()<<endl;
    q.insert_front(1);
    cout<<q.get_front()<<endl;
    q.insert_front(2);
    cout<<q.get_front()<<endl;
    cout<<q.get_rear()<<endl;
    q.insert_rear(3);
    q.insert_rear(4);
    cout<<q.isempty()<<endl;
    cout<<q.get_front()<<endl;
    cout<<q.get_rear()<<endl;
    q.delete_front();
    q.delete_rear();
    cout<<q.get_front()<<endl;
    cout<<q.get_rear()<<endl;
}