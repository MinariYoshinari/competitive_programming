    #include<iostream>
    #include<algorithm>
    #include<cstdio>
    #include<cmath>
    #include<math.h>
    #include<string>
    #include<string.h>
    #include<stack>
    #include<queue>
    #include<vector>
    #include<utility>
    #include<set>
    #include<map>
    #include<stdlib.h>
    #include<iomanip>
     
    using namespace std;
     
    #define ll long long
    #define ld long double
    #define EPS 0.0000000001
    #define INF 1e9
    #define MOD 1000000007
    #define rep(i,n) for(i=0;i<n;i++)
    #define loop(i,a,n) for(i=a;i<n;i++)
    #define all(in) in.begin(),in.end()
    #define shosu(x) fixed<<setprecision(x)
    #define int ll
    typedef vector<int> vi;
    typedef pair<int,int> pii;
     
    signed main(void) {
      int i,j;
      int h,w;
      cin>>h>>w;
      if(h%3==0 || w%3==0)cout<<0<<endl;
      else{
        int ans=INF;
        if(h>w)swap(h,w);
        loop(i,1,w){
          vi a(3);
          a[0]=h*i;
          a[1]=(h/2)*(w-i);
          a[2]=h*w-a[0]-a[1];
          sort(all(a));
          ans=min(ans,a[2]-a[0]);
          a[0]=h*i;
          a[1]=((i+w)/2-i)*h;
          a[2]=h*w-a[0]-a[1];
          sort(all(a));
          ans=min(ans,a[2]-a[0]);
        }
        cout<<ans<<endl;
      }
    }
