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

void add(vector<Student> &studentList);
void print(vector<Student> &studentList);
void deleteStudent(vector<Student> &studentList);



int main () {
  int studentCount = 0;
  bool stillActive = true;
  vector<Student> studentList;
  while(stillActive == true) {
    cout << "Please enter add print delete or quit: " << endl;
    char input[20];
    cin >> input;
  if (strcmp(input, "add") == 0) {
    add(studentList);
    studentCount++;
  }
  if (strcmp(input, "print") == 0) {
    print(studentList);
  }
  if (strcmp(input, "delete") == 0) {
    deleteStudent(studentList);
  }
  if (strcmp(input, "quit") == 0) {
    stillActive = false;
  }
  }

  return 0;
}

void add(vector<Student> &studentList) {
  Student *stu = new Student;
  cout << "Enter a first name: " << endl;
  cin >> stu -> firstName;
  cout << "Enter a last name: " << endl;
  cin >>  stu -> lastName;
  cout << "Enter a ID number: " << endl;
  cin >> stu -> idNum;
  cout << "Enter a GPA: " << endl;
  cin >> stu -> gpa;
  studentList.push_back(*stu);
}

void print(vector<Student> &studentList) {
  vector<Student>:: iterator itr;
  for(itr = studentList.begin(); itr < studentList.end(); itr++) {
    cout << "First Name: " << (*itr).firstName << " Last Name: " << (*itr).lastName << " ID Number : " << (*itr).idNum << " GPA: " << setprecision(3) << (*itr).gpa << endl;
  }
}

void deleteStudent (vector<Student> &studentList) {
  char input[20];
  cout << "please enter the first name of the student you wish to delete: " << endl;
  cin >> input;
  vector<Student>:: iterator itr;
  for(itr = studentList.begin(); itr < studentList.end(); itr++) {
    if(strcmp(input, (*itr).firstName) == 0) {
      delete -> itr;
      }
  }

}


