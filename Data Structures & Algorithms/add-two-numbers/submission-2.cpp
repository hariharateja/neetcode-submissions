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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        int addon = 0;
        ListNode* last = nullptr;
        while(t1 || l2){
            if(!t1){
                last->next = new ListNode(0);
                t1 = last->next;
            }
            int val1 = t1->val;
            int val2 = (l2 ? l2->val :0);
            t1->val =  (val1 + val2 + addon)%10;
            addon = (val1 + val2 + addon)/10;
            last = t1;
            t1 = t1->next;
            if(l2)
                l2 = l2->next;
        }
        cout<<addon;
        if(addon == 0){
            return l1;
        }
        last->next = new ListNode(1);
        return l1;
        

    }
};
