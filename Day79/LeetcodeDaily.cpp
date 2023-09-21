class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        int i = 0 ;
        int j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                num.push_back(nums1[i]);
                i++;
            }else{
                num.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            num.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            num.push_back(nums2[j]);
            j++;
        }
        if(num.size()%2 != 0){
            return num[(num.size())/2];
        }
        for(int i = 0 ;i<num.size() ; i++){
            cout<<num[i]<<" ";
        }
        cout<<endl;
        int n = num.size();
        double ans = (num[n/2] + num[(n/2)-1])*(1.0)/2;
        return ans;
    }
};