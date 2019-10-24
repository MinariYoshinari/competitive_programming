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
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};
struct yahoo{string s; int idx, cnt;};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, flag = 0, cnt = 0; string s,t;
    cin >> n;
    set<char> candidate;
    for(char c='a';c<='z';c++) candidate.insert(c);
    rep(n){
        cin >> s >> t;
        if(flag){
            if(s == "!" || (s == "?" && i != n-1)){
                cnt++;
            }
        }else{
            if(s == "!"){
                set<char> tmp;
                repp(j, (int)t.length()){
                    if(candidate.find(t[j]) != candidate.end()){
                        tmp.insert(t[j]);
                    }
                }
                swap(candidate, tmp);
            }else if(s == "."){
                repp(j, (int)t.length()) candidate.erase(t[j]);
            }else if(s == "?"){
                repp(j, (int)t.length()) candidate.erase(t[j]);
            }
        }
        if((int)candidate.size() == 1){
            flag = 1;
        }
        // cout << (int)candidate.size() << endl;
    }
    cout << cnt << endl;
}