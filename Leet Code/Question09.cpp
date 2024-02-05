class Solution {
public:
    bool isPalindrome(int x) {
        //convert the integer to string
        string s = to_string(x);
        //reverse the string 
        string revS = s;
        reverse(revS.begin(), revS.end());
        //check for palindrom
        if(s == revS){
            return true;
        } else{
            return false;
        }
    }
};
