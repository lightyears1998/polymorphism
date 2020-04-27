// https://leetcode-cn.com/problems/add-two-numbers/
// 模拟

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *prev = head;

        int entry = 0;
        do {
            int left = l1 ? l1->val : 0;
            int right = l2 ? l2->val : 0;
            int sum = entry + left + right;

            entry = sum / 10;
            prev->next = new ListNode(sum % 10);
            prev = prev->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        } while (l1 || l2 || entry);

        return head->next;
    }
};
