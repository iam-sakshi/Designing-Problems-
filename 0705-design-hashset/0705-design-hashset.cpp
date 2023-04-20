
class MyHashSet {
    struct Node {
        int digit;
        bool val;
        vector<Node *> children;
        
        Node(int digit) {
            this->val = false;
            this->digit = digit;
        }
    };
    
    Node *root;
public:
    MyHashSet() {
        root = new Node(0);
    }
    
    void add(int key) {
        if(key == 0) {
            root->val = true;
            return;
        }
        
        Node *cur = root;
        
        while(key) {
            bool found = false;
            
            for(auto i:cur->children) {
                if(i->digit == key%10) {
                    found = true;
                    cur = i;
                    break;
                }
            }
            
            if(!found) {
                cur->children.push_back(new Node(key%10));
                cur = cur->children.back();
            }
            
            key /= 10;
        }
        
        cur->val = true;
    }
    
    void remove(int key) {
        if(key == 0) {
            root->val = false;
            return;
        }
        
        Node *cur = root;
        
        while(key) {
            bool found = false;
            
            for(auto i:cur->children) {
                if(i->digit == key%10) {
                    found = true;
                    cur = i;
                    break;
                }
            }
            
            if(!found)
            return;
            
            key /= 10;
        }
        
        cur->val = false;
    }
    
    bool contains(int key) {
        if(key == 0)
        return root->val;
        
        Node *cur = root;
        
        while(key) {
            bool found = false;
            
            for(auto i:cur->children) {
                if(i->digit == key%10) {
                    found = true;
                    cur = i;
                    break;
                }
            }
            
            if(!found) 
            return false;
            
            key /= 10;
        }
        
        return cur->val;
    }
}; 
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */