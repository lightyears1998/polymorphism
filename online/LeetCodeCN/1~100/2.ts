// 两数相加
// https://leetcode-cn.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    let head = new ListNode(), cur = head

    let entry = 0
    while (l1 != null || l2 != null || entry != 0) {
        let left = 0, right = 0
        if (l1) {
            left = l1.val
            l1 = l1.next
        }

        if (l2) {
            right = l2.val
            l2 = l2.next
        }

        const sum = left + right + entry
        const val = sum % 10;
        entry = Math.floor(sum / 10)

        cur.next = new ListNode(val)
        cur = cur.next
    }

    return head.next
};
