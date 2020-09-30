//find triplets with zero sum in an array



// basically sort the array and use two pointer approach for each i

bool findTriplets(int a[], int n)
{ 
    //Your code here
    sort(a,a+n);
    
    for(int i=0;i<n-1;i++)
    {
    
    int l=i+1;int r=n-1;
        
        while(l<r)
        {
            if(a[i]+a[l]+a[r]==0)
            return true;
            else if(a[i]+a[l]+a[r]<0)
            l++;
            else r--;
        }
        
    }
    
    return false;
    
    
}