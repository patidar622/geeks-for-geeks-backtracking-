#include<bits/stdc++.h>
using namespace std;
set<string>s;
set<int>s1;
vector<string>ans;
void find_solution(string ss,int i,string s3)
{
    if(i>=ss.size())
    {
        ans.push_back(s3);
        return;
    }
    
    for(auto i1:s1)
    {
        string sw;
      if(i+i1<=ss.size()){
         sw=ss.substr(i,i1);
        if(s.find(sw)!=s.end())
        {
            string oe=s3;
            if(i!=0)
            s3.append(1,' ');
            s3.append(sw);
            find_solution(ss,i+i1,s3);
            s3=oe;
        }
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
        for(int i=0;i<n;i++)
        {
            string s2;
            cin>>s2;
            s.insert(s2);
            int n1=s2.size();
            s1.insert(n1);
        }
        string ss;
        cin>>ss;
        string s3="";
        find_solution(ss,0,s3);
        for(int i=0;i<ans.size();i++)
    {
        cout<<'(';
        cout<<ans[i];
        cout<<')';
    }
    cout<<endl;
    s3.clear();
    ans.clear();
    s1.clear();s.clear();
    }
	return 0;
}
