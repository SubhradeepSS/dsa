// LINK:https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        int a = k - 1, b = k, c = 0;
        ListNode t = head, t1 = head, t2 = head;
        while (a > 0) {
            t = t.next;
            a--;
        }
        a = t.val;
        // t=head;
        while (t2 != null) {
            c++;
            t2 = t2.next;
        }
        b = c - k;
        // t=head;
        while (b > 0) {
            t1 = t1.next;
            b--;
        }
        t.val = t1.val;
        t1.val = a;
        return head;
    }
}