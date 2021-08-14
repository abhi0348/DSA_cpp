3.1
//set matrix elements to zero present in any row or column (https://leetcode.com/problems/set-matrix-zeroes/)
class Solution {
public:
     bool crow(int rind,vector<vector<int>>& matrix)
    {
        for(int i=0;i<matrix[0].size();i++)
            if(matrix[rind][i]==0) return true;
       return false;
    }
     bool ccol(int cind,vector<vector<int>>& matrix)
    {
        for(int i=0;i<matrix.size();i++)
            if(matrix[i][cind]==0)return true;
         return false;
    }
     void zcol(int cind,vector<vector<int>>& matrix)
    {
         
        for(int i=0;i<matrix.size();i++)
            matrix[i][cind]=0;
    }
    void zrow(int rind,vector<vector<int>>& matrix)
    {
         //int k=0;
        for(int i=0;i<matrix[0].size();i++)
            matrix[rind][i]=0;
    }
    void pro(vector<vector<int>>& matrix,int ind,int n,int m)
    {
   
        bool row=0,col=0;
        if(ind<n)
         row=crow(ind,matrix);
        if(ind<m)
         col=ccol(ind,matrix);
        
        int c=ind+1;
        
        if(c<n||c<m)
            pro(matrix,c,n,m);  
        if(row&&ind<n)zrow(ind,matrix);
        if(col&&ind<m)zcol(ind,matrix);
        
        
    }
 
    void setZeroes(vector<vector<int>>& matrix) {
          int n=matrix.size();
        int m=matrix[0].size();
     
        pro(matrix,0,n,m);
          
    }
};
3.2
//removing certain values from the array (https://leetcode.com/problems/remove-element/)
class Solution {
public:
    
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;int j=n-1;
        int c=count(nums.begin(),nums.end(),val);
        while(i<j)
        {    
        if(nums[i]==val)
        {swap(nums[i],nums[j]);j--;}
            else i++;
        }
        return n-c;}
};
3.3
//find the power of a number (double , int)(https://leetcode.com/problems/powx-n/)
class Solution {
public:
    double myPow(double x, int n) {
     
        double res=1;
        while(n){
        if(n%2)res=n>0?res*x:res/x;
        x=x*x;
        n/=2;}
    
    return res;}
};
3.4
//remove duplicates in place from the array (https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n=nums.size(); int i=0,j=1;
       for(int j=1;j<n;j++)
       {
            if(nums[i]!=nums[j])
            { i++;
            nums[i]=nums[j];}
            
        }
       return i+1;
    }
};
3.5
//check if double of a number is present in the array or not (https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(2*arr[i])!=mp.end()||mp.find(arr[i]/2)!=mp.end()&&arr[i]%2==0)return true;
            else mp[arr[i]]++;
        }
        return false;}
};
3.6.a
//mountain array (https://leetcode.com/problems/valid-mountain-array/solution/)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        if(n<3)return false;
        for(i=0;i<n-1;i++)
        {
            if(arr[i]<arr[i+1])continue;
            else break;
        }
        if(i==n-1||i==0)return false;
        else for(i=i;i<n-1;i++)
        {
          if(arr[i]>arr[i+1])continue;
            else break;
          }
        if(i==n-1)return true;
        else return false;
    }
};
3.6.b
       int n=a.size();
        int i=0;
        if(n<3)return false;
        int left=0,right=0;
        for(int i=0;i<n-1;i++)
         if(a[i]>=a[i+1]){left=i;break;}
        for(int i=n-1;i>=1;i--)
            if(a[i-1]<=a[i]){right=i;break;}
if(right==left&&right!=0&&right!=n-1)return true;
        return false;}
};
3.7
//move all 0 at the end of the arrayhttps://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3157/)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int ind=0;
        for(int i=0;i<n;i++)
        
            if(nums[i]!=0){nums[ind]=nums[i];ind++;}
        for(int i=ind;i<n;i++)
        { nums[i]=0;}
        
    }
};
3.8 
//sort array by parity(https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3260/)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int ind=0;
        for(int i=0;i<n;i++)
        {
            if(!(nums[i]&1)){swap(nums[ind],nums[i]);ind++;}
        }
        return nums;
    }
};
3.9
//no of inplaced elements (https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3228/)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int c=0;
        int n=heights.size();
        vector<int>a;
        a=heights;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            if(a[i]!=heights[i])c++;
          }
        return c;
    }
};

