    void convertToWave(int n, vector<int>& arr){
        
        if(n == 1) return;
        int i = 0;
        int j = 2;
        while(j<n){
            swap(arr[i+1] , arr[i]);
            i = j;
            j = j + 2;
        }
        j = n-1;
        if(i>=j) return ;
        swap(arr[i] , arr[j]);
    }