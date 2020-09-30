//longest palindromic substring

//O(n^2)
//the length can be even or odd we take centres accordingly and keep expanding while it is a palindrome(for each i)
#include <iostream>
using namespace std;

int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n=s.length();
	    int maxc=0;
	    int st=0;
	    for(int i=0;i<n;i++)
	    {
	        int c=1;
	        int p1=i-1;int p2=i+1;
	        while(p1>=0&&p2<n&&s[p1]==s[p2])
	        {c+=2;p1--;p2++;}
	        if(c>maxc) {st=p1+1;maxc=c;}
	        c=0;p1=i-1;p2=i;
	        while(p1>=0&&p2<n&&s[p1]==s[p2])
	        {c+=2;p1--;p2++;}
	        if(c>maxc) {st=p1+1;maxc=c;}
	        
	    }
	    
	    cout<<s.substr(st,maxc)<<"\n";
	    
	}
	return 0;
}