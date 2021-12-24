/* Shubham Kumar */
 
#include<bits/stdc++.h>
using namespace std;

#define competitive() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);ll z;cin>>z;while(z--){solve();}
#define MOD 1000000007
#define MOD1 998244353
#define all(x) (x).begin(), (x).end()
#define minheap(pq) priority_queue <int, vector<int>, greater<int> > pq;
#define maxheap(pq) priority_queue <int> pq;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
vector<ll> sieve(ll n) {ll*arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
//give prime nos till n

bool comp(tuple<ll,ll> &a,tuple<ll,ll> &b){return (get<1>(a) > get<1>(b));}
bool asc(int a,int b){return (a<b);}  // ascending order
bool des(int a,int b){return (a>b);}  // Descending order

void solve(){
    
}

	
int main() {
    competitive();
}