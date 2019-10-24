#include<cstdio>
#include<cstdlib>
#include<cmath>
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
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    int h,w;
    cin >> h >> w;
    int one = (h*w) % 2;
    int four = (h/2) * (w/2);
    int two = (h*w - one - 4*four)/2;
    /*
    printf("%d %d %d\n", one, two, four);
    return 0;
    */

    map<char, int> mp;
    rep(h){
        string s;
        cin >> s;
        repp(j, w) mp[s[j]]++;
    }

    for(auto itr=mp.begin();itr!=mp.end();itr++){
        int n = itr->second;
        if(n % 2 == 1){
            if(one > 0){
                n--;
                one--;
            }else{
                cout << "No\n";
                return 0;
            }
        }
        while(four > 0 && n >= 4){
            n -= 4;
            four--;
        }
        while(two > 0 && n >= 2){
            n -= 2;
            two--;
        }
        if(n > 0){
            cout << "No\n";
            return 0;
        }
    }
    if(one + two + four == 0){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}