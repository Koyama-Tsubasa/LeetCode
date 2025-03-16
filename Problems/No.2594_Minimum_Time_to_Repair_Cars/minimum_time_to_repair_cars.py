class Solution(object):
    def repairCars(self, ranks, cars):
        """
        :type ranks: List[int]
        :type cars: int
        :rtype: int
        """
        
        min_rank, max_rank = 100, 0
        for rank in ranks:
            min_rank = min(min_rank, rank)
            max_rank = max(max_rank, rank)
        
        left, right = 0, min_rank*(cars**2)

        rank_nums = [0]*(max_rank + 1)
        for rank in ranks:
            rank_nums[rank] += 1

        while left < right:
            car_repaired, mid = 0, (left + right)//2
            for rank in range(1, max_rank+1):
                car_repaired += rank_nums[rank] * int((mid/rank)**0.5)
            
            if car_repaired >= cars:
                right = mid
            else:
                left = mid + 1
    
        return right
