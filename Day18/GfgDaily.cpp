// Maximum Index
// Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].
int maxIndexDiff(int arr[], int n) {
        // code 
         int nums[]= new int [n];
        for(int i =0;i<n;i++){
            nums[i]=arr[i];
        }
        Arrays.sort(nums);
        int k =n-1;
        int maxi=0;
        int i=0;
        int j=n-1;
        while(i<j){
            int x = j-i;
            if(arr[i]<=arr[j]){
                maxi = Math.max(x,maxi);
                i++;
                j = n-1;
            }
            else if(arr[i]==nums[k]){
                k--;
                i++;
            }
            else{
                j--;
            }
        }
        
        return maxi;
    }