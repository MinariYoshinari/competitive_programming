#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<set>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
 
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    if(n == k){
        cout  << endl;
        return 0;
    }
    set<int> ok;
    vector<string> s(n);
    rep(k){
        int tmp;
        cin >> tmp;
        ok.insert(tmp-1);
    }
    rep(n) cin >> s[i];
    string keyword = s[*(ok.begin())];
    int keylength = (int)keyword.length();

    for(int i: ok){
        int common_length = 0;
        while(common_length < min(keylength, (int)s[i].length())){
            if(keyword[common_length] == s[i][common_length]){
                common_length++;
            }else{
                break;
            }
        }
        keyword = keyword.substr(0, common_length);
        keylength = (int)keyword.length();
    }

    vector<int> ng_length;
    rep(n){
        if(ok.find(i) != ok.end()) continue;
        int common_length = 0;
        while(common_length < min(keylength, (int)s[i].length())){
            if(keyword[common_length] == s[i][common_length]){
                common_length++;
            }else{
                break;
            }
        }
        ng_length.push_back(common_length);
    }
    
    int anslength = *max_element(all(ng_length)) + 1;
    if(anslength <= keylength)
        cout << keyword.substr(0, anslength) << endl;
    else
        cout << -1 << endl;

    return 0;
}
