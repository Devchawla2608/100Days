// Delete middle element of a stack
// Given a stack, delete the middle element of the stack without using any additional data structure.
// Middle element:- ceil((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.
// Note: The output shown by the compiler is the stack from top to bottom.

    int f(stack<int> &st , int size , int index){
        if(index == 1){
            int element = st.top();
            st.pop();
            return element;
        }
        int element = st.top();
        st.pop();
        int ans = f(st , size-1 , index-1);
        st.push(element);
        return ans;
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        if(sizeOfStack%2 == 0){
            int element = f(s , sizeOfStack ,(sizeOfStack/2)+1);
        }
        else int element = f(s , sizeOfStack , (sizeOfStack + 1)/2);
    }