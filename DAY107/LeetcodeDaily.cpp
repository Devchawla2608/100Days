class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1;
        for(int i = 0;i<s.size() ; i++){
            if(s[i] == '#'){
                if(s1.size() != 0) s1.pop_back();
            }else{
                s1.push_back(s[i]);
            }
        }
        string s2;
        for(int i = 0;i<t.size() ; i++){
            if(t[i] == '#'){
                if(s2.size() != 0) s2.pop_back();
            }else{
                s2.push_back(t[i]);
            }
        }
        if(s1 == s2) return true;
        else return false;
    }
};