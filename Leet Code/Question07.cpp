class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }

        // Convert to string for easy manipulation
        std::string numStr = std::to_string(x);

        // Handle negative sign
        bool isNegative = (numStr[0] == '-');
        if (isNegative) {
            numStr = numStr.substr(1);  // Remove the negative sign
        }

        // Reverse the string
        std::reverse(numStr.begin(), numStr.end());

        // Remove leading zeros
        int i = 0;
        while (numStr[i] == '0') {
            i++;
        }
        numStr = numStr.substr(i);

        // Convert back to integer and check for overflow
        long long reversedNum = stoll(numStr);

        if (reversedNum > numeric_limits<int>::max() || reversedNum <   numeric_limits<int>::min()) {
            return 0;
        }

        // Add back the negative sign if applicable
        return isNegative ? static_cast<int>(-reversedNum) : static_cast<int>(reversedNum);
    }
};
