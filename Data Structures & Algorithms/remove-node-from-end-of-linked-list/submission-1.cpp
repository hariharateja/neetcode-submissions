class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        int len = 0;
        ListNode* temp = head;

        while(temp){
            len++;
            temp = temp->next;
        }

        int pos = len - n;

        temp = dummy;

        for(int i=0;i<pos;i++){
            temp=temp->next;
        }

        temp->next = temp->next->next;

        return dummy->next;
    }
};