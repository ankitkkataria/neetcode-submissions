class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> s;
        s.insert(nums.begin(), nums.end());
        int res = 0;
        for (auto num : nums)
        {
            if (s.find(num - 1) == s.end())
            {
                // Could be start of a sequence
                int tempRes = 1;
                while (s.find(num + 1) != s.end())
                {
                    tempRes++;
                    num++;
                }
                res = max(tempRes, res);
            }
        }

        return res;
    }
};
