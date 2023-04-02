class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        // parameter
        std::priority_queue<int> GiftPiles;
        long long remaining_gifts = 0;

        // start computing
        for (auto &initial_gift: gifts) GiftPiles.push(initial_gift);
        for (int i=0; i<k; i++) {
            
            auto gift = std::sqrt(GiftPiles.top());
            GiftPiles.pop();
            GiftPiles.push(gift);

        }
        while (!GiftPiles.empty()) {

            remaining_gifts += GiftPiles.top();
            GiftPiles.pop();

        }

        return remaining_gifts;

    }
};
