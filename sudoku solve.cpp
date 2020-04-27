#include<bits/stdc++.h>
using namespace std;
bool find_empty(vector<vector<int> >&dp)
{
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            if(dp[i][j]==0)
            return true;
        }
    }
    return false;
}
bool find_row(vector<vector<int> >&dp,int row,int num)
{
    for(int i=0;i<9;i++)
    {
        if(dp[row][i]==num)
        return true;
    }
    return false;
}
bool find_col(vector<vector<int> >&dp,int col,int num)
{
    for(int i=0;i<9;i++)
    {
        if(dp[i][col]==num)
        return true;
    }
    return false;
}
bool find_block(vector<vector<int> >&dp,int rs,int cs,int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(dp[i+rs][j+cs]==num)
            return true;
        }
    }
    return false;
}
bool is_safe(vector<vector<int> >& dp,vector<pair<int,int> >v,int i,int num)
{
    return (!find_row(dp,v[i].first,num)) && (!find_col(dp,v[i].second,num)) && (!find_block(dp,v[i].first-(v[i].first)%3,v[i].second-(v[i].second)%3,num)) && (dp[v[i].first][v[i].second]==0);
}
bool find_solution(vector<vector<int> >& dp,vector<pair<int,int> >v,int i)
{
    if(!find_empty(dp))
    {
        return true;
    }
    
    
    for(int num=1;num<=9;num++)
    {
        if(is_safe(dp,v,i,num))
        {
            dp[v[i].first][v[i].second]=num;
            if(find_solution(dp,v,i+1))
            return true;
            dp[v[i].first][v[i].second]=0;
        }
    }
    return false;
}
int main()
 {
     int t;cin>>t;
     while(t--)
     {
         vector<vector<int> >dp(9,vector<int>(9,0));
         vector<pair<int,int> >v;
         for(int i=0;i<9;i++)
         {
             for(int j=0;j<9;j++)
             {
                 int x;
                 cin>>x;
                 if(x==0)
                 v.push_back({i,j});
                 dp[i][j]=x;
             }
         }
         find_solution(dp,v,0);
         for(int i=0;i<dp.size();i++)
         {
             for(int j=0;j<dp[0].size();j++)
             {
                 cout<<dp[i][j]<<" ";
             }
         }   
        cout<<endl;
        dp.clear();
     }
	return 0;
}                                            
