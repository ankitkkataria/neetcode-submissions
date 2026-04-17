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
        cout << pq.size() << endl;
        cout << nums.size() - k << endl;
        int pqsize = pq.size();
        while(pq.size() > pqsize - k) {
            pair<int,int>topElement = pq.top();
            pq.pop();
            res.push_back(topElement.second);
        }
        return res;
    }
};
