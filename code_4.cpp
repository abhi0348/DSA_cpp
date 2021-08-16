4.1
//set greatest element next to current (https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        
        for(int i=0;i<n-1;i++)
        {int m=INT_MIN;
            for(int j=i+1;j<n;j++)
            {
                m=max(m,arr[j]);
            }
         
            arr[i]=m;
           }
        arr[n-1]=-1;
        return arr;
    }
};
4.2
//find the missing element (https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        int n=a.size();
        for(int i=0;i<n;i++)
        {
           int m=abs(a[i])-1;
            a[m]=a[m]>0?-a[m]:a[m];
                
        }
        vector<int>v;
        for(int i=0;i<n;i++)
        {if(a[i]>0)v.push_back(i+1);}
        return v;
        
    }
};