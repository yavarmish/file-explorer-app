// move zeroes to the end of array
// use O(1) space
#include <iostream>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    int count=0;
	    for(int i=0;i<n;i++)
	    if(a[i]!=0)
	    a[count++]=a[i];
	    
	    while(count<n)
	    a[count++]=0;
	    
	    for(int i=0;i<n;i++)
	    cout<<a[i]<<" ";
	    
	    
	    cout<<"\n";
	    
	}
	return 0;
}