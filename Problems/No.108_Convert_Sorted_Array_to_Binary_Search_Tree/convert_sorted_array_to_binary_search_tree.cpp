/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // make binary search balanced tree
    TreeNode* makeBST(vector<int>& nums, int left_index, int right_index) {
        
        if (left_index > right_index) return NULL;
        else if (left_index == right_index) return new TreeNode(nums[left_index]);
        else {
            
            int mid = (left_index+right_index)/2;
            TreeNode *left = makeBST(nums, left_index, mid - 1);
            TreeNode *right = makeBST(nums, mid + 1, right_index);
            return new TreeNode(nums[mid], left, right);
            
        }
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return makeBST(nums, 0, nums.size()-1);
        
    }
};
