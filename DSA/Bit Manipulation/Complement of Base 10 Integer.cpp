/* For a given number N in base-10, return the complement of it's binary representation as a base-10 integer.
Example:

Input: 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10. */

class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        int bit_length=log2(N)+1;
        int to_xor=pow(2,bit_l)-1;
        return to_xor^N;
    }
};
