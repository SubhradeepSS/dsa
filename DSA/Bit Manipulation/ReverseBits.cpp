 uint32_t reverseBits(uint32_t n) {
        uint32_t rev=0;
        int i=31;
        while(i>=0){
            rev=rev|(1&n)<<i;
            n>>=1;
            i--;
        }
        return rev;
    }
