class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nset = set(nums)
        res = 0
        for n in nset:
            if n - 1 not in nset:
                i = itertools.count(1)
                while n + next(i) in nset:
                    pass
                res = max(res, next(i) - 1)
        return res

