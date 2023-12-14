class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       sort(nums.begin(), nums.end());

       nums.erase(unique(nums.begin(),nums.end()), nums.end());
       int n = nums.size();
       int k = 1;
       for (int i = 0; i<n; ){
           if(nums[i] <= 0){
               i++;
           }
           else{
               if(nums[i] != k){
                   return k;
               }else {
                   i++;
                   k++;
               }
           }
       }
       return k;
    }
};