#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<bitset>

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

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll n,k,cnt = 0, i = 0, msb = -1;
    cin >> n >> k;
    map<ll, ll> mp;
    while(n > 0LL){
        if(n % 2){
            mp[i]++;
            msb = i;
            cnt++;
        }
        n >>= 1;
        i++;
    }

    if(cnt > k){
        cout << "No" << endl;
        return 0;
    }

    
    cout << "Yes" << endl;
    while(cnt != k){
        mp[msb]--;
        mp[msb-1] += 2LL;
        cnt++;
        if(mp[msb] == 0) msb--;
    }

    i = 0LL;
    
    for(auto itr=mp.rbegin();itr!=mp.rend();itr++){
        i += (itr->second);
        repp(j, (itr->second)){
            if(i == k && j == (itr->second) - 1LL) cout << (itr->first) << endl;
            else cout << (itr->first) << " ";
        }
    }
    
    return 0;
}
