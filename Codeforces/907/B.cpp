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

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
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

int main(){
    vector<string> field(9);
    rep(9){
        string a,b,c;
        cin >> a >> b >> c;
        field[i] = a+b+c;
    }
    int x,y;
    cin >> y >> x;

    int field_y = (y-1) % 3;
    int field_x = (x-1) % 3;
    int flag = 0;
    rep(3){
        repp(j,3){
            if(field[field_y*3+i][field_x*3+j] == '.'){
                flag = 1;
                field[field_y*3+i][field_x*3+j] = '!';
            }
        }
    }
    if(!flag){
        rep(9){
            repp(j,9){
                if(field[i][j] == '.') field[i][j] = '!';
            }
        }
    }

    rep(9){
        repp(j,9){
            cout << field[i][j];
            if(j % 3 == 2) cout << ' ';
        }
        cout << endl;
        if(i % 3 == 2) cout << endl;
    }

}
