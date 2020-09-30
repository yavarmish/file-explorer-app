#include<bits/stdc++.h>
using namespace std;
// distribute candies
//Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  
// All the children sit in a line and each of them has a rating score according to his or her performance in the class.  
// Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. 
// Alice wants to minimize the total number of candies she must buy. 

// logic
// traverse the array from left to right and assign candies as cur=prev+1 if ratings are in ascending order or cur=1 if ratings are equal
// then traverse from right to left and do the same but assigning cur ans max(cur,prev+1)


long candies(int n, vector<int> a) {
    vector<int> v(n,1);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<=a[i+1])
        {
            if(a[i]==a[i+1])
            v[i+1]=1;
            else 
            v[i+1]=v[i]+1;
            
        }
    }

    for(int i=n-1;i>0;i--)
    {
        if(a[i]<a[i-1])
        v[i-1]=max(v[i-1],v[i]+1);
    }
    long ans=0;

    for(auto i:v)
    cout<<i<<" ";
    cout<<"\n";
    for(auto i:v)
    ans+=i;
    return ans;
}