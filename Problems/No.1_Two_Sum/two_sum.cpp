class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // if first two sums are the solution
        if ((nums[0]+nums[1]) == target) {
            vector<int> solution = {0, 1};
            return solution;
        }
        else {
            int i;
            vector<int> vector_find = {nums[0], nums[1]};   // create a vector to save elements before index i
            vector<int>::iterator it;   // an iterator to find element in vector_find
            for (i=2; i<nums.size(); i++) {
                it = find(vector_find.begin(), vector_find.end(), target-nums[i]);
                if (it != vector_find.end()) break;
                else vector_find.push_back(nums[i]);    // add element of index i into vector_find
            }
            int find_solution = distance(vector_find.begin(), it);  // calculate the distance between index 0 and it
            vector<int> solution = {i, find_solution};
            return solution;
        }
    }
};
