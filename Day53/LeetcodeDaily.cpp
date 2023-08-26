class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i<=j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                int temp_i = i;
                int temp_j = j;
                i++;
                bool tell = true;
                while(i<=j){
                    if(s[i] == s[j]){
                        i++;
                        j--;
                    }else {tell = false ; break;}
                }
                if(tell == true) return true;
                i = temp_i;
                j = temp_j;
                j--;
                tell = true;
                while(i<=j){
                    if(s[i] == s[j]){
                        i++;
                        j--;
                    }else {tell = false ; break;}
                }
                if(tell == true) return true;
                return false;
            }  
        }
        return true;
    }
};