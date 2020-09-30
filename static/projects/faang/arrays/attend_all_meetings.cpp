//attend all meetings
//we are given start time and end time of several meetings,we have 2 sub problems
//1.determine if it's possible to attend all meetings
//2.find number of meeting rooms such that it is possible to conduct all meetings

//for 1. we simply sort the array according to starting time and check a[i].end<=a[i+1].start for all i
//for 2. we create a map(not unordered because we need it to be sorted) and increment the count at evry start time and decrement it at evry end time the max count 
//is max number of meetings going on at a particular time and hence our answer(notice that it is similar to minimum numbers of platforms problem)



#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        pair<int,int> a[n];
        
        for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
            
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[a[i].first]++;
            m[a[i].second]--;
            
        }
        int cnt=0;
        int ans=0;
        // for(auto i:m)
        // cout<<i.first<<" "<<i.second<<"\n";
        
        for(auto i:m)
        {
            cnt+=i.second;
            ans=max(cnt,ans);
        }
        cout<<ans<<"\n";
        
        
    }
    return 0;
}