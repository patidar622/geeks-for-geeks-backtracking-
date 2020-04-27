class Solution {
public:
bool is_parenthesis(char s)
{
    return s=='(' || s==')';
}
bool is_valid(string ss)
    {
        int count=0;
        for(int i=0;i<ss.size();i++)
        {
            if(is_parenthesis(ss[i]))
            {
                if(ss[i]=='(')
                    count++;
                else
                    count--;
            }
            if(count<0)
                return false;
        }
        return count==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        queue<string>q1;
        q1.push(s);
        set<string>s1;
        s1.insert(s);
        vector<string>ans;
        bool flag=false;
        while(!q1.empty())
        {
            string ss=q1.front();
            q1.pop();
            if(is_valid(ss))
            {
                ans.push_back(ss);
                flag=true;
            }
            if(flag)
                continue;
            for(int i=0;i<ss.size();i++)
            {
                if(!is_parenthesis(ss[i]))
                    continue;
                string sw1=ss.substr(0,i)+ss.substr(i+1);
                if(s1.find(sw1)==s1.end())
                {
                    s1.insert(sw1);
                    q1.push(sw1);
                }
            }
        }
        return ans;
    }
};
