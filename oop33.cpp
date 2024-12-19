// Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.

#include <iostream>
#include <string>
using namespace std;


class publication
{
  protected:
    char title[50] ;
    float price;

  public:   
    void get_data(){
      cout<<"Enter Title: ";
      cin.ignore();
      cin.getline(title,50);
              
      cout<<"Enter Price: ";
      cin>>price;
              
      if(cin.fail())
      {
        cout << "Invalid input for price. Resetting values.\n";
        reset();
        cin.clear();
        cin.ignore(10000 , '\n');
      }
      }
            
    void display(){
      cout<<"Title is: "<<title<<endl;
      cout<<"Price is: "<<price<<endl;
    }

    publication(){
      title[0] = '\0';
      price = 0.0;
    }   
            
    void reset(){
      title[0] = '\0';
      price = 0.0;
    }
};

class book : public publication 
{
  private:  
    int pg_count;

  public:  
  
  void get_data(){

    publication::get_data();
    cout<<"Enter page count: ";
    cin>>pg_count;
              
    if (cin.fail()) {
      cout << "Invalid input for page count. Resetting values.\n";
      reset();
      cin.clear();
      cin.ignore(10000,'\0');
    }
  }

  void display(){
    publication::display();
    cout<<"Page count is: "<<pg_count<<endl<<endl;
  }

  book(){
    pg_count = 0;
  }

  void reset(){
    publication::reset();
    pg_count = 0;
  }
};

class tape : public publication 
{
  private:  
    float time;
  public:   
    void get_data(){
      publication::get_data();
      cout<<"Enter timing in mins: ";
      cin>>time;
              
      if(cin.fail()){
        cout << "Invalid input for time. Resetting values.\n";
        reset();
        cin.clear();
        cin.ignore(10000,'\0');
      }
    }
    
    void display(){
      publication::display();
      cout<<"Timing is: "<<time<<endl;
    }
            
    void reset(){
      publication::reset();
      time = 0.0;
    }
            
    tape(){
      time = 0.0;
    }
};


int main (){
  book b;
  tape t ;
 
  cout << "Enter details for book:\n";
  b.get_data();
 
  cout<<"Details Entered\n";
  b.display();
 
  cout << "Enter details for tape:\n";
  t.get_data();
 
  cout<<"Details Entered \n";
  t.display();
 
  return 0;
}