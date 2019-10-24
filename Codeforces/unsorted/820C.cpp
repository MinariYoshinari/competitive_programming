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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    int a, b, l, r, n;
    scanf("%d%d%d%d", &a, &b, &l, &r);
    n = a + b;
    vector<int> s(a+1);
    reppp(i, 1, a){
        s[i] = i;
    }
    if(r-l+1 >= n){
        cout << a+1 << endl;
    }else{
        if(l % n < a){
            if(r % n < a){
                cout << r-l+1 << endl;
            }else{
                //難しそう
            }
        }else{
            if(r % n >= a){
                cout << 1 << endl;
            }else{
                if(l / n == r / n){
                    cout << 1+(r%n)+1 << endl;
                }else{
                    if(a >= b){
                        cout << a+1 << endl;
                    }else{
                        cout << a+2 << endl;
                    }
                }
            }
        }
    }
    return 0;
}

// whileの方がforより速い説