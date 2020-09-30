#include <iostream>
using namespace std;
//A number is called happy if it leads to 1 after a sequence of steps wherein each step number is replaced by the sum of squares of its
// digit that is if we start with Happy Number and keep replacing it with digits square sum, we reach 1. 


// logic
// basically we have to detect loop(similar to detecting loop in linked list) if value is repeated and is not equal to one it can't be a happy number
// we can use set to detect if value is repeated but for O(1) space we use floyd cycle detection algo
// we use two pointers slow and fast slow moves one at a time and fast two at a time if they meet then loop will be present

int next_square(int n)
{
    int ans=0;
    while(n!=0)
    {
        ans+=(n%10)*(n%10);
        n/=10;
    }
    return ans;
}
int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int slow=next_square(n);
	    int fast=next_square(next_square(n));
	    bool ans;
	    while(1)
	    {
	        if(slow==1||fast==1)
	        {ans=true;break;}
	        if(slow==fast)
	        {ans=false;break;}
	        
	       // cout<<slow<<" "<<fast<<"\n";
	        
	        slow=next_square(slow);
	        fast=next_square(next_square(fast));
	        
	    }
	    ans?cout<<"1\n":cout<<"0\n";
	}
	return 0;
}