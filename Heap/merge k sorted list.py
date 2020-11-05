# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from Queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        pq = PriorityQueue()
        head=point=ListNode(0)
        
        for l in lists:
            if l:
                pq.put((l.val,l))
        
        while not pq.empty():
            val,node=pq.get()
            point.next=ListNode(val)
            point=point.next
            node=node.next
            if node:
                pq.put((node.val,node))
        
        return head.next
