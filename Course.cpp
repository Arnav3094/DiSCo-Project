#include <bits/stdc++.h>
using namespace std;

class Course{
    string name;
    int courseCode;
    int type;
    /**
     * 1 is FDCDC
     * 2 is FDEL
     * 3 is HDCDC
     * 4 is HDEL
    */
    vector <Professor&> professors;
    vector <Professor&> allottedTo; 
    // We wanted to keep a cap on the number of professors that can be allotted to a course
    // but could not find a way to keep a cap on the maximum size of the vector
    public:
        Course(string name, int courseCode, int type){
            this->name = name;
            this->courseCode = courseCode;
            this->type = type;
        }
        int getCourseCode(){
            return courseCode;
        }
        int getType(){
            return type;
        }
        string getName(){
            return name;
        }
        vector<Professor&>& getProfessors(){
            return professors;
        }
        void addProfessor(Professor& professor){
            professors.push_back(professor);
        }
        void setProfessors(vector<Professor&>& professors){
            this->professors = professors;
        }
        vector<Professor&>& getAllottedTo(){
            return allottedTo;
        }
        void setAllottedTo(vector<Professor&>& allottedTo){
            if (allottedTo.size() > 2){
                throw invalid_argument("ERROR: Cannot allot more than 2 professors to a course.\nPlease allot only 2 professors to this course.");
            }
            this->allottedTo = allottedTo;
        }
        void allotTo(Professor& professor){
            if(allottedTo.size() >= 2){
                throw invalid_argument("ERROR: Cannot allot more than 2 professors to a course.\nPlease allot only 2 professors to this course.");
            }
            allottedTo.push_back(professor);
        }

};