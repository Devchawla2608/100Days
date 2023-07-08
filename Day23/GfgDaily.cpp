// Find triplets with zero sum
// Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 
bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr+n);
          for(int i=0;i<n;i++)
          {
              int s=i+1;
              int e=n-1;
            while(s<e)
            {
            int sum=arr[i]+arr[s]+arr[e];
            
            if(sum==0)
              return true;
            else if(sum>0)
                    e--;
                  else 
                    s++; 
            }
          } 
          return false;
    }