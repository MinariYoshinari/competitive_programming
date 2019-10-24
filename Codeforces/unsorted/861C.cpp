#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 2000000001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int m = (int)s.length();

    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    int cnt = 0;
    vector<int> space_before;
    rep(m){
        int is_vowel = 0;
        repp(j, 5){
            if(s[i] == vowels[j]){
                is_vowel = 1;
                break;
            }
        }

        if(is_vowel){
            cnt = 0;
        }else{
            cnt++;
        }
        
        if(cnt >= 3){
            int all_same = 1;
            repp(j, cnt-1){
                if(s[i-cnt+j+1] != s[i]){
                    all_same = 0;
                    break;
                }
            }
            if(!all_same){
                space_before.pb(i);
                cnt = 1;
            }
        }
    }

    int si = 0, sb_size = (int)space_before.size();
    rep(m){
        if(si < sb_size && i == space_before[si]){
            cout << ' ';
            si++;
        }
        cout << s[i];
    }
}