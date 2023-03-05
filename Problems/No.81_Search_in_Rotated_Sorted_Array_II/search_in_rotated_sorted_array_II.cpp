class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        // parameters
        int left = 0, right = nums.size()-1;
        int mid;

        // start computing (use Binary Search like algorithm)
        while (left <= right) {

            mid = left + (right-left)/2;

            if (nums[mid] == target) return true;
            else if ((nums[left] == nums[mid]) && (nums[mid] == nums[right])) {

                left++;
                right--;

            }
            else if (nums[left] <= nums[mid]) {

                if ((nums[left] <= target) && (target < nums[mid])) right = mid - 1;
                else left = mid + 1;

            }
            else {

                if ((nums[mid] < target) && (target <= nums[right])) left = mid + 1;
                else right = mid - 1;

            }

        }

        return false;

    }
};
