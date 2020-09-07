#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findTwoNumSumArray(vector<int>& numbers,int target,vector<vector<int> >& op)
{ 
  int l=0,r=numbers.size()-1;
     while(l!=r && l<r) {
      if(numbers[l]+numbers[r]==target){
          op.push_back({numbers[l],numbers[r]});
          //cout<< numbers[l] <<" + "<<numbers[r]<<endl;
          l++;r--;
      }
      else if(numbers[l]+numbers[r] > target)
      r--;
      else
      l++;
  }    
}

int main()
{
  int n,inp,target;
  cin>>n>>target;
  vector<int> numbers;
  vector<vector<int> > op;
  for (int i = 0; i < n; i++) {
      cin>>inp;
      numbers.push_back(inp);
  }
  sort(numbers.begin(),numbers.end());
  findTwoNumSumArray(numbers,target,op);
  for (auto i : op) {
      cout<<"{ ";
      for (auto two : i) {
          cout<<two<<" ";
      }
      cout<<"}";
  }
  
  
  
  
}