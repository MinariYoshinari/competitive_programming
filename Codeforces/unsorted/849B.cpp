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
#define EPS 1e-10
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n, flag = 1;
    cin >> n;

    vector<long double> v(n+1);

    rep(n) cin >> v[i+1];

    vector<int> idx;

    reppp(j, 4, n){
        if(abs(v[j] - ((v[3]-v[2])*(long double)j + (v[3]-(v[3]-v[2])*(long double)3))) > EPS){
            flag = 0;
            break;
        }
    }
    if(flag && abs(v[1] - ((v[3]-v[2])*(long double)1 + (v[3]-(v[3]-v[2])*(long double)3))) > EPS){
        cout << "Yes";
        return 0;
    }
    

    reppp(i, 2, n){
        flag = 1;
        idx.clear();

        reppp(j, 2, n){
            if(j == i) continue;
            if(abs(v[j] - ((v[i]-v[1])/(long double)(i-1)*(long double)j + (v[i]-(v[i]-v[1])/(long double)(i-1)*(long double)i))) > EPS){
                if((int)idx.size() < 2){
                    idx.pb(j);
                }else{
                    int k = idx[0], l = idx[1];
                    if(abs(v[j] - ((v[k]-v[l])/(long double)(k-l)*j + (v[k]-(v[k]-v[l])/(long double)(k-l))*(long double)k)) > EPS){
                        flag = 0;
                        break;
                    }
                }
            }
        }
        int m = (int)idx.size();
        if(flag && m > 0){
            if(m == 1 || (m == 2 && abs((v[i]-v[1])/(long double)(i-1) - (v[idx[0]]-v[idx[1]])/(long double)(idx[0]-idx[1])) < EPS)){
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}
