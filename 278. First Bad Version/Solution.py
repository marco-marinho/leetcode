class Solution:
    def firstBadVersion(self, n: int) -> int:
        lowest_bad = int(2e31) - 1
        highest_good = 0
        cur = (lowest_bad + highest_good) // 2
        while True:
            if isBadVersion(cur):
                lowest_bad = cur
            else:
                highest_good = cur
            if lowest_bad == highest_good + 1:
                break
            cur = (lowest_bad + highest_good) // 2
        return lowest_bad
