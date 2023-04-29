class Solution(object):
    def peopleAwareOfSecret(self, n, delay, forget):
        """
        :type n: int
        :type delay: int
        :type forget: int
        :rtype: int
        """

        # parameters
        additional_people = [0] * n
        who_know_the_secret = 0
        people_alteration = 0
        MOD = int(1e9 + 7)

        # start computing
        # calculate the new secret-shared people in each day
        additional_people[0] = 1
        for i in range(1, n):
            if (i >= delay):
                people_alteration = (people_alteration + additional_people[i-delay])%MOD
            if (i >= forget):
                people_alteration = (people_alteration - additional_people[i-forget] + MOD)%MOD
            additional_people[i] = people_alteration

        # calculate how many people know the secret at the end of day n
        for i in range(n-forget, n):
            who_know_the_secret = (who_know_the_secret + additional_people[i])%MOD
        
        return who_know_the_secret
