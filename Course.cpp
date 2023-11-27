#include <bits/stdc++.h>
#include "Course.h"
#include "Professor.h"
using namespace std;


Course::Course(string name, int courseCode, int type){
    this->name = name;
    this->courseCode = courseCode;
    this->type = type;
}
int Course::getCourseCode(){
        return courseCode;
}
int Course::getType(){
    return type;
}
string Course::getName(){
    return name;
}
vector<Professor*> Course::getProfessors(){
    return professors;
}
void Course::addProfessor(Professor professor){
    professors.push_back(&professor);
}
void Course::addProfessor(Professor* professor){
    professors.push_back(professor);
}
void Course::setProfessors(vector<Professor*> professors){
    this->professors = professors;
}
vector<Professor*> Course::getAllottedTo(){
    return allottedTo;
}
void Course::setAllottedTo(vector<Professor*> allottedTo){
    if (allottedTo.size() > 2){
        throw invalid_argument("ERROR: Cannot allot more than 2 professors to a course.\nPlease allot only 2 professors to this course.");
    }
    this->allottedTo = allottedTo;
}
void Course::allotTo(Professor* professor){
    if(allottedTo.size() >= 2){
        throw invalid_argument("ERROR: Cannot allot more than 2 professors to a course.\nPlease allot only 2 professors to this course.");
    }
    allottedTo.push_back(professor);
}
void Course::allotTo(Professor professor){
    if(allottedTo.size() >= 2){
        throw invalid_argument("ERROR: Cannot allot more than 2 professors to a course.\nPlease allot only 2 professors to this course.");
    }
    allottedTo.push_back(&professor);
}