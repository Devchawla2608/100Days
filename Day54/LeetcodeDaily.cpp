class Solution {
public:

    void f(int index , int dot , string s , string &temp , vector<string> &ans){
        if(index<0 && dot == 0){
            string x = temp.substr(0 , temp.size()-1);
            ans.push_back(x);
            return;
        }else if(index<0 && dot == 0) return ;
        if(dot == 0) return;

        for(int i = index ; i>=0 ; i--){
            string str = s.substr(i , index-i+1)
            ;
            if(str.size() != 1 && str[0] == '0') continue;
            int val = stoi(str);
            if(val >=0 && val <= 255){
                temp = str + "." +temp;
                f(i-1 , dot-1 , s , temp , ans);
                temp.replace(0 , str.size()+1 , "");
            }else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp;
        vector<vector<int>> dp(s.size() , vector<int>(5 , -1));
        f(s.size() -1 , 4 , s , temp , ans );
        return ans;
    }
};