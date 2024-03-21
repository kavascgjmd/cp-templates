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
class Pair{
  public :
  ll a, b , h;
  Pair(ll a, ll b, ll h){this->a = a; this->b = b ; this->h = h;}
};

bool cmp3(Pair & x, Pair & y){
  if(x.b == y.b){
    if(x.a == y.a){
     if(x.h == y.h){
      return x.h > y.h;
     }
    }
    return x.a > y.a;
  }
  return x.b > y.b;
}

vt<ll>tree;
void update(ll k , ll x){
  k += 1;
  while(k < tree.size()){
    tree[k] = max(tree[k], x);
    k += (k & -k);
  }
}

ll query(ll y){
  y += 1;
   ll ans = 0;
   while(y > 0){
    ans = max(ans, tree[y]);
    y -= (y & -y);
   }
   return ans;
}

void solve(){
ll n ;
cin>>n;
vt<Pair>v;
ll t = n;
while(t -- ){
  ll a, b , h;
  cin>>a>>b>>h;
  Pair p(a, b, h);
  v.push_back(p);
}

sort(all(v) , cmp3);
ll count = 0; set<ll>s;
rep(i  , 0 , n){
  s.insert(v[i].a); s.insert(v[i].b);
}
ll size = s.size();
map<ll,ll>mp;
for(auto & x : s){
  mp[x] = count;
  count ++;
}

tree.resize(size+1);
rep(i,  0 , size+1){
  tree[i] = 0;
}
vt<ll>dp(n);
rep(i , 0 , n){
    dp[i] = query(mp[v[i].b] -1 )+v[i].h;
    update(mp[v[i].a],dp[i]);
}
ll sol = 0;
rep(i , 0 , n){
   sol = max(sol , dp[i]);
}
cout <<sol<<"\n";
}


int_fast32_t main(){

    // ff();
    //   ll t;
    // cin>>t;
    
    // while(t--){
   
    solve();
// }

return 0;
}