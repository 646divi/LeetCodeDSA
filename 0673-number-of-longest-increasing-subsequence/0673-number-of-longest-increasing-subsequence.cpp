class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int maxi=0;
        vector<int>temp(n,1),cnt(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] and 1+temp[j] > temp[i]){
                    temp[i]=1+temp[j];
                    cnt[i]=cnt[j];
                }else if(1+temp[j]==temp[i]){
                    cnt[i]+=cnt[j];
                }
                maxi=max(maxi,temp[i]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(temp[i]==maxi)ans+=cnt[i];
        }
        return ans;
        
        
        
    }
};