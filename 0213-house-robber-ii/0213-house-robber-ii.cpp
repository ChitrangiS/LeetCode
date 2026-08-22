class Solution {
public:
    int solve(int start,vector<int>& nums,int end){
        //ans from prev house
        int prev1=0;
        //ans from two house before
        int prev2=0;
        for(int i=start;i<=end;i++){
            int take=nums[i]+prev2;
            int nottake=prev1;

            int curr=max(take,nottake);

            //prev ko forward
            prev2=prev1;
            prev1=curr;
            
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int case1=solve(0,nums,n-2);
        int case2=solve(1,nums,n-1);
        
        return max(case1,case2);
    }
};