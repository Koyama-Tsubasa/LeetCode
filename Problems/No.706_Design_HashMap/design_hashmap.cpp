class MyHashMap {

private:
    std::vector<std::pair<int, int>> HashMap;

public:
    MyHashMap() {}
    
    void put(int key, int value) {

        for (auto &[in_key, in_value]: HashMap)
            if (in_key == key) {

                in_value = value;
                return;

            }
        HashMap.push_back({key, value});

    }
    
    int get(int key) {

        for (auto &[in_key, value]: HashMap) 
            if (in_key == key) return value;
        
        return -1;

    }
    
    void remove(int key) {

        int erase_pos;
        for (erase_pos=0; erase_pos<HashMap.size(); erase_pos++)
            if (HashMap[erase_pos].first == key) break;
        if (erase_pos != HashMap.size()) HashMap.erase(HashMap.begin()+erase_pos);

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
