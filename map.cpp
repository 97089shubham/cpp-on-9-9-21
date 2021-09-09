#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;

void print(map<string,int> m){
    for(auto i:m)
        cout<<i.first<<" - "<<i.second<<endl;
    cout<<endl;
}

int main(){
    map<string,int> m{{"ab",1},{"bc",2},{"cd",3},{"de",4}};
    m["ef"]=6;
    // cout<<m.size()<<endl;
    // print(m);

    // map<string,int> a=m;
    // a["ab"]=90;
    // print(m);print(a);

    auto it=m.find("cd");
    cout<<it->first;
}