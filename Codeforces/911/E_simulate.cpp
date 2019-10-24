#include<cstdio>
#include<cstdlib>
#include<stack>
#include<vector>
#include<algorithm>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define Pii pair<int, int>
 
using namespace std;

int main(){
    int n, k, next = 1;
    scanf("%d %d", &n, &k);
    vector<int> v(k);
    stack<int> st;
    rep(k){
        scanf("%d", &v[i]);
        if(!st.empty() && st.top() < v[i]){
            printf("-1\n");
            return 0;
        }
        st.push(v[i]);
        while(!st.empty() && st.top() == next){
            next = st.top() + 1;
            st.pop();
        }
    }

    while(!st.empty()){
        int t = st.top();
        for(int i=t-1;i>=next;i--) v.push_back(i);
        next = t + 1;
        st.pop();
    }
    int i = n;
    while((int)v.size() < n) v.push_back(i--);
    rep(n) printf("%d ", v[i]);
}
