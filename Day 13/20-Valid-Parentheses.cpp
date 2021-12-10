class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' ||s[i]=='[' ||s[i]=='{'){
                st.push(s[i]);
            }
            
            else{
                if(st.empty()){
                     return false;
                 }
                char ch=st.top();
                switch(ch){
                    case '(':if(s[i]==')'){
                        st.pop();
                        break;
                    }
                    else{
                        return false;
                    }
                    case '[':if(s[i]==']'){
                        st.pop();
                        break;
                    }
                    else{
                        return false;
                    }
                    case '{':if(s[i]=='}'){
                        st.pop();
                        break;
                    }
                    else{
                        return false;
                    }
                    default: return false;    
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};