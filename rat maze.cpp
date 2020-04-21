vector<vector<int>>vis;
set<string>dd;
map<char,pair<int,int>>m1;
void find_solution(int m[MAX][MAX],int i,int j,string s,int n)
{
    if(i==n-1 && j==n-1)
       {
           dd.insert(s);
           return;
       }
       vis[i][j]=1;
       for(auto i1:m1)
       {
           int new_r=i+i1.second.first;
           int new_c=j+i1.second.second;
           if(new_r>=0 && new_r<n && new_c>=0 && new_c<n && vis[new_r][new_c]==-1 && m[new_r][new_c]==1)
           {
               s.append(1,i1.first);
               find_solution(m,new_r,new_c,s,n);
               s.pop_back();
           }
       }
       vis[i][j]=-1;
       return;
}
vector<string> printPath(int m[MAX][MAX], int n)
{
vector<string>dp;
if(m[0][0]==0)
return dp;
    vis.resize(n,vector<int>(n,-1));
    string s="";
    m1['U']={-1,0};
    m1['D']={1,0};
    m1['L']={0,-1};
    m1['R']={0,1};
    find_solution(m,0,0,s,n);
    
    if(dd.size()>0){
    for(auto i:dd)
    {
        dp.push_back(i);
    }
    }
    dd.clear();
    m1.clear();
    vis.clear();
    return dp;
	// Your code goes here 
}
