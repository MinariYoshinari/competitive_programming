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

int used[26][26];

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.length();
    if(s.length() != 26){
        rep(n){
            used[0][(int)(s[i]-'a')] = 1;
        }
        cout << s;
        rep(26){
            if(!used[0][i]){
                putchar('a'+i);
                break;
            }
        }
    }else{
        used[0][(int)(s[0]-'a')] = 1;
        reppp(i, 1, n){
            repp(j, 26){
                if(used[i-1][j]) used[i][j] = 1;
            }
            used[i][(int)(s[i]-'a')] = 1;
        }
        int change_idx = -1, change = -1;
        for(int i=n-2;i>=0;i--){
            reppp(j, (int)(s[i]-'a')+1, 26){
                if(!used[i][j]){
                    change = j;
                    change_idx = i;
                    break;
                }
            }
            if(change_idx != -1) break;
        }
        if(change_idx == -1){
            cout << -1;
        }else{
            cout << s.substr(0, change_idx);
            putchar(change+'a');
        }
    }
    return 0;
}