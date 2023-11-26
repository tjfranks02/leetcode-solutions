class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;

        for (int i = 0; i < 32; i++) {
            uint32_t mask = pow(2, i);

            if ((n & mask) == mask) {
                reversed += pow(2, 31 - i);
            }
        }

        return reversed;
    }
};