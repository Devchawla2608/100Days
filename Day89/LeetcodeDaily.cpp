class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        string ans;
        int i;
        for(i = 0 ; i<s.size() ; i++){
            if(s[i] == ' '){
                string temp = s.substr(j , i-j+1);
                reverse(temp.begin() , temp.end());
                ans += temp;
                j = i+1;
            }
        }
        ans += ' ';
        string temp = s.substr(j , i-j);
        reverse(temp.begin() , temp.end());
        ans += temp;
        return ans.substr(1);
    }
};