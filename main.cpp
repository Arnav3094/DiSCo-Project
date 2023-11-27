#include <bits/stdc++.h>
#include <fstream>
#include "Professor.cpp"
#include "Course.cpp"
using namespace std;

const int NUM_FACULTIES = 5;
const int NUM_COURSES = 6;


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
    for(auto a : s) cout << a.getName() << " " << a.getCourseCode()<< " " << " " << a.getType()<< "\n";
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

void populateUnallottedCourses(vector<Course>& courses, string inputFile){
    fstream courseInput;
    courseInput.open("Courses.txt", ios::in);
    if(!courseInput.is_open()) throw runtime_error("File could not be opened correctly.");
    string line;
    while(getline(courseInput, line)){

        vector<string> a = breakString(line);
        // Course c = Course(a[0], stoi(a[1]), stoi(a[2]));
        courses.push_back(Course(a[0], stoi(a[1]), stoi(a[2])));
    }
}

int main(){
    vector<vector<int>> graph(NUM_FACULTIES + 1, vector<int>(NUM_COURSES + 1, 0));

    vector<Professor> unallottedProfessors;
    vector<Course> unallottedCourses;

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





    printGraph(graph);

    
}