    void solve2(stack<int> &st , int element){
        if(st.size() == 0){
            st.push(element);
            return ;
        }
        int save = st.top();
        st.pop();
        solve2(st , element);
        st.push(save);
    }
    void solve(stack<int> &st){
        if(st.size() == 0){
            return ;
        }
        int store = st.top();
        st.pop();
        solve(st);
        solve2(st , store);
    }


    void Reverse(stack<int> &st){
       solve(st);
    }