class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    int n = nums.size();
    vector<vector<int>> freqVec(n + 1, vector<int>());
    unordered_map<int, int> hashmap;
    for (auto num : nums) {
      hashmap[num]++;
    }
    for (auto entry : hashmap) {
      freqVec[entry.second].push_back(entry.first);
    }
    vector<int> res;

    for (int i = n; i >= 0; i--) {
      for (auto num : freqVec[i]) {
        if (res.size() == k)
            return res; 
        res.push_back(num);
      }
    }

    return res;
  }
};
