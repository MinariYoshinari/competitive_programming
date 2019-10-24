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
#include<bitset>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int not_prime[1000000];

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    scanf("%d %d", &n, &m);

    not_prime[1] = 1;
    int j = 4;
    while(j <= 1000000){
        not_prime[j] = 1;
        j += 2;
    }
    for(int i=3;i<=1000;i+=2){
        if(not_prime[i]) continue;
        j = i+i;
        while(j <= 1000000){
            not_prime[j] = 1;
            j += i;
        }
    }

    int mst_cost = n-1;
    if(mst_cost != 2 && mst_cost % 2 == 0) mst_cost++;
    while(not_prime[mst_cost]){
        mst_cost += 2;
    }

    if(n == 2){
        printf("2 2\n1 2 2\n");
        return 0;
    }

    set<Pii> st;

    printf("2 %d\n", mst_cost);
    printf("1 2 1\n2 %d 1\n", n);
    st.insert(Pii(1,2));
    st.insert(Pii(2,n));
    reppp(i, 3, n){
        printf("1 %d %d\n", i, (i==n-1)?(mst_cost-n+2):1);
        st.insert(Pii(1,i));
    }
    
    if(m == n-1) return 0;

    int from = 1, to = n;
    rep(m-n+1){
        printf("%d %d %d\n", from, to, INF);
        st.insert(Pii(from, to));
        while(st.find(Pii(from, to)) != st.end()){
            if(to == n){
                from++;
                to = from + 1;
            }else{
                to++;
            }
        }
    }
    return 0;
}
