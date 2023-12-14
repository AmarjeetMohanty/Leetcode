class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        lis.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++){
            int in = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            if(in>=lis.size())lis.push_back(nums[i]);
            else lis[in] = nums[i]; 
        }
        return lis.size();
    }
};