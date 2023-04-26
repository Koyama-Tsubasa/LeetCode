class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        // parameters
        std::vector<int> ReorderedDeck(deck.size(), 0);
        std::queue<int> increasing_deck_idx;

        // start computing
        std::sort(deck.begin(), deck.end());
        for (int i=0; i<deck.size(); i++) increasing_deck_idx.push(i);

        for (auto &card: deck) {

            ReorderedDeck[increasing_deck_idx.front()] = card;
            increasing_deck_idx.pop();
            increasing_deck_idx.push(increasing_deck_idx.front());
            increasing_deck_idx.pop();

        }

        return ReorderedDeck;

    }
};
