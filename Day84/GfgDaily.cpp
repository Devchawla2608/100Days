    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> result;
        if(arr.size() == 0) return result;
        
        sort(arr.begin() ,  arr.end());
        
        for(int i = 0 ;i<arr.size() ; i++){
           for(int j = i+1 ;j<arr.size() ; j++){
                int sum = arr[i] + arr[j];
                int remain = k - sum;
                int f = j+1 ; 
                int b = arr.size()-1;
                while(f<b){
                    if((arr[f] + arr[b] ) == remain){
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[f]);
                        v.push_back(arr[b]);
                        result.push_back(v);
                        while(f<b && arr[f] == v[2]) f++;
                        while(f<b && arr[b] == v[3]) b--;
                    }
                    else if((arr[f] + arr[b] )< remain){
                        f++;
                    }else{
                        b--;
                    }
                }
                while(j<arr.size() && arr[j+1] == arr[j]) ++j;
            } 
             while(i<arr.size() && arr[i+1] == arr[i]) ++i;
        }
     return result;   
    }