class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &pre)
    {
        vector<vector<int>> edges(n, vector<int>());
        vector<int> indegree(n, 0);
        for (auto p : pre)
        {
            indegree[p[0]]++;
            edges[p[1]].push_back(p[0]);
        }

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto adjNode : edges[front])
            {
                indegree[adjNode]--;
                if(!indegree[adjNode])
                    q.push(adjNode);
            }
        }

        for(auto num : indegree)
            if(num) return false;

        return true;
    }
};
