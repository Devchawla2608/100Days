    
// Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].
// NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.

void arrange(long long arr[], int n) {
        int input[1000000];
       for(int i = 0;i< n;i++){
           input[i] = arr[arr[i]];
       }
        for(int i = 0;i< n;i++){
            arr[i] = input[i];
        }
    }