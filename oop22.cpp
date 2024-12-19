// Develop a program in C++ to create a database of student’s information system containing the following information: Name, roll number, Class, Division, Date of Birth, Blood group, contact address, Telephone number, Driving license no. and other. Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators- new and delete as well as exception

#include<iostream>
#include<string>
using namespace std;

class student
{
  private: 
  
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    long long telephoneNumber;
    string drivingLicense;
    
    static int count; 
   
  public: 
  
   static void ShowCount()
    {
      cout<<"No. of records: "<<count<<endl;
    }
  //Default Constructor: 
  student(string n =  "" , int roll = 0, string Class =  "", char div = 'A', string d =  "", string bg =  "",string Address =  "",long long Number = 0, string dl =  "")
  {
    this->name = n;
    this->rollNumber = roll;
    this->studentClass = Class;
    this->division = div;
    this->dob = d;
    this->bloodGroup = bg;
    this->contactAddress = Address;
    this->telephoneNumber = Number;
    this->drivingLicense = dl;
    count++;
  }
  
  //Copy Constructor: 
  
  
  student(const student &s)
  {
    this->name = s.name;
    this->rollNumber = s.rollNumber;
    this->studentClass = s.studentClass;
    this->division = s.division;
    this->dob = s.dob;
    this->bloodGroup = s.bloodGroup;
    this->contactAddress = s.contactAddress;
    this->telephoneNumber = s.telephoneNumber;
    this->drivingLicense = s.drivingLicense;
    count++;
  }
  void getname();
  friend class frnd;
};
// explicit inline
inline void student:: getname(){
  cout<<name<<endl;
}

int student :: count = 0;

class frnd 
{
  public:
  void display(student s)
  {
    cout<<"\nName: "<<s.name<<"\n"<<"Roll: "<<s.rollNumber<<"\n"<<"Class: "<<s.studentClass<<"\n"<<"Division: "<<s.division<<"\n"<<"Date of birth: "<<s.dob<<"\n"<<"Blood group: "<<s.bloodGroup<<"\n"<<"Address: "<<s.contactAddress<<"\n"<<"Ph no. :"<<s.telephoneNumber<<"\n"<<"Driving license no. : "<<s.drivingLicense<<endl;
  }
  
};
int main ()
{
  student s1("Rutik", 20, "Second Year", 'A', "01/01/2004", "O+", "Pune", 9876543210, "DL123456789");
  student s2(s1) ;
  frnd f;
  f.display(s1);
  f.display(s2);
  cout<<"\nName is: ";
  s2.getname();
  student::ShowCount();
}
