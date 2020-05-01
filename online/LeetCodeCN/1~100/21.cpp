// https://leetcode-cn.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *fakeHead = new ListNode(0), *cur = fakeHead;

        while (l1 && l2) {
            ListNode *&list = l1->val < l2->val ? l1 : l2;
            cur->next = new ListNode(list->val);
            list = list->next;
            cur = cur->next;
        }
        while (l1) {
            cur->next = new ListNode(l1->val);
            l1 = l1->next;
            cur = cur->next;
        }
        while (l2) {
            cur->next = new ListNode(l2->val);
            l2 = l2->next;
            cur = cur->next;
        }

        cur = fakeHead->next;
        delete fakeHead;
        return cur;
    }
};
