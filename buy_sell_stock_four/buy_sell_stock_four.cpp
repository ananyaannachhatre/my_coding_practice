class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
   int n = (int)prices.size();
        if (n == 0) return 0;

        // If k is large, this reduces to unlimited transactions
        if (2 * k > n) {
            long long ans = 0;
            for (int i = 1; i < n; ++i)
                ans += max(0, prices[i] - prices[i - 1]);
            return ans;
        }

        // Use vector instead of VLA
        vector<vector<long long>> dp(k + 1, vector<long long>(n, 0));

        for (int i = 1; i <= k; ++i) {
            long long m = -prices[0];
            for (int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + m);
                m = max(m, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return (int)dp[k][n - 1];
    }
};