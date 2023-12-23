 int countOccurence(int arr[], int n, int k) {
        long long int c=n/k,b=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto &it:mp){
            if(it.second>c){
                b++;
            }
        }
        return b;
    }