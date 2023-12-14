class Solution {
public:
    vector<string> ans;
    void back(string &s, string temp, int idx, int dig_cnt){
        if(dig_cnt>4) return ;
        if(dig_cnt==4 && idx >= s.length()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int i = 1; i<=3 && idx+i<=s.length(); i++){
            string num = s.substr(idx,i);
            if(num[0]=='0' && i != 1) break;
            else if(stol(num)<=255){
                back(s,temp+s.substr(idx,i)+".", idx+i, dig_cnt+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        back(s,"",0,0);
        return ans;
    }
};