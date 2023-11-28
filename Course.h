#include <string>
#include <vector>
using namespace std;

// Forward declaration of Professor
class Professor;

class Course {
    string name;
    int courseCode;
    int type;
    vector<Professor*> professors;
    vector<Professor*> allottedTo;
public:
    // Constructor and method declarations...
    Course(string name, int courseCode, int type);
    int getCourseCode();
    int getType();
    string getName();
    vector<Professor*> getProfessors();
    void addProfessor(Professor professor);
    void addProfessor(Professor* professor);
    void setProfessors(vector<Professor*> professors);
    vector<Professor*> getAllottedTo();
    void setAllottedTo(vector<Professor*> allottedTo);
    void allotTo(Professor* professor);
    void allotTo(Professor professor);
};