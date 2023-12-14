class Solution {
public:
    string reverseVowels(string s) {
        if(s==" ") return s;
        int n = size(s);
        stack<char> idx;
        for(int i = 0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') {
                idx.push(s[i]);
                s[i]=-1;
            }
        }
        for(int i = 0;i<n;i++){
            if(s[i]==-1){
                s[i]=idx.top();
                idx.pop();
            }
        }
        return s;
    }
};