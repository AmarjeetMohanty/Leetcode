class Solution {
public:
    int compress(vector<char>& chars) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(chars.size()==1){
            return 1;
        }
        string s = "";
        for(int i = 0;i<chars.size();i++){
            char x = chars[i];
            s+=x;
            int count = 1;
            while(i<chars.size()-1 &&  x == chars[i+1]){
                count++;
                i++;
            }
            // i--;
            if(count>1){
                s+= to_string(count);
            }
        }
        chars.clear();
        for(int i=0;i<s.size();i++){
            chars.push_back(s[i]);
        }
        return chars.size();
    }
};