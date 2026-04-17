class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ; i++) {
            if(res.back()[1] < intervals[i][0]) {
                // Non-overlapping intervals no need to worry
                res.push_back(intervals[i]);
            }
            else {
                // Overlapping intervals 
                vector<int>temp;
                temp = {res.back()[0], max(res.back()[1], intervals[i][1])};
                res.pop_back();
                res.push_back(temp);
            }
        }
        return res;
    }
};
