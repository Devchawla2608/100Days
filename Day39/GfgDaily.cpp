    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> a(q.size() , 0);
        int size = q.size()/2;
        int j = 0;
        while(size--){
            a[j] = q.front();
            q.pop();
            j = j + 2;
        }
        j = 1;
        size = q.size();   
        while(size--){
            a[j] = q.front();
            q.pop();
            j = j + 2;
        }
        return a;
    }