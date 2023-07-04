    // Count the subarrays having product less than k
    // Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=1;
        for(int i=0; i<n;i++){
            int j=i;
            long long mul=a[i];
            while(j<n and mul < k){
                j++;
                ans++;
                mul = mul*a[j];
            }
            j=i+1;
        }
        return ans-1;
    }