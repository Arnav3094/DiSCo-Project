#include <bits/stdc++.h>
using namespace std;

class Professor{
    string name;
    int facultyCode;
    int category;
    /**
     * 1 is x1
     * 2 is x2
     * 3 is x3 
    */
    vector <Course&> courses; // This is the preference list of the prof
    vector <Course&> allotted;
    public:
        Professor(string name, int facultyCode, int category, vector<Course&>& courses){
            this->name = name;
            this->facultyCode = facultyCode;
            this->category = category;
            this->courses = courses;
        }
        Professor(string name, int facultyCode, int category){
            this->name = name;
            this->facultyCode = facultyCode;
            this->category = category;
        }
        string getName(){
            return name;
        }
        int getFacultyCode(){
            return facultyCode;
        }
        int getCategory(){
            return category;
        }
        void setCourses(vector<Course&>& courses){
            this->courses = courses;
        }
        void addCourse(Course& course){
            courses.push_back(course);
        }
        vector<Course&>& getCourse(){
            return courses;
        }
        void setAllotted(vector<Course&>& allotted){
            if(allotted.size() > category){
                throw invalid_argument("ERROR: Cannot allot more than " + to_string(category) + " courses to a professor.\nPlease allot only " + to_string(category) + " courses to this professor.");
            }
            this->allotted = allotted;
        }
        void allotCourse(Course& course){
            if(allotted.size() >= category){
                throw invalid_argument("ERROR: Cannot allot more than " + to_string(category) + " courses to a professor.\nPlease allot only " + to_string(category) + " courses to this professor.");
            }
            allotted.push_back(course);
        }
        vector<Course&>& getAllotted(){
            return allotted;
        }
};