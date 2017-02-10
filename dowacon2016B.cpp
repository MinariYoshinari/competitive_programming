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
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

signed main(){
	string s;
	cin >> s;

	string s1(s), s2(s);
	rep((int)s.size()){
		if(s[i] == '?'){
			if(i % 2 == 0){
				s1[i] = '2';
				s2[i] = '5';
			}else{
				s1[i] = '5';
				s2[i] = '2';
			}
		}
	}

	int count1 = 0, count2 = 0;
	int tmp1 = 0, tmp2 = 0;
	rep((int)s.size()){
		if(s1[i] == '2'){
			if(tmp1 % 2 == 0){
				tmp1++;
			}else{
				tmp1 = 1;
			}
		}else if(s1[i] == '5' && tmp1 % 2 == 1){
			tmp1++;
		}else{
			tmp1 = 0;
		}
		count1 = max(tmp1,count1);
		if(s2[i] == '2'){
			if(tmp2 % 2 == 0){
				tmp2++;
			}else{
				tmp2 = 1;
			}
		}else if(s2[i] == '5' && tmp2 % 2 == 1){
			tmp2++;
		}else{
			tmp2 = 0;
		}
		count2 = max(tmp2, count2);
	}

	cout << max(count1, count2) /2 *2;
}
