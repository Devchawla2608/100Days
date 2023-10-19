class Solution
{
public:
int nodeLevel(int V, vector<int> adj[], int X) 
{
        set<pair<int, int>> s;
        bool* visited = new bool[V]{0};
        visited[0] = true;
        s.insert({0, 0});

        while (!s.empty()) 
        {
            auto it = s.begin();
            int x = it->first;
            int lvl = it->second;
            s.erase(it); 

            if (x == X) 
            {
                return lvl;
            }

            for (auto child : adj[x]) 
            {
                if (!visited[child]) 
                {
                    visited[child] = true;
                    s.insert({child, lvl + 1});
                }
            }
        }
        return -1;
    }
};