class LRUCache {
private:
    struct Cache {
        int key;
        int val;
        int lruCounter;
    };
    Cache* store;
    int cap;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        store = new Cache[capacity];
        
        // Initialize the cache
        for(int i = 0; i < capacity; i++) {
            store[i].key = -1;
            store[i].val = -1;
            store[i].lruCounter = 0;
        }
    }
    
    int get(int key) {
        
        // First increment the LRU counter
        for(int i = 0; i < cap; i++) {
            store[i].lruCounter++;
        }
        
        // Check if the key is present in the cache
        for(int i = 0; i < cap; i++) {
            if(key == store[i].key) {
                store[i].lruCounter = 0;
                return store[i].val;
            }
        }
        
        // Key not found in the cache
        return -1;
    }
    
    void put(int key, int value) {

        // First increment the LRU counter
        for(int i = 0; i < cap; i++) {
            store[i].lruCounter++;
        }
             
        // Check if the key is present in the cache
        for(int i = 0; i < cap; i++) {
            if(key == store[i].key) {
                store[i].lruCounter = 0;
                store[i].val = value;
                return;
            }
        }
                
        // Check if there is an empty space in the cache
        for(int i = 0; i < cap; i++) {
            if(store[i].key == -1 && store[i].val == -1) {
                store[i].lruCounter = 0;
                store[i].key = key;
                store[i].val = value;
                return;
            }
        }
        
        // Since there is no empty space in the cache, we have to evict the LRU block
        int maxCounterVal = 0;
        int maxIndex = 0;
        for(int i = 0; i < cap; i++) {
            if(store[i].lruCounter > maxCounterVal) {
                maxCounterVal = store[i].lruCounter;
                maxIndex = i;
            }
        }
        
        // maxIndex corresponds to the LRU block, we need to evict that
        store[maxIndex].key = key;
        store[maxIndex].val = value;
        store[maxIndex].lruCounter = 0;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */