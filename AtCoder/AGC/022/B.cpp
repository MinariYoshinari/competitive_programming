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

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, three, two, flag = 0;
    cin >> n;
    if(n == 19999){
        n++;
        flag = 1;
    }
    if(n == 3){
        cout << "2 5 63" << endl;
    }else if(n == 4){
        cout << "2 5 20 63" << endl;
    }else if(n == 6){
        cout << "2 3 6 9 10 30" << endl;
    }else{
        two = min(n/3*3, 15000);
        int rest = n-two;
        if(rest & 1){
            two -= 3;
            rest += 3;
        }
        three = rest/2*2;

        if(three == 0){
            two -= 6;
            three += 6;
        }
        while(3+6*(three-1) > 30000){
            three -= 6;
            two += 6;
        }

        reppp(i, 1, two+1){
            if(i == 3 && flag) continue;
            cout << 2*i << " ";
        }
        repp(i, three){
            cout << 3+6*i << " ";
        }
        cout << endl;
    }
    return 0;
}
