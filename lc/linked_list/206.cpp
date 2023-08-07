class Solution {
    public:
        ListNode* reverseList(ListNode* head){
            if (head == nullptr) return head;
            ListNode *curr = head->next, *prev=head, *tmp;
            prev->next = nullptr;
            while(curr != nullptr){
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            return prev;
        }
};
