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

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.length();

    int ans = INT_MAX;
    reppp(i, 1, 1 << n){
        string t = "";
        repp(j, n){
            if(i & (1 << j)){
                t += s[j];
            }
        }
        int j = 0;
        int m = (int)t.length();
        while(j < m && t[j] == '0') j++;
        if(j == m) continue;
        if(j != 0){
            t = t.substr(j, m-j);
            m -= j;
        }
        int num = stoi(t);
        int rt = sqrt(num);
        if(rt*rt == num && (n-m) < ans){
            ans = n-m;
        }
    }
    cout << (ans==INT_MAX?-1:ans) << endl;
}
