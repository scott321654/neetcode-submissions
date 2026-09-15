class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i = 0;
        uint32_t j = 0; 
        while (j <32) {
            i <<= 1;
            i |= (n & 1);
            n >>= 1;
            j++;
        }

        return i;
    }
};
