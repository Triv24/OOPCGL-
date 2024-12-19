#include<iostream>
#include <fstream>
#include<string>
using namespace std;

int main ()
{
  ofstream fout("File.txt");
  

  if(!fout)
  {
    cerr<<"Error opening the file for writing";
    return 1;
  }
  
  fout<<"This is the content of the file :)"<<endl;
  fout<<"End of the file ;)";
  cout << "Data written to file successfully." << endl;
  
  fout.close();
  
  ifstream fin("File.txt");
  
  if(!fin)
  {
    cerr<<"Error opening the file for reading";
    return 1;
  }
  cout << "\nReading data from file:\n" << endl;
  string line;
  while(getline(fin,line))
  {
    cout<<line<<"\n";
  }
  
  fin.close();
  return 0 ;
}
