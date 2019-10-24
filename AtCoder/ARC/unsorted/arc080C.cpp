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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    int n;
    cin >> n;
    vector<int> a(3, 0);
    rep(n){
        int tmp;
        cin >> tmp;
        if(tmp % 4 == 0) a[2]++;
        else if(tmp % 2 == 0) a[1]++;
        else a[0]++;
    }

    if(a[0] == 0){
        cout << "Yes";
        return 0;
    }

    a[0]--;
    int last = 0;
    rep(n-1){
        if(last == 0){
            if(a[2] > 0){
                a[2]--;
                last = 2;
            }else{
                cout << "No";
                return 0;
            }
        }else if(last == 1){
            if(a[1] > 0){
                a[1]--;
                last = 1;
            }else if(a[2] > 0){
                a[2]--;
                last = 2;
            }else{
                cout << "No";
                return 0;
            }
        }else{
            int flag = 0;
            rep(3){
                if(a[i] > 0){
                    a[i]--;
                    last = i;
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
