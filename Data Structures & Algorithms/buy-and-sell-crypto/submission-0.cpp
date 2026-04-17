class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minToLeft = prices[0];
        for(int i = 0 ; i < prices.size() ; i++) {
            minToLeft = min(prices[i], minToLeft);
            res = max(res, prices[i]-minToLeft);
        }

        return res;

    }
};
