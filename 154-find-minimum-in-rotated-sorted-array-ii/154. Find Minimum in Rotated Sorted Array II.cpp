class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int ans = nums[0];

        if(nums[low]<nums[high]) return nums[low];
        
        while(low<=high){
            if(nums[low]<nums[high]){
                ans = min(ans,nums[low]);
                break;
            }
            int mid = (low+high)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid]>nums[low]) low = mid+1;
            else if(nums[mid]<nums[high]) high = mid-1;
            else{
                if(nums[low]==nums[mid]) low++;
                else high--;
            }
        }
        return ans;
    }
};