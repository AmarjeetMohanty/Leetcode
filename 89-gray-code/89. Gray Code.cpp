class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> p = {0,1};
        n--;
        int prod = 1;
        while(n>0){
            prod = prod*2;
            for(int i = p.size()-1; i>-1; i--) p.emplace_back(p[i]+prod);
            n--;
        }
        return p;
    }
};