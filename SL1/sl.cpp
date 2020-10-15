# include <iostream>
# include <iomanip>
# include <vector>

using namespace std;

struct Student
{
  char name[10];
  char surname[10];
  int id;
  float gpa;
};

int main()
{
  vector<Student> student(10);
  int input = 0;
  int kt = 0;
  int sum = 0;
  bool running = true;
  while (running == true)
  {
    cout << endl << "Please pick an option. 0 = Add a student, 1 = Delete a student, 2 Print out all students, 3 = Quit" << endl;
    cin >> input;
    // adding students
    if (input == 0)
      {
        cout << "name" << endl;
        cin >> student.at(kt).name;
        cout << "last name" << endl;
        cin >> student.at(kt).surname;
        cout << "id" << endl;
        cin >> student.at(kt).id;
        cout << "gpa" << endl;
        cin >> student.at(kt).gpa;
        kt++;
      }
    //deleting students
    if (input == 1)
      {
        cout << "Pick which student you'd like to delete" << endl;
	for (int i = 0; i < kt; i++)
	  {
	    cout << i << ": " << student.at(i).name << endl;
	  }
	cin >> sum;
	for (int i = sum; i < kt; i++)
	  {
	    
	  }
      }
    //printing students
    if (input == 2)
      {
	for (int i = 0; i < kt; i++)
	  {
	    cout << "Student #" << i << endl;
	    cout << student.at(i).name << " " << student.at(i).surname << ", "<< student.at(i).id << ", " << fixed << setprecision(2) << student.at(i).gpa << endl;
	  }
      }
    if (input == 3)
      {
	running = false;
      }
  }
  return 0;
}

