class RangeFreqQuery {

private:
    std::unordered_map<int, std::vector<int>> value_mapping;

public:
    RangeFreqQuery(vector<int>& arr) {

        for (int i=0; i<arr.size(); i++)
            value_mapping[arr[i]].push_back(i);
        
    }

    int find_low(std::vector<int> &idxs, int low_limit) {

        int low = -1;
        int left = 0, right = idxs.size()-1;
        
        while (left <= right) {

            int mid = (left + right)/2;
            if (idxs[mid] < low_limit) {

                low = mid;
                left = mid + 1;

            }
            else right = mid - 1;

        }

        return low + 1;

    }

    int find_high(std::vector<int> &idxs, int high_limit) {

        int high = idxs.size();
        int left = 0, right = idxs.size()-1;
        
        while (left <= right) {

            int mid = (left + right)/2;
            if (high_limit < idxs[mid]) {

                high = mid;
                right = mid - 1;

            }
            else left = mid + 1;

        }

        return high - 1;

    }
    
    int query(int left, int right, int value) {
        
        int lower_ID = find_low(value_mapping[value], left);
        int higher_ID = find_high(value_mapping[value], right);
        
        return (higher_ID - lower_ID + 1);

    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
