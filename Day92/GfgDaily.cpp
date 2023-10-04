class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char , int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int num = 0;
        int i;
        for(i = 0 ;i<s.size()-1 ; i++){
            if(mp[s[i+1]] > mp[s[i]]){
                int val = mp[s[i+1]] - mp[s[i]];
                num += val;
                i++;
            }else{
                num = num + mp[s[i]];
            }
        }
        if(i==s.size()-1) num += mp[s[s.size()-1]];
        return num;
    }
};