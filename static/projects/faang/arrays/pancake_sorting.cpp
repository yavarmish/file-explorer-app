//pancake sorting
//determine the minimum number of flips to sort the array(operation allowed-chowes a sub array from 0 to i and flip it)

//O(n^2)

//we simply bring the max element to it's correct position each time 




#include<bits/stdc++.h>
using namespace std;

int findmax(int a[],int n)
{
	int mi=0;
	for(int i=0;i<n;++i)
		if(a[i]>a[mi])
			mi=i;

		return mi;
}
void flip(int a[],int n)
{
	int i=0;int j=n;

	while(i<j)
	{
		int temp=a[j];
		a[j]=a[i];
		a[i]=temp;

		i++;j--;
	}
	
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];


    for(int i=n;i>1;--i)
    {
    	int mi=findmax(a,i);
    	// cout<<mi<<"\n";

    	// for(int i=0;i<n;i++)
    	// 	cout<<a[i]<<" ";
    	// cout<<"\n";
    	if(mi!=i-1)
    	{   		

    		// cout<<"chapra\n";
    		flip(a,mi);
    		flip(a,i-1);
    		// for(int i=0;i<n;i++)
    		// cout<<a[i]<<" ";
    		// cout<<"\n";
    	}

    }
   
    // cout<<"\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}