#include <bits/stdc++.h>
#include "Professor.h"
#include "Course.h"
#include <fstream>
using namespace std;

const int NUM_FACULTIES = 30;
const int NUM_COURSES = 29;


// TESTER FUNCTIONS
void printGraph(vector<vector<int>>& graph){
    cout << "   Courses\n";
    cout << "   ";
    for(int i = 1; i < graph[0].size(); i++){
        cout << i << " ";
    }
    cout << endl << "   ";
    for(int i = 1; i < graph[0].size(); i++){
        cout << "_ ";
    }
    cout << endl;
    for(int i = 1; i < graph.size(); i++){
        cout << i << "| ";
        for(int j = 1; j < graph[0].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void printVector(vector<Course> s){
    for(Course a : s) cout << a.getName() << " " << a.getCourseCode()<< " " << " " << a.getType()<< "\n";
    cout << endl;
}

void printVector(vector<Course*> s){
    for(Course* a : s) cout << a->getName() << " " << a->getCourseCode()<< " " << " " << a->getType()<< "\n";
    cout << endl;
}

// preference 1 is the highest preference
void addEdge(vector<vector<int>>& graph, int facultyCode, int courseCode, int weight){
    graph[facultyCode][courseCode] = weight;
}

vector<string> breakString(string s){
    vector<string> substrings;
    stringstream ss(s);
    string substring;
    while(getline(ss, substring, ',')) substrings.push_back(substring);
    return substrings;
}

Course* getCourseByCode(int code){
    Course* c;
    
    return c;
}

void populateUnallottedCourses(vector<Course*>& courses, string inputFile){
    fstream courseInput;
    courseInput.open(inputFile, ios::in);
    if(!courseInput.is_open()) throw runtime_error("File could not be opened correctly.");
    string line;
    int i = 1;
    while(i <= NUM_COURSES){ // Ideally change this to while(getline(courseInput, line))
        getline(courseInput, line);
        // cout << i <<" here1\n";
        vector<string> strings = breakString(line);
        // cout << i <<" here2\n";
        int type;
        if(strings[2] == "FDCDC") type = 1;
        else if (strings[2] == "FDEL") type = 2;
        else if(strings[2] == "HDCDC") type = 3;
        else if (strings[2] == "HDEL") type = 4;
        else throw invalid_argument("Invalid course type: " + strings[2]);
        // cout << i <<" here3\n";
        try{
            Course* c = new Course(strings[0], stoi(strings[1]), type);
            courses.push_back(c);
        } catch (invalid_argument e){
            cout << "Invalid argument: " << e.what() << " + " << strings[0] << " + " << strings[1] << " + " << strings[2] << endl;
        }
        i++;
    }
}

void populateUnallottedProfs(vector<Professor*>& professors, string inputFile1/*Profs.txt*/, string inputFile2/*Prof_plist.txt*/){
    fstream profInput;
    profInput.open(inputFile1, ios::in);
    if(!profInput.is_open()) throw runtime_error(inputFile1 + " could not be opened correctly.");
    string profsLine;

    fstream plistInput;
    plistInput.open(inputFile2, ios::in);
    if(!profInput.is_open()) throw runtime_error(inputFile2 + " could not be opened correctly.");
    string plistLine;

    int i=1;
    while(i <= NUM_FACULTIES){
        getline(profInput, profsLine);
        vector<string> profsSubstrings = breakString(profsLine);
        Professor* p;
        getline(plistInput,plistLine);
        vector<string> plistSubstrings = breakString(plistLine);
        vector<Course*> profsPlist;
        int j=1;
        while(j <= plistSubstrings.size() - 1){
            Course* c;
            try {
                c = getCourseByCode(stoi(plistSubstrings[j]));
                // add some code if course could not be found
            } catch (invalid_argument e){
                throw invalid_argument("Invalid Course Code. Make sure Course Code is numeric");
            }
            profsPlist.push_back(c);
        }
        try{
            p = new Professor(profsSubstrings[0], stoi(profsSubstrings[1]), stoi(profsSubstrings[2]), profsPlist);
            professors.push_back(p);
        } catch (invalid_argument e){
            throw invalid_argument("Invalid Argument: "+profsSubstrings[0]+" "+profsSubstrings[1]+" "+profsSubstrings[2]);
            cout << "Invalid argument: " << e.what() << " + " << profsSubstrings[0] << " + " << profsSubstrings[1] << " + " << profsSubstrings[2] << endl;
        }
        //Course* c = getCourseByCode(plistLine[2]);
    }

}

int main(){
    vector<vector<int>> graph(NUM_FACULTIES + 1, vector<int>(NUM_COURSES + 1, 0));

    vector<Professor*> unallottedProfessors;
    vector<Course*> unallottedCourses;

    populateUnallottedCourses(unallottedCourses, "Courses.txt");
    printVector(unallottedCourses);

    // BUILD GRAPH HERE
    // addEdge(graph, 1, 1, 1); // prof 1 wants course 1 with preference 1
    // addEdge(graph, 1, 5, 2); // prof 1 wants course 5 with preference 2
    // addEdge(graph, 1, 4, 3); // prof 1 wants course 4 with preference 3
    // addEdge(graph, 1, 2, 4); // prof 1 wants course 2 with preference 4
    // addEdge(graph, 2, 1, 1); // prof 2 wants course 1 with preference 1
    // addEdge(graph, 3, 4, 1); // prof 3 wants course 4 with preference 1
    // addEdge(graph, 4, 1, 1); // prof 0 wants course 0 with preference 1
    // addEdge(graph, 5, 2, 1); // prof 0 wants course 0 with preference 1

    // printGraph(graph);

    
}