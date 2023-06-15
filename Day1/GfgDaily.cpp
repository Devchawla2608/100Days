// Longest Palindrome in a String

// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S. In case of conflict, return the substring which occurs first ( with the least starting index).

string longestPalin (string s) {
         if(s.size() == 0 || s.size() == 1) return s;
         int n = s.size();
         int ans = 0;
         string result = s.substr(0 , 1);
            for(int i = 0;i<s.size() -1 ; i++){
                if(s[i] == s[i+1]){
                    int io = i;
                    int jo = i+1;
                    int len = 0;
                    while(io >= 0 && jo<n){
                        if(s[io] == s[jo]) len = len + 2;
                        else break;
                        io--;
                        jo++;
                    }
                    if(ans < len){
                        string temp = s.substr(io+1 , jo -io -1);
                        result = temp;
                        ans = len;
                    }
                }
            }
            for(int i = 1;i<s.size()-1 ; i++){
                if(s[i-1] == s[i+1]){
                    int io = i-1;
                    int jo = i+1;
                    int len = 1;
                    while(io >= 0 && jo<n){
                        if(s[io] == s[jo]) len = len + 2;
                        else break;
                        io--;
                        jo++;
                    }
                    if(ans < len){
                        string temp = s.substr(io+1 , jo -io -1);
                        result = temp;
                        ans = len;
                    }
                }
            }
         return result;
    }