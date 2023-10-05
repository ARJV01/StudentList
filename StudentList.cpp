#include<iostream>
#include<cstring>
#include<vector>
#include<iterator>

using namespace std;

void add(char firstName[20], char lastName[20], int id, float gpa, struct Student &stu, vector<Student> &studentList);
void print(vector<Student> &studentList);
void deleteStudent();

struct Student {
  char firstName[20];
  char lastName[20];
  int idNum;
  float gpa;
};

int main () {
  int input = 0;
  int studentCounter = 0;
  vector<Student> studentList;
  cout << "please enter add, remove, or print" << endl;
  cin >> input;
  if (input == 0) {
    char firstName[20];
    char lastName[20];
    int id = 0;
    float gpa = 0;
    cout << "First Name:" << endl;
    cin >> firstName;
    Student valueOf(firstName);
    //Student &firstName;
    cout << "Enter a last name:" << endl;
    cin >> lastName;
    cout << "id number:" << endl;
    cin >> id;
    cout << "GPA:" << endl;
    cin >> gpa;
    add(firstName, lastName, id, gpa, strcpy(Student, firstName), studentList);
    //print(studentList);
  }

  return 0;
}

void add(char firstName[20], char lastName[20], int id, float gpa, struct Student &stu, vector<Student> &studentList) {
  strcpy(firstName , stu.firstName);
  strcpy(lastName , stu.lastName);
  stu.idNum = id;
  stu.gpa = gpa;
  studentList.push_back(stu);
}

void print(vector<Student> studentList) {
  vector<Student>:: iterator itr;
  for(itr = studentList.begin(); itr < studentList.end(); itr++) {
    //cout << Student.name << endl;
  }
}

void deleteStudent () {

}
