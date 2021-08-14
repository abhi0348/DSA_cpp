2.1
//string shift (https://leetcode.com/problems/replace-all-digits-with-characters/submissions/)
class Solution {
public:
    string replaceDigits(string s) {
     int n=s.length();int i=1;
while(i<n){
int x = s[i]-'0';
int y = int(s[i-1]);
s[i] = char(x+y);
i+=2;
}
return s;}
};
2.2
//longest common substring without repeting char(https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/?currentPage=1&orderBy=newest_to_oldest&query=)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.size();
        
        if(s.size()==0)return 0;
        
        int i=0, j=0;
        
        vector<int> cnt(300, 0);
        cnt[s[0]]++;
        int ans=1;
       
        while(1){
            if(j==n-1) break;
            if(cnt[s[j+1]] == 0) j++, cnt[s[j]]++, ans=max(ans,j-i+1);
            else {
                cnt[s[i++]]--;
            }
        }
        return ans;
    }
};
2.3
//min heap using priority queue(https://leetcode.com/problems/seat-reservation-manager/)
class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    SeatManager(int n) {
       for(int i=1;i<=n;i++)
           pq.push(i);
    }
    
    int reserve() {
        int t=pq.top();
        pq.pop();
        return t;
        
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
//priority queue - priority_queue<int> gq;
//min heap priority queue - priority_queue <int, vector<int>, greater<int>> g ;  

2.4
//no of digit is odd or even.(https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)
	int count=0;
    for(int i=0;i<nums.size();i++)
    {
        int x=log10(nums[i]); //ex- log10(100) =2 so digits in 100 will be log10(100)+1
        x++;
        if(x%2==0)
            count++;
    }
    return count;
}
'''
2.5
//two pointer approach for squares of array.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1;
        for (int k = A.size() - 1; k >= 0; k--) {
            if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
            else res[k] = A[l] * A[l++];
        }
        return res;
    }
};
2.6
***//duplicate of zero (https://leetcode.com/problems/duplicate-zeros/solution/)

class Solution {
public:
    void duplicateZeros(vector<int>& a) {
        int n=a.size();
int c=count(a.begin(),a.end(),0);
        int j=c+n-1;
        for(int i=n-1,k=j;i>=0,k>=0;i--,k--)
        {
            if(a[i]==0)
            {
                if(k<n)a[k]=a[i];
                k--;
                if(k<n)a[k]=a[i];
            }
            else
                if(k<n)a[k]=a[i];
                
            
        }
    }
};
2.7
//merge two arrays without using extra array (https://leetcode.com/problems/merge-sorted-array/)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1;int j=n-1;
        int c=m+n-1;
        while(j>=0&&i>=0)
        {
            if(nums1[i]<=nums2[j])
              nums1[c--]=nums2[j--];
            else 
                nums1[c--]=nums1[i--];
        }
        while(j>=0)
            nums1[c--]=nums2[j--];
        
    }
};


