int transitionPoint(int arr[], int n) {
        if(arr[0]==1)return 0;
        bool zero=0;
        bool one=0;
        for(int i=0;i<n;i++){
            if(zero==1&&one==1){
                return i-1;
                break;
            }
            if(arr[i]==0) zero=1;
            if(arr[i]==1) one=1;
        }
        return -1;
    }