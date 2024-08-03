#include <iostream>
#include<string>
using namespace std;
class Student{
  private:
    string gf;
  public:
    string name;
    int id;
    int age;
    int present;
    int nos;
    int *v;
    /*Constructor : 1)Constructor tabhi call hoti hai jab object ban rha hota hai otherwise constructor call nhi 
                    hoti hai.
                    2)Constructor is the only function jiska koi return type nhi hota.
                    3)Is code mein humne dher saare constructors call kiye hai -> It shows the polymorphism property of OOPS.

                */

    //Default Constructor
    Student(){
      cout<<"Default Constructor called"<<endl;
    }
    // Parameterized Constructor 1
    Student(int id,int age,string name,int nos,int present){
      cout<<"Parameterized constructor called"<<endl;
      this->id=id;
      this->age=age;
      this->name=name;
      this->nos=nos;
      this->present=present;
      this->v=new int(10);
    }
    // Parameterized Constructor 2
    Student(int id,int age,string name,int nos,int present,string gf){
      cout<<"Parameterized constructor called"<<endl;
      this->id=id;
      this->age=age;
      this->name=name;
      this->nos=nos;
      this->present=present;
      this->gf=gf;
    }
    /*
      Why copy constructor is used?
      Copy Constructor is used just to copy the values of an object to another.
      The copy constructor is used only for initializations, and does not apply 
      to assignments where the assignment operator is used instead. The implicit 
      copy constructor of a class calls base copy constructors and copies its members
      by means appropriate to their type. If it is a class type, the copy constructor
      is called.
    */
    //Copy Constructor
    Student(const Student & srcObj){ // why "const" and "&" has been used
    cout<<"Student copy constructor called"<<endl;
      this->id=srcObj.id;
      this->age=srcObj.age;
      this->name=srcObj.name;
      this->nos=srcObj.nos;
      this->present=srcObj.present;
    }

    //Destructor
    /*
      Why we need destructor if already default destructor is there in the compiler?
      Ans : Suppose we declare a variable int *v in heap, then we have to destroy it also
            otherwise there will be memory leak, so for deleting the heap memory allocated 
            to v we need destructor. Because Default Destructor Can't handle that.Baaki saara
            defaault destructor handle kar lega.
    */
    ~Student(){
      cout<<"Destructor has been called"<<endl;
      delete v;
    }


};
int main() {
  Student s1(1,11,"Punit",5,1);
  Student s2(s1);

  cout<<s2.name<<endl;
  cout<<s1.name<<endl;
  return 0;
}