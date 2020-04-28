class Solution {
public:
    vector<vector<int> >dp;
    bool find_solution(string s,string p,int i,int j)
    {
        if(i==s.size() && j==p.size())
            return true;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int c=0;
        if(s[i]==p[j] || p[j]=='.')
        {
            c=1;
        }
        if(j+1<p.size() && p[j+1]=='*')
        {
            return dp[i][j]=(find_solution(s,p,i,j+2)||(i<s.size() && (c==1) && find_solution(s,p,i+1,j)));
        }
        else
        {
            return dp[i][j]=i<s.size() && c==1 && find_solution(s,p,i+1,j+1);
        }
       
        return dp[i][j]=0;
        
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1,vector<int>(p.size()+1,-1));
        return find_solution(s,p,0,0);
        
    }
};
