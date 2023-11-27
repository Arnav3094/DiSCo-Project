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

## Our Initial Approach

- in Adjacency Matrix, we will not use 1 to denote the edge, we will rather use weights. Where higher weight denotes higher preference of a prof for that course

- weight of 1 is highest preference

- Firstly, we will asign the courses to the professors who have only one course in their preference list

- Then we will assign the courses to the professors who have only two courses in their preference list

- Then we will assign the courses to the professors who have only three courses in their preference list

- And then so on...


- In doing this, we will first assign the courses x1 professors, then x2 professors and then x3 professors


### Input

1. 3 Files: Prof_plist.txt, Courses.txt, Profs.txt

    - Prof_plist.txt: Preference list of each professor
    - Courses.txt: List of courses
    - Profs.txt: List of professors

2. Code for converting text to data inside the code

### Data Structure

Options:

1. Classes
2. Struct
