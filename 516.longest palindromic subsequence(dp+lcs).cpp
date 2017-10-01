class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = "";
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            t += s[i];
        }
            
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[s.size()][s.size()];
    }
};