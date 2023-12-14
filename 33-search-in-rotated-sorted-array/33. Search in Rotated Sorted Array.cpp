class Solution {
public:
    int search(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        if(target==nums[start])     return start;
        if(target==nums[end])       return end;
        while(start<end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target)
                return mid; 
            if(nums[start] <= nums[mid])
                (target>=nums[start] && target<nums[mid]) ? end = mid-1 : start = mid+1;
            else
                (target>nums[mid] && target<=nums[end]) ? start = mid+1 : end = mid-1;
        }
        return nums[start] == target ? start : -1;
    }
};