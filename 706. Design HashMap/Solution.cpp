class MyHashMap {
public:
    MyHashMap(): bucket(1000001, -1) {
        
    }
    
    void put(int key, int value) {
        bucket[key] = value;
    }
    
    int get(int key) {
        return bucket[key];
    }
    
    void remove(int key) {
        bucket[key] = -1;
    }
private:
    vector<int> bucket;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
