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
    ios::sync_with_stdio(false); cin.tie(0);
    int n, tmp;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    rep(n){
        cin >> tmp;
        mp[tmp]++;
        a[i] = tmp;
    }
    int dim = *max_element(all(a));
    int  flag = 1;
    if(dim % 2 == 0){
        for(int i=dim;i>dim/2;i--){
            if(mp[i] >= 2){
                mp[i] -= 2;
            }else{
                flag = 0;
                break;
            }
        }
        if(flag){
            if(mp[dim/2] == 1){
                mp[dim/2]--;
            }else{
                flag = 0;
            }
        }
        if(flag){
            for(auto iter=mp.begin(); iter!=mp.end(); iter++){
                if(iter->second == 0) continue;
                if(dim/2+1 > iter->first){
                    flag = 0;
                    break;
                }
            }
        }
    }else{
        for(int i=dim;i>=(dim+1)/2;i--){
            if(mp[i] >= 2){
                mp[i] -= 2;
            }else{
                flag = 0;
                break;
            }
        }
        if(flag){
            for(auto iter=mp.begin(); iter!=mp.end(); iter++){
                if(iter->second == 0) continue;
                if((dim+1)/2 >= iter->first){
                    flag = 0;
                    break;
                }
            }
        }
    }

    if(flag) cout << "Possible";
    else cout << "Impossible";
}
