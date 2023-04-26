class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """

        # parameters
        ReorderedDeck = [0] * len(deck)
        increasing_deck_idx = range(len(deck))
        
        # start computing
        deck.sort()
        for card in deck:
            ReorderedDeck[increasing_deck_idx[0]] = card
            increasing_deck_idx.pop(0)
            if increasing_deck_idx:
                increasing_deck_idx.append(increasing_deck_idx.pop(0))

        return ReorderedDeck
