#include<bits/stdc++.h>
using namespace std;
vector<pair<string,int> >vis;
vector<int>ans;
void find_solution(string s)
{
	for(int i=s.size()-1;i>=0;i--)
	{
		string s1=s.substr(i,s.size()-i);
		vis.push_back({s1,i});
	}
	sort(vis.begin(),vis.end());
	for(int i=0;i<vis.size();i++)
	{
		ans.push_back(vis[i].second);
	}
}
int strncmp11(string s1,string s2)
{
	for(int i=0;i<s2.size();i++)
	{
		if(s1[i]>s2[i])
		return 1;
		else if(s1[i]<s2[i])
		return -1;
	}
	return 0;
}
bool find_search(string s1,string s2)
{
	int i=0,j=s1.size()-1;
	while(i<=j)
	{
		int mid=i+(j-i)/2;
		int res=strncmp11(s1.substr(mid,s1.size()-mid),s2);
		if(res==0)
		return true;
		else if(res<0)
		j=mid-1;
		else
		i=mid+1;
	}
	return false;
}

int main()
{
	string s1,s2;
	cout<<"Enter the first string ::"<<endl;
	cin>>s1;
	cout<<"Enter the string for match:: "<<endl;
	cin>>s2;
	find_solution(s1);
	if(find_search(s1,s2))
	   cout<<"string found"<<endl;
	   else
	   cout<<"string not found"<<endl;
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	cout<<endl;
}
