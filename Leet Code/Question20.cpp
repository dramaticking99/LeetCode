class Solution {
public:
    bool isValid(string s) {
        //creating a stack of characters which are going to be brackets
        stack<char>myStack;
        
        for(int i = 0; i < s.size(); i++){
            char bracket = s[i];
            if( bracket == '(' || bracket == '[' || bracket == '{' ){
                myStack.push(bracket);
            }
            if( bracket == ')' || bracket == ']' || bracket == '}'){
                if(myStack.empty()){
                    return false;
                }
                char fromStack = myStack.top();
                myStack.pop();

                if(bracket == ')' && fromStack != '(' ||
                   bracket == ']' && fromStack != '[' ||
                   bracket == '}' && fromStack != '{')  {
                     return false;
                 }
            }
        }

        if(!myStack.empty()){
            return false;
        } 

        return true;
    }
};
