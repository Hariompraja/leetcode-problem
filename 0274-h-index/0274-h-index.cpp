class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end());

        for(int i = 0; i < citations.size(); i++){

            int h = citations.size() - i; // Or you can write h = n - 1;
            if(citations[i] >= h){
                return h;
            }
        }
        return 0;
    }
};