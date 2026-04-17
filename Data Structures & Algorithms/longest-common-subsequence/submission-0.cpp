class Solution
{
public:
    // f's job is starting at index i & j for text1 and text2 return me the length of the LCS.
    int f(int i, int j, string text1, string text2, vector<vector<int>> &dp)
    {
        // Base condition
        if (i >= text1.size() || j >= text2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Incase the character at the beginning of both the strings matches
        if (text1[i] == text2[j])
            return dp[i][j] = 1 + f(i + 1, j + 1, text1, text2, dp);
        // Incase the character at the beginning of both the strings doesn't match
        else
            return dp[i][j] = max(f(i + 1, j, text1, text2, dp), f(i, j + 1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        return f(0, 0, text1, text2, dp);
        
    }
};
