#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // O(n^2) using sliding window

    // int t;cin>>t;
    // while(t--)
    // {
    // 	string s;cin>>s;
    // 	int n=s.length();
    // 	int ans=0;

    // 	for(int i=0;i<n;i++)
    // 	{
    // 		vector<bool> visited(256,0);
    // 		for(int j=i;j<n;j++)
    // 		{
    // 			if(visited[s[j]]==true)
    // 				break;
    // 			ans=max(ans,j-i+1);

    // 			visited[s[j]]=true;

    // 		}
    		
    // 		visited[s[i]]=false;
    // 	}


    // 	cout<<ans<<"\n";
    // }

    // O(n) using sliding window with optimization
    int t;cin>>t;
    while(t--)
    {
    	string s;cin>>s;
    	int n=s.length();
    	int ans=0;
    	vector<int> lastIndex(256,-1);
    	int i=0;
    	for(int j=0;j<n;i++)
    	{
    		i=max(lastIndex[s[j]]+1,i);

    		ans=max(ans,j-i+1);

    		lastIndex[s[j]]=j;
    	}

    	cout<<ans<<"\n";

    }



    
    return 0;
}