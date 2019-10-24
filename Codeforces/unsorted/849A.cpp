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
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

/*
signed main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    if(n % 2  == 0){
        cout << "No";
        return 0;
    }

    vector<int> a(n), odds;
    rep(n){
        cin >> a[i];
        if(a[i] % 2 == 0) odds.pb(i);
    }
    if(a[0] % 2 == 0 || a[n-1] % 2 == 0){
        cout << "No";
        return 0;        
    }

    cout << "Yes";
    return 0;
}
*/
signed main(){
    int n; cin >> n;
    int arr[n];
    rep(n) cin >> arr[i];
    vector<bool> odd(n, false), even(n,false);

    repp(i, n){
        if(arr[i]%2 == 1){
            for(int j=i;j>=0;j--){
                if(arr[j]%2 == 1){
                    if((i-j+1)%2 == 1){
                        if(j >= 0 && odd[j-1]){
                            even[i] = true;
                        }else{
                            odd[i] = true;
                        }
                    }
                }
            }
        }
    }

    if(odd[n-1]) cout << "Yes";
    else cout << "No";

}