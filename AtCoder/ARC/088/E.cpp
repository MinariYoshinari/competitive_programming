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
#define EPS 1e-9
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

int N;
int bit[1000001];

void clear(){
    rep(N+1) bit[i] = 0;
}

void update(int index, int value){
    for(int i=index; i <= N; i += i & -i){
        bit[i] += value;
    }
}

//sum bit[1]~bit[back_index]
int calc_sum(int back_index){
    int sum = 0;
    for(int i=back_index; i >= 1; i -= i & -i){
        sum += bit[i];
    }
    return sum;
}

// count swaps
ll calc_swap(vector<int> v){
    ll ret = 0;
    reppp(i, 1, N){
        update(v[i], 1);
        ret += (ll)(i - calc_sum(v[i]));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll ans = 0;
    string s;
    cin >> s;
    N = (int)s.length();
    map<char, int> mp;
    rep(N) mp[s[i]]++;

    int odd = 0;
    for(auto itr=mp.begin();itr!=mp.end();++itr){
        if(itr->second % 2){
            odd++;
            if(odd > 1){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    // 左右に分けるのに必要な交換回数
    vector<int> index(N+1);
    map<char, int> mp_dec(mp);
    int front_idx = 1, back_idx = (N+1)/2 + 1;
    int center_idx = (N+1)/2;
    rep(N){
        if(mp[s[i]] % 2  == 1 && (mp[s[i]]+1)/2 == mp_dec[s[i]]){
            index[i+1] = center_idx;
        }else{
            if(mp_dec[s[i]] > mp[s[i]]/2){
                index[i+1] = front_idx;
                front_idx++;
            }else{
                index[i+1] = back_idx;
                back_idx++;
            }
        }
        mp_dec[s[i]]--;
    }
    ans += calc_swap(index);
    clear();
    // cout << ans << endl;
    vector<char> ss(N+1);
    rep(N) ss[index[i+1]] = s[i];

    // 右半分を並べ替えるのに必要な交換回数
    map<char, vector<int>> mp_right_idx;
    for(int i=center_idx-((N%2==1)?1:0);i>=1;i--){
        mp_right_idx[ss[i]].push_back(center_idx-((N%2==1)?1:0) + 1 - i);
    }
    vector<int> right_idx(N/2+1);
    reppp(i, (N+1)/2+1, N){
        right_idx[i - (N+1)/2] = mp_right_idx[ss[i]][0];
        mp_right_idx[ss[i]].erase(mp_right_idx[ss[i]].begin());
    }
    N = N/2;
    ans += calc_swap(right_idx);
    cout << ans << endl;
}
