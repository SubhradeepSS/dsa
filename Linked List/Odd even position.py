# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None or head.next.next is None:
            return head
        odd=head
        even=head.next
        evenstart=even
        while odd is not None and even is not None:
            if even is not None:
                odd.next=even.next
                if odd.next is not None:
                    odd=odd.next
            if odd is not None:
                even.next=odd.next
                even=even.next
        odd.next=evenstart
        return head
