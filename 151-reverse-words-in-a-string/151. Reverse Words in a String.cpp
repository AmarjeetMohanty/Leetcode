class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        int size = s.size();
        int i = size-1;
        int j = size-1;
        while(i >= 0){
            if(s[i]==' '){
                while(s[i]==' '){
                    i--;
                    if(i<0) return ret;
                }
                if(ret != "" ) ret += ' ';
                j=i;
            }
            if(s[i]!=' '){
                while(s[i] != ' '){
                    i--;
                    if(i<0) break;
                }
                ret += s.substr(i+1,j-i);
                j=i;
            }
        }
        return ret;
    }
};