# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def middle(node):
            if node is None or node.next is None:
                return node
            slow=node
            fast=node
            while fast.next is not None and fast.next.next is not None:
                slow=slow.next
                fast=fast.next.next
            return slow
        
        def merge(a,b):
            if a is None:
                return b
            if b is None:
                return a
            result=None
            if a.val<=b.val:
                result=a
                result.next=merge(a.next,b)
            else:
                result=b
                result.next=merge(a,b.next)
            return result
        
        def main(head):
            if head is None or head.next is None:
                return head
            middle_node=middle(head)
            middle_next=middle_node.next
            middle_node.next=None
            
            left=main(head)
            right=main(middle_next)
            ans=merge(left,right)
            return ans
        
        return main(head)
