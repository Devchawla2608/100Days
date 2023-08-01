    int evaluatePostfix(string s)
    {
        stack<int> st;
        for(int i = 0;i<s.size() ; i++){
            if(isdigit(s[i])){
                st.push(s[i] - '0');
                continue;
            } 
            if(st.size() <=1) return 1e9;
            int second = st.top();st.pop();
            int first = st.top(); st.pop();
            if(s[i] == '+') st.push(first + second);
            else if(s[i] == '-') st.push(first - second);
            else if(s[i] == '*') st.push(first*second);
            else if(s[i] == '/') st.push(first/second);
        }
        return st.top();
    }