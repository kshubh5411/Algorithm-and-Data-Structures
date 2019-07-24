/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
**/
void generate(vector<string>&ans,char *s,int A,int cp,int op,int idx)
{
    if(idx==2*A)
    {
        s[idx]='\0';
        ans.push_back(s);
        return;
    }
    if(op<A)
    {
        s[idx]='(';
        generate(ans,s,A,cp,op+1,idx+1);
    }
    if(cp<op)
    {
        s[idx]=')';
        generate(ans,s,A,cp+1,op,idx+1);
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    char s[2*A+1];
    generate(ans,s,A,0,0,0);
    return ans;
}
