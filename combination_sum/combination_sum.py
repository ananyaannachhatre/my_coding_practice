class Solution:
    def combinationSum(self, candidates, target):
        ans = []
        temp = []

        def rec(i, curr_sum):
            if curr_sum > target:
                return  # pruning
            if i == len(candidates):
                if curr_sum == target:
                    ans.append(temp[:])
                return
            # not choosing i-th element
            rec(i + 1, curr_sum)
            # choosing i-th element
            temp.append(candidates[i])
            rec(i, curr_sum + candidates[i])
            temp.pop()

        rec(0, 0)
        return ans