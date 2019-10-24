#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

char ans[100][50];
int w, b, ww, bb;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    cin >> w >> b;

    ww = 1;
    bb = 1;

    rep(50){
        if(i % 2 == 0 || i >= 40){
            repp(j, 50) ans[i][j] = '#';
        }else{
            repp(j, 50){
                if((j % 2) != 0 && ww < w){
                    ans[i][j] = '.';
                    ww++;
                }
                else ans[i][j] = '#';
            }
        }
    }
    rep(50){
        if(i % 2 == 0 || i >= 40){
            repp(j, 50) ans[i+50][j] = '.';
        }else{
            repp(j, 50){
                if((j % 2) != 0 && bb < b){
                    ans[i+50][j] = '#';
                    bb++;
                }
                else ans[i+50][j] = '.';
            }
        }
    }
    cout << 100 << " " << 50 << endl;
    rep(100){
        repp(j, 50) cout << ans[i][j];
        cout << endl;
    }
}
