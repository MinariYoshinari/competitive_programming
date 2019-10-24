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

int judge(vector<ll> v, ll p, int is_x){
    map<ll, int> mp[2];
    mp[1][0] = 1;
    int ii = 1;
    rep((int)v.size()){
        ii = 1 - ii;
        for(auto itr=mp[1-ii].begin();itr!=mp[1-ii].end();++itr){
            mp[ii][itr->first + v[i]] = 1;
            if(is_x && i == 0) continue;
            mp[ii][itr->first - v[i]] = 1;
        }
        mp[1-ii].clear();
    }
    return mp[ii][p];
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    s += 'T';
    ll x, y;
    cin >> x >> y;

    vector<ll> vx, vy;
    ll cnt = 0;
    int is_x = 1;
    rep((int)s.length()){
        if(s[i] == 'T'){
            if(cnt != 0){
                if(is_x) vx.push_back(cnt);
                else vy.push_back(cnt);
                cnt = 0;
            }
            is_x = 1 - is_x;
        }else{
            cnt++;
        }
    }

    /*
    for(ll item: vx){
        cout << item << " ";
    }
    cout << endl << judge(vx, x) << endl;
    for(ll item: vy){
        cout << item << " ";
    }
    cout << endl << judge(vy, y) << endl;
    */
    
    if(judge(vx, x, (int)(s[0] == 'F')) && judge(vy, y, 0)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
