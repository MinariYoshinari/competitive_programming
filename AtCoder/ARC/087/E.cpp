#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MAX_N 112345
#define MOD 1000000007
#define EPS 1e-9
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::priority_queue;
using std::stack;
using std::map;
using std::pair;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

struct Trie{
    int max_index, n;
    vector< vector<int> > tree;
    vector<int> depth;

    Trie(){
        max_index = 0;
        n = 1;
        tree = vector< vector<int> >(MAX_N, vector<int>(2, -1));
        depth = vector<int>(MAX_N);
        depth[0] = 0;
    }

    int add(string s){
        int parent = 0;
        rep((int)s.length()){
            if(s[i] == '0'){
                if(tree[parent][0] == -1){
                    tree[parent][0] = ++max_index;
                    depth[max_index] = depth[parent] + 1;
                }
                parent = tree[parent][0];
            }else{
                if(tree[parent][1] == -1){
                    tree[parent][1] = ++max_index;
                    depth[max_index] = depth[parent] + 1;
                }
                parent = tree[parent][1];
            }
        }
        n = max_index + 1;
        return parent;
    }
};

ll grundy(ll l, ll d){
    return (l-d) & (d-l);
}

int main(){
    int n;
    ll l;
    string s;
    cin >> n >> l;

    Trie t = Trie();
    rep(n){
        cin >> s;
        t.add(s);
    }

    ll game = 0;
    rep(t.n){
        if((t.tree[i][0] == -1) ^ (t.tree[i][1] == -1)){
            game ^= grundy(l, t.depth[i]);
        }
    }

    if(game){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
    return 0;
}
