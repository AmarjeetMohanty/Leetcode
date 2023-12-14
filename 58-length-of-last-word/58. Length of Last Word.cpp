class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;
        int space = 0;
        int flag = 0;
        for(int i = n-1;i>=0;i--){
            if(s[i]==' ' && flag==0) space++;
            else if(s[i]!=' ') flag = 1;
            else if(s[i]==' ' && flag==1) break;
            count++;
        }
        return abs(space-count);
    }
};