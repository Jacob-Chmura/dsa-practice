class Solution {
    public:
        ListNode* reverseList(ListNode* head){
            if (head == nullptr || head->next == nullptr) return head;
            ListNode* reversedAfterHead = reverseList(head->next);
            reversedAfterHead->next->next = reversedAfterHead;
            reversedAfterHead->next = nullptr;
            return reversedAfterHead;
        }
}
