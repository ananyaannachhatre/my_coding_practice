class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        max_len = 0
        start = 0  # Start of the current subarray (after last zero)

        while start < len(nums):
            # Skip zeros
            while start < len(nums) and nums[start] == 0:
                start += 1
            if start == len(nums):
                break

            end = start
            count_neg = 0
            first_neg = -1
            last_neg = -1

            # Process segment without zero
            while end < len(nums) and nums[end] != 0:
                if nums[end] < 0:
                    count_neg += 1
                    if first_neg == -1:
                        first_neg = end
                    last_neg = end
                end += 1

            if count_neg % 2 == 0:
                max_len = max(max_len, end - start)
            else:
                # Exclude up to first negative or after last negative
                max_len = max(max_len, end - first_neg - 1, last_neg - start)

            start = end + 1  # Move to next segment after zero

        return max_len
        