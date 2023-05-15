class MyHashSet {

private:
    std::unordered_map<int, bool> HashSet;

public:
    MyHashSet() {}
    
    void add(int key) {HashSet[key] = true;}
    
    void remove(int key) {HashSet[key] = false;}
    
    bool contains(int key) {

        if (HashSet.count(key)) return HashSet[key];
        else return false;

    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
