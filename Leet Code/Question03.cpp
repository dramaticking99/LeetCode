class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>substring;
        int length = 0;
        int max = 0;
        int firstIndex = 0 ;
        
        int size = s.size();

        for(int i = 0; i < size; i++){
            char element = s[i];
            if(substring.find(element) == substring.end()){
                substring[element] = i;
                length += 1;
                
            } else {
                if(length>max){
                    max = length;
                }
                while(substring.find(element) != substring.end()){

                    
                    substring.erase(s[firstIndex]);
                    firstIndex += 1;
                    length -= 1;
                }
                substring[element] = i;
                length += 1;
            }
        } if(max<length){
            max = length;
        }
        return max;

        
    }
};
