#include <bits/stdc++.h>
#include <fstream>
#include "graph.h"
using namespace std;

const int NUM_PROFESSORS = 30;
const int NUM_COURSES = 29;

const int n = NUM_PROFESSORS * 3 + NUM_COURSES * 2 + 2; // Total number of nodes, including sink and source

// Primarily for keeping track of the Course/Prof Codes that exist in our input files
vector<int> courseCodes;
vector<int> profCodes;

// To quickly get the Course/Prof object from the Course/Prof Code
map<int, Course*> courses;
map<int, Professor*> professors;

// Graph
Graph* graph = new Graph(n, NUM_PROFESSORS, NUM_COURSES);
Graph* newGraph = new Graph(n, NUM_PROFESSORS, NUM_COURSES);

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

bool bfs(vector<vector<int>>& graph, int s, int t,vector<int>& path){
    int n = graph.size();
    path = vector<int>(n, 0);
    vector<bool> visited(n, 0);
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    path[s] = -1;
    
    //bfs loop
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v=0; v<n; v++){
            if(visited[v] == false && graph[u][v] > 0){
                if(v==t){
                    path[v] = u;
                    return true; 
                }
                q.push(v);
                path[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

Graph* fordFulkerson(vector<vector<int>>& graph, int s, int t){
    int y,x ;
    int n = graph.size();
    vector<vector<int>> rGraph(graph.size(),vector<int>(graph.size(),0)) ;
    Graph* newGraphObj = new Graph(n, NUM_PROFESSORS, NUM_COURSES);
    vector<vector<int>> newGraph(n, vector<int>(n, 0));
    for(y=0; y<n; y++)
        for(x=0; x<n; x++)
            rGraph[y][x] = graph[y][x];
    // cout << "here1\n";
    vector<int> path(n,0);
    while(bfs(rGraph, s, t, path)){
        //finding the bottle-neck for the given path
        int bottle_neck = INT_MAX ;
        for(x = t; x!=s; x = path[x]){
            y = path[x];
            bottle_neck = min(bottle_neck, rGraph[y][x]);
        }
        // cout << "here2\n";
        for( x=t; x!=s; x=path[x]){
            y = path[x];
            rGraph[y][x] -= bottle_neck;
            rGraph[x][y] += bottle_neck;
            newGraph[y][x] += bottle_neck; // building the new graph
            // newGraph[x][y] -= bottle_neck;
            // cout <<"y:" + to_string(y) + " x:" + to_string(x) + " bottle_neck: "+ to_string(bottle_neck) +" here3\n";
        }

    }
    newGraphObj->setGraph(newGraph);
    return newGraphObj;
}


void printAssignment(string outputFile, Graph* graphObj, map<int, Professor*> professors, map<int, Course*> courses){
    FILE* out;
    out = fopen(outputFile.c_str(), "w"); // Assign the file pointer to 'out'
    if(out == NULL){
        throw runtime_error("Could not open file");
        cout << "Error opening file" << endl;
        return;
    }
    int index1, index2;
    vector<vector<int>> graph = graphObj->getGraphCopy();
    for(int i = 3 * NUM_PROFESSORS + 1; i < 2 * NUM_COURSES + 3 * NUM_PROFESSORS + 1; i+= 2){
        // cout << "i: " << i << endl;
        index1 = findInColumn(graph, 1, i);
        index2 = findInColumn(graph, 1, i + 1);
        int courseCode = graphObj->getCourseCode(i);
        string courseName = courses[courseCode]->getName();
        string courseType;
        switch (courses[courseCode]->getType()){
        case 1:
            courseType = "FDCDC";
            break;
        case 2:
            courseType = "FDEL";
            break;
        case 3:
            courseType = "HDCDC";
            break;
        case 4:
            courseType = "HDEL";
            break;
        default:
            throw runtime_error("Something went wrong. You got an invalid course type.");
            break;
        }
        if(index1 == -1 && index2 == -1){
            fprintf(out, "[COULD NOT BE ASSIGNED] Course: %s, Course Code: %d, Course Type: %s,\n", courseName.c_str(), courseCode, courseType.c_str());
            continue;
        }
        else if(index1 == -1 || index2 == -1){
            int profCode = (index1 == -1) ? graphObj->getProfCode(index2) : graphObj->getProfCode(index1);
            string profName = professors[profCode]->getName();
            fprintf(out, "[COURSE ALLOTTED PARTIALLY] Course: %s, Course Code: %d, Course Type: %s, Professor Code: %d, Professor: %s\n", courseName.c_str(), courseCode, courseType.c_str(), profCode, profName.c_str());
            continue;
        } else{
            int profCode1 = graphObj->getProfCode(index1);
            int profCode2 = graphObj->getProfCode(index2);
            if(profCode1 == profCode2){
                string profName = professors[profCode1]->getName();
                fprintf(out, "Course: %s, Course Code: %d, Course Type: %s, Professor: %s, Professor Code: %d\n", courseName.c_str(), courseCode, courseType.c_str(), profName.c_str(), profCode1);
            } else{
                string profName1 = professors[profCode1]->getName();
                string profName2 = professors[profCode2]->getName();
                fprintf(out, "Course: %s, Course Code: %d, Course Type: %s, Professors: %s (%d), %s (%d)\n", courseName.c_str(), courseCode, courseType.c_str(), profName1.c_str(), profCode1, profName2.c_str(), profCode2);
            }
        }

    }
    fclose(out);
}

int main(){

    populateCourses(courses, courseCodes, "Courses.txt");
    sort(courseCodes.begin(), courseCodes.end()); // Sorting the courseCodes vector so that we can iterate through it in order
    // printCourses();
    populateProfs(professors, profCodes, courses, "Profs.txt", "Prof_plist1.txt");
    sort(profCodes.begin(), profCodes.end()); // Sorting the profCodes vector so that we can iterate through it in order
    // printProfessors();

    graph->build(professors, profCodes);
    graph->print("original_graph.txt");

    vector<vector<int>> rGraph = graph->getGraphCopy();

    Graph* newGraph = fordFulkerson(graph->getGraph(), graph->getS(), graph->getT());
    newGraph->print("output.txt");
    printAssignment("assignment.txt", newGraph, professors, courses);
}