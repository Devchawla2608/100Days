    int setBits(int N) {
        int cnt = 0;
        while(N != 0){
            N = N&(N-1);
            cnt++;
        }
        return cnt;
    }