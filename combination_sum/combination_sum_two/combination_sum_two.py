

class Solution:
    def combinationSum2(self, candidates, target):
        candidates.sort()
        res = []

        def backtrack(start, path, total):
            if total == target:
                res.append(path[:])
                return
            if total > target:
                return
            prev = None
            for i in range(start, len(candidates)):
                if candidates[i] == prev:  # skip duplicates
                    continue
                path.append(candidates[i])
                backtrack(i + 1, path, total + candidates[i])
                path.pop()
                prev = candidates[i]

        backtrack(0, [], 0)
        return res

        