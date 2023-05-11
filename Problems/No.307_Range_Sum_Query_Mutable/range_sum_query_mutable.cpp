class RangeSum {

    public:
        int range_start, range_end;
        int rsum;
        RangeSum *left, *right;
        RangeSum(int range_start, int range_end) {

            this->range_start = range_start;
            this->range_end = range_end;
            rsum = 0;
            left = nullptr;
            right = nullptr;

        }

};

class NumArray {

private:
    RangeSum *root;

public:
    NumArray(vector<int>& nums) {root = create_STree(nums, 0, nums.size()-1);}

    RangeSum *create_STree(std::vector<int> &vec, int start, int end) {

        RangeSum *node = new RangeSum(start, end);

        if (start == end) node->rsum = vec[start];
        else {

            int mid = (start + end)/2;
            node->left = create_STree(vec, start, mid);
            node->right = create_STree(vec, mid+1, end);
            node->rsum = node->left->rsum + node->right->rsum;

        }
        
        return node;

    }

    RangeSum *update_path(RangeSum *node, int idx, int val) {

        if ((node->range_start == idx) && (node->range_end == idx)) node->rsum = val;
        else {

            if (node->left->range_end >= idx) node->left = update_path(node->left, idx, val);
            else node->right = update_path(node->right, idx, val);
            node->rsum = node->left->rsum + node->right->rsum;

        }

        return node;

    }
    
    void update(int index, int val) {root = update_path(root, index, val);}

    int CalSRangeum(RangeSum *node, int left, int right) {

        if ((left == node->range_start) && (right == node->range_end)) return node->rsum;
        else if (right <= node->left->range_end) return CalSRangeum(node->left, left, right);
        else if (node->right->range_start <= left) return CalSRangeum(node->right, left, right);
        else return CalSRangeum(node->left, left, node->left->range_end) + 
                    CalSRangeum(node->right, node->right->range_start, right);

    }
    
    int sumRange(int left, int right) {return CalSRangeum(root, left, right);}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
