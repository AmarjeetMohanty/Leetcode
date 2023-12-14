class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0, mid = 0, in = 0;
        for(int i = 0; i<n; i++){
            total += gas[i]-cost[i];
            mid += gas[i]-cost[i];
            if(mid<0){
                mid = 0;
                in = i+1;
            }
        }
        if(total<0) return -1;
        else return in;
    }
};