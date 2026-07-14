class Solution {
public:

    map<pair<int,int>,bool> dp;

    bool solve(vector<int>& stones,int index,int lastJump){

        if(index==stones.size()-1)
            return true;

        if(dp.count({index,lastJump}))
            return dp[{index,lastJump}];

        for(int next=index+1;next<stones.size();next++){

            int jump=stones[next]-stones[index];

            if(jump<lastJump-1)
                continue;

            if(jump>lastJump+1)
                break;

            if(solve(stones,next,jump))
                return dp[{index,lastJump}]=true;
        }

        return dp[{index,lastJump}]=false;
    }

    bool canCross(vector<int>& stones){

        return solve(stones,0,0);

    }
};