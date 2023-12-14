class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        int s = 0;
        int m = INT_MIN;
        for(int i = 0;i<k;i++) s += v[i];
        m = s;
        int i = 0;
        int j = k;
        while(j<v.size()){
            s+=v[j]-v[i];
            if(s>=m) m=s;
            j++;
            i++;
        }
        return (double)m/(double)k;
    }
};