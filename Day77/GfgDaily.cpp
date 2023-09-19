    unsigned int getFirstSetBit(int n)
    {
        int i = 0;
        while(i<32){
            if(((1<<i)&n) != 0){
                return i+1;   
            }
            i++;
        }
        return 0;
    }