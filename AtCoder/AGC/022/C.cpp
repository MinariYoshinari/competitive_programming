#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

ll wf[51][51];
int n;
int a[50], b[50];

void floyd_warshall(set<int> st){
    fill((ll *)wf[0], (ll *)wf[51], LLONG_MAX);

    for(int k: st){
        repp(n, 51){
            wf[n][n%k] = 1LL;
        }
    }

    repp(k, 51){
        repp(i, 51){
            repp(j, 51){
                wf[i][j] = min(wf[i][j], (wf[i][k]|wf[k][j]));
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    rep(n) cin >> a[i];
    rep(n) cin >> b[i];

    int same = 1, max_a = -1, max_b = -1;
    rep(n){
        if(a[i] != b[i]) same = 0;
        max_a = max(max_a, a[i]);
        max_b = max(max_b, b[i]);
    }

    /* 操作の必要なし */
    if(same){
        cout << 0 << endl;
        return 0;
    }
    /* bの要素がすべて0 (=1で剰余とっておしまい) */
    if(max_b == 0){
        cout << 2 << endl;
        return 0;
    }

    set<int> st;
    reppp(i, 1, 51) st.insert(i);
    
    int use = 0;
    ll ans = 0LL;
    floyd_warshall(st);
    rep(n){
        if(wf[a[i]][b[i]] == LLONG_MAX){
            use = 1;
            break;
        }
    }
    if(use){
        cout << -1 << endl;
        return 0;
    }

    for(int l=50;l>=1;l--){
        int use = 0;
        st.erase(l);
        floyd_warshall(st);
        rep(n){
            if(wf[a[i]][b[i]] == LLONG_MAX){
                use = 1;
                break;
            }
        }
        if(use){
            ans |= 1LL << l;
            st.insert(l);
        }
    }

    cout << (ans?ans:-1) << endl;
}
