#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >m1;
vector<int>vis;
bool visited()
{
    for(int i=1;i<vis.size();i++)
    {
        if(vis[i]==0)
        return true;
    }
    return false;
}
bool find_solution(int i)
{
    if(!visited())
    return true;
    
    for(int i1=0;i1<m1[i].size();i1++)
    {
        if(vis[m1[i][i1]]==0)
        {
            vis[m1[i][i1]]=1;
            if(find_solution(m1[i][i1]))
                return true;
            vis[m1[i][i1]]=0;
        }
    }
    return false;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    for(int i=0;i<m;i++)
	    {
	        int n1,n2;
	        cin>>n1>>n2;
	        m1[n1].push_back(n2);
	        m1[n2].push_back(n1);
	    }
	    int ans=m1[1].size(),i1=1;;
	   for(auto i:m1)
	    {
	        if(ans>i.second.size())
	     {   ans=i.second.size();
	        i1=i.first;
	    }
	    }
        vis.resize(n+1,0);
	    vis[i1]=1;
	    if(find_solution(i1))
	    cout<<1<<endl;
	    else
	    cout<<0<<endl;
	    vis.clear();
	    m1.clear();
	}
	
	return 0;
}
