class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        // parameters
        std::vector<long long> additional_people(n, 0);
        long long who_know_the_secret = 0;
        long long people_alteration = 0;
        static const int MOD = 1e9 + 7;

        // start computing
        // calculate the new secret-shared people in each day
        additional_people[0] = 1;
        for (int i=1; i<n; i++) {

            if (i >= delay) 
                people_alteration = (people_alteration + additional_people[i-delay])%MOD;
            if (i >= forget) 
                people_alteration = (people_alteration - additional_people[i-forget] + MOD)%MOD;

            additional_people[i] = people_alteration;

        }

        // calculate how many people know the secret at the end of day n
        for (int i=n-forget; i<n; i++) 
            who_know_the_secret = (who_know_the_secret + additional_people[i])%MOD;
        
        return who_know_the_secret;

    }
};
