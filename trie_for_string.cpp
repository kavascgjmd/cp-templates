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
const ll mod = 1e9+7;
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
    Node * nodes[26];
    bool f ;
    ll count = 0;
    bool containsKey(char ch){
         if(nodes[ch-'a'] != NULL){
             return true;
         }
         return false;
    }
    Node * getKey(char ch){
         return nodes[ch-'a'];
    }
    Node * put(char ch, Node * node){
        nodes[ch-'a']= node;
        return node;
    }
};
class Trie {
public:
    Node * root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * node = root;
        for(int i = 0 ; i<word.length() ; i++){
           if(node->containsKey(word[i])){
              node = node->getKey(word[i]);
              node->count++;
           }
           else {
              Node * nnode = new Node();
              nnode->count = 1;
              node = node->put (word[i], nnode);
           }
        }
        node->f = true;
    }
    
    ll search(string word) {
        Node * node = root ;
        ll val = 0;
        for(int i = 0 ; i<word.size() ; i++){
            if(node->containsKey(word[i])){
                node = node->getKey(word[i]);
                val += node->count * 2;
            }
            else {
                return val;
            }
        }
        return val;
    }
    
 
};

void solve(){
ll n;
cin>>n;
vt<string>s(n);
ll sol = 0;
Trie trie;
rep(i  , 0 , n){
  cin>>s[i];
  sol += s[i].size();
  trie.insert(s[i]);
}
sol *= n;
sol *= 2;
rep(i , 0 , n){
  string x = s[i];
  reverse(all(x));
  sol -= trie.search(x);

  
}

cout << sol<<"\n";
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