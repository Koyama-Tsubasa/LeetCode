class NumArray {

private:
    std::vector<int> numArray;

public:
    NumArray(vector<int>& nums) { for (auto num: nums) numArray.push_back(num); }
    
    int sumRange(int left, int right) {
        
        // parameter
        int sum = 0;

        // start computing
        for (int i=left; i<=right; i++) sum += numArray[i];

        return sum;

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
