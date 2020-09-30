#include<bits/stdc++.h>
using namespace std;
//  ma(time->O(n) space O(n))
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 		int t;cin>>t;
// 		while(t--)
// 		{
// 		unordered_map<int,int> m;
// 		int n;cin>>n;
// 		int a[n];
// 		bool ok=false;
// 		int j=0;
// 		for(int i=0;i<n;i++)
// 		{
// 		cin>>a[i];
// 		m[a[i]]++;
// 		if(m[a[i]]>n/2)
// 		{ok=true;j=i;}
// 		}
// 		if(!ok)
// 		cout<<-1<<"\n";
// 		else cout<<a[j]<<"\n";
// 		}	

// 		return 0;
// }

//optimal(time->O(n) space->O(1))

//  int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 		int t;cin>>t;
// 		while(t--)
// 		{
// 			int n;cin>>n;
// 			int a[n];
// 			for(int i=0;i<n;i++) cin>>a[i];
// 			int count=1;int maj_index=0;
// 			for(int i=1;i<n;i++)
// 			{
// 				if(a[i]==a[maj_index])
// 				count++;
// 				else count--;
// 				if(count==0)
// 				{
// 					maj_index=i;
// 					count=1;
// 				}
// 			}
// 			int ans=0;
// 			for(int i=0;i<n;i++)
// 			{
// 				if(a[i]==a[maj_index])
// 				ans++;
// 			}
// 			if(ans>n/2)
// 			cout<<a[maj_index]<<"\n";
// 			else cout<<"-1\n";
// 		}	

// 		return 0;
// }

