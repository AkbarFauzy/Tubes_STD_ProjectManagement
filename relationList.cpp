#include "main.h"

void viewProgrammerAssignment(relationList L, programmerAddress P){
    relationAddress Q = first(L);
    if(P!=NULL){
        cout<<programmer(P).username<<" Assignment : "<<endl;
        cout<<"Project\t\tAssignment\t\tStatus\t\tDeadline"<<endl;
        while(Q != NULL){
            if(up(Q) == P){
                cout<<project(down(Q)).projectName<<"\t\t"<<assignment(Q).assignmentDesc<<"\t\t"<<getAssignmentStatus(assignment(Q).status)<<"\t\t "<<project(down(Q)).deadline.dd<<"-"<<project(down(Q)).deadline.mm<<"-"<<project(down(Q)).deadline.yy<<endl;
            }
            Q = next(Q);
        }
    }
}

void viewProjectAssignment(relationList L, projectAddress P){
    relationAddress Q = first(L);
    if(P!=NULL){
        cout<<project(P).projectName<<" Programmer : "<<endl;
        cout<<"Username\t\tAssignment\t\tStatus"<<endl;
        while(Q != NULL){
            if(down(Q) == P){
                cout<<programmer(up(Q)).username<<"\t\t"<<assignment(Q).assignmentDesc<<"\t\t"<<getAssignmentStatus(assignment(Q).status)<<endl;
            }
            Q = next(Q);
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
    if(P!=NULL){
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
}

void viewDataAssignment(relationList L){
    if(first(L)==NULL){
        cout<<"Tidak ada Assignment saat ini"<<endl;
    }else{
        relationAddress P = first(L);
        cout<<"---------------------------------------"<<endl;
        cout<<"List Assignment : "<<endl;
        cout<<"ID\tProject\tProgrammer"<<endl;
        while(P != NULL){
            cout<<assignment(P).id<<"\t"<<project(down(P)).projectName<<"\t"<<programmer(up(P)).username<<endl;
            P=next(P);
        }
    }
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
    if(tempAssignment == NULL){
        cin>>input;
        while(!validateInput()){
            cin>>input;
        }
        tempAssignment = searchAssignmentById(assignment, input);
    }
}

void updateAssignmentStatus(relationAddress &P){
    int input;
    cout<<"1. Not Started"<<endl;
    cout<<"2. In Progress"<<endl;
    cout<<"3. On Hold"<<endl;
    cout<<"4. Completed"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Select the Status"<<endl;
    cin>>input;
    while(!validateInput() || (input < 1 && input > 4)){
        cin>>input;
    }
    assignment(P).status = input;
}

bool isAssignmentDuplicate(programmerAddress tempProgrammer, projectAddress tempProject, relationList A){
    bool isDuplicate = false;
    relationAddress P;

    if(tempProgrammer == NULL || tempProject == NULL || first(A) == NULL){
        return false;
    }

    P = first(A);
    while(!isDuplicate && P != NULL){
        isDuplicate = up(P) == tempProgrammer && down(P) == tempProject;
        P = next(P);
    }

    return isDuplicate;
}

void printProgrammerAssignmentByDate(relationList R, programmerAddress P){
    relationList temp;
    relationAddress Q = first(R);
    relationAddress tempAdr;

    createRelationList(temp);

    if(first(R)!=NULL){
        while(Q != NULL){
            if(up(Q) == P){
                tempAdr = createRelationElmn(assignment(Q), up(Q), down(Q));
                insertRelationByDate(temp, tempAdr);
            }
            Q = next(Q);
        }
        Q = first(temp);
        while(Q != NULL){
            cout<<" Project : "<<project(down(Q)).projectName<<" Desc : "<< assignment(Q).assignmentDesc<<" Deadline : "<<project(down(Q)).deadline.dd<<"-"<<project(down(Q)).deadline.mm<<"-"<<project(down(Q)).deadline.yy<<endl;
            Q = next(Q);
        }
    }
}

void insertRelationByDate(relationList &L, relationAddress Q){
    relationAddress P = first(L);

    if(first(L)!=NULL){
        if(project(down(Q)).deadline.yy < project(down(P)).deadline.yy){
            next(Q) = P;
            first(L) = Q;
        }else if(project(down(Q)).deadline.yy <= project(down(P)).deadline.yy && project(down(Q)).deadline.mm < project(down(P)).deadline.mm){
            next(Q) = P;
            first(L) = Q;
        }else if((project(down(Q)).deadline.yy <= project(down(P)).deadline.yy && project(down(Q)).deadline.mm <= project(down(P)).deadline.mm) && (project(down(Q)).deadline.dd < project(down(P)).deadline.dd)){
            next(Q) = P;
            first(L) = Q;
        }else{
            while(next(P) != NULL && project(down(Q)).deadline.yy > project(down(next(P))).deadline.yy){
                P = next(P);
            }
            if(next(P) != NULL && project(down(Q)).deadline.yy >= project(down(next(P))).deadline.yy){
                while(next(P) != NULL && project(down(Q)).deadline.mm > project(down(next(P))).deadline.mm){
                    P = next(P);
                }
            }
            if(next(P) != NULL && project(down(Q)).deadline.yy >= project(down(next(P))).deadline.yy && project(down(Q)).deadline.mm >= project(down(next(P))).deadline.mm){
                while(next(P) != NULL && project(down(Q)).deadline.dd > project(down(next(P))).deadline.dd){
                    P = next(P);
                }
            }

            if(next(P) == NULL){
                cout<<project(down(Q)).projectName;
                next(P) = Q;
            }else{
                next(Q) = next(P);
                next(P) = Q;
            }
        }
    }else{
        first(L) = Q;
    }
}

string getAssignmentStatus(int S){
    if(S == 1){
        return "Not Started";
    }else if(S == 2){
        return "In Progress";
    }else if(S == 3){
        return "On Hold";
    }else if(S == 4){
        return "Completed";
    }else{
        return "ERROR";
    }
}
