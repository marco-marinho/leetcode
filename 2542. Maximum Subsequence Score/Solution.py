class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        pairs = [(nums1[i], nums2[i]) for i in range(len(nums1))]
        pairs.sort(key=lambda x: x[1], reverse=True)
        heap = []
        heapq.heapify(heap)
        sum = 0
        for i in range(k):
            heapq.heappush(heap, pairs[i][0])
            sum += pairs[i][0]
        res = sum * pairs[k - 1][1]
        for i in range(k, len(nums1)):
            smallest = heapq.heappop(heap)
            sum -= smallest
            sum += pairs[i][0]
            heapq.heappush(heap, pairs[i][0])
            res = max(res, sum * pairs[i][1])
        return res

