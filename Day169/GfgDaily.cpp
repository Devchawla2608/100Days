        int findWinner(int n, int A[]){
        // code here
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans^=A[i];
        }
        if(ans==0) return 1;
        if(n%2==0) return 1;
        return 2;
    }