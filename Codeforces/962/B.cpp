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
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n,a,b, ans = 0;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    rep(n){
        if(s[i] == '*') continue;
        if(a >= b){
            if(i == 0){
                if(a != 0){
                    s[i] = 'a';
                    a--;
                    ans++;
                }else if(b != 0){
                    s[i] = 'b';
                    b--;
                    ans++;
                }
            }else if(s[i-1] == 'a'){
                if(b != 0){
                    s[i] = 'b';
                    b--;
                    ans++;
                }
            }else{
                if(a != 0){
                    s[i] = 'a';
                    a--;
                    ans++;
                }
            }
        }else{
            if(i == 0){
                if(b != 0){
                    s[i] = 'b';
                    b--;
                    ans++;
                }else if(a != 0){
                    s[i] = 'a';
                    a--;
                    ans++;
                }
            }else if(s[i-1] == 'b'){
                if(a != 0){
                    s[i] = 'a';
                    a--;
                    ans++;
                }
            }else{
                if(b != 0){
                    s[i] = 'b';
                    b--;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
