### Compile Command: g++ main.cpp graph.cpp Professor.cpp Course.cpp -o main

# Question Statement: An Application of Graph Optimization-Course Project

The research problem at hand revolves around the optimization of the University Course Assignment System. Within a department, there are "n" faculty members categorised into three distinct groups: "x1," "x2," and "x3." Faculty in each category are assigned different course loads, with "x1" handling 0.5 courses per semester, "x2" taking 1 course per semester, and "x3" managing 1.5 courses per semester.

In this system, faculty members have the flexibility to take multiple courses in a given semester, and conversely, a single course can be assigned to multiple faculty members. When a course is shared between two professors, each professor's load is considered to be 0.5 courses. Moreover, each faculty member maintains a preference list of courses, ordered by their personal preferences, with the most preferred courses appearing at the top. Importantly, there is no prioritisation among faculty members within the same category.

The primary objective of this research problem is to develop an assignment scheme that maximises the number of courses assigned to faculty while aligning with their preferences and the category-based constraints ("x1," "x2," "x3"). The challenge lies in ensuring that a course can only be assigned to a faculty member if it is present in their preference list.

This problem is unique due to the flexibility it offers regarding the number of courses faculty members can take, distinct from typical Assignment problems. Potential modifications may include adjusting the maximum number of courses "y" for each category of professors, instead of requiring exact adherence, or extending the number of professor categories beyond the existing three to devise a more generalised solution.

***Additionally:*** "your  job is to produce multiple different, acceptable combinations as assignments and not to recommend the best solution"

- A professor can be assigned a lower course load than their limit only if it is not possible to assign them a course of their preference.

- However, in no case are we allowed to assign more than the limit to a prof.

- "What is the minimum number of courses a professor has to give his preferences for?
4 FD CDC, 2 FD Ele, 2 HD CDC, 2 HD Ele "


## File Structure

1. **main.cpp**: the main script that is to be run
2. **Course.h**: header file which defines the Course class
3. **Course.cpp**: the file that defines the methods of the class Course 
4. **Professor.h**: header file which defines the Professor class
5. **Professor.cpp**: the file that defines the methods of the class Professor
6. **graph.h**: header file which defines the Graph class
7. **graph.cpp**: defines methods of the Graph class
8. **Profs.txt**: The input file that stores all data of the professors
9. **Courses.txt**: The input file that stores all data of the courses
10. **Profs_plist1.txt**: An input file that stores the preference lists of all professors matched with the professor's code
11. **Profs_plist2.txt**: Another plist file
12. **Profs_plist3.txt**: This plist file forces multiple courses to be left unassigned
13. **original_graph.txt**: The original graph gets printed here
14. **output.txt**: The graph with the correct assignments gets orinted here

## Note: To change the plist in use for the program, change line no. 293 in main.cpp to 'populateProfs(professors, profCodes, courses, "Profs.txt", "<plist_filename>");'

## Input Format

Profs.txt:

<img width="200" alt="Profs txt image" src="https://github.com/Arnav3094/DiSCo-Project/assets/80634921/37c74fd1-2855-4481-9bed-e72866ee125f">


The first datapoint is the name of the professor, the second is the professor's code that we have assigned, and the third represents the category, where 1 denotes x1, 2 denotes x2, and 3 denotes x3.


Courses.txt:

<img width="314" alt="Courses txt image" src="https://github.com/Arnav3094/DiSCo-Project/assets/80634921/9a928c1b-3b9e-4e64-b90f-b183f6e77f32">

The first datapoint is the name of the course, the second is the course's code that we have assigned, the third is the type of the course


Profs_plist.txt/Profs_plist2.txt:

<img width="312" alt="Screenshot 2023-12-01 at 12 45 54 AM" src="https://github.com/Arnav3094/DiSCo-Project/assets/80634921/09b824c3-7b7a-4681-a281-2b894fc76823">

The first datapoint is the code of the professor for which that line is the plist, then the courses' codes follow


