class RangeFreqQuery {

private:
    std::unordered_map<int, std::vector<int>> value_mapping;

public:
    RangeFreqQuery(vector<int>& arr) {

        for (int i=0; i<arr.size(); i++)
            value_mapping[arr[i]].push_back(i);
        
    }

    int find_left(std::vector<int> &idxs, int L_limit) {

        int left_edge = -1;
        int left = 0, right = idxs.size()-1;
        
        while (left <= right) {

            int mid = (left + right)/2;
            if (idxs[mid] < L_limit) {

                left_edge = mid;
                left = mid + 1;

            }
            else right = mid - 1;

        }

        return left_edge + 1;

    }

    int find_right(std::vector<int> &idxs, int R_limit) {

        int right_edge = idxs.size();
        int left = 0, right = idxs.size()-1;
        
        while (left <= right) {

            int mid = (left + right)/2;
            if (R_limit < idxs[mid]) {

                right_edge = mid;
                right = mid - 1;

            }
            else left = mid + 1;

        }

        return right_edge - 1;

    }
    
    int query(int left, int right, int value) {
        
        int left_ID = find_left(value_mapping[value], left);
        int right_ID = find_right(value_mapping[value], right);
        
        return (right_ID - left_ID + 1);

    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
