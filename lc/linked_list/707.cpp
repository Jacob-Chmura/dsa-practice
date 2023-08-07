class MyLinkedList {
    public:
        MyLinkedList() : head(nullptr), length(0) {}

        int get(int index){
            if(index >= _size || index < 0) return -1;
            return getNode(index)->val;
        }

        void addAtHead(int val){
            ListNode* newNode = createNode(val);
            newNode->next = head;
            if(_size > 0) head->prev = newNode;
            head = newNode;
            ++_size;
        }

        void addAtTail(int val){
            if(_size <= 1) addAtHead(val);
            ListNode* newNode = createNode(val);
            ListNode*curr = getNode(_size - 1);
            curr->next = newNode;
            newNode->prev = curr;
            ++_size;
        }

        void addAtIndex(int index, int val){
            if(index > _size || index < 0) return;
            if(index == 0) addAtHead(val);
            if(index == _size) addAtTail(val);

            ListNode* curr = getNode(index-1);
            ListNode* newNode = createNOde(val);
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next->prev = newNode;
            curr->next = newNode;
            ++_size;
        }

        void deleteAtIndex(int index){
            if(index >= _size || index < 0) return;
            ListNode* curr = getNode(index - 1);
            if(index < _size-1){
                // not deleting at the end, so need to move prev
                curr->next->next->prev = curr;
            }
            
            delete curr->next;
            curr->next = curr->next->next;
            --_size;
        }

    private:
        struct ListNode {
            int val;
            ListNode *next;
            ListNide *prev;
        };

        ListNode *getNode(int index){
            int i = 0;
            ListNode *curr = head;
            for(int i = 0; i < index; ++i) curr = curr->next;
            return curr;        
        }
        
        ListNode *createNode(int val){
            ListNode* newNode = new ListNode;
            newNode->val = val;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            return newNode;
        }

        int _size;
        ListNode *head;
};

