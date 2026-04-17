class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>>s;
        int itr = nums.size() - 1;
        vector<int>res;
        while(itr >= 0) {
            if(s.empty() == true) {
                s.push({itr, nums[itr]});
                res.push_back(0);
            } else {
                // Stack has some elements
                if(nums[itr] >= s.top().second) {
                    while(!s.empty() && nums[itr] >= s.top().second) {
                        s.pop();
                    }
                    if(s.empty() == true) {
                        res.push_back(0);
                    } else {
                        res.push_back(s.top().first - itr);
                    }
                    s.push({itr, nums[itr]});
                }
                else {
                    res.push_back(s.top().first - itr);
                    s.push({itr, nums[itr]});
                }
            }
            itr--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
