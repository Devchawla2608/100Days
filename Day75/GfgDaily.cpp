    vector<long long> printFibb(int n) 
    {
        vector<long long> ans;
        long long o = 1;
        long long w = 1;
        if(n == 1){
            ans.push_back(1);
            return ans;
        }
        if(n == 2){
            ans.push_back(1);
            ans.push_back(1);
            return ans;
        }
        ans.push_back(1);
        ans.push_back(1);
        for(int i = 3 ; i<= n ; i++){
            long long val = o + w;
            ans.push_back(val);
            o = w;
            w = val;
        }
        return ans;
    }