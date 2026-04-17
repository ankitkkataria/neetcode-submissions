class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        unordered_map<char, int> hashmap;
        int res = 0;
        while (j < s.size())
        {
            hashmap[s[j]]++;
            int windowSize = j - i + 1;
            if (hashmap.size() == windowSize)
            {
                res = max(res, windowSize);
            }
            else if (hashmap.size() < windowSize)
            {
                while (hashmap.size() < windowSize)
                {
                    hashmap[s[i]]--;
                    if (!hashmap[s[i]])
                        hashmap.erase(s[i]);
                    i++;
                    windowSize = j - i + 1;
                }
            }
            j++;
        }
        return res;
    }
};
