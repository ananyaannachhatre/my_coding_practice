class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1, high = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long coins_needed = (long long)mid * (mid + 1) / 2;
            
            if (coins_needed == n) {
                return mid;  // Found exact match
            } else if (coins_needed < n) {
                low = mid + 1;  // We can possibly make more rows
            } else {
                high = mid - 1;  // Too many coins, reduce the number of rows
            }
        }
        
        return high;
    }
};
        