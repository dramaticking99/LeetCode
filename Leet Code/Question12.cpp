class Solution {

private: 
unordered_map<int,string> romanMap1 = {
    {1, "I"},
    {2, "II"},
    {3, "III"},
    {4, "IV"},
    {5, "V"},
    {6, "VI"},
    {7, "VII"},
    {8, "VIII"},
    {9, "IX"}
};

unordered_map<int,string> romanMap10 = {
    {10, "X"},
    {20, "XX"},
    {30, "XXX"},
    {40, "XL"},
    {50, "L"},
    {60, "LX"},
    {70, "LXX"},
    {80, "LXXX"},
    {90, "XC"}
};
unordered_map<int,string> romanMap100 = {
    {100, "C"},
    {200, "CC"},
    {300, "CCC"},
    {400, "CD"},
    {500, "D"},
    {600, "DC"},
    {700, "DCC"},
    {800, "DCCC"},
    {900, "CM"},
};    
unordered_map<int,string> romanMap1000 = {
    {1000, "M"},
    {2000, "MM"},
    {3000, "MMM"}
};

public:
    string intToRoman(int num) {
        int digits = static_cast<int>(log10(abs(num))) + 1;
        int numLeft = num;
        string workingString;
        string resultString = "";

        for(int i = 0; i < digits; i ++){
            int number = numLeft%10;
            numLeft = numLeft/10;
            int power = pow(10, i);
            string mapName = "romanMap" + to_string(power);
            switch (power) {
                case 1: workingString = romanMap1[number]; break;
                case 10: workingString = romanMap10[number * power]; break;
                case 100: workingString = romanMap100[number * power]; break;
                case 1000: workingString = romanMap1000[number * power]; break;
                default: break;
            }
            resultString = workingString + resultString;
        }

        return resultString;

    }
};
