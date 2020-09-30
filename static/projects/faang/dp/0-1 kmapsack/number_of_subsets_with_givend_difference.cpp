#include<bits/stdc++.h>
using namespace std;

int count(int a[],int n,int sum)
{
	int dp[n+1][sum+1];

	for(int i=1;i<sum+1;i++)
		dp[0][i]=0;

	for(int i=0;i<n+1;i++)
		dp[i][0]=1;

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++){

			if(a[i-1]<=j)
			dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];

			else dp[i][j]=dp[i-1][j];
			

		}
	}
	return dp[n][sum];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
		 int n;cin>>n;
		 int a[n];
		 int range=0;
		 for(int i=0;i<n;i++)
		 	{cin>>a[i];range+=a[i];}

		 int dif;cin>>dif;
		 int sum=0;
		 
		 if((dif+range)%2==0)
		 	{
		 		
		 		sum=(dif+range)/2;
		 		cout<<count(a,n,sum);
		 	}

		 else
		 cout<<0;
		 
		 
    	
    		
    	
    
    return 0;
}