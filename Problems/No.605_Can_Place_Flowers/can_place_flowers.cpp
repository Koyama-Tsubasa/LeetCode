class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        // parameter
        bool planted;
        int FbedSize = flowerbed.size();

        // start computing
        if (n == 0) return true;
        else {

            for (int i=0; i<FbedSize; i++) {
                
                if (!flowerbed[i] && 
                    (((i == 0) || !flowerbed[i-1]) && 
                    ((i == FbedSize-1) || !flowerbed[i+1]))) {
                    
                    flowerbed[i] = 1;
                    n--;

                    if (n == 0) return true;

                }

            }

        }

        return false;

    }
};
