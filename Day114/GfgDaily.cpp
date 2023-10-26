    int minOperation(int n)
    {
        int cnt = 1;
        while(n>1){
            if(n%2 != 0){
                cnt++;
                n--;
            }else{
                n/=2;
                cnt++;
            }
        }
        return cnt;
    }