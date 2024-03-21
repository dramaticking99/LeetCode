class Solution {
public:
    int strStr(string haystack, string needle) {
        int flag = -1;

        int i = 0;
        int j = 0;
        while(i < haystack.size() && j < needle.size()){
            
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == needle.size()){
                    flag = 1;
                    break;
                }
            } else {
                    i = i - j + 1;
                    j = 0;
                   
            }
        }
        if( flag == 1 ){
            return (i - j);
        } else {
            return flag;
        }
    }
};
