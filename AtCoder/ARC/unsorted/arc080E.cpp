#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
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
#define MAX 100000
#define INF 2147483647
#define EPS 1e-9
#define DEBUG 0
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> Tiii;

struct segment{
    int w, start, end;
    bool operator <(const segment &s)const{return w > s.w;}
};

class SegmentTree{
    public:
        int n = 1;
        vector<int> v;
        map<int, int> idx;

        void init(int nn, int value){
            while(n < nn) n *= 2;
            v.assign(2 * n - 1, value);
        }

        void update(int index, int value, int i){
            idx[value] = i;
            index += n-1;
            v[index] = value;
            while(index > 0){
                index = (index-1) / 2;
                v[index] = min(v[2*index+1], v[2*index+2]);
            }
        }

        //[start, end) (※半開区間)の最小値
        //RMQ(0, n, 0, n, 0)
        int RMQ(int start, int end, int l, int r, int k){
            if(r <= start || end <= l) return INF;
            else if(start <= l && r <= end) return v[k];
            else return min(
                RMQ(start, end, l, (l+r)/2, 2*k+1), 
                RMQ(start, end, (l+r)/2, r, 2*k+2)
            );
        }
};

signed main(){
    int n, tmp;
    cin >> n;
    SegmentTree tree[2];
    tree[0].init(n/2, INF);
    tree[1].init(n/2, INF);
    rep(n){
        cin >> tmp;
        tree[i%2].update(i/2, tmp, i);
        rep(15){
            cout << tree[0].v[i] <<  " ";
        }
        cout << endl;
        rep(15){
            cout << tree[1].v[i] <<  " ";
        }
        cout << endl;
    }
    
    return 0;

    priority_queue<segment> que;
    que.push((segment){tree[0].RMQ(0, n/2, 0, n/2, 0), 0, n});
    while(!que.empty()){
        segment s = que.top(); que.pop();
        int n1 = s.w;
        //printf("\n(segment){%d, %d, %d}", s.w, s.start, s.end);
        //printf("\nn2: [%d, %d)", tree[s.start%2].idx[s.w], s.end);
        int n2 = tree[1-s.start%2].RMQ(tree[s.start%2].idx[s.w]/2 + (s.start%2), s.end/2, 0, n/2, 0);
        int i1 = tree[s.start%2].idx[n1];
        int i2 = tree[1-s.start%2].idx[n2];
        printf("%d %d ", n1, n2);
        if(s.start < i1){
            printf("\n[%d %d)", s.start, i1);
            que.push((segment){tree[s.start%2].RMQ(s.start/2, i1/2, 0, n/2, 0), s.start, i1});
        }
        if(i1+1 < i2){
            printf("\n[%d %d)", i1+1, i2);
            que.push((segment){tree[(i1+1)%2].RMQ((i1+1)/2, i2/2, 0, n/2, 0), i1+1, i2});
        }
        if(i2+1 < s.end){
            printf("\n[%d %d)", i2+1, s.end);
            printf("\n(segment){%d, %d, %d}", tree[(i2+1)%2].RMQ((i2+1)/2, s.end/2, 0, n/2, 0), i2+1, s.end);
            que.push((segment){tree[(i2+1)%2].RMQ((i2+1)/2, s.end/2, 0, n/2, 0), i2+1, s.end});
        }
        if(n2 == INF) break;
    }
}