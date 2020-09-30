#include <bits/stdc++.h>
using namespace std;

// Given an array of size N consisting of only 0's and 1's ,
// which is sorted in such a manner that all the 1's are placed first and then they are followed by all the 0's. You have to find  the count of all the 0's.


// logic
// use modified binary search to find the first zero in ther array,number of zeroes=n-index_of_first_zero 
int find_last_one(int a[],int n,int s,int e)
{
    if(s>e) {return s;}
    int mid=(s+e)/2;
    if(a[mid]==1) {s=mid+1;return find_last_one(a,n,s,e);}
    else if(a[mid]==0){e=mid-1;return find_last_one(a,n,s,e);}
    
    
    
}
int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    
	    int k=find_last_one(a,n,0,n-1);
	   
	    cout<<n-k<<"\n";
	}
	return 0;
}