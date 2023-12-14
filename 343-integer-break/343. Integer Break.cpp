class Solution {
public:
    int integerBreak(int n) {
        if(n<4) return n-1;

        int num = n/3;
        long long product = pow(3, num);
        if(n%3 == 1){
            product /= 3;
            product *= 4;
        }
        else if(n%3==2) product *= 2;
        return product;
    }
};