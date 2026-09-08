class Solution
{
public:

    bool findElement(unordered_set<int>&s, int num) {
        return s.find(num) != s.end();
    }


    int longestConsecutive(vector<int> &nums)
    {
        int res = 0;
        unordered_set<int>s(nums.begin(), nums.end());

        for(auto num : nums) {
            // Start of a sequence?
            if(!findElement(s, num-1)) {
                // Count the seq
                int countOfSeq = 0;
                while(findElement(s, num)) {
                    countOfSeq++;
                    num++;
                }
                res = max(res, countOfSeq);
            }
        }
        return res;
    }
};
