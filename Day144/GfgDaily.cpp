LINK-->https://www.geeksforgeeks.org/problems/print-pattern3549/1



Code--->class Solution{
private:
    vector<int> plus(vector<int> &ans, int &N,int a){
        if(N==a){
            ans.push_back(N);
            return ans;
        }
        ans.push_back(N);
        N += 5;
        return plus(ans,N,a);
    }
    vector<int> minus(vector<int> &ans, int &N,int a){
        if(N<=0){
            return plus(ans,N,a);
        }
        ans.push_back(N);
        N -= 5;
        return minus(ans,N,a);
    }
public:
    vector<int> pattern(int N){
        // code here
        vector<int> ans;
        
        
        int a =N;
        return minus(ans,N,a);
    }
};
