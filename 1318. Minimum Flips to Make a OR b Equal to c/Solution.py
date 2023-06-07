class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        res = 0
        while a > 0 or b > 0 or c > 0:
            ta = (a & 1)
            tb = (b & 1)
            tc = (c & 1)
            if tc != ta | tb:
                if tc == 0:
                    res += ta + tb
                else:
                    res += 1
            a >>= 1
            b >>= 1
            c >>= 1
        return res
