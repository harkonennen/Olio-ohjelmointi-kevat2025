#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
public:
    Student(string n , int a){
        cout << "Student " << n << " created" << endl;
        setAge(a);
        setName(n);
    }

    void setAge(int a){
        age = a;
    }

    void setName(string n){
        name = n;
    }

    string getName()const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void printStudentInfo(){
        cout << "Student name: " << getName() << ". Age: " << getAge() << endl;
    }

private:
    int age;
    string name;
};




int main ()
{
    int selection = 0;
    vector<Student>studentList;
    string name;
    int age;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl << endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
        {
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            cout<< "Give student name" << endl;
            cin.ignore();
            getline(cin,name);
            cout << "Give student age" << endl;
            cin >> age;
            Student newStudent(name, age);
            studentList.emplace_back(newStudent);
            break;
        }

        case 1:

            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for(auto& students : studentList){
                cout << students.getName() << endl;
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(), [](const Student&a,const Student& b){
                return a.getName() < b.getName();
            });

            for(auto& students : studentList){
                students.printStudentInfo();
            }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(), [](const Student&a,const Student& b){
                return a.getAge() < b.getAge();
            });

            for(auto& students : studentList){
                students.printStudentInfo();
            }
            break;


            break;

        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            cout<< "Give student name" << endl;
            cin.ignore();
            getline(cin,name);

            auto it = find_if(studentList.begin(),studentList.end(),[&](const Student& student)    {
                return student.getName() == name;
                });

            if (it == studentList.begin()){
                cout << "Student: " << name << " found." << endl;
            } else {
                cout << "Student not found" << endl;
            }
            break;
        }

        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    }while(selection < 5);
return 0;
}

