class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int>v;
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            v.push_back(it.first);
        }
        for(auto it:v){
           cout<<it<<endl;
        }
        if(v.size()==0){
            return 0;
        }
        if(v.size()==1){
            return 1;
        }
        int ans=INT_MIN;
        int count=0;
        for(int i=1;i<v.size()+1;i++){
            if(i==v.size()){
                ans=max(ans,count);
                break;
            }
            if(v[i-1]+1==v[i]){
                count++;
            }
            else{
                ans=max(ans,count);
                count=0;
            }
            
            
        }
        
        return ans+1;
    }
};