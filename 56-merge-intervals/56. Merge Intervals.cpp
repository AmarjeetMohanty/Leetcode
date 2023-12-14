class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());

        for(int i = 1;i<v.size();){
            if(v[i-1][1]>=v[i][0]){
                v[i-1][1] = max(v[i][1],v[i-1][1]);
                v.erase(v.begin()+i);
            }
            else i++;
        }

        return v;
    }
};