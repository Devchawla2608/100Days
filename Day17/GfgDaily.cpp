// Copy Set Bits in Range
//    Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 31. You have to copy the set bits of 'Y' in the range L to R in 'X'. Return this modified X.Note: Range count will be from Right to Left & start from 1.


    int setSetBit(int x, int y, int l, int r){
        for(int i=l;i<=r;i++){
        if((y&(1<<(i-1)))!=0)
        x=x|(1<<(i-1));
    }
    return x;
    }