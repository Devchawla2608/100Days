class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int flag = 0, i = 0, j = 1;
        int ans = INT_MAX;
        if(n==1)return -1;
        while(j<n){
            if((a[i]==x && a[j]==y) || (a[i]==y && a[j]==x)){
                ans = min(ans, abs(i-j));
                i = j;
                j++;
                flag = 1;
            }
            else if((a[j]==x && a[i]!=y) || (a[j]==y && a[i]!=x)){
                i = j;
                j++;
            }
            else{
                j++;
            }
        }
        if(flag)return ans;
        return -1;
    }
};