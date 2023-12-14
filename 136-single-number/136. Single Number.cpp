class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freqMap;
        int ans ;
        for(int num:nums){
            freqMap[num]++;
        }
        for(const auto& pair : freqMap){
            if(pair.second==1) ans = pair.first;
        }
        return ans;
    }
};