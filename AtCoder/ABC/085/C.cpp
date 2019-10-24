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
#define MOD 1000000007
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,y;
    scanf("%d %d", &n, &y);

    int A = 10000, B = 5000, C = 1000;

    reppp(a, 0, y/A+1){
        reppp(b, 0, (y-A*a)/B+1){
            int c = (y-A*a-B*b)/C;
            if(a+b+c == n){
                printf("%d %d %d\n", a,b,c);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}
