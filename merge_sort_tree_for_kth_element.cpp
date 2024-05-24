#include <bits/stdc++.h>
using namespace std;
//https://www.spoj.com/problems/MKTHNUM/
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
const ll mod = 1e9+7;
const ll nax = 2e5 + 5;
const ll mod2 = 998244353;
const int LIM = 263005;
const int N = 100005;
void ff(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
ll binexpo(ll a, ll n , ll mod ){
   if(n == 0){return 1;}
   ll res = binexpo(a, n / 2 , mod);
   if(n & 1){res *= a % mod; res%= mod;}
   return res;
}
ll inverse_mod(ll a ){
   return binexpo(a , mod -2 , mod);
}
 
struct cmp{
  bool operator()(int a,int b){
    return a < b;
  }
};
bool cmp2(pair<ll,ll>&a, pair<ll,ll>&b){
    return a.first + a.second > b.first + b.second;
}
vt <pi>nums;
vt <vt<int>> seg(LIM);
vt<int>inp(N);
void solve(){
       
 
}
 
 
void build_merge_sort(int t,  int i , int j){
    if(i == j){
        seg[t].push_back(nums[i].second);
        return;
    }
    int mid = (i + j)/2;
    int left = 2*t ;
    int right = 2*t+1;
    build_merge_sort(left  , i , mid);
    build_merge_sort(right , mid + 1 , j);
    merge(seg[left].begin(), seg[left].end(), seg[right].begin() , seg[right].end(), back_inserter(seg[t]));
}
 
int query(int t , int i , int j , int l, int r, int k){
    if(i == j){
        return seg[t][0];
    }
    int mid = (i + j)/2;
    int left = 2*t ;
    int tot = upper_bound(all(seg[left]), r) - lower_bound(all(seg[left]) , l);
    if(tot >= k){
        return query(2*t , i , mid, l ,r , k);
    }
    else {
        return query(2*t + 1 , mid +1 , j , l ,r , k-tot);
    }
}
int main(){
    ff();
    
    int n , m , x, y, idx,k, ans;
    cin>>n>>m;
    rep(i , 0 , n){
       cin>>x;
       nums.push_back({x, i});
       inp[i] = x;
    }
    sort(all(nums));
    build_merge_sort(1 , 0 , n-1);
    while(m--){
        cin>>x>>y>>k;
        --x; --y;
        idx = query(1, 0 , n-1, x, y , k);
        ans = inp[idx];
        cout << ans <<"\n";
    }
} 

