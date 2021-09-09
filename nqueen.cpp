#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;



bool issafe(vector<vector<int>> &arr,int row,int col,int n){
    // for all col elements in a row
    for(int i=0;i<n;i++){
        if(arr[row][i]==1)
            return false;
    }

    // for all row elements in a col
    for(int i=0;i<n;i++){
        if(arr[i][col]==1)
            return false;
    }

    // for 135 degree diagonal
    int i=row;
    int j=col;
    while((i>=0 && i<n) && (j>=0 && j<n)){
        if(arr[i][j]==1)
            return false;
        i++;
        j++;
    }
    int k=row;
    int l=col;
    while((k>=0 && k<n) && (l>=0 && l<n)){
        if(arr[k][l]==1)
            return false;
        k--;
        l--;
    }

    // for 45 degree diagonal
    int a=row;
    int b=col;
    while((a>=0 && a<n) && (b>=0 && b<n)){
        if(arr[a][b]==1)
            return false;
        a--;
        b++;
    }

    int c=row;
    int d=col;
    while((c>=0 && c<n) && (d>=0 && d<n)){
        if(arr[c][d]==1)
            return false;
        c++;
        d--;
    }

    return true;
}

bool nqueen(vector<vector<int>> &arr,int n,int row){
    if(row==n)
        return true;
    for(int i=0;i<n;i++){
        if(issafe(arr,row,i,n)){
            arr[row][i]=1;
            row=row+1;
            if(nqueen(arr,n,row))
                return true;
            arr[row][i]=0;
        }
    }
    return false;

}

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    vector<vector<int>> arr(n,v);
    int row=0;
    nqueen(arr,n,row);
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
