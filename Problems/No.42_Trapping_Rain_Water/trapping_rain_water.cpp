class Solution {
public:
    int trap(vector<int>& height) {
        
        // parameters
        int pLeft = 0, pRight = height.size()-1;
        int maxL = height[pLeft++], maxR = height[pRight--];
        int trapped_water = 0;

        // start computing
        if (height.size() <= 2) return 0;
        while (pLeft <= pRight) {

            if (maxL < maxR) {

                if (height[pLeft] > maxL) maxL = height[pLeft];
                else trapped_water += (maxL-height[pLeft]);
                pLeft++;

            }
            else {

                if (height[pRight] > maxR) maxR = height[pRight];
                else trapped_water += (maxR-height[pRight]);
                pRight--;

            }

        }

        return trapped_water;

    }
};
