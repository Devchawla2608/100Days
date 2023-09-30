void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> v; 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1){
                    v.push_back({i, j});
                }
            }
        }
        
        for(int i=0; i<v.size(); i++){
            int row = v[i].first;
            int col = v[i].second;
            for(int j=0; j<m; j++){
                matrix[row][j] = 1;
            }
            for(int k=0; k<n; k++){
                matrix[k][col] = 1;
            }
        }
    }