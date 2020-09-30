
#include <iostream>
using namespace std;

// Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

// logic
// do a binary search two times(i.e. 1 for first and other for last occurence)
int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n,k;cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int s=0;int e=n-1;
	    int ans1=-1,ans2=-1;
	    while(s<=e)
	    {
	        int mid=(s+e)/2;
	        if(a[mid]==k)
	        {
	            ans1=mid;
	            e=mid-1;
	        }
	        else if(a[mid]<k)
	        s=mid+1;
	        else e=mid-1;
	    }
	    s=0;e=n-1;
	    while(s<=e)
	    {
	        int mid=(s+e)/2;
	        if(a[mid]==k)
	        {
	            ans2=mid;
	            s=mid+1;
	        }
	        else if(a[mid]<k)
	        s=mid+1;
	        else e=mid-1;
	    }
	    if(ans1==-1)
	    cout<<"-1\n";
	    else
	    cout<<ans1<<" "<<ans2<<"\n";
	}
	return 0;
}