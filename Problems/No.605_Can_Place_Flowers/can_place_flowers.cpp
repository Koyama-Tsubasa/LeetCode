class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        // start computing
        if (n == 0) return true;
        else {

            for (int i=0; i<flowerbed.size(); i++) {
                
                if (!flowerbed[i] && 
                    (((i == 0) || !flowerbed[i-1]) && 
                    ((i == flowerbed.size()-1) || !flowerbed[i+1]))) {
                    
                    flowerbed[i] = 1;
                    n--;

                    if (n == 0) return true;

                }

            }

        }

        return false;

    }
};
