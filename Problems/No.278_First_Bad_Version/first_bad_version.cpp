// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        // parameters
        int early = 1, late = n, mid;
        int latest;

        // start computing
        while (early <= late) {

            mid = early + (late-early)/2;
            if (isBadVersion(mid)) {

                late = mid - 1;
                latest = mid;

            }
            else early = mid + 1;

        }

        return latest;

    }
};
