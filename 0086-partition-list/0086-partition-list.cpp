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
    ListNode* partition(ListNode* head, int x) {
        // for starting of less and high
        ListNode* lessdummy = new ListNode(0);
        ListNode* highdummy = new ListNode(0);

        // last node of less and high
        ListNode* less = lessdummy;
        ListNode* high = highdummy;

        ListNode* temp = head;

        while (temp != NULL) {

            if (temp->val < x) {
                less->next = temp;
                less = less->next;
            } else {
                high->next = temp;
                high = high->next;
            }
            temp = temp->next;
        }
        high->next = NULL;
        less->next = highdummy->next;

        return lessdummy->next;
    }
};