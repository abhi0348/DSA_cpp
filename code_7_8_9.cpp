.1
//valid parentheses(https://leetcode.com/problems/valid-parentheses/)
class Solution {
public:
    bool isValid(string s) {
          int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
        else if(st.empty())return false;
        else if(s[i]==')'&&st.top()=='('||s[i]=='}'&&st.top()=='{'||s[i]==']'&&st.top()=='[')
                st.pop();
        else return false;
        }
        if(st.empty())return true;
        return false;
    }
};

.2
//single number(https://leetcode.com/problems/single-number/)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        
           ans=ans^nums[i]; 
        return ans;
    }
};
.3
//maximum contigous subarray(https://leetcode.com/problems/maximum-subarray/)
 class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m,x;
         x=nums[0];
         m=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            x=max(nums[i],x+nums[i]);
            m=max(x,m);
        }
        return m;
    }
};

.4
//soting of sentece (https://leetcode.com/problems/sorting-the-sentence/)
class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        unordered_map<int,string>mp;
        string word;
        while(ss>>word)
        {
            int t=word[word.length()-1]-48;
            word.resize(word.length()-1);
            mp[t-1]=word;
            
        }
        string ans="";
        if(mp.size()==1)return mp[0];
        for(int i=0;i<mp.size();i++)
        {
            ans=ans+mp[i];
            if(i<=mp.size()-2)ans+=" ";
            
        }
        return ans;
    }
};

.5
// 3sum (https://leetcode.com/problems/3sum/)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>>v;
        int n=a.size();
        for(int i=0;i<n-2;i++)
        {
           if(i==0||(i>0&&a[i]!=a[i-1]))
           {int sum=0-a[i];
               int l=i+1;int r=n-1;
            while(l<r)
            {
               
                if(a[l]+a[r]==sum)
                { vector<int>temp;
                   temp.push_back(a[i]);
                   temp.push_back(a[l]);
                    temp.push_back(a[r]);
                   v.push_back(temp);
                    while(l<r&&a[l]==a[l+1])l++;
                    while(l<r&&a[r]==a[r-1])r--;
                    l++;r--;
                }
                    else if(a[l]+a[r]>sum)r--;
                         else l++;
            } 
        }
    }
        
        return v;}
};

.6
//longest common prefix(https://leetcode.com/problems/longest-common-prefix/)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     if(strs.size()==1)return strs[0];
        string ans= strs[0]; 
        for(int i=1;i<strs.size();i++)
        { string s=strs[i];
           string temp;
            for(int j=0;j<min(s.length(),ans.length());j++)
            if(ans[j]!=s[j]){ temp=s.substr(0,j);break;}
           else  {temp+=s[j];}
            ans=temp;
        }
        return ans;
    }
};

