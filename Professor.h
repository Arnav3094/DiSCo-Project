#include <vector>
#include <string>
using namespace std;
// Forward declaration of Course
class Course;

class Professor {
    string name;
    int profCode;
    int category;
    vector<Course*> courses;
    vector<Course*> allotted;
public:
    // Constructor and method declarations...
    Professor(string name, int profCode, int category, vector<Course*> courses);
    Professor(string name, int profCode, int category);
    string getName();
    int getProfCode();
    int getCategory();
    void setCourses(vector<Course*> courses);
    void addCourse(Course* course);
    void addCourse(Course course);
    vector<Course*> getCourses();
    void setAllotted(vector<Course*> allotted);
    void allotCourse(Course* course);
    void allotCourse(Course course);
    vector<Course*> getAllotted();

};