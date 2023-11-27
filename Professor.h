#include <vector>
#include <string>
using namespace std;
// Forward declaration of Course
class Course;

class Professor {
    string name;
    int facultyCode;
    int category;
    vector<Course*> courses;
    vector<Course*> allotted;
public:
    // Constructor and method declarations...
    Professor(string name, int facultyCode, int category, vector<Course*> courses);
    Professor(string name, int facultyCode, int category);
    string getName();
    int getFacultyCode();
    int getCategory();
    void setCourses(vector<Course*> courses);
    void addCourse(Course* course);
    void addCourse(Course course);
    vector<Course*> getCourse();
    void setAllotted(vector<Course*> allotted);
    void allotCourse(Course* course);
    void allotCourse(Course course);
    vector<Course*> getAllotted();

};