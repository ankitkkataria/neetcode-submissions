class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<vector<int>> cnt(nums.size() + 1, vector<int>());
        unordered_map<int, int> hashmap;
        for (auto num : nums)
        {
            hashmap[num]++;
        }

        for (auto entry : hashmap)
        {
            cnt[entry.second].push_back(entry.first);
        }

        vector<int> res;

        for (int j = nums.size(); j >= 0 && k > 0; j--)
        {
            for (auto num : cnt[j])
            {
                res.push_back(num);
                k--;
                if (!k)
                    break;
            }
        }
        return res;
    }
};
