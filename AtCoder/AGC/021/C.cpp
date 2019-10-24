#include <bits/stdc++.h>

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

int n,m,a,b;
int is = 0, js = 0;
char ans[1000][1000];

void puta(int i, int j){
    if(
        a == 0 ||
        j+1 >= m ||
        ans[i][j] != '.' || ans[i][j+1] != '.'
    ) return;
    ans[i][j] = '<';
    ans[i][j+1] = '>';
    a--;
}

void putb(int i, int j){
    if(
        b == 0 ||
        i+1 >= n ||
        ans[i][j] != '.' || ans[i+1][j] != '.'
    ) return;
    ans[i][j] = '^';
    ans[i+1][j] = 'v';
    b--;
}

void solve(){
    for(int i=is;i<n-1;i+=2){
        for(int j=js;j<m-1;j+=2){
            if(a){
                puta(i, j);
                puta(i+1, j);
            }else if(b){
                putb(i, j);
                putb(i, j+1);
            }
        }
    }
}

void odd_a(int start){
    is = 1;
    for(int j=start;j<m;j+=2){
        puta(0, j);
    }
}

void odd_b(int start){
    js = 1;
    for(int i=start;i<n;i+=2){
        putb(i, 0);
    }
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> a >> b;
    int aa = a, bb = b;
    if(2*(a+b) > n*m){
        cout << "NO" << endl;
        return 0;
    }

    fill(ans[0], ans[n], '.');
    if(n%2){
        odd_a(0);
        if(m%2){
            odd_b(1);
        }
    }else if(m%2){
        odd_b(0);
    }
    solve();

    if((a||b) && n%2 && m%2){
        a = aa;
        b = bb;
        fill(ans[0], ans[n], '.');
        puta(0, 0);
        puta(2, 1);
        putb(0, 2);
        putb(1, 0);
        if(m-3 > 0){
            odd_a(3);
        }
        if(n-3 > 0){
            odd_b(3);
        }
        solve();
    }

    if(a || b){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    rep(n){
        repp(j, m){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
