class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)return 0;
        int n=nums.size();
        int cnt=0;
        int prod=1;
        int i=0,j=0;
        while(j<n){
            prod*=nums[j];
            while(i<=j and prod>=k){
                prod/=nums[i];
                i++;
            }
            cnt+=(j - i + 1);
            j++;
        }
        return cnt;
    }
};