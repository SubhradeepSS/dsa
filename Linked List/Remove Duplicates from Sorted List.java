// LINK: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode t = head;
        while (t != null) {
            ListNode next = t.next;
            while (next != null && next.val == t.val) {
                next = next.next;
            }
            t.next = next;
            t = next;
        }
        return head;
    }
}