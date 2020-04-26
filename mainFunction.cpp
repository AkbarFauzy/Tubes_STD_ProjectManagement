#include "main.h"

bool validateInput(){
    if (cin.fail())
    {
     cout << "Please enter a Number"<<endl;
     cin.clear();
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     return false;
    }
    return true;
}

void viewProgrammerAssignment(relationList L, programmerAddress P){
    relationAddress Q = first(L);
    cout<<programmer(P).username<<" Assignment : "<<endl;
    cout<<"Project \t Assignment \t Status \t Deadline"<<endl;
    while(Q != NULL){
        if(up(Q) == P){
            cout<<project(down(Q)).projectName<<"\t"<<assignment(Q).assignmentDesc<<"\t"<<getProjectStatus(assignment(Q).status)<<"\t"<<project(down(Q)).deadline.dd<<"-"<<project(down(Q)).deadline.mm<<"-"<<project(down(Q)).deadline.yy<<endl;
        }
        Q = next(Q);
    }
}

void viewProjectAssignment(relationList L, projectAddress P){
    relationAddress Q = first(L);
    cout<<project(P).projectName<<" Programmer : "<<endl;
    cout<<"Username \t Assignment \t Status"<<endl;
    while(Q != NULL){
        if(down(Q) == P){
            cout<<programmer(up(Q)).username<<"\t"<<assignment(Q).assignmentDesc<<"\t"<<getProjectStatus(assignment(Q).status)<<endl;
        }
        Q = next(Q);
    }
}

void programmerMenu(){
    cout<<"---------------------------------------"<<endl;
    cout<<"\t 1. View all project"<<endl;
    cout<<"\t 2. View all project deadline"<<endl;
    cout<<"---------------------------------------"<<endl;
}
void managerMenu(int &input){
    cout<<"---------------------------------------"<<endl;
    cout<<"\t 1. Assign Project to Programmer"<<endl;
    cout<<"\t 2. View Assignment Detail of a Programmer"<<endl;
    cout<<"\t 3. View Assignment Detail of a Project"<<endl;
    cout<<"\t 4. View All Programmer and Assignment"<<endl;
    cout<<"\t 5. View All Project and Programmer"<<endl;
    cout<<"\t 6. Change Assignment Status"<<endl;
    cout<<"\t 7. Delete an Assignment"<<endl;
    cout<<"\t 8. Logout"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Your Input : ";
    cin>>input;
    system("CLS");
}

void adminMenu(int &input){
    cout<<"---------------------------------------"<<endl;
    cout<<"\t 1. Add a Programmer"<<endl;
    cout<<"\t 2. Update a Programmer"<<endl;
    cout<<"\t 3. Delete a Programmer"<<endl;
    cout<<"\t 4. View All Programmer"<<endl;
    cout<<"\t 5. Add a Project"<<endl;
    cout<<"\t 6. Update a Project"<<endl;
    cout<<"\t 7. Delete a Project"<<endl;
    cout<<"\t 8. View all Project"<<endl;
    cout<<"\t 9. Logout"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Your Input : ";
    cin>>input;
    system("CLS");
}

void Login(string username, string password, programmerList L, bool &logged, int &activeRole, programmerAddress &P){
    P = first(L);
    while(P !=NULL && programmer(P).username != username){
        P = next(P);
    }
    if(P != NULL){
        if(programmer(P).password == password){
            logged = true;
        }else{
            logged = false;
            P = NULL;
        }
    }
}

void createRelationList(relationList &L){
    first(L) = NULL;
}

relationAddress createRelationElmn(assignmentInfo R, programmerAddress P, projectAddress Pr){
    relationAddress Q = new relationElmn;
    assignment(Q).id = R.id;
    assignment(Q).assignmentDesc = R.assignmentDesc;
    assignment(Q).deadline = R.deadline;
    assignment(Q).status = 1;
    up(Q) = P;
    down(Q) = Pr;
    next(Q) = NULL;

    return Q;

}

void insertFirstRelation(relationList &L, relationAddress P){
    if(first(L)==NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void deleteDataAssignment(relationList &L, relationAddress &P){
    relationAddress Q = first(L);
    if(P == first(L)){
        first(L) = next(P);
        next(P) = NULL;
    }else{
        while(next(Q)!=P){
            Q = next(Q);
        }
        if(next(next(Q))==NULL){
            next(Q) = NULL;
        }else{
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
}

void viewDataAssignment(relationList L){

}

relationAddress searchAssignmentById(relationList L, int input){
    relationAddress Q = first(L);
    while(Q!=NULL && assignment(Q).id != input){
        Q = next(Q);
    }
    if(Q == NULL){
        cout<<"Data tidak di temukan"<<endl;
    }
    return Q;
}

void getAssignment(relationList assignment, relationAddress &tempAssignment){
    int input;

    tempAssignment = NULL;
    cout<<"---------------------------------------"<<endl;
    viewDataAssignment(assignment);
    cout<<"---------------------------------------"<<endl;
    cout<<"Select an Assignment ID: ";
    while(tempAssignment == NULL){
        cin>>input;
        while(!validateInput()){
            cin>>input;
        }
        tempAssignment = searchAssignmentById(assignment, input);
    }
}

void updateAssignmentStatus(relationAddress &P){
    int input;

    cout<<"Select the Status"<<endl;
    cout<<"1. Not Started"<<endl;
    cout<<"2. In Progress"<<endl;
    cout<<"3. On Hold"<<endl;
    cout<<"4. Completed"<<endl;
    cin>>input;
    while(!validateInput() || (input < 1 && input > 4)){
        cin>>input;
    }
    assignment(P).status = input;
}

bool isAssignmentDuplicate(programmerAddress tempProgrammer, projectAddress tempProject, relationList A){
    bool isDuplicate;
    relationAddress P = first(A);

    if(tempProgrammer == NULL || tempProject == NULL){
        return false;
    }

    isDuplicate = up(P) == tempProgrammer && down(P) == tempProject;
    while(!isDuplicate && P != NULL){
        P = next(P);
        isDuplicate = up(P) == tempProgrammer && down(P) == tempProject;
    }

    return isDuplicate;
}
