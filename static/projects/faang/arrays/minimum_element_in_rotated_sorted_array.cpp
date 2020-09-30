//A sorted array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.
//example-[1,2,3,4,5] changes to [3,4,5,1,2]

//we will look in the left if a[0]<a[mid] else we will look in the right
//we will check if mid element or next to mid is the answer at each step
//sorted array is a boundary case


#include <iostream>
using namespace std;

int find_min(int a[],int s,int e)
{
    
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]>a[mid+1]) return a[mid+1];
        if(a[mid-1]>a[mid]) return a[mid];
        if(a[0]<a[mid]) s=mid+1;
        else e=mid-1;
        
        
    }
    
    return a[s];
}

int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    int k=find_min(a,0,n-1);
	    if(a[0]<a[n-1])
	    cout<<a[0]<<"\n";
	    else
	    cout<<k<<"\n";
	}
	return 0;
}