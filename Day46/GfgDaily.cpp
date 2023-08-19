//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n == 0) return 0;
        int cnt = 0;
        while((1<<cnt) <=n){
            cnt++;
        }
        cnt--;
        int bit1 = cnt*(1<<(cnt-1));
        int bit2 = n - (1<<cnt) +1;
        int rest = n- (1<<cnt);
        return bit1 + bit2 + countSetBits(rest);
    }
};
