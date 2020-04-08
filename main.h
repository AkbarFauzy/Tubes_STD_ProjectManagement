#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <conio.h>

#define up(P) P->up
#define down(P) P->down
#define next(P) P->next
#define programmer(P) P->programmer
#define projectName(P) P->projectName
#define deadline(P) P->deadline
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

struct user{
    string username;
    string password;
    int id;
    int role;
};

struct relationElmn{
    programmerAddress up;
    projectAddress down;
    string assignment;
    relationAddress next;
};

struct programmerElmn{
    user programmer;
    programmerAddress next;
};

struct projectElmn{
    string projectName;
    date deadline;
    projectAddress next;
};

const int idCounter = 1;

struct programmerList{programmerAddress first;};
struct projectList{projectAddress first;};

//mainFucntion.cpp
void viewTotalAssignment();
void viewAssignProject();
void programmerMenu();
void managerMenu(int &input);
void adminMenu(int &input);
void Login(bool &logged, int &activeRole);


//Programmer.cpp
void createProgrammerList(programmerList &L);
programmerAddress createProgrammerElmn(user U);
void viewDataProgrammer(programmerList L);
void insertByUsername(programmerList &L, programmerAddress P);
void updateDataProgrammer();
void deleteDataProgrammer(programmerList &L, programmerAddress &P);
bool isUsernameExist(programmerList L, string username);
bool isEmpty(programmerList L);

//Project.cpp
void createProjectList(projectList &L);
void viewDataProject(projectList L);
void insertLast(projectList &L, projectAddress P);
void updateDataProject();
void deleteDataProject(projectList &L, projectAddress &P);

#endif // MAIN_H_INCLUDED
