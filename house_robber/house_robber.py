class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)  
        if n == 0:
            return 0
        if n == 1:
            return nums[0]

        prev_incl = nums[0]  # dp[0][1]
        prev_excl = 0        # dp[0][0]

        for i in range(1, n):
            new_incl = prev_excl + nums[i]
            new_excl = max(prev_incl, prev_excl)
            prev_incl = new_incl
            prev_excl = new_excl
        
        return max(prev_incl, prev_excl)
        