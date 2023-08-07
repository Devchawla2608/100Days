// Search a 2D Matrix
// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        if(size == 0){
            false;
        }
        if(size == 1){
             if ( std::find( matrix[0].begin(),  matrix[0].end(), target) !=                            matrix[0].end() )
                    return true;
                else{
                    return false;
                }
        }
        //cases size == 0
        //size == 1
        int start = 0;
        int end = size - 1;
        while(start<=end){
            int mid = (start + end)/2;
            int midStart = matrix[mid][0];
            int midEnd = matrix[mid][matrix[mid].size()-1];
            if(target < midStart){
                end = mid-1;
            }else if(target > midStart && target < midEnd){
                if ( std::find( matrix[mid].begin(),  matrix[mid].end(), target) !=                            matrix[mid].end() )
                    return true;
                else
                    return false;
            }else if(target == midStart || target == midEnd){
                return true;
                
            }else if(target > midEnd){
                start = mid+1;
            }
        }
        return false;
    }
};

Time Complexity: O(log(m * n))
Auxiliary Space: O(1)