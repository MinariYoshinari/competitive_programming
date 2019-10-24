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

#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios         ios_base::sync_with_stdio(false);  cin.tie(0);	cout.tie(0);
#define N  100005

using namespace std;

int main() {
	ios
	int n, k;
	cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=n-1; i>=0; i--) {
		if(k%a[i] == 0){
			cout<<k/a[i]<<endl;
			break;
		}
	}
	return 0;
}

