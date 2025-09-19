class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        if time == 0:
            return list(range(n))
        
        non_inc = [0] * n  # non-increasing count before or at i
        non_dec = [0] * n  # non-decreasing count after or at i

        # Fill non-increasing days from left to right
        for i in range(1, n):
            if security[i] <= security[i - 1]:
                non_inc[i] = non_inc[i - 1] + 1
            else:
                non_inc[i] = 0

        # Fill non-decreasing days from right to left
        for i in range(n - 2, -1, -1):
            if security[i] <= security[i + 1]:
                non_dec[i] = non_dec[i + 1] + 1
            else:
                non_dec[i] = 0

        # Find all valid days
        result = []
        for i in range(time, n - time):
            if non_inc[i] >= time and non_dec[i] >= time:
                result.append(i)

        return result