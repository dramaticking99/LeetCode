class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        char* o = new char[len + 1]; 

        int index = 0;
        int l = numRows + (numRows-2);

        if(numRows == 1){
            return s;
        }
        


        for(int i = 0; i < numRows;i++){
            for(int j = i; j < len; j = j + l){
                o[index] = s[j];
                index++;
            
            if (i>0&&i< numRows- 1 && j + l - 2 * i < len){
                o[index] = s[j + l - 2 * i];
                index++;
            }
            }
        }
        o[len] = '\0';

        string result(o);

        delete[] o;
        return result;

        
    
}
    };
