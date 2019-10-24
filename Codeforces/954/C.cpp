#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, height = 1000000000, width = 1;
    cin >> n;
    int a[n];
    cin >> a[0];
    rep(n-1){
        cin >> a[i+1];
        int diff = abs(a[i+1] - a[i]);
        if(diff != 1) width = diff;
    }
    if(width == 1){
        cout << "YES" << endl;
        cout << height << " " << width << endl;
        return 0;
    }

    int succeeded = (width?1:0);
    if(succeeded) rep(n-1){
        int x = a[i] % width, y = (a[i]+width-1)/width;
        if(x == 0) x = width;
        int xx = a[i+1] % width, yy = (a[i+1]+width-1)/width;
        if(xx == 0) xx = width;

        if(xx == x && yy == y){
            succeeded = 0;
            break;
        }
        if(x != 1 && width != 1 && xx == x-1 && yy == y) continue;
        else if(xx == x && y != 1 && yy == y-1) continue;
        else if(x != width && width != 1 && xx == x+1 && yy == y) continue;
        else if(xx == x && yy == y+1) continue;
        else{
            succeeded = 0;
            break;
        }
    }

    if(succeeded){
        cout << "YES" << endl;
        cout << height << " " << width << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
