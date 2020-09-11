class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        int i, n=timeSeries.size();
        int previous=-1;
        
        for(i=0;i<n;i++){
            if(previous<=timeSeries[i]){
                ans= ans+duration;
            }
            else{
                ans= ans+(timeSeries[i]+duration-previous);
            }
            previous= timeSeries[i]+duration;
        }
        
        return ans;
    }
};
