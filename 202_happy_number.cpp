class Solution {
public:
    bool isHappy(int n) {

        // We need to loop through the digits
        int curr = n;

        for (int i = 0; i < 9999; i++) {
            int sum = 0;

            while (curr > 0) {
                sum += pow(curr % 10, 2);
                curr /= 10;
            }

            if (sum == 1) {
                return true;
            }

            curr = sum;
        }

        return false;
    }
};