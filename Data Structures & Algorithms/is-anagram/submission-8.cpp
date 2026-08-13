class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }

        return count(cnt.begin(), cnt.end(), 0) == 26 ? true : false;
    }
};
