#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

int main(){
    ll N, K;
    cin >> N >> K;
    if(N == K){
        cout << "";
        return 0;
    }
    vector<ll> an(K);
    vector<string> av(K), sv(N-K);
    rep(K) cin >> an[i];
    int j = 0, k = 0;
    int min_length = 100000;
    rep(N){
        if(an[j] - 1 == i){
            cin >> av[j];
            if(min_length > (int)av[j].length()) min_length = (int)av[j].length();
            j++;
        }else{
            cin >> sv[k];
            k++;
        }
    }
    
    string ans = "-1";
    for(int i = min_length; i >= 0; i--){
        string tmp = av[0].substr(0, i);
        bool flag = true;
        repp(j, K){
            if(av[j].substr(0, i) != tmp){
                flag = false;
                break;
            }    
        }
        if(!flag) break;
        flag = true;
        repp(j, N-K){
            if((int)sv[j].length() >=i)  
				if(sv[j].substr(0,i) == tmp){
                	flag = false;
                	break;
            	}
        }
        if(flag){
            ans = tmp;
            break;
        }
    }
    
    cout << ans;
    return 0;
}
