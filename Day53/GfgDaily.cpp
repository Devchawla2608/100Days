    string longestCommonPrefix (string arr[], int N)
    {
        sort(arr , arr + N);
        string s1 = arr[0];
        string s2 = arr[N-1];
        int i = 0 ;
        string temp;
        while(i<s1.size() && i<s2.size()){
            if(s1[i] == s2[i]) temp.push_back(s1[i]);
            else {
                if(temp.size() == 0) return "-1";
                return temp;
            }
            i++;
        }
        if(temp.size() == 0) return "-1";
        return temp;
    }