class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hashmap;
        for(int num : nums) {
            hashmap[num]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto entry : hashmap) {
            pq.push({entry.second, entry.first});
        }

        vector<int>res;
        while(k > 0) {
            pair<int,int>topElement = pq.top();
            pq.pop();
            res.push_back(topElement.second);
            k--;
        }
        return res;
    }
};
