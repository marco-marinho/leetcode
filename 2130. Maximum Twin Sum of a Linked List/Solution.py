class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        if head is None:
            return 0
        curr = head
        size = 1
        while (curr := curr.next) is not None:
            size += 1
        curr = head
        prev = None
        for _ in range(size // 2):
            buff = curr.next
            curr.next = prev
            prev = curr
            curr = buff
        output = 0
        while prev is not None:
            output = max(output, prev.val + curr.val)
            prev = prev.next
            curr = curr.next
        return output
