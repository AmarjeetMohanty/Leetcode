class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groupsofpeople;
        map<int, vector<int>> groupMap;
        for(int i = 0;i<groupSizes.size();i++){
            int desired = groupSizes[i];
            groupMap[desired].push_back(i);
            if(groupMap[desired].size()==desired){
                groupsofpeople.push_back(groupMap[desired]);
                groupMap[desired].clear();
            }
        }
        return groupsofpeople;
    }
};