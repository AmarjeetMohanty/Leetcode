class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low, high, mid;
        const int size = numbers.size()-1;
        for(int i = 0;i<numbers.size();i++){
            int complement = target-numbers[i];
            low = i+1;
            high = size;
            while(low<=high){
                mid = (low+high)/2;
                if(numbers[mid]==complement) return {i+1,mid+1};
                else if(numbers[mid]>complement) high = mid-1;
                else low = mid + 1;
            }
        }
        return {};
    }
};