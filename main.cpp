#include <bits/stdc++.h>
using namespace std;

const int NUM_FACULTIES = 5;
const int NUM_COURSES = 6;

// TESTER FUNCTIONS
void printGraph(vector<vector<int>>& graph){
    cout << "   Courses\n";
    cout << "   ";
    for(int i = 1; i <= NUM_COURSES; i++){
        cout << i << " ";
    }
    cout << endl << "   ";
    for(int i = 1; i <= NUM_COURSES; i++){
        cout << "_ ";
    }
    cout << endl;
    for(int i = 1; i <= NUM_FACULTIES; i++){
        cout << i << "| ";
        for(int j = 1; j <= NUM_COURSES; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


void addEdge(vector<vector<int>>& graph, int facultyCode, int courseCode, int weight){
    graph[facultyCode][courseCode] = weight;
}

int main(){
    vector<vector<int>> graph(NUM_FACULTIES + 1, vector<int>(NUM_COURSES + 1, 0));

    // BUILD GRAPH HERE
    addEdge(graph, 1, 1, 1); // prof 1 wants course 1 with preference 1
    addEdge(graph, 1, 5, 2); // prof 1 wants course 5 with preference 2
    addEdge(graph, 1, 4, 3); // prof 1 wants course 4 with preference 3
    addEdge(graph, 1, 2, 4); // prof 1 wants course 2 with preference 4
    addEdge(graph, 2, 1, 1); // prof 2 wants course 1 with preference 1
    addEdge(graph, 3, 4, 1); // prof 3 wants course 4 with preference 1
    addEdge(graph, 4, 1, 1); // prof 0 wants course 0 with preference 1
    addEdge(graph, 5, 2, 1); // prof 0 wants course 0 with preference 1

    printGraph(graph);

    
}