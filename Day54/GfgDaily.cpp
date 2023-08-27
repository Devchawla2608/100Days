    string secFrequent (string arr[], int n)
    {
        unordered_map<string , int> mp;
        for(int i = 0; i <n ; i++){
            mp[arr[i]]++;
        }
        int mx = 0;
        int smx = -1;
        string mxString;
        string smxString;
        for(auto it : mp){
            if(it.second > mx){
                smx = mx;
                smxString = mxString;
                mx = it.second;
                mxString = it.first;
            }else if(it.second > smx && it.second < mx){
                smx = it.second;
                smxString = it.first;
            }
        }
        return smxString;
    }