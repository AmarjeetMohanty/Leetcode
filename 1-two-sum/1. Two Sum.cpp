#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the complement is present in the hash map
            if (hash.find(complement) != hash.end()) {
                // Add the indices to the result vector
                result.push_back(hash[complement]);
                result.push_back(i);
                break;
            }

            // Insert the current element and its index into the hash map
            hash[nums[i]] = i;
        }

        return result;
    }
};