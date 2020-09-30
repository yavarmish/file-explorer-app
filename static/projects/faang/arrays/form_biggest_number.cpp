//form biggest bumber

//Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, 
// hence return the result in the form of a string.

//idea is to use custom comparator during sorting

//how to write custom comparator
//visualise the final array and assume data recieved in comparator is to be arranged in same order as of final array


#include <bits/stdc++.h>
using namespace std;


bool comp(string x,string y)
{
    string xy=x.append(y);
    string yx=y.append(x);
    
    if(xy>yx) return 1;else return 0;
}
int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    string s[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>s[i];
	    
	    sort(s,s+n,comp);
	    
	    for(int i=0;i<n;i++)
	    cout<<s[i];
	    
	    cout<<"\n";
	    
	}
	
	return 0;
}