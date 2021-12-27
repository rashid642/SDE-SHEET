//brute force

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int pre=0;
        while(s!=""){
            int i;
            for(i=0; i<s.length(); i++){
                if(s[i]==' ')break;
            }
            v.push_back(s.substr(0,i));
            while(s[i]==' ' && i<s.length())i++;
            if(i==s.length())break;
            s=s.substr(i,s.length());
        }
        string ans="";
        for(int i=v.size()-1; i>=0; i--){
            ans=ans+v[i]+" ";
        }
        int i=ans.length()-1;
        while(ans[i]==' '){
            ans=ans.substr(0,i);
            i--;
        }
        return ans;
    }
};

//optimized

class Solution {
public:
void reverse(string &s, int i, int j){
    while(i<j){
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
    // cout<<s<<" ";
}
    string reverseWords(string s) {
        int wordcount=0;
        int i=0, j=0;
        int l=0;
        while(true){
            while(s[j]==' ' && j!=s.length())j++;
            if(j==s.length())break;
            if(wordcount!=0){
                s[i]=' ';
                i++;
            }
            l = i;
            while(s[j]!=' ' && j<s.length()){
                s[i++]=s[j++];
            }
            wordcount++;
            reverse(s, l, i-1);
        }
        s = s.substr(0,i);
        reverse(s,0,s.length()-1);
        return s;
    }
};