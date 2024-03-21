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

class Node {
  public :
  int l = -1 ; int  r = -1; int  val = 0;
 

};

int N = 1e5+10;
int M = N * 50;
vt<int>roots(N);
vt<Node>tree(M);
int ts = 0;
int n ;

int build(int l, int r){
  int v = ts++;
  tree[v] = Node();
  if( l + 1 == r){
    return v;
  }
  int mid = (l + r)/2;
  tree[v].l = build(l , mid);
  tree[v].r = build(mid , r);
  return v;
}

int addNode(int v, int a, int b, int pos, int delta){
  if(pos < a || pos >=b ){return v;}
  int u = ts++;
  tree[u] = tree[v];
  tree[u].val += delta;
  if(tree[v].l == -1){return u;}
  int mid = ( a + b )/2;
  tree[u].l = addNode(tree[v].l , a, mid , pos ,delta);
  tree[u].r = addNode(tree[v].r, mid , b , pos, delta);
  return u;
}
int findNext(int v, int a, int b , int k){
  if(k >= tree[v].val){ return b;}
  if(a + 1 == b){return a;}
  int mid = (a+ b)/2;
  if(k >= tree[tree[v].l].val){
    return findNext(tree[v].r , mid , b , k - tree[tree[v].l].val);
  }
  return findNext(tree[v].l , a , mid , k );
}
int val(int k ){
  int pos = 0;
  int ans = 0;
  while(pos < n){
      ans ++;
      pos = findNext(roots[pos], 0 , n , k );
  }
  return ans;
}
void solve(){
 cin>>n;
 vt<int>v(n);
 rep(i , 0 , n){cin>>v[i];}
 vt<int>lst(n+1 , -1);
 roots[n] = build(0 , n);
 repr(i , n- 1  , 0){
  int x = v[i];
  int root = roots[i+1];
  if(lst[x] != -1){
     root = addNode(root, 0 , n , lst[x] , -1);
  }
  lst[x] = i;
  roots[i] = addNode(root, 0 , n , lst[x] , 1);
 }

  for(int  k = 1 ; k<=n ;k++){
    cout << val(k)<<" ";
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