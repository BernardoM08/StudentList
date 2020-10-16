#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
//main struct
struct Student {
  char* name;
  char* surname;
  int id;
  float gpa;
};
// methods
void addStudent(vector<Student*>*);
void printStudent(vector<Student*>*);
void deleteStudent(vector<Student*>*);

int main()
{
  //vector pointer containing struct pointers
  vector<Student*>* list = new vector<Student*>();
  //variables
  int input = 0;
  bool running = true;
  // while loop that will repeat until 'running' is false
  while(running == true)
    {
      cout << endl << "Please pick an option. 0 = Add a student, 1 = Delete a student, 2 Print out all students, 3 = Quit" << endl;
      cin >> input;
      //Calls the addStudent() method
      if (input == 0)
	{
	  addStudent(list);
	}
      //Calls the deleteStudent() method
      if (input == 1)
	{
	  deleteStudent(list);
	}
      //Calls the printStudent() method
      if (input == 2)
	{
	  printStudent(list);
	}
      // ends the while loop by turning running to false
      if (input == 3)
	{
	  cout << "end student list" << endl;
	  running = false;
	}
    }
  return 0;
}

void addStudent(vector<Student*>* paramlist) {
  // creates new student
  Student* newstudent = new Student();
  // new names/surnames for the element
  newstudent->name = new char[80];
  newstudent->surname = new char[80];
  // allows user to input the names, surnames, id and gpa of the new element
  cout << "Enter first name" << endl;
  cin >> newstudent->name;
  cout << "Enter last name" << endl;
  cin >> newstudent->surname;
  cout << "Enter id number" << endl;
  cin >> newstudent->id;
  cout << "Enter GPA" << endl;
  cin >> newstudent->gpa;
  // adds the student as a new element to the vector
  paramlist->push_back(newstudent);
}

void deleteStudent(vector<Student*>* list)
{
  int impid = 0;
  // prints the ids and names of all the students, allowing the user to delete the student by inputting the corresponding id number
  for (int i = 0; i < list->size(); i++)
    {
      cout << list->at(i)->id << ": " << list->at(i)->name << endl;
    }
  cout << "Please select who you would delete from the record. Type in their id to continue." << endl;
  cin >> impid;
  // goes through every element in the vector, checks whether the id inputted is equal to the id of the student. If it is, delete the student, if not, do nothing.
  for (int i = 0; i < list->size(); i++)
    {
      if (list->at(i)->id == impid)
	{
	  list->erase(list->begin() + i);
	}
      else
	{
	  cout << "You deleted nothing :)" << endl;
	}
    }
}

void printStudent(vector<Student*>* list)
{
  // goes through each of the element of the vector, and prints out the names, surnames, ids, and gpas of the elements.
  for (int i = 0; i < list->size(); i++)
    {
      cout << list->at(i)->name << " " << list->at(i)->surname << ", " << list->at(i)->id << ", " << fixed << setprecision(2) << list->at(i)->gpa << endl;
    }
}
