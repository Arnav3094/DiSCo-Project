#include <bits/stdc++.h>
using namespace std;

class Course{
    string name;
    int courseCode;
    int type;
    vector <Professor&> professors;
    /**
     * 1 is FDCDC
     * 2 is FDEL
     * 3 is HDCDC
     * 4 is HDEL
    */
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
};