class Solution {
  public:
  int countDigit(int N, int d){
      int c=0;
      while(N>0){
          if(N%10==d) c++;
          N/=10;
      }
      return c;
  }
    int countX(int L, int R, int X) {
        int cnt=0;
        for(int i=L+1;i<R;i++){
            cnt+=countDigit(i,X);
        }
        return cnt;
    }