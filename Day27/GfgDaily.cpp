bool isFrequencyUnique(int n, int arr[])
    {
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        unordered_set<int>st;
        for(auto it:mp){
            int x = it.second;
            if(st.count(x)>0) return false;
            st.insert(x);
            
        }
        return true;
    }