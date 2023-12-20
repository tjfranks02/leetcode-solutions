/**
 * Flowerbed is a binary array, 0 means empty, 1 means planted.
 * 
 * We can iterate through the array and check if the previous, current, and next. If all are 0, we 
 * can plant a flower.
 * 
 * Got this one myself. Was surprisingly difficult! Seems pretty slow though.
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int n_spots = flowerbed.size();
        
        int prev = 0;
        int i = 0;

        while (i < n_spots && n > 0) {
            int curr = flowerbed[i];
            int next = i == n_spots - 1 ? 0 : flowerbed[i + 1];

            if (prev == 0 && curr == 0 && next == 0) {
                n--;
                curr = 1;
            }

            prev = curr;
            i++;
        }

        return n == 0;
    }
};