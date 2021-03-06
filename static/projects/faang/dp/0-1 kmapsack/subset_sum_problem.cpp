#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];
// int solve(int a[],int n,int sum)
// {	

// 	if(sum==0)
// 	return 1;

// 	if(n==0)
// 	return 0;
	
// 	if(dp[sum][n]!=-1)
// 	return dp[sum][n];
	
// 	if(a[n-1]<=sum)
// 	{
// 		if(solve(a,n-1,sum-a[n-1])||
// 		solve(a,n-1,sum))
// 		dp[sum][n]=1;
// 		else dp[sum][n]=0;

// 		return dp[sum][n];

// 	}
	
	
// 	else
// 	{
// 		if(solve(a,n-1,sum))
// 			dp[sum][n]=1;
// 		else dp[sum][n]=0;

// 		return dp[sum][n];
// 	}
// }	


bool solve(int a[],int n,int sum)
{
	bool ans[n+1][sum+1];

	for(int i=1;i<sum+1;i++)
		ans[0][i]=false;

	for(int i=0;i<n+1;i++)
		ans[i][0]=true;

	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(a[i-1]<=j)
			ans[i][j]=ans[i-1][j]||ans[i-1][j-a[i-1]];

			else
			ans[i][j]=ans[i-1][j];
		}
	}	

	if(ans[n][sum])
		return true;
	else return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
    	int n;cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    		cin>>a[i];

    	int sum;cin>>sum;

    	memset(dp,-1,sizeof(dp));
    	if(solve(a,n,sum))
    		cout<<"YES\n";
    	else cout<<"NO\n";

    	
    	
    	
    }
    return 0;
}