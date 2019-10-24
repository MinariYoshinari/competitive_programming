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
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define EPS 1e-9
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::priority_queue;
using std::stack;
using std::map;
using std::pair;
using std::string;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

struct Cake{
    int index,area,d,w;

    Cake(int index0, int area0, int d0, int w0){
        index = index0;
        area = area0;
        d = d0;
        w = w0;
    }
};

// 大きいものからpriority_queueで取れる
bool operator< (const Cake &cake1, const Cake &cake2){
    if(cake1.index != cake2.index)
        return cake1.index > cake2.index;
    else
        return cake1.area > cake2.area; 
};

int main(){
    int n,w,d,p,s;
    scanf("%d %d %d", &n, &w, &d);

    while(n + d + w != 0){
        priority_queue<Cake> que, tmp;
        que.push(Cake(0, d*w, d, w));

        rep(n){
            scanf("%d %d", &p, &s);

            repp(j, p-1){
                Cake c = que.top();
                // printf("Cake(%d %d %d %d)\n", c.index, c.area, c.w, c.d);
                tmp.push(c);
                que.pop();
            }
            Cake c = que.top(); que.pop();
            // printf("Cake(%d %d %d %d)\n", c.index, c.area, c.w, c.d);

            // 2つのピースに分けて，queに2つともぶっっこむ
            s %= (c.w + c.d);
            if(s < c.w){
                if(s != 0)   que.push(Cake(i+1, c.d*s, c.d, s));
                if(s != c.w) que.push(Cake(i+1, c.d*(c.w-s), c.d, c.w-s));
            }else{
                s -= c.w;
                if(s != 0)   que.push(Cake(i+1, s*c.w, s, c.w));
                if(s != c.d) que.push(Cake(i+1, (c.d-s)*c.w, (c.d-s), c.w));
            }

            while(!tmp.empty()){
                que.push(tmp.top());
                tmp.pop();
            }
        }
        
        vector<int> ans;
        while(!que.empty()){
            Cake c = que.top(); que.pop();
            ans.push_back(c.area);
        }
        sort(all(ans));
        rep((int)ans.size()-1) printf("%d ", ans[i]);
        printf("%d\n", ans.back());

        scanf("%d %d %d", &n, &w, &d);
    }
    return 0;
}
