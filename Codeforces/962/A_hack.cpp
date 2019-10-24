#include <bits/stdc++.h>
using namespace std;

int main() 
{
	// your code goes here
	
	double n, a[1000000], i;
	double s=0, temp=0;
	a[0]=0;
	cin>>n;
	
	for(int i=1; i<=n; i++)
	
	{	cin>>a[i];
		s+=a[i];
		a[i]=a[i]+a[i-1];
		
	}
    debug(s/2);
	for(int i=0; ;i++)
	{
		if(a[i]>=s/2)
			{
				cout<<i<<endl;
				break;
			}
	}

	return 0;
}