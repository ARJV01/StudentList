//Arjun Vinsel
//9/13/2023
//This will take an input and determine if that input is a palindrome

#include<iostream>
#include<cstring>

using namespace std;

int main () {
  char input[80];
  char userString[80];
  char reverseString[80];
  cin.getline(input ,80);
  int counter = 0;
  int counter2 = 0;
  int counter3 = 0;
  int length = strlen(input);

  for(int i =0; i < length; i++) {//Sets input to all upper case
    input[i] = toupper(input[i]);
  }

  for (int i = 0; i < length; i ++) {
    if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || ((int) (input[i]) >= 65 && (int)(input[i]) <= 90) || ((int)(input[i]) >= 97 && (int)(input[i]) <= 122)) {//Removes anything other than alphabetic charecters
        userString[counter] = input[i];
	reverseString[counter] = input[i];
     

        counter++;
    }
    }
  int length2 = strlen(userString);

  for (int i = length2 - 1; i >= 0; i--) { // determines if the string in eaqual to its reveserse by comparing each charecter
    if (reverseString[counter2] == userString[i]) {
      counter3++;
    }
    counter2++;
  }

  
  if (counter3 == counter) { // determines if the input is a palindrome and tells user
    cout << "This is a palindrome" << endl;
  }
  
  else {//If not a palindrome alerts user
    cout << "This is not a palindrome" << endl;
  }
  return 0;
}

