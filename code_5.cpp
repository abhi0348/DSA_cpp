5.1
//sell and buy stokes (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/)
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int m=0,mi=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(mi>a[i])mi=a[i];
            m=max(m,a[i]-mi);}
            return m;
    }
};
5.2
//reverse number not exceeding int max min(https://leetcode.com/problems/reverse-integer/)
class Solution {
public:
    int reverse(int x) {
        long long int t=0,m=0;
        while(x)
        {
            m=x%10;
            t=t*10+m;
            x/=10;
        }
        return t>INT_MAX||t<INT_MIN? 0:t;
    }
};
5.3.a
//element occuring greater than n/2 times(https://leetcode.com/problems/majority-element/submissions/)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans=0,s=0;
        
              unordered_map<int ,int>mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        for(int i=0;i<n;i++)
        {
          if(mp[nums[i]]>ans)
          { ans=mp[nums[i]];
            s=nums[i];}
              
        
        }
        return s;
    }
};
5.3.b
class Solution {
public:
    int majorityElement(vector<int>& a) {
       int n=a.size();
      int ele=0;int ans=0;
        for(int i=0;i<n;i++)
        {
            if(ans==0)
            {ele=a[i];}
            
                if(a[i]==ele)
                    ans+=1;
            else
                ans-=1;
                
        }
        return ele;
    }
};
5.4
//reverse the word of string (https://leetcode.com/problems/reverse-words-in-a-string/)
class Solution {
public:
    string reverseWords(string s) {
       
        stringstream ss(s);
        string word;
        ss>>s;
        
        
        while(ss>>word)   
        s=word+" "+s;         
  
        return s;
    }
};
5.5 
//range sum query(https://leetcode.com/problems/range-sum-query-immutable/submissions/)
private:
    vector<int>v;

    public:
     
    NumArray(vector<int> nums) {
       
        v=nums;
        for(int i=1;i<nums.size();i++)
        
            v[i]+=v[i-1];
        
    }
    
    int sumRange(int left, int right){
        if(left==0)return v[right];
        return v[right]-v[left-1];
    }