//Given a sorted array in which all elements appear twice (one after one) and one element appears only once. Find that element in O(log n) complexity.

//use binary search-find mid index if it is odd compare a[mid] and a[mid-1],if a[mid]==a[mid-1] search in the right side else in the left
//if it is even comapre a[mid] and a[mid+1] if(a[mid]==a[mid+1]) search in right side else in the left,the final starting index element is the answer
#include <iostream>
using namespace std;


void bin(int a[],int s,int e)
{
    
        
        if(s>e) return;
        
        if(s==e)
        {cout<<a[s]<<"\n";return;}
        int mid=(s+e)/2;
        if(mid%2==0)
        {
            if(a[mid]==a[mid+1])
            return bin(a,mid+2,e);
            else return bin(a,s,mid);   
        }
        else
        {
            if(a[mid]==a[mid-1])
            return bin(a,mid+1,e);
            else return bin(a,s,mid);
        }
    
}
int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    
	    for(int i=0;i<n;i++) cin>>a[i];
	    bin(a,0,n-1);
	    
	}
	return 0;
}