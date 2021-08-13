1.1.a//find the repeating element (1-n)
//floyd cycle detection method.
class Solution {
public:
int findDuplicate(vector& nums) {
int f=nums[0];
int s=nums[0];
do
{
s=nums[s];
f=nums[nums[f]];
} while(s!=f);
f=nums[0];
while(s!=f)
{
s=nums[s];
f=nums[f];
}
return s;
}
};

1.1.b//method 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=nums.size();
        vector<int>v(l-1);
        for(int i=0;i<l;i++)
            v[nums[i]-1]++;
        int i;
        for( i=0;i<l-1;i++)
        if(v[i]>1)
            break;
        return i+1;
        
    }
};
1.2//missing and repeated element (1-n)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {



       
      vector<int>v(n+1);
      int* a=new int[2];
      for(int i=0;i<n;i++)
      
          v[arr[i]]++;
      for(int i=0;i<=n;i++)
      {
         if(v[i]==2)
         a[0]=i; if(v[i]==0)
         a[1]=i;
      }
    
     
        return a;
    }
    };
//1.3 sort the players 

#include<bits/stdc++.h>
using namespace std;

struct game{
    int score;
    string s;
};
//comparetor fun for sorting.
bool comp(game g1,game g2)
{
    if(g1.score>g2.score)return true;
    if(g1.score==g2.score)return g1.s<g2.s;
    return false;
}
vector<game> order(vector<game>g)
{
   sort(g.begin(),g.end(),comp);
   return g;
   }


int main() {
    int n;
    cin>>n;
    vector<game>g;
    int a; string b;
    for(int i=0;i<n;i++)
   { 
     cin>>b>>a;
     game gm;
     gm.s=b,
     gm.score=a;
     g.push_back(gm);
     }
   vector<game>g1= order(g);
    for(int i=0;i<n;i++)
    cout<<g1[i].s<<" "<<g1[i].score<<endl;
    return 0;
}

//1.4 special string (substring having same char and having middle element diff rest are same)https://www.hackerrank.com/challenges/special-palindrome-again/problem?h_l=interview&isFullScreen=true&playlist_slugs%5B%5D=arcesium

long substrCount(int n, string s) {

  vector<pair<char,int>>v;
  long ans;
  int curr='\0';
  int ind=-1;
  for(int i=0;i<n;i++)
  {
      if(curr==s[i])
      {
          v[ind].second++;
      }
      else 
      {curr=s[i];
         ind++;
          v.push_back({curr,1});
      }}
      ans+=v[0].second*(v[0].second+1)/2;
      int j=v.size();
      for(int i=1;i<j;i++)
      {
          ans+=v[i].second*(v[i].second+1)/2;
         
          if((v[i-1]).first==(v[i+1]).first&&v[i].second==1)
          ans+=min((v[i+1]).second,(v[i-1]).second);
      }


