class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end());
      vector<vector<int>>result;
        for(int i=0;i<intervals.size();i++){
            int currStart=intervals[i][0];
            int currEnd=intervals[i][1];
            if(result.size()==0){
                result.push_back(intervals[i]);
            }
            else{
                int lastIndex=result.size()-1;
                int prevEnd=result[lastIndex][1];
                if(currStart<=prevEnd){
                    result[lastIndex][1]=max(prevEnd,currEnd);

                }
                else{
                    result.push_back(intervals[i]);
                }
            }
        }
        return result;
    
    }
};