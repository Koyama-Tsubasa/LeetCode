class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """

        # parameter
        primes = [True] * n

        # start computing (using Sieve of Eratosthenes Method)
        if (n <= 1):
            return 0

        primes[0] = primes[1] = False
        for i in range(2, int(math.sqrt(n))+1):
            if primes[i]:
                for check_multiple in range(i*i, n, i):
                    primes[check_multiple] = False
        
        return sum(primes)
