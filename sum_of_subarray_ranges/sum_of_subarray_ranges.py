class Solution:
    def subArrayRanges(self, nums: list[int]) -> int:
        n = len(nums)

        def count_contributions(is_max: bool) -> int:
            total = 0
            stack = []
            for i in range(n + 1):
                while stack and (i == n or (nums[stack[-1]] < nums[i] if is_max else nums[stack[-1]] > nums[i])):
                    j = stack.pop()
                    left = j - (stack[-1] if stack else -1)
                    right = i - j
                    total += nums[j] * left * right
                stack.append(i)
            return total

            # Sum of all subarray maximums - sum of all subarray minimums
        return count_contributions(True) - count_contributions(False)
        