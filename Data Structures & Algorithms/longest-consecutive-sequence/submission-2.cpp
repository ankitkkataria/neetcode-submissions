class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int res = 0;

        for (int num : s) {
            // Only start counting if num is the beginning
            // of a consecutive sequence.
            if (s.find(num - 1) == s.end()) {
                int current = num;
                int length = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    length++;
                }

                res = max(res, length);
            }
        }

        return res;
    }
};
