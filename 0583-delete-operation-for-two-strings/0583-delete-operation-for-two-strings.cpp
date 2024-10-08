class Solution {
public:
    int minDistance(string s1, string s2){

        int m=s1.size();
        int n=s2.size();

        int dp[m+1][n+1];

        for(int i=0; i<=m||i<=n; i++)
        {
            if(i<=m) dp[i][0]=i;
            if(i<=n) dp[0][i]=i;
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
            }
        }

        return dp[m][n];
    }
};