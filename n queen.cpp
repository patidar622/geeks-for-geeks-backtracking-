#include<bits/stdc++.h>
using namespace std;
vector<int>ld,rd,cl;
vector<vector<int>>mat;
vector<vector<int>>ans;
void find_way()
{
    vector<int>aa;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[i].size();j++)
        {
            if(mat[i][j]==1)
            aa.push_back(j+1);
    }
    }
    ans.push_back(aa);
}
void find_solution(int col,int n)
{
    if(col==n)
    {
        find_way();
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(ld[i-col+n-1]!=1 && rd[i+col]!=1 && cl[i]!=1)
        {
            ld[i-col+n-1]=1; rd[i+col]=1 ; cl[i]=1;
            mat[i][col]=1;
            find_solution(col+1,n);
            ld[i-col+n-1]=0; rd[i+col]=0 ; cl[i]=0;
            mat[i][col]=0;
        }
    }
    return;
}
int main()
 {
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    mat.resize(n,vector<int>(n,0));
    ld.resize(100,0);
    rd.resize(100,0);cl.resize(100,0);
    find_solution(0,n);
    if(ans.size()>0)
    {
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            cout<<'[';
            for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<']';
            cout<<" ";
        }
        cout<<endl;
    }
    else
    cout<<-1<<endl;
    mat.clear();rd.clear();ld.clear();cl.clear();ans.clear();
}
	return 0;
}
