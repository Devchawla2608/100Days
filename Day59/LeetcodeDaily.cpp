class Solution {
public:

    int findOne(int num){
        int cnt = 0;
        while(num != 0){
            if(num%2 != 0) cnt++;
            num /= 2; 
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        vector<int> arr(n+1 , 0);
        for(int i = 0;i<=n ; i++){
            arr[i] = findOne(i);
        }
        return arr;
    }
};