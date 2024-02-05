class Solution {

private:
    unordered_map<char,int>value = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };    
public:
    int romanToInt(string s) {
        int num;
        for(int i = size(s) - 1; i >= 0; i--){

            if(i == size(s) - 1){
                num = value[s[i]];
            }else if (value[s[i]] >= value[s[i+1]]){
                num = num + value[s[i]];
            } else {
                num = num - value[s[i]];
            }
        }
        return num;
    }
};
