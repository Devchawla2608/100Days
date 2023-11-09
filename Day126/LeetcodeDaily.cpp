class Solution {
public:
<<<<<<< HEAD
int countHomogenous(string s) {
    long long ans = 1, count = 1, m = 1e9 + 7;
    for(int i = 1; i < s.size(); ++i){
        count = (s[i] == s[i-1])?count + 1: 1;
        ans = (ans + count)%m;
    }
    return ans;
}
};
=======
    int Chebyshev(int sx, int sy, int fx, int fy){
        return max(abs(sx-fx), abs(sy-fy) );
    }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d=Chebyshev(sx, sy, fx, fy);
        return d>0 ? t>=d: t!=1;
    }
};
>>>>>>> a102612de6d92551dd1ad050e2d80e855ca79a2b
