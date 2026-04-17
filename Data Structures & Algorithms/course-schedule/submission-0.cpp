class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        // Toposort implement
        vector<vector<int>>adjList(numCourses, vector<int>());
        vector<int>indegree(numCourses, 0);
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        
        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++) 
            if(indegree[i] == 0) q.push(i);
        
        vector<int>topoSort;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                int node = q.front();
                topoSort.push_back(node);
                q.pop();
                for(int adjNode : adjList[node]) {
                    indegree[adjNode]--;
                    if(indegree[adjNode] == 0)
                        q.push(adjNode);
                }
            }
        }

        return topoSort.size() == numCourses;
    }
};
