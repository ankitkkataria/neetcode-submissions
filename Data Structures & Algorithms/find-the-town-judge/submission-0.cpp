class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    vector<vector<int>> adjList(n + 1, vector<int>());
    vector<int> indegree(n + 1, 0);

    for (auto t : trust) {
      adjList[t[0]].push_back(t[1]);
      indegree[t[1]]++;
    }

    int cnt = 0;
    int storeNode = 0;
    for (int i = 1; i <= n; i++) {
      if (indegree[i] == n - 1) {
        cnt++;
      storeNode = i;
      }
    }
    // cout << cnt << endl;
    return (cnt != 1 || adjList[storeNode].size() != 0) ? -1 : storeNode;
  }
};
