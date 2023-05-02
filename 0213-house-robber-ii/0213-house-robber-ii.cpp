class Solution {
public:
    int solve(vector<int>& nums){
        int n=nums.size();
        int prev=nums[0],prev2=0;
        for(int i=1;i<n;i++){
            int curr=max((nums[i]+prev2),(prev+0));
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>t1,t2;
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)t1.push_back(nums[i]);
            if(i!=n-1)t2.push_back(nums[i]);
        }
        return max(solve(t1),solve(t2));
    }
};