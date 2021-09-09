#include<iostream>
using namespace std;

struct priority_queue{
    int capacity;
    int size=0;
    int *arr;

    priority_queue(int n){
        arr=new int[n];
        capacity=n;
    }

    void insert(int x){
        size++;
        int temp=x;
        int n=size;
        while(n>1){
            if(arr[n/2] < temp){
                arr[n]=arr[n/2];
                n=n/2;
            }
            else
                break;
        }
        arr[n]=temp;
    }

    int dequeue(){
        int n=size;
        int temp=arr[1];
        arr[1]=arr[n];
        int i=1;
        int j=2*i;
        while(j<n){
            if(j<n-1){
                if(arr[j]<arr[j+1])
                    j=j+1;
            }
            if(arr[j]>arr[i]){
                swap(arr[i],arr[j]);
                i=j;
                j=2*i;
            }
            else
                break;
        }
        size--;
        return temp;
    }
};

int main(){
    priority_queue p(5);
    for(int i=0;i<5;i++){
        int a;
        cin>>a;
        p.insert(a);
    }
    for(int i=1;p.size>0;i++){
        cout<<p.dequeue()<<" ";
    }
}