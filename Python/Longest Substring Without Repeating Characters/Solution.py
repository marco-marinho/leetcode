class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cur_chars = []
        max_len = 0
        for start in range(len(s)):
            cur = start
            cur_len = 0
            while (cur < len(s) and s[cur] not in cur_chars):
                cur_chars.append(s[cur])
                cur += 1
                cur_len += 1
            cur_chars.clear()
            if cur_len > max_len:
                max_len = cur_len
        return max_len
