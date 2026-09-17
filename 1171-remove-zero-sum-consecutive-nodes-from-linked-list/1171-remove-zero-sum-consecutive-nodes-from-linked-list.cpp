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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> mp;

        int sum = 0;
        ListNode* temp = dummy;
        while (temp != NULL) {
            sum += temp->val;
            mp[sum] = temp;
            temp = temp->next;
        }
        sum = 0;
        temp = dummy;

        while (temp != NULL) {
            sum += temp->val;

            temp->next = mp[sum]->next;

            temp = temp->next;
        }

        return dummy->next;
    }
};