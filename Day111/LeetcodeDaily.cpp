class Solution {
public:
    bool isPowerOfFour(int n) {
        float a = (float) n;
        while (a >= 1) {
            if (a == 1) return true;
            a = a / 4;
        }
        return false;
    }
};