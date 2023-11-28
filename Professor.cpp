#include <bits/stdc++.h>
#include "Professor.h"
#include "Course.h"
using namespace std;

Professor::Professor(string name, int facultyCode, int category, vector<Course*> courses){
    this->name = name;
    this->facultyCode = facultyCode;
    this->category = category;
    this->courses = courses;
}
Professor::Professor(string name, int facultyCode, int category){
    this->name = name;
    this->facultyCode = facultyCode;
    this->category = category;
}
string Professor::getName(){
    return name;
}
int Professor::getFacultyCode(){
    return facultyCode;
}
int Professor::getCategory(){
    return category;
}
void Professor::setCourses(vector<Course*> courses){
    this->courses = courses;
}
void Professor::addCourse(Course* course){
    courses.push_back(course);
    (*course).addProfessor(*this);
}
void Professor::addCourse(Course course){
    courses.push_back(&course);
    course.addProfessor(*this);
}
vector<Course*> Professor::getCourses(){
    return courses;
}
void Professor::setAllotted(vector<Course*> allotted){
    if(allotted.size() > category){
        throw invalid_argument("ERROR: Cannot allot more than " + to_string(category) + " courses to a professor.\nPlease allot only " + to_string(category) + " courses to this professor.");
    }
    this->allotted = allotted;
}
void Professor::allotCourse(Course* course){
    if(allotted.size() >= category){
        throw invalid_argument("ERROR: Cannot allot more than " + to_string(category) + " courses to a professor.\nPlease allot only " + to_string(category) + " courses to this professor.");
    }
    allotted.push_back(course);
}
void Professor::allotCourse(Course course){
    if(allotted.size() >= category){
        throw invalid_argument("ERROR: Cannot allot more than " + to_string(category) + " courses to a professor.\nPlease allot only " + to_string(category) + " courses to this professor.");
    }
    allotted.push_back(&course);
}
vector<Course*> Professor::getAllotted(){
    return allotted;
}
