#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int main(){
    int q,a,b,c,d;
    // scanf("%d", &q);
    cin >> q;
    for(int i=0;i<q;i++){
        // scanf("%d %d %d %d", &a, &b, &c, &d);
        cin >> a >> b >> c >> d;
        int n = a+b, aa, bb, l = max((a+b) / (b+1), (b+a) / (a+1));

        int ok = 0, ng = a+b+1;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            aa = a - mid/(l+1)*l - mid%(l+1);
            bb = b - mid/(l+1);
            
            if((long long)bb < (long long)(aa+1)*(long long)l){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        string ans = "";
        /*
        if(c <= ok){
            for(int j=c-1;j<min(d,ok);j++){
                // putchar((j % (l+1) == l)?'B':'A');
                ans += (j % (l+1) == l)?'B':'A';
            }
        }
        if(ng <= d){
            for(int j=max(ok,c-1);j<min(n,d);j++){
                // putchar(((n-j) % (l+1) == 0)?'A':'B');
                ans += ((n-j) % (l+1) == 0)?'A':'B';
            }
        }
        */

        for(int j=0;j<min(ok);j++){
            // putchar((j % (l+1) == l)?'B':'A');
            ans += (j % (l+1) == l)?'B':'A';
        }
        for(int j=ok;j<n;j++){
            // putchar(((n-j) % (l+1) == 0)?'A':'B');
            ans += ((n-j) % (l+1) == 0)?'A':'B';
        }
        cout << ans.substr(c-1, d-c+1) << endl;
        // puts("");
    }
}
