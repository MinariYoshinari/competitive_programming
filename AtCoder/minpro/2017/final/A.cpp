#include<iostream>
#include<string>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
 
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.length();
    int dp[n+1][5];
    fill(dp[0], dp[n+1], 1000000);

    dp[0][0] = 0;
    rep(n) dp[i+1][0] = i+1;
    rep(5) dp[0][i] = i;
    rep(n){
        repp(j, 10){
            if(
                (j%5 == 0 && s[i] == 'y')
                || (j%5 == 1 && s[i] == 'a')
                || (j%5 == 2 && s[i] == 'h')
                || (j%5 >= 3 && s[i] == 'o')
            ){
                dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i][j%5]);
            }else{
                dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i][j%5]+1);
            }
            dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i+1][j%5]+1);
            dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i][(j+1)%5]+1);
        }
        
    }

    cout << dp[n][0] << endl;
    return 0;
}

