class Solution {
public:
    int m = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {

        vector<vector<int>> memo(n+1,vector<int>(target+1,-1));
        
        return rolls(n,k,target,memo);
    }

    int rolls(int n, int k, int target, vector<vector<int>>& memo){

        if(target<0){
            return 0;
        }

        if(n==0 && target==0){
            return 1;
        }

        if(n<0){
            return 0;
        }

        if(memo[n][target]!=-1){
            return memo[n][target];
        }


        int no=0;

        for(int i=1;i<=k;i++){

            int r = rolls(n-1,k,target-i,memo);
            no = (no%m + r%m)%m;

        }


        memo[n][target] = no%m;

        return (no%m);
    }
};