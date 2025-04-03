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

        // Move `prev` to the node just before the sublist
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // `last_node` will be the new tail of the reversed sublist
        ListNode* last_node = prev->next;
        ListNode* curr = prev->next;
        ListNode* pre = nullptr; // Previous node in reversal

        // Reverse the sublist between `left` and `right`
        for (int i = 0; i <= right - left; ++i) { // Fix: Loop runs (right-left+1) times
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        // Connect the reversed sublist back to the original list
        prev->next = pre;       // Link the node before sublist to the new head
        last_node->next = curr; // Link the sublist's tail to the remaining nodes

        return dummy->next;
    }
};
