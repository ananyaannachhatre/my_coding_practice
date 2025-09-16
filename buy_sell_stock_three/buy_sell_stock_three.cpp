class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
    //Complete the function
    int n = (int)prices.size();
    long long pre[n];
    pre[0] = 0;
    long long m = prices[0];
    for (long long i = 1; i < n; ++i) {
        pre[i] = max(pre[i-1], prices[i] - m);
        m = min(m, 1LL * prices[i]);
    }
    long long post[n];
    post[n-1] = 0;
    m = prices[n-1];
    for (long long i = n - 2; i >= 0; --i) {
        post[i] = max(post[i+1], m  -prices[i]);
        m = max(m, 1LL * prices[i]);
    }
    long long ans = 0;
    for (long long i = 0; i < n; ++i) {
        ans=max(ans, pre[i]+post[i]);
    }
    return ans;
    
}
        
};