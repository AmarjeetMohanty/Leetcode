class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i, j, sum, minlen = n+1;
        i=j=sum = 0;
        while(j<n){
            sum += nums[j];

            while(i<= j && sum >= target){
                minlen = min(minlen, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;

        } 
        return (minlen==n+1 ? 0: minlen);
    }
};