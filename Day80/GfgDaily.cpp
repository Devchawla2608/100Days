    
    int f(int arr[] , int n , int start , int end , int x , int tog){
        if(start == end){
            if(arr[start] == x) return start;
            return -1;
        }
        int mid;
        int ans = -1;
        while(start<=end){
            mid = (start+end)/2;
            if(arr[mid] > x){
                end = mid-1;
            }else if(arr[mid]<x){
                start = mid+1;
            }else{
                ans = mid;
                if(tog == -1){
                    end = mid+tog;
                }else{
                    start = mid+tog;
                }
            }
        }
        return ans;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> temp;
        int i = 0;
        int j = n-1;
        int mid = (i+j)/2;
        while(i<=j){
            mid = (i+j)/2;
            if(arr[mid] == x){
                break;
            }else if(arr[mid] < x){
                i = mid + 1;
            }else{
                j = mid-1;
            }
        }
        if(i>j){
            temp.push_back(-1);
            temp.push_back(-1);
            return temp;
        }
        int lower = f(arr , n , 0 , mid , x , -1);
        int upper = f(arr , n , mid , n-1 , x , 1);
        temp.push_back(lower);
        temp.push_back(upper);
        return temp;
    }