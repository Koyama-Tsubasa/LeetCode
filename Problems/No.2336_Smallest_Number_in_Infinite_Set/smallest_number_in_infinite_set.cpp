class SmallestInfiniteSet {

private:
    std::map<unsigned int, bool> isInSet;
    std::priority_queue<unsigned int, std::vector<unsigned int>, std::greater<unsigned int>> InfiniteSet;

public:
    SmallestInfiniteSet() {

        for (unsigned int num=1; num<=1000; num++) {

            InfiniteSet.push(num);
            isInSet[num] = true;

        }

    }
    
    int popSmallest() {
        
        unsigned int smallest = InfiniteSet.top();
        InfiniteSet.pop();
        isInSet[smallest] = false;

        return smallest;

    }
    
    void addBack(int num) {
        
        if (isInSet[num] == false) {

            InfiniteSet.push(num);
            isInSet[num] = true;

        }

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
