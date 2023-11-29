#include <vector>
#include "Professor.h"
#include "Course.h"
#include <map>

class Graph{
    vector<vector<int>> graph;
    int n; // Total number of nodes, including sink and source
    int numProfessors;
    int numCourses;
    int s; // Source node, will be set to n - 2
    int t; // Sink node, will be set to n - 1
public:
    Graph(int n, int numProfessors, int numCourses);
    void print();
    void build(map<int, Professor*> professors, vector<int> profCodes);
};