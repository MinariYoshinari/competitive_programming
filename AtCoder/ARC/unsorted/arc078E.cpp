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
#include<sstream>

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
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

ll N = 1;
int q = 0;

string lltos(ll n) {
    ostringstream s;
    s << n;
    return s.str();
}

string response(ll n){
    bool a = (n <= N);
    bool b = (lltos(n) <= lltos(N));
    return !(a^b) ? "Y" : "N";
}

string query(ll n){
    q++;
    printf("? %lld\n", n);
    fflush(stdout);
    string ret;
    //ret = response(n);
    cin >> ret;
    return ret;
}

void answer(ll n){
    printf("! %lld\n", n);
}

signed main(){
    ll digit_num = 0, min_digit = 0, max_digit = 11;
    while(min_digit < max_digit){
        digit_num = (min_digit + max_digit) / 2;
        if(query(pow(10, digit_num)) == "Y"){
            min_digit = digit_num + 1;
        }else{
            max_digit = digit_num;
        }
    }
    digit_num = min_digit;
    if(digit_num == 11){
        reppp(i, 1, 9){
            if(query(pow(10,i)-1) == "Y"){
                answer(pow(10, i-1));
                return 0;
            }
        }
    }
    ll ans = 0;
    for(int i=digit_num-1;i>=1;i--){
        ll mid = 0, min_num = 0, max_num = 9;
        while(min_num < max_num){
            mid = (min_num + max_num) / 2;
            if(query(ans*10+mid) == "Y"){
                if(min_num == mid){
                    if(query(ans*10+min_num+1) == "N"){
                        break;
                    }else{
                        min_num++;
                    }
                }else{
                    min_num = mid;
                }
            }else{
                max_num = mid - 1;
            }
        }
        mid = min_num;
        if(mid == 9 && ans != 0 && query(ans*10-1) == "N"){
            answer(ans*10);
            return 0;
        }
        ans = ans*10+mid;
    }

    ll mid = 0, min_num = 0, max_num = 9;
    while(mid != (min_num + max_num) / 2){
        mid = (min_num + max_num) / 2;
        if(query((ans*10+mid)*10) == "N"){
            min_num = mid + 1;
        }else{
            max_num = mid;
        }
    }
    mid = min_num;
    if(mid == 9 && ans != 0 && query(ans*10-1) == "N"){
        answer(ans*10);
        return 0;
    }
    ans = ans*10+mid;
    
    if(ans > 1000000000){
        answer(1);
    }else{
        answer(ans);
    }
    return 0;
}
