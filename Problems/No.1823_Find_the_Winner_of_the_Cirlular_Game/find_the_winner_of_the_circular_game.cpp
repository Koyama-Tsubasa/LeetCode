class Solution {
public:
    int findTheWinner(int n, int k) {
        
        // parameter
        std::queue<int> friends;

        // start computing
        for (int i=1; i<=n; i++) friends.push(i);
        while (friends.size() > 1) {

            for (int cnt=1; cnt<k; cnt++) {

                friends.push(friends.front());
                friends.pop();

            }
            friends.pop();

        }

        return friends.front();

    }
};
