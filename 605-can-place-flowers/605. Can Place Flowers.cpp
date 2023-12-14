class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int k=flowerbed.size();
        int ct=0;
        for(int i=0;i<k;i++)
        {
            if(i==(k-1))
            {
                if(flowerbed[i]==1)
                i++;
               else if(k>1 && flowerbed[i-1]!=1)
               {
                ct++;
                i++;
               }
               else if(k>1)
                   i++;
               else
               {
                   ct++;
                   i++;
               }
            }
          else if(flowerbed[i]==1)
                i++;
        else if(flowerbed[i]!=1 && (flowerbed[i+1]==1) && i!=(k-1))
                i=i+2;
            else
            {
                ct++;
                i++;
            }

           
        }
        if(ct>=n)
        return true;
        else
        return false;
    }
};