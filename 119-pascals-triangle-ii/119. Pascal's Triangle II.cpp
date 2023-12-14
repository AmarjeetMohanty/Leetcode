class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int>res;
      long long factor = 1 ;
      for(int i = 0 ; i <= rowIndex ; i++){
        res.push_back(factor);
        factor = factor * (rowIndex - i)/(i+1);
      }
      return res;

    }
};