class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        unordered_map<int, int> hashmap;
        int res = 0;
        while (j < s.size())
        {
            hashmap[s[j]]++;
            if (hashmap.size() == j - i + 1) // Current window is unique
                res = max(res, j - i + 1);
            else // Current window is not unique
            {
                while (i < s.size() && hashmap.size() != j - i + 1)
                {
                    hashmap[s[i]]--;
                    if (hashmap[s[i]] == 0)
                        hashmap.erase(s[i]);
                    i++;
                }
            }
            j++;
        }

        return res;
    }
};
