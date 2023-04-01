class Solution(object):
    def maxProfit(self, inventory, orders):
        """
        :type inventory: List[int]
        :type orders: int
        :rtype: int
        """

        # reference:
        # https://leetcode.com/problems/sell-diminishing-valued-colored-balls/solutions/1557501/python-explained-with-diagram/

        # parameters
        total_value = 0
        MOD = int(1e9 + 7)
        Colored_balls = []
        count_values = {}

        # start computing
        # compute the initial value of each balls
        for balls in inventory:
            count_values[balls] = count_values.get(balls, 0) + 1
        for [ball_value, count] in count_values.items():
            heapq.heappush(Colored_balls, [(-1)*ball_value, count])

        # start selling the balls
        while orders:
            [curr_value, curr_count] = heapq.heappop(Colored_balls)
            if Colored_balls:
                [next_value, next_count] = heapq.heappop(Colored_balls)
            else:
                next_value, next_count = 0, 0
            
            if ((next_value-curr_value)*curr_count <= orders):
                total_value += ((abs(curr_value+next_value)+1)*(next_value-curr_value)//2)*curr_count
                orders -= (next_value-curr_value)*curr_count
                heapq.heappush(Colored_balls, [next_value, next_count+curr_count])

            else:
                complete_row_of_values = orders // curr_count
                remaining_row_of_values = orders % curr_count
                
                total_value += ((2*abs(curr_value)-complete_row_of_values+1)*complete_row_of_values//2*curr_count)
                total_value += (abs(curr_value)-complete_row_of_values)*remaining_row_of_values
                break
                
        return int(total_value % MOD)
