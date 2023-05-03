class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {

        // parameters
        int cnt = 0;
        int arr_size = arr.size();

        // start computing
        for (int i=0; i<arr_size-2; i++)
            for (int j=i+1; j<arr_size-1; j++)
                if (abs(arr[i]-arr[j]) <= a)
                    for (int k=j+1; k<arr_size; k++)
                        if ((abs(arr[j]-arr[k]) <= b) &&
                            (abs(arr[i]-arr[k]) <= c))
                            cnt++;
        
        return cnt;

    }
};
