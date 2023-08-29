class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long sum = 0;
        long long val = target/2;
        int i = 1;
        while(i<= n && i<=val){
            sum+= i;
            i++;
        }
        i--;
        n = n - i;
        i = target;
        while(n--) {sum += i; i++;}
        cout<<sum<<endl;
        return sum;
    }
};