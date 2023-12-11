    long maximumSumSubarray(int k, vector<int> &arr , int N){
        if(arr.size() == 0 || k<=0 || k>arr.size()) return -1;
        long sum = 0;
        int i;
        for(i = 0 ; i<k ; i++){
            sum = sum + arr[i];
        }
        long max_sum = sum;
        int start = 0;
        for(int j = k; j<arr.size() ; j++){
            sum = sum + arr[j] - arr[start++];
            if(sum > max_sum) max_sum = sum;
        }
            return max_sum;
    }