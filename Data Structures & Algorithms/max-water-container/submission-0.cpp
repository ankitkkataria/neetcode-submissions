class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;
        while(l < r) {
            int tempMinH = min(heights[l], heights[r]);
            int tempArea = tempMinH * (r - l);
            res = max(res, tempArea);
            if(heights[l] > heights[r]) r--;
            else l++;
        }
        return res;
    }
};
