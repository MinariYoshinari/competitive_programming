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
#define MOD 1000000007
#define MAX 100000
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

//int G[MAX][MAX];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;

    vector<int> ones;
    int count = 0;
    rep(n){
        if(s[i] == '1') count++;
        else{
            ones.push_back(count);
            count = 0;
        }
    }
    ones.push_back(count);

    int m = (int)ones.size();
    if(m == 1){
        cout << 0 << endl;
        return 0;
    }

    vector< vector<int> > dp(m, vector<int>(4, 0));
    if(ones[0] != 0 && ones[1] != 0){
        dp[1][0] = ones[0]; //左を使い切る(右を1つ使う)
        dp[1][1] = ones[1]; //右を使い切る(左を1つ使う)
        dp[1][2] = ones[1]-1; //右を1つ残す
        // dp[1][3] = 0; //使わない
    }

    reppp(i, 2, m-1){
        int max_ = *max_element(all(dp[i-1]));

        if(ones[i-1] == 0 || ones[i] == 0){
            repp(j, 4) dp[i][j] = max_;

        }else{

            dp[i][0] = max(dp[i-1][2]+1, dp[i-1][3]+ones[i-1]);
            if(ones[i-1] > 1)
                dp[i][0] = max(dp[i][0], dp[i-1][0]+ones[i-1]-1);

            dp[i][1] = max(dp[i-1][2], dp[i-1][3])+ones[i];
            if(ones[i-1] > 1)
                dp[i][1] = max(dp[i][1], dp[i-1][0] + ones[i]);

            if(ones[i] > 1)
                dp[i][2] = max(dp[i-1][2], dp[i-1][3])+ones[i]-1;
                if(ones[i-1] > 1)
                    dp[i][2] = max(dp[i][2], dp[i-1][0]+ones[i]-1);
            else
                dp[i][2] = max_;
                
            dp[i][3] = max_;
        }
        // repp(j, 4){
        //     cout << dp[i][j] << " ";
        // }
        // cout << endl;
    }
    
    cout << *max_element(all(dp[m-1])) << endl;

    return 0;
}
