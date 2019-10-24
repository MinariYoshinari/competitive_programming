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

const ll MOD = 1000000007;
const double EPS = 1e-9;

int main(){
    int n, p;
    cin >> n;
    rep(n){
        cin >> p;
        priority_queue<Pii> que;
        int a, total = 0;
        repp(j, p){
            cin >> a;
            total += a;
            que.push(Pii(a, j));
        }

        cout << "Case #" << i+1 << ": ";
        while(total > 0){
            do{
                Pii pa = que.top(); que.pop();
                putchar('A'+pa.second);
                total--;
                que.push(Pii(pa.first-1, pa.second));
            }while(total & 1);
            cout << " ";
        }
        cout << endl;
    }
}
