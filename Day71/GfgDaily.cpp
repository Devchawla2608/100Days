// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
         if(S==0 && N!=1){
            return "-1";
        }
        string ans="";
       
        for(int i=0;i<N;i++){
            if(S>=9){
                ans.append("9");
                S-=9;
            }
            else{
                ans+=to_string(S);
                S=0;
            }
        }
        if(S>0)
        return "-1";
        return ans;
    }
};