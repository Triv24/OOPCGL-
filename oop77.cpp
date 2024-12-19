#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
 vector<string> name;
 string n;

 for(auto it = name.begin() ; it < name.end() ; ++it)
 {
  cout<<"Enter the name: ";
  cin>>n;
  name.push_back(n);
 }
 
 for(auto it = name.begin() ; it<name.end() ; ++it)
  {
    cout<<"Name is: "<<*it<<" ";
  }
  
return 0;

}
