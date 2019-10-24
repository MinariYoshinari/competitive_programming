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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    rep(k){
        cin >> a[i];
    }

    int four = n, two = 2*n;
    // 隙間無く埋める
    rep(k){
        while(four > 0 && a[i] >= 4){
            four--;
            a[i] -= 4;
        }
    }
    rep(k){
        while(two > 0 && a[i] >= 2){
            two--;
            a[i] -= 2;
        }
    }

    // i人組がcnt[i]組残ってる
    map<int, int> cnt;
    rep(k){
        cnt[a[i]]++;
    }

    // 4人席に3人座らせる
    // YESになりうる状況なら，この地点でもう4人以上の組は残ってないはず……
    rep(k){
        while(four > 0 && a[i] == 3){
            four--;
            a[i] -= 3;
            cnt[3]--;
        }
    }

    // 4人席に1+2人座らせる
    int three = min(cnt[2], cnt[1]);
    if(four >= three){
        four -= three;
    }else{
        three = four;
        four = 0;
    }
    three *= 2;
    rep(k){
        if(three > 0 && a[i] == 2){
            a[i] = 0;
            cnt[2]--;
        }else if(three > 0 && a[i] == 1){
            a[i] = 0;
            cnt[1]--;
        }else{
            continue;
        }
        three--;
    }

    // 4人席に1+2人座らせるが，1人は2人組を切り離した人
    three = (int)(cnt[2] / 3 * 2);
    if(four >= three){
        four -= three;
    }else{
        three = four;
        four = 0;
    }
    three = (three * 3 + 1) / 2;
    rep(k){
        if(three > 0 && a[i] == 2){
            a[i] = 0;
            cnt[2]--;
            three--;
        }
    }

    // 余った1〜2人組を余った席に座らせる
    rep(k){
        if(two > 0 && a[i] == 1){
            two--;
            a[i] = 0;
            cnt[1]--;
        }
        if(four >= 1 && a[i] == 2){
            four--;
            a[i] = 0;
            cnt[2]--;
        }
    }
    int tmp = 0;
    while(four > 0 && cnt[1] > 0){
        cnt[1] -= 2;
        four--;
        tmp += 2;
    }
    int flag = 1;
    rep(k){
        if(tmp > 0 && a[i] == 1){
            tmp--;
            a[i] = 0;
        }
        if(a[i] > 0) flag = 0;
    }


    if(flag){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}
