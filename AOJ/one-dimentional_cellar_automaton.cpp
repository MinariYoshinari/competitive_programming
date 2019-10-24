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

vector< vector<ll> > product(vector< vector<ll> > A, vector< vector<ll> > B, ll height, ll width, ll n, int m){
	
	vector< vector<ll> > C(height, vector<ll>(width, 0));
	
	rep(height){
		repp(j, width){
			repp(k, n){
				C[i][j] += A[i][k] * B[k][j];
			}
            C[i][j] %= m;
		}
	}
	
	return C;
}

signed main(){
    int n,m,t;
    ll a,b,c;
    vector< vector<ll> > ans;
    while(true){
        scanf("%d %d %lld %lld %lld %d", &n, &m, &a, &b, &c, &t);
        if(n == 0) break;

        vector< vector<ll> > s(n, vector<ll>(1));
        rep(n) scanf("%lld", &s[i][0]);

        vector< vector<ll> > A(n, vector<ll>(n, 0));
        rep(n){
            if(i > 0) A[i][i-1] = a;
            A[i][i] = b;
            if(i < n-1) A[i][i+1] = c;
        }

        vector< vector<ll> > B(n, vector<ll>(n, 0));
        rep(n) B[i][i] = 1;
        while(t){
            if(t & 1){
                B = product(B, A, n, n, n, m);
            }
            A = product(A, A, n, n, n, m);
            t = t >> 1;
        }

        vector< vector<ll> > C = product(B, s, n, 1, n, m);
        rep(n-1) printf("%lld ", C[i][0]);
        printf("%lld\n", C[n-1][0]);
    }


}
