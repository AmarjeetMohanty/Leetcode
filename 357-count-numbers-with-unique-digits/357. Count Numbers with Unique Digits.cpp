class Solution { 
public:
    int countNumbersWithUniqueDigits(int n) {
        
        int dpOneBack;
        
        n = min(n, 10);
        dpOneBack = 1;

        for (int i = 1, prod = 1; i <= n; ++i, prod *= (11 - i))
            dpOneBack += (9 * prod);

        return dpOneBack;
    }
};