class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        for(int i = 0 ;i< n ;i++){
            arr[arr[i]%n] += n;
        }
        vector<int> result;
        for(int i = 0 ;i< n;i++){
            if(arr[i]/n >1){
                result.push_back(i);
            }
        }
        for(int i = 0 ;i< n;i++){
            arr[i] = arr[i]%10;
        }
        if(result.size() == 0){
            result.push_back(-1);
            return result;
        }
        return result;
    }
};
