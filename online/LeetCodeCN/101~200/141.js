// 环形链表
// https://leetcode-cn.com/problems/linked-list-cycle/
// 哈希表法

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    const nodeSet = new Set()
    while (head != null) {
        if (nodeSet.has(head)) {
            return true
        }

        nodeSet.add(head)
        head = head.next
    }
    return false
};
