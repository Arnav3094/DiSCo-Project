#include <bits/stdc++.h>
using namespace std;

class Professor{
    string name;
    int facultyCode;
    vector <int> preference;
    vector <Course&> courses;
    public:
        Professor(string name, int facultyCode, vector<int>& preference){
            this->name = name;
            this->facultyCode = facultyCode;
            this->preference = preference;
        }
        Professor(string name, int facultyCode){
            this->name = name;
            this->facultyCode = facultyCode;
        }
        vector<int>& getPrefs(){
            return preference;
        }
        void setPrefs(vector<int>& preference){
            this->preference = preference;
        }
        int getFacultyCode(){
            return facultyCode;
        }
        string getName(){
            return name;
        }
        void addCourse(Course& course){
            courses.push_back(course);
        }
        void setCourses(vector<Course&>& courses){
            this->courses = courses;
        }
        vector<Course&>& getCourse(){
            return courses;
        }
};