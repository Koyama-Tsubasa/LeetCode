class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {

        long long left=0, right;
        int min_rank=100, max_rank=0;

        for (int rank: ranks) {
            min_rank = min(min_rank, rank);
            max_rank = max(max_rank, rank);
        }
        right = min_rank * pow(cars, 2);

        vector<int> rank_nums(max_rank + 1);
        for (int rank: ranks) rank_nums[rank] += 1;
        
        long long car_repaired, mid;
        while (left < right) {

            car_repaired = 0;
            mid = (left + right) >> 1;

            for (size_t rank=1; rank<=max_rank; rank++ )
                car_repaired += rank_nums[rank] * (long long)sqrt(mid/rank);

            if (car_repaired >= cars) right = mid;
            else left = mid + 1;

        }

        return right;
  
    }
};
