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

int total[202][202], deployed[202][202];

int main(){
    int t,a;
    cin >> t;
    repp(tt, t){
        cin >> a;
        int ex = (a+2)/3;
        int x = 1 + (ex+1)/2;
        int y = 2;
        int xx, yy;
        
        cout << x << " " << y << endl;
        cin >> xx >> yy;
        while(xx != 0 || yy != 0){
            int min_total = INT_MAX;
            deployed[xx][yy] = 1;
            reppp(dx, -1, 2){
                reppp(dy, -1, 2){
                    total[xx+dx][yy+dy]++;
                }
            }
            reppp(i, 2, ex+1){
                if(min_total > total[i][2]){
                    min_total = total[i][2];
                    x = i;
                }
            }

            cout << x << " " << y << endl;
            cin >> xx >> yy;
        }
    }
}
