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

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.length();
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    
    int flag = 1, i = 0;
    while(i < n-1-i){
        if(s[i] != s[n-1-i]){
            flag = 0;
            break;
        }
        i++;
    }
    if(flag == 1){
        cout << 0 << endl;
        return 0;
    }

    reppp(ans, 1, n-1){
        int flag = 1, i = ans;
        while(i < n-1-i+ans){
            if(s[i] != s[n-1-i+ans]){
                flag = 0;
                break;
            }
            i++;
        }
        if(flag){
            cout << ans << endl;
            return 0;
        }
    }
      
}
