#include <bits/stdc++.h>
#include <fstream>
#include "Course.h"
#include "Professor.h"
using namespace std;

const int NUM_PROFESSORS = 30;
const int NUM_COURSES = 29;

// Graph
vector<vector<int>> graph(NUM_PROFESSORS + 1, vector<int>(NUM_COURSES + 1, 0));

// Primarily for keeping track of the Course/Prof Codes that exist in our input files
vector<int> courseCodes;
vector<int> profCodes;

// To quickly get the Course/Prof object from the Course/Prof Code
map<int, Course*> courses;
map<int, Professor*> professors;

// TESTER FUNCTIONS
// void printGraph(vector<vector<int>>& graph){
//     cout << "   Courses\n";
//     cout << "   ";
//     for(int i = 1; i < graph[0].size(); i++){
//         cout << i << " ";
//     }
//     cout << endl << "   ";
//     for(int i = 1; i < graph[0].size(); i++){
//         cout << "_ ";
//     }
//     cout << endl;
//     for(int i = 1; i < graph.size(); i++){
//         cout << i << "| ";
//         for(int j = 1; j < graph[0].size(); j++){
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

void printVector(vector<Course> s){
    for(Course a : s) cout << a.getName() << " " << a.getCourseCode()<< " " << " " << a.getType()<< "\n";
    cout << endl;
}

void printVector(vector<Course*> s){
    for(Course* a : s) cout << a->getName() << " " << a->getCourseCode()<< " " << " " << a->getType()<< "\n";
    cout << endl;
}

void printVector(vector<Professor*> s){
    for(Professor* a : s) cout << a->getName() << " " << a->getProfCode()<< " " << " " << a->getCategory()<< "\n";
    cout << endl;
}

void printVector(vector<Professor> s){
    for(Professor a : s) cout << a.getName() << " " << a.getProfCode()<< " " << " " << a.getCategory()<< "\n";
    cout << endl;
}

vector<string> breakString(string s){
    vector<string> substrings;
    stringstream ss(s);
    string substring;
    while(getline(ss, substring, ',')) substrings.push_back(substring);
    return substrings;
}

int getCourseType(string type){
    int typeInt;
    if(type == "FDCDC") typeInt = 1;
    else if (type == "FDEL") typeInt = 2;
    else if(type == "HDCDC") typeInt = 3;
    else if (type == "HDEL") typeInt = 4;
    else throw invalid_argument("Invalid course type: " + type);
    return typeInt;
}

void populateCourses(map<int, Course*>& courses, vector<int> courseCodes, string inputFile){
    fstream courseInput;
    courseInput.open(inputFile, ios::in);
    if(!courseInput.is_open()) throw runtime_error("File could not be opened correctly.");
    string coursesLine;

    int i = 1;
    while(i <= NUM_COURSES){ // Ideally change this to while(getline(courseInput, line))
        getline(courseInput, coursesLine);
        vector<string> coursesStrings = breakString(coursesLine);
        int code;
        try {code = stoi(coursesStrings[1]);}
        catch (invalid_argument e) {throw invalid_argument("[populateCourses] Invalid Course Code: "+ coursesStrings[1] +". Make sure Course Code is numeric.");}
        int type = getCourseType(coursesStrings[2]);
        Course* c = new Course(coursesStrings[0], code, type);
        courses.insert({code, c});
        i++;
    }
}

void populateProfs(map<int,Professor*>& professors, vector<int>& professorCodes, map<int, Course*>courses, string inputFile1/*Profs.txt*/, string inputFile2/*Prof_plist.txt*/){
    fstream profsInput;
    profsInput.open(inputFile1, ios::in);
    if(!profsInput.is_open()) throw runtime_error(inputFile1 + " could not be opened correctly.");
    string profsLine;

    fstream plistInput;
    plistInput.open(inputFile2, ios::in);
    if(!profsInput.is_open()) throw runtime_error(inputFile2 + " could not be opened correctly.");
    string plistLine;

    int i = 1;
    while(i <= NUM_PROFESSORS){
        getline(profsInput, profsLine);
        vector<string> profStrings = breakString(profsLine);
        getline(plistInput,plistLine);
        vector<string> plistStrings = breakString(plistLine);
        int profsCode, profsCategory;
        try{
            profsCode = stoi(profStrings[1]);
            profsCategory = stoi(profStrings[2]);
        } catch(invalid_argument e){
            throw invalid_argument("Invalid Argument: " + profStrings[1] + " " + profStrings[2]);
        }
        professorCodes.push_back(profsCode);
        // Making vector of Profs plist
        vector<Course*> profsPlist;
        int j = 1;
        while(j <= plistStrings.size() - 1){
            int courseCode;
            try{
                // cout << "i: " + to_string(i) + " j: " + to_string(j) + " " + plistStrings[j] << endl;
                courseCode = stoi(plistStrings[j]);
            } catch (invalid_argument e){
                throw invalid_argument("[populateProfs] Invalid Course Code: " + plistStrings[j]);
            }
            Course* c = courses[courseCode];
            profsPlist.push_back(c);
            j++;
        }
        Professor* p = new Professor(profStrings[0], profsCode, profsCategory, profsPlist);
        professors.insert({profsCode, p});
        i++;
    }
}

void printCourses() {
    for (const auto& pair : courses) {
        Course c = *pair.second;
        cout << pair.first << ": " << c.getName() << ", " << c.getType() << endl;
    }
}

void printProfessors() {
    for (const auto& pair : professors) {
        Professor p = *pair.second;
        cout << pair.first << ": " << p.getName() << ", " << p.getCategory() << endl;
    }
}


int main(){

    populateCourses(courses, courseCodes, "Courses.txt");
    // sort(courseCodes.begin(), courseCodes.end()); // Sorting the courseCodes vector so that we can iterate through it in order
    printCourses();
    populateProfs(professors, profCodes, courses, "Profs.txt", "Prof_plist.txt");
    // sort(profCodes.begin(), profCodes.end()); // Sorting the profCodes vector so that we can iterate through it in order
    printProfessors();
}