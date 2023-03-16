class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target > nums[-1] or target < nums[0]:
            return -1
        low = 0
        high = len(nums)
        while low <= high:
            mid = low + (high - low)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1
