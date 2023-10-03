    string colName (long long int n)
    {
        // your code here
        string temp;
        while(n>0){
            long long int rem = n%26;
            if(rem == 0){
                rem = 26;
                n -= 1;
            }
            n /= 26;
            temp += 'A'+rem-1;
        }
        reverse(temp.begin() , temp.end());
        return temp;
    }