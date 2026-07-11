class MyHashMap {
    private:
        struct ListNode
        {
            int key,val;
            ListNode* next;
            ListNode(int key =-1,int val = -1,ListNode* next = nullptr) : key(key), val(val), next(next){}
        };
        vector<ListNode*> mp;

        int hash(int key)
        {
            return key % mp.size();
        }
public:
    MyHashMap() {
        mp.resize(10000);
        for(auto & bucket : mp)
        {
            bucket = new ListNode(0);
        }
        
    }
    
    void put(int key,int val) {
        ListNode* cur = mp[hash(key)];
        while(cur->next)
        {
            if (cur->next->key == key)
            {
                cur->next->key = val;
            }
            cur = cur->next;

        }
        cur->next = new ListNode(key,val);
        
    }
    
    void remove(int key) {
        ListNode* cur = mp[hash(key)];
        while(cur->next)
        {
            if(cur->next->key == key)
            {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                delete temp;
                return;
            }
            cur = cur->next;
        }
        
        
    }
    
    int get(int key) {
        ListNode* cur = mp[hash(key)];
        while(cur->next)
        {
            if (cur->next->key == key) return cur->next->val ;
            cur = cur->next;

        }
        return -1;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */