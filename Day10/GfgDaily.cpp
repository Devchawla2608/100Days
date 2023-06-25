// Unique rows in boolean matrix
// Unique rows in boolean matrix
// Given a binary matrix your task is to find all unique rows of the given matrix in the order of their appearance in the matrix.

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
       set<vector<int>>ds;
       vector<vector<int>>ans;
       for(int i=0;i<row;i++)
       {
           vector<int>temp;
           for(int j=0;j<col;j++)
           {
               temp.push_back(M[i][j]);
           }
           if(ds.find(temp)==ds.end())
           {
           ds.insert(temp);
           ans.push_back(temp);
           }
       }
       
       return ans;
    }