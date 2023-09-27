   vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int i = 0;
        int j = m-1;
        int sum = 1e9;
        int a = -1;
        int b = -1;
        while(i <n && j>=0){
            int val = abs((arr[i] + brr[j]) - x);
            // cout<<val<<" "<<sum<<endl;
            if(val < sum){
                sum = val;
                a = i;
                b = j;
            }
            if(arr[i] + brr[j] > x) j--;
            else i++;
        }
        vector<int> temp;
        if(a == -1 || b == -1) return temp;
        temp.push_back(arr[a]);
        temp.push_back(brr[b]);
        return temp;
    }