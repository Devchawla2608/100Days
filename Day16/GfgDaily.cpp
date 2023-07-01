    // Number of 1 Bits
    // Given a positive integer N, print count of set bits in it. 
    int setBits(int N) {
        int temp = N;
        int count = 0;
        while(temp!=0){
            if(temp&1 == 1) count++;
            temp = temp>>1;
        }
        return count;
    }