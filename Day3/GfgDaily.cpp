
Given N integers, the task is to insert those elements in the queue. Also, given M integers, the task is to find the frequency of each number in the Queue.
Note:

insert() will be called N times by main().
findFrequency() will be called M times by main();
Where k is each element passing through respective function calls    

void insert(queue<int> &q, int k){
        q.push(k);
    }

    int findFrequency(queue<int> q, int k){
        int count = 0;
        while(q.size() != 0){
            int top = q.front();
            q.pop();
            if(top == k) count++;
        }
        return count;
    }