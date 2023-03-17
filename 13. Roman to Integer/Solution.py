values = {
    'I' : 1,
    'V' : 5,
    'X' : 10,
    'L' : 50,
    'C' : 100,
    'D' : 500,
    'M' : 1000,
}

class Solution:
    def romanToInt(self, s: str) -> int:
        total = 0
        last_val = 0
        for entry in s[::-1]:
            cur_val = values[entry]
            if cur_val >= last_val:
                total += cur_val
            else:
                total -= cur_val
            last_val = cur_val
        return total