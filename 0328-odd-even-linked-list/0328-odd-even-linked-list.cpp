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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return head;

        vector<int> odd;
        vector<int> even;

        ListNode* temp = head;
        int pos = 1; // set the position

        while(temp!=NULL){
            if(pos%2==1){
                odd.push_back(temp->val);
            }else{
                even.push_back(temp->val);
            }
            temp=temp->next;
            pos++;
        }
        temp=head;

        for(int x:odd){
            temp->val=x;
            temp=temp->next;
        }
        for(int x:even){
            temp->val=x;
            temp=temp->next;
        }
        return head;
    }
};