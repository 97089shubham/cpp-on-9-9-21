#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define loop(k, n) for (ll i = k; i < n; i++)

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int a[], int n)
{
    head = new node;
    head->data = a[0];
    head->next = NULL;
    node *last, *t;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void display_back(node *p)
{
    if (p == NULL)
        return;
    display_back(p->next);
    cout << p->data << " ";
}

int count(node *p)
{
    int res = 0;
    while (p != NULL)
    {
        res++;
        p = p->next;
    }
    return res;
}

node *search(node *p, int key)
{
    if (p == NULL)
        return NULL;
    while (p)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

void insert(node *p, int x, int pos)
{
    node *t = new node;
    t->data = x;
    t->next = NULL;
    if (pos == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void insertsorted(struct node *p, int x)
{
    struct node *t = new node;
    t->data = x;
    t->next = NULL;
    if (x <= p->data)
    {
        t->next = p;
        head = t;
    }
    else
    {
        struct node *q = NULL;
        while (p != NULL && x > p->data)
        {
            q = p;
            p = p->next;
        }
        t->next = q->next;
        q->next = t;
    }
}

void deleteele(struct node *p, int pos)
{
    if (pos == 1)
    {
        struct node *temp = p;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        struct node *q = NULL;
        for (int i = 1; i < pos && p != NULL; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        p->next = NULL;
        delete p;
    }
}

void reverse(struct node *p)
{
    struct node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void recursive_reverse(struct node *q, node *p)
{
    if (p)
    {
        recursive_reverse(p, p->next);
        p->next = q;
    }
    else
        head = q;
}

bool loopcheck(node *first)
{
    node *p = first, *q = first;
    do
    {
        p = p->next;
        q = q->next;
        if (q != NULL)
            q = q->next;
        else
            q = NULL;
    } while (p && q && p != q);

    if (p == q)
        return true;
    else
        return false;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, sizeof(a) / sizeof(a[0]));
    display(head);
    // display_back(head);
    // cout<<count(head);
    // cout<<search(head,4);
    // node *q=NULL;
    // recursive_reverse(q,head);
    // display(head);
    // cout<<boolalpha<<loopcheck(head);
}

// doubly linked list

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL;

void create_doubly(int a[], int n)
{
    head = new node;
    head->prev=NULL;
    head->data = a[0];
    head->next = NULL;
    node *t, *last;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        t->prev=last;
        last->next = t;
        last = t;
    }
}

void display_doubly(struct node *p)
{   node *q=0;
    while (p)
    {
        cout << p->data << " ";
        q=p;
        p = p->next;
    }
    cout<<endl;
    while(q){
        cout<<q->data<<" ";
        q=q->prev;
    }
    cout<<endl;
}

void insert_doubly(int x,int pos){
    node *t=new node;
    t->data=x;
    t->prev=0;
    t->next=0;
    if(pos==0){
        t->next=head;
        head->prev=t;
        head=t;
    }
    else{
        node *q=0,*p=head;
        for(int i=0;i<pos && p!=0;i++){
            q=p;
            p=p->next;
        }
        t->next=q->next;
        t->prev=p->prev;
        q->next=t;
        p->prev=t;
    }
}

void delete_doubly(int pos){
    if(pos==1){
        node *temp=head;
        node *p=temp->next;
        p->prev=0;
        delete temp;
        head=p;
    }
    else{
        node *p=head;
        for(int i=1;i<pos;i++)
            p=p->next;
        if(p->next)
            p->next->prev=p->prev;
        p->prev->next=p->next;
        delete p;
    }
}

int main()
{
    int a[] = {3, 5, 7, 9, 11};
    int size = sizeof(a) / sizeof(a[0]);
    create_doubly(a, size);
    display_doubly(head);
    // insert_doubly(23,2);
    // display_doubly(head);
    delete_doubly(5);
    display_doubly(head);
}



// later formed

#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *create(int n){
    node *p=new node;
    cin>>p->data;
    p->next=NULL;
    node *last=p;
    for(int i=1;i<n;i++){
        node *t=new node;
        cin>>t->data;
        t->next=NULL;
        last->next=t;
        last=t;
    }
    return p;
}

void display(node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    int n;
    cin>>n;
    node *head=create(n);
    head=reverse(head);
    display(head);
}