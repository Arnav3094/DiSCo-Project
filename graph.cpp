#include "graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int n, int numProfessors, int numCourses){
    this->n = n;
    this->s = n - 2;
    this->t = n - 1;
    this->numProfessors = numProfessors;
    this->numCourses = numCourses;
    this->graph = vector<vector<int>>(n, vector<int>(n, 0));
}

void Graph::print(){
    FILE* out = fopen("output.txt", "w");
    if(out == NULL){
        throw runtime_error("Could not open file");
        cout << "Error opening file" << endl;
        return;
    }
    fprintf(out, "    ");
    for(int i = 0; i < this-> numProfessors * 3; i++) fprintf(out, "%3d", i + 1);
    for (int i = 0; i < this->numCourses * 2; i++) fprintf(out, "%3d", i + 1);
    fprintf(out, "  s  t\n");
    for(int i = 0; i < this->numProfessors * 3; i ++){
        fprintf(out, "%2d| ", i + 1);
        for(int j = 0; j < this->n; j++){
            fprintf(out, "%3d", graph[i][j]);
            // cout << graph[i][j] << "  ";
        }
        fprintf(out, "\n");
    }
    for(int i = 0; i < this->numCourses * 2; i ++){
        fprintf(out, "%2d| ", i + 1);
        for(int j = 0; j < this->n; j++){
            fprintf(out, "%3d", graph[i + this->numProfessors * 3][j]);
            // cout << graph[i + this->numProfessors * 3][j] << "  ";
        }
        fprintf(out, "\n");
    }
    fprintf(out, "s | ");
    for(int i = 0; i < this->n; i++){
        fprintf(out, "%3d", graph[this->s][i]);
        // cout << graph[this->s][i] << "  ";
    }
    fprintf(out, "\nt | ");
    for(int i = 0; i < this->n; i++){
        fprintf(out, "%3d", graph[this->t][i]);
        // cout << graph[this->t][i] << "  ";
    }

}

void Graph::build( map<int, Professor*> professors,vector<int> profCodes){
    // Graph for all professor nodes
    for(int i = 0; i < this->numProfessors * 3; i += 3){
        // cout << "i: " << i << endl;
        Professor* p = professors[profCodes[i/3]];
        vector<Course*> plist = p->getCourses();
        int category = p->getCategory();

        // Creating vector for the one row of the ith professor
        vector<int> row(n, 0);
        for(int j = 0;j < plist.size(); j++){
            Course* c = plist[j];
            int k = (c->getCourseCode() - 1)*2 + numProfessors * 3;
            row[k] = 1;
            row[k + 1] = 1;
        }
        // Row vector created

        // Setting the row vector to the graph category times
        for(int j = 0; j < p->getCategory(); j++){
            graph[i + j] = row;
        }
    }

    // Graph for all course nodes
    for(int i = 0; i < this->numCourses * 2; i++){
        graph[i + this->numProfessors * 3][t] = 1;
    }

    for(int i = 0; i < this->numProfessors * 3; i += 3){
        Professor* p = professors[profCodes[i/3]];
        int category = p->getCategory();
        for(int j = 0; j < category; j++){
            graph[s][i + j] = 1;
        }
    }
}