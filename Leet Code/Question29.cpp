class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge cases
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // Overflow case
        
        // Determine the sign of the quotient
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        // Convert both dividend and divisor to their absolute values
        long long absDividend = labs((long long)dividend);
        long long absDivisor = labs((long long)divisor);
        
        long long result = 0;
        while (absDividend >= absDivisor) {
            long long temp = absDivisor, shifts = 1;
            while ((temp << 1) <= absDividend) {
                temp <<= 1;
                shifts <<= 1;
            }
            result += shifts;
            absDividend -= temp;
        }
        
        return sign * result;
    }
};
