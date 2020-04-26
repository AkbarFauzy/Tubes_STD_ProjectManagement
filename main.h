#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <limits>

#define up(P) P->up
#define down(P) P->down
#define assignment(P) P->assignment
#define next(P) P->next
#define programmer(P) P->programmer
#define project(P) P->project
#define first(L) L.first

using namespace std;

struct date{
    int dd;
    int mm;
    int yy;
};

typedef struct projectElmn *projectAddress;
typedef struct programmerElmn *programmerAddress;
typedef struct relationElmn *relationAddress;

struct userInfo{
    int id;
    string username;
    string password;
    int role;
};

struct ProjectInfo{
    int id;
    string projectName;
    date deadline;
};

struct assignmentInfo{
    int id;
    string assignmentDesc;
    date deadline;
    int status;
};

struct relationElmn{
    programmerAddress up;
    projectAddress down;
    assignmentInfo assignment;
    relationAddress next;
};

struct programmerElmn{
    userInfo programmer;
    programmerAddress next;
};

struct projectElmn{
    ProjectInfo project;
    projectAddress next;
};

struct programmerList{programmerAddress first;};
struct projectList{projectAddress first;};
struct relationList{relationAddress first;};

//mainFucntion.cpp
bool validateInput();
void viewTotalAssignment();
void viewProgrammerAssignment(relationList L, programmerAddress P);
void viewProjectAssignment(relationList L, projectAddress P);
void programmerMenu(int &input);
void managerMenu(int &input);
void adminMenu(int &input);
void Login(string username, string password, programmerList L,bool &logged, int &activeRole, programmerAddress &tempProgrammer);

//relation.cpp
void createRelationList(relationList &L);
relationAddress createRelationElmn(assignmentInfo R, programmerAddress P, projectAddress Pr);
void insertFirstRelation(relationList &L, relationAddress P);
void viewDataAssignment(relationList L);
relationAddress searchAssignmentById(relationList L, int input);
void getAssignment(relationList assignment, relationAddress &tempAssignment);
void updateAssignmentStatus(relationAddress &P);
void deleteDataAssignment(relationList &L, relationAddress &P);
bool isAssignmentDuplicate(programmerAddress tempProgrammer, projectAddress tempProject, relationList A);

//Programmer.cpp
void createProgrammerList(programmerList &L);
programmerAddress createProgrammerElmn(userInfo U);
void viewDataProgrammer(programmerList L, relationList A = {NULL}, bool isGetTotal = false);
int countDataProgrammerAssignment(relationList A, programmerAddress P);
void insertByUsername(programmerList &L, programmerAddress P);
void updateDataProgrammer(programmerList &L, programmerAddress &P, int type);
void deleteDataProgrammer(programmerList &L, programmerAddress &P);
programmerAddress searchProgrammerById(programmerList L, int userId);
bool isUsernameExist(programmerList L, string username);
bool isEmpty(programmerList L);
void getProgrammer(programmerList programmer, programmerAddress &tempProgrammer);

//Project.cpp
void createProjectList(projectList &L);
projectAddress createProjectElmn(ProjectInfo P);
void viewDataProject(projectList L, relationList A = {NULL}, bool isGetProgrammer = false);
void insertLast(projectList &L, projectAddress P);
void updateDataProject(projectAddress &P, int type);
void deleteDataProject(projectList &L, projectAddress &P);
projectAddress searchProjectById(projectList L, int projectId);
void getProject(projectList programmer, projectAddress &tempProject);
string getProjectStatus(int S);

#endif // MAIN_H_INCLUDED
