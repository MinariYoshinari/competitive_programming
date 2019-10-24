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

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    if(n < a || n < b){
        cout << -1 << endl;
        return 0;
    }

    
    vector<int> idx(b, 0), start(b+1);
    start[0] = 1;
    idx[0] = a;
    reppp(i, 1, b){
        start[i] = start[i-1] + idx[i-1];
        idx[i] = (n-a)/(b-1) + ((n-a)%(b-1)>=i?1:0);
        if(idx[i] > a || idx[i] == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    start[b] = start[b-1] + idx[b-1];

    if(start[b] != n+1){
        cout << -1 << endl;
        return 0;
    }

    for(int i=b-1;i>=0;i--){
        reppp(j, start[i], start[i+1]){
            cout << j << " ";
        }
    }

    cout << endl;
    return 0;
}
