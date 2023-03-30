class KthLargest {

private:
    int Kth;
    std::priority_queue<int, std::vector<int>, std::greater<int>> KminHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        
        Kth = k;
        for (int i=0; i<std::min(Kth, (int)nums.size()); i++) KminHeap.push(nums[i]);
        for (int i=Kth; i<nums.size(); i++) {
            if (nums[i] > KminHeap.top()) {

                KminHeap.pop();
                KminHeap.push(nums[i]);

            }
        }

    }
    
    int add(int val) {
        
        if (KminHeap.size() < Kth) KminHeap.push(val);
        else if (val > KminHeap.top()) {

            KminHeap.pop();
            KminHeap.push(val);

        }

        return KminHeap.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
