class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target > nums[-1]:
            return len(nums)
        if target < nums[0]:
            return 0
        low = 0
        high = len(nums)
        to_insert = 0
        while low <= high:
            mid = low + (high - low)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                low = mid + 1
                to_insert = low
            else:
                high = mid - 1
        return to_insert
