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
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    scanf("%d", &n);
    
    char op;
    unsigned int x, a = 0, b = ~0;
    rep(n){
        scanf("\n%c %u", &op, &x);
        if(op == '|'){
            a |= x;
            b |= x;
        }else if(op == '&'){
            a &= x;
            b &= x;
        }else{
            a ^= x;
            b ^= x;
        }
        //printf("%c %x %x\n", op, a, b);
        
    }
    
    unsigned int on = 0, inverted = 0;
    rep(10){
        unsigned int j = 1 << i;
        if(((a & b) & j) != 0) on |= j;
        if(((~a & ~b) & j) != 0){
            on |= j;
            inverted |= j;
        }
        if(((a & ~b) & j) != 0) inverted |= j;
    }

    printf("%d\n", 2);
    printf("| %u\n", on&1023);
    printf("^ %u\n", inverted&1023);

}
