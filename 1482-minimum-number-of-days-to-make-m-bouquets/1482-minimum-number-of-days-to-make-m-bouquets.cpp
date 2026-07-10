class Solution {
public:
    int ispossible(vector<int>& bloomDay, int day,int m, int k){
        int cnt=0;//consecutive 
        int bouq=0;

        for(int x:bloomDay){
            if(x<=day){
                cnt++;
            }
            else{
                //no consecutive
                bouq+=cnt/k;
                cnt=0;//reset
            }
        }
        bouq+=cnt/k;
        return bouq>=m;//true return agar m se jyada hoga
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long req=1LL*m*k;

        if(req>bloomDay.size()){
            return -1;
        }
        //min possible
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(bloomDay,mid,m,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};