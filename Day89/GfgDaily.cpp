    vector<int> boundaryTraversal(vector<vector<int> > arr, int n, int m) 
    {
        vector<int> temp;
        
        if(n == 1){
            for(int i = 0 ;i<m ; i++){
                temp.push_back(arr[0][i]);
            }  
            return temp;
        }
        
        if(m == 1){
            for(int i = 0 ;i<n ; i++){
                temp.push_back(arr[i][m-1]);
            }
            return temp;
        }
        
        for(int i = 0 ;i<m-1 ; i++){
            temp.push_back(arr[0][i]);
        }
        for(int i = 0 ;i<n-1 ; i++){
            temp.push_back(arr[i][m-1]);
        }
            for(int i = m-1 ;i>=1 ; i--){
                temp.push_back(arr[n-1][i]);
            }
            for(int i = n-1 ;i>=1 ; i--){
                temp.push_back(arr[i][0]);
            }            

        return temp;
    }