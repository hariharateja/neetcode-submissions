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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* mid = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevmid = nullptr;
        while(fast && fast->next){
            prevmid = slow;
            fast = fast->next->next;
            slow = slow ->next;
        }
        prevmid->next = nullptr;
        mid = slow;
        ListNode* prev = nullptr;
        ListNode* curr = mid;
        ListNode* next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while(first && second){
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            if(t1 == nullptr){
                break;
            }
            second -> next = t1;
            first = t1;
            second = t2;
        }
    }
};
