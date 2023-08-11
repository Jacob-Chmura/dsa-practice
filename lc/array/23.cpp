class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists){
            // O(k*n)
            ListNode *result = new ListNode(), *curr;
            curr = result;
            int min_idx = getMinIndex(lists);
            while(min_idx != -1){
                ListNode* tmp = lists[min_idx];
                curr->next = tmp;
                curr = tmp;
                lists[min_idx] = lists[min_idx]->next;
                min_idx = getMinIndex(lists);
            }
            return result->next;
        }

        ListNode* mergeKListsFast(vector<ListNode*>& lists, int s, int e){
            // O(logk * n)
            if(e-s+1 <= 0) return nullptr;
            ListNode* l = mergeKListsFast(lists, s, (s+e)/2);
            ListNode* r = mergeKListsFast(lists, (s+e)/2+1, e);
            
            // Sort two linked lists l, r which are sorted
            return merge2Lists(l, r);
        }

    private:
        int getMinIndex(vector<ListNode*>&lists){
            int min_idx = -1, curr_min;
            for(int i = 0; i < lists.size(); ++i){
                if (lists[i] != nullptr){
                    if(min_idx == -1 || lists[i]->val < curr_min){
                        min_idx = i;
                        curr_min = lists[i]->val;
                    }
                }
            }
            return min_idx;
        }

        ListNode* merge2Lists(ListNode *l, ListNode *r){
            ListNode *result = new ListNode(), *curr;
            curr = result;
            while(l != nullptr && r != nullptr){
                if(l->val <= r->val){
                    curr->next = l;
                    l = l->next;
                } else{
                    curr->next = r;
                    r = r->next;
                }
                curr = curr->next;
            }
            if(l == nullptr)curr->next = r;
            else curr->next = l;
            return result->next;
        }
};
