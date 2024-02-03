class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string>result;
        string current;
        generateCombinations(digits, 0, current, result);
        return result;
    }

private:
    void generateCombinations(string digits, int index, string current, vector<string> result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        string letters = digitMap[digit];

        for (char letter : letters) {
            current.push_back(letter);
            generateCombinations(digits, index + 1, current, result);
            current.pop_back();
        }
    }

    const vector<string> digitMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
