class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int left = 0 , right = 0 , blank = 0;
        for(auto it : s){
            if(it == 'L') left++;
            else if(it == 'R') right++;
            else blank++;
        }
        return abs(right-left) + blank;
    }
};