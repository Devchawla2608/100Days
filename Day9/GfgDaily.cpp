    

iven a character array tasks of size N, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
CPU has a cooldown period for each task. CPU can repeat a task only after atleast K units of time has passed after it did same task last time. It can perform other tasks in that time, can stay idle to wait for repeating that task.

int leastInterval(int N, int K, vector<char> &tasks) {
        int ans=N;
        map<char,int>mp;
        int idle_count=0;
        int max_count=0;
        for(int i=0;i<N;i++)
        {
            mp[tasks[i]]++;
            max_count=max(max_count,mp[tasks[i]]);
        }
           idle_count=(max_count-1)*K+(max_count-1);
      
        for(auto it:mp)
        {
          idle_count-=min(max_count-1,it.second);
    
        }
       return (idle_count>0)?(ans+idle_count):(ans);
    }