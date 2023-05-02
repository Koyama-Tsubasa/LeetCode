class Solution {
public:
    int countPrimes(int n) {
        
        // parameters
        int prime_cnt = 0;
        std::vector<bool> primes(n, true);

        // start computing (using Sieve of Eratosthenes Method)
        if (n <= 1) return 0;
        for (long long i=2; i<n; i++)
            if (primes[i]) {

                prime_cnt++;
                long long check_multiple = i * i;
                while (check_multiple < n) {

                    primes[check_multiple] = false;
                    check_multiple += i;

                }

            }
        
        return prime_cnt;

    }
};
