    queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int> s;
        queue <int> ans;
        int n  = q.size();
        for (int i = 0;i<n;i++)
        {
            s.push(q.front());
            q.pop();
        }
         for (int i = 0;i<n;i++)
        {
            ans.push(s.top());
            s.pop();
        }
        return ans;
        
    }