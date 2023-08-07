class Solution{
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
            if (list1 == nullptr) return list2;
            if (list2 == nullptr) return list1;

            ListNode *curr, *res;
            if(list1->val <= list2->val){
                res = list1;
                list1 = list1->next;
            } else{
                res = list2;
                list2 = list2->next;
            }
            curr = res;
            while(list1 != nullptr && list2 != nullptr){
                if(list1->val <= list2->val){
                    curr->next = list1;
                    list1 = list1->next;
                } else{
                    curr->next = list2;
                    list2 = list2->next;
                }
                curr = curr->next;
            }
            if(list1 == nullptr)
                curr->next = list2;
            else
                curr->next = list1;
            return res;
        }

        ListNode* mergeTwoListRecursive(ListNode* list1, ListNode* list2){
            if (list1 == nullptr) return list2;
            if (list2 == nullptr) return list1;

            if(list1->val <= list2->val){
                list1->next = mergeTwoListRecursive(list->next, list2);
                return list1;
            } else {
                list2->next = mergeTwoListRecursive(list, list2->next);
                return list2;
            }
            
        }
};

