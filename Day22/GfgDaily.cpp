// Merge Without Extra Space
// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int gap = (n+m)/2 + (n+m)%2;
            while(gap != 0){
                int left = 0;
                int right = gap + left;
                while(right < n + m){
                    if(left<n && right <n){
                        if(arr1[left] > arr1[right]){
                            swap(arr1[left] , arr1[right]);
                        }
                    }else if(left<n && right>=n){
                        if(arr1[left] > arr2[right-n]){
                            swap(arr1[left] , arr2[right-n]);
                        }
                    }else if(left >=n && right >=n){
                        if(arr2[left-n] > arr2[right-n]){
                            swap(arr2[left-n] , arr2[right-n]);
                        }
                    }
                    left++;
                    right++;
                } 
                if(gap == 1) break;
                gap = gap/2 + (gap%2);
            }
        }