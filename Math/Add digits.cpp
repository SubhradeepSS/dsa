// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

int addDigits(int num) {
        return (num?1+(num-1)%9:0);
}

int addDigits(int num) {
     if(num==0)
      return num;
     return (num%9?num%9:9);
}
