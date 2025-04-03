/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* last_node = prev->next;
        ListNode* curr = prev->next;
        ListNode* pre = nullptr;

        for (int i = 0; i <= right - left; ++i) { 
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        prev->next = pre;       
        last_node->next = curr;

        return dummy->next;
    }
};
