//Arjun Vinsel
//10/16/2023
//This program will read in details about a student into a struct. This program can also print out all of theese students, and can also delete students 

#include<iostream>
#include<cstring>
#include<vector>
#include<iterator>
#include<iomanip>

using namespace std;

struct Student {
  char firstName[20];
  char lastName[20];
  int idNum;
  float gpa;
};

void add(vector<Student*> &studentList);//Funtion prototype for add
void print(vector<Student*> &studentList); // Funtion prototype for print
void deleteStudent(vector<Student*> &studentList);// Funtion prototype for deleteStudent



int main () {
  bool stillActive = true;
  vector<Student*> studentList;
  while(stillActive == true) {
    cout << "Please enter add print delete or quit: " << endl;
    char input[20];
    cin >> input;
    if (strcmp(input, "add") == 0) {//When a user enters add this condition will call the add method  
    add(studentList);
  }
    if (strcmp(input, "print") == 0) {// When a user enters print the condition will call the print funtion
    print(studentList);
  }
    if (strcmp(input, "delete") == 0) {// When a user enters delete the condition will call the delete funtion
    deleteStudent(studentList);
  }
    if (strcmp(input, "quit") == 0) {// When a user enters quit the loop will set still active to false and quit the program
    stillActive = false;
  }
  }

  return 0;
}

void add(vector<Student*> &studentList) {// This method will have a user enter in the fist name, last name, ID, and Gpa of a student, then it will add the student to the vector 
  Student *stu = new Student;
  cout << "Enter a first name: " << endl;
  cin >> stu -> firstName;
  cout << "Enter a last name: " << endl;
  cin >>  stu -> lastName;
  cout << "Enter a ID number: " << endl;
  cin >> stu -> idNum;
  cout << "Enter a GPA: " << endl;
  cin >> stu -> gpa;
  studentList.push_back(stu);
}

void print(vector<Student*> &studentList) {// This method will print all the students in the vector
  vector<Student*>:: iterator itr;
  for(itr = studentList.begin(); itr < studentList.end(); itr++) {
    cout << "First Name: " << (*itr) -> firstName << " Last Name: " << (*itr) -> lastName << " ID Number : " << (*itr) -> idNum << " GPA: " << fixed << setprecision(2) << (*itr) -> gpa << endl;
  }
}

void deleteStudent (vector<Student*> &studentList) {// This method will have a user enter a name and delete student
  int input = 0;
  cout << "please enter the id number of the student you wish to delete: " << endl;
  cin >> input;
  vector<Student*>:: iterator itr;
  for(itr = studentList.begin(); itr < studentList.end(); itr++) {
    if(input == (*itr) -> idNum) {
      delete *itr;
      studentList.erase(itr);
    break;
    }
  }

}


