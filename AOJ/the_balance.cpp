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
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

int a, b, d;

int calc(int i, int j, int mode){
    switch(mode){
        case 0:
            return a*i+b*j;
            break;
        case 1:
            return -a*i+b*j;
            break;
        case 2:
            return a*i-b*j;
            break;
    }
    return 0;
}

bool judge(int i, int j, int modeij, int x, int y, int modexy){
    if(modexy == -1) return true;
    int ij = calc(i, j, modeij);
    int xy = calc(x, y, modexy);
    return ij < xy;
}

signed main(){
    cin >> a >> b >> d;
    while(a+b+d != 0){
        int x = 500000, y = 500000, mode = -1;
        rep(50001){
            if((d-a*i) % b == 0){
                int j = (d-a*i) / b;
                if(j >= 0 && (i+j < x+y || (i+j == x+y && judge(i,j,0,x,y,mode)))){
                    x = i;
                    y = j;
                }
            }
            if((d+a*i) % b == 0){
                int j = (d+a*i) / b;
                if(j >= 0  && (i+j < x+y || (i+j == x+y && judge(i,j,1,x,y,mode)))){
                    x = i;
                    y = j;
                }
            }
            if((d-a*i) % (-b) == 0){
                int j = (d-a*i) / (-b);
                if(j >= 0 && (i+j < x+y || (i+j == x+y && judge(i,j,1,x,y,mode)))){
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d %d\n", x, y);
        cin >> a  >> b >> d;
    }
}