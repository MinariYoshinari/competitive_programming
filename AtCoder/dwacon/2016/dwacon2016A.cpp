

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
     
    signed main(){
        int k;
        string s;
        cin >> k >> s;
        int n = (int)s.length();
        vector< vector< vector<Pll> > > dp(n, vector< vector<Pll> >(n, vector<Pll>(n+1, Pll(2LL*INF,-2LL*INF))));
        //長さ1
        rep(n){
            int m = (int)(s[i] - '0');
            if(0 <= m && m <= 9){
                dp[i][i][0] = Pll(m, m);
            }
            dp[i][i][1] = Pll(1, 9);
        }
        /*
        長さ3〜
        d: 区間の長さ
        l: 左の項の左のidx
        r: 右の項の左のidx
        c: 左右+演算子合わせての書き換え数
        数字→演算子の書き換えに対応していない
        */
        vector<ll> v;
        for(int d=3; d<=n; d+=1){
            repp(l, n-d+1){
                reppp(r, l+1, l+d-2){
                    repp(c, min(d,k)+1){
                        ll tmpmax = -2LL*INF, tmpmin = 2LL*INF;
                        repp(cl, min(c,r-l)+1){
                            if(cl < 0) continue;
                            Pll p = dp[l][r-1][cl], q = dp[r][l+d-2][c-cl];
                            Pll qq=dp[r][l+d-2][c-cl-1>=0?c-cl-1:0];
                            if(s[l+d-1] == '+'){
                                if(abs(p.first) < INF){
                                    if(abs(q.first) < INF) v.pb(p.first + q.first);
                                    if(c-cl-1 >= 0 && abs(qq.second) < INF) v.pb(p.first - qq.second);
                                }
                                if(abs(p.second) < INF){
                                    if(abs(q.second) < INF) v.pb(p.second + q.second);
                                    if(c-cl-1 >= 0 && abs(qq.first) < INF) v.pb(p.second - qq.first);
                                }
                            }else if(s[l+d-1] == '-'){
                                if(abs(p.first) < INF){
                                    if(abs(q.second) < INF) v.pb(p.first - q.second);
                                    if(c-cl-1 >= 0 && abs(qq.first) < INF) v.pb(p.first + qq.first);
                                }
                                if(abs(p.second) < INF){
                                    if(abs(q.first) < INF) v.pb(p.second - q.first);
                                    if(c-cl-1 >= 0 && abs(qq.second) < INF) v.pb(p.second + qq.second);
                                }
                            }else if(c-cl-1 >= 0){
                                if(abs(p.first) < INF){
                                    if(abs(qq.first) < INF) v.pb(p.first + qq.first);
                                    if(abs(qq.second) < INF) v.pb(p.first - qq.second);
                                }
                                if(abs(p.second) < INF){
                                    if(abs(qq.first) < INF) v.pb(p.second - qq.first);
                                    if(abs(qq.second) < INF) v.pb(p.second + qq.second);
                                }
                            }
                        }
                        if((int)v.size() > 0){
                            tmpmin = *min_element(all(v));
                            tmpmax = *max_element(all(v));
                        }
                        tmpmin = max(tmpmin, dp[l][l+d-1][c].first);
                        tmpmax = max(tmpmax, dp[l][l+d-1][c].second);
                        dp[l][l+d-1][c] = Pll(tmpmin, tmpmax);
                        //printf("dp[%d][%d][%d] = %lld\n", l, l+d-1, c, dp[l][l+d-1][c].second);
                        v.clear();
                    }
                }
            }
        }
     
        ll ans = -INF;
        repp(c, k+1){
            ll tmpmax = dp[0][n-1][c].second;
            //printf("%d %d %d\n", 0, n-1, c);
            if(tmpmax >= INF) continue;
            ans = max(ans, tmpmax);
        }
        if(ans != -INF){
            cout << "OK" << endl;
            cout << ans << endl;
        }else{
            cout << "NG" << endl;
        }
        return 0;
    }