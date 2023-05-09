class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len=1;
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                len++;
                temp.push_back(nums[i]);
            }else{
                auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
                *it=nums[i];
            }
        }
        if(len>=3)return true;
        else return false;
    }
};