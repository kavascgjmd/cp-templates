#include <bits/stdc++.h>
using namespace std;

// #define __int128_t i128
const double eps = 1e-6;
#define ll long long
typedef long double ld;
#define pb push_back // for vector
#define pi pair <ll, ll>
// #define mp make_pair
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define ff first
#define ss second
#define vt vector
#define vi vt<ll>
#define ub upper_bound
#define lb lower_bound
#define repr(i, n, a) for (ll i = n; i >= a; i--)
#define dq deque
#define inset(a, st) st.find(a) != st.end()
#define issub(a, b) b.find(a) != string::npos // check if a is substr of b
#define len(a) (ll)a.size()
const ld PI = 2 * acos(0.0);
const ll mod = 1e9 + 7;
const ll nax = 2e5 + 5;
void ff(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
struct cmp{
  bool operator()(pair<ll,ll>&a, pair<ll,ll>&b){
    if(a.first == b.first){
      return a.second > b.second;
    }
    return a.first < b.first;
  }
};

bool cmp2(pair<ll,ll>&a, pair<ll,ll>&b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

void solve(){
  int n ;
  cin>>n;
  vt<int>v(n);
  int S = (int)sqrt(n + .0)+1;

  rep(i , 0 ,  n){cin>>v[i];}
  vt<vt<pi>>blocks(S);
  rep(i , 0 , n ){
    blocks[i/S].push_back({v[i] ,  i});
  }
  rep(i , 0 , blocks.size()){
    sort(all(blocks[i]));
  }
  int q;
  cin>>q;
  while(q--){
    int x ;
    cin>> x ;
    if(x == 0){
    int a, b , c;
    cin>>a>>b>>c;
    a--; b--;
    int sol = 0;
    int st= (a / S)+1;
    int end = (b/S);
    
    bool f = 0;
    if(b -a +  1 <= S){
      while( a <= b){
       if(v[a] >=c ){
       sol ++;
       }
     
       a ++ ;
    }
    f = 1;
    }
    if(f){
      cout << sol<<"\n";
      continue;
    }

    while( a < st * S){
       if(v[a] >=c ){
       sol ++;
       }
     
       a ++ ;
    }
    while(st < end){
      pi p = {c, -1};
      sol += blocks[st].size() -  (upper_bound(all(blocks[st]) , p) - blocks[st].begin());
      st++;
    }
    
    (end *= S);
    // cout << end <<" ";
    while(end <= b){
       if(v[end] >= c){
        sol ++;
       }
      //  cout << end <<" ";
       end ++;
    }
   cout << sol<<"\n";
    }
    else {
    int a, b;
    cin>>a>>b;
    a--;
    pi p = {v[a],a };
    v[a] = b;
    int ind = lower_bound(all(blocks[a/S]) , p)  - blocks[a/S].begin();
    blocks[a/S][ind] = {b,a};
    sort(all(blocks[a/S]));
    }
  }
}

int main(){

    ff();
    //   ll tn;
    // cin>>tn;
    
    // while(tn--){
   
    solve();
// }

return 0;
}