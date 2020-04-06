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

typedef struct projectElmn *childAddress;
typedef struct programmerElmn *parentAddress;
typedef struct relationElmn *relationAddress;

struct user{
    string username;
    string password;
    //string id;
    int role;
};

struct relationElmn{
    parentAddress up;
    childAddress down;
    relationAddress next;
};

struct programmerElmn{
    user programmer;
    parentAddress next;
};

struct projectElmn{
    string projectName;
    date deadline;
    childAddress next;
};

struct parentList{parentAddress first;};

struct childList{childAddress first;};

//mainFucntion.cpp
void viewTotalAssignment();
void viewAssignProject();
void programmerMenu();
void managerMenu(int &input);
void adminMenu(int &input);
void Login(bool &logged, int &activeRole);


//Programmer.cpp
void createParentList(parentList &L);
parentAddress createParentElmn(user U);
void viewDataProgrammer(parentList L);
void insertByUsername(parentList &L, parentAddress P);
void updateDataProgrammer();
void deleteDataProgrammer();
bool isUsernameExist(parentList L, string username);
bool isEmpty(parentList L);

//Project.cpp
void createChildList(childList &L);
void viewDataProject();
void insertLast();
void updateDataProject();
void deleteDataProject();

#endif // MAIN_H_INCLUDED
