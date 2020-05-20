#include "main.h"

void createProgrammerList(programmerList &L){
    first(L) = NULL;
}

programmerAddress createProgrammerElmn(userInfo U){
    programmerAddress P = new programmerElmn;
    programmer(P).username = U.username;
    programmer(P).password = U.password;
    programmer(P).role = U.role;
    programmer(P).id = U.id;
    next(P) = NULL;

    return P;
}

void viewDataProgrammer(programmerList L , relationList A, bool isGetTotal ){
    if(isEmpty(L)){
        cout<<"Tidak ada Programmer saat ini"<<endl;
    }else{
        programmerAddress P = first(L);
        cout<<"---------------------------------------"<<endl;
        cout<<"List Programmer : "<<endl;
        if(isGetTotal){
            cout<<"ID"<<" \tUsername"<<"\t Total Assignment"<<endl;
        }else{
            cout<<"ID"<<" \tUsername"<<endl;
        }
        while(P != NULL){
            if(isGetTotal){
                cout<<programmer(P).id<<"\t"<<programmer(P).username<<"\t\t"<<countDataProgrammerAssignment(A,P) <<endl;
            }else{
                cout<<programmer(P).id<<"\t"<<programmer(P).username<<endl;
            }
            P=next(P);
        }
    }
}

int countDataProgrammerAssignment(relationList A, programmerAddress P){
    relationAddress Q = first(A);
    int counter = 0;
    while(Q != NULL){
        if(up(Q) == P){
            counter++;
        }
        Q = next(Q);
    }
    return counter;
}

void insertByUsername(programmerList &L, programmerAddress P){
    programmerAddress Q = first(L);
    if(!isEmpty(L)){
        if(programmer(Q).username > programmer(P).username ){
            next(P) = Q;
            first(L) = P;
        }else{
            while(next(Q) != NULL && programmer(next(Q)).username < programmer(P).username){
                Q = next(Q);
            }
            if(next(Q)==NULL){
                next(Q) = P;
            }else{
                next(P) = next(Q);
                next(Q) = P;
            }
        }
    }else{
        first(L) = P;
    }
}

void updateDataProgrammer(programmerList &L, programmerAddress &P, int type)
{
    userInfo tempUser;
    bool isDuplicate = true;

    while(isDuplicate){
        if(type == 1 || type == 3){
            cout<<"---------------------------------------"<<endl;
            cout<<"Old Username : "<< programmer(P).username<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"New Username : ";
            cin>>tempUser.username;
            cout<<"---------------------------------------"<<endl;
        }
        if(type == 2 || type == 3){
            cout<<"---------------------------------------"<<endl;
            cout<<"Old Password : "<< programmer(P).password<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"New Password : ";
            cin>>tempUser.password;
            cout<<"---------------------------------------"<<endl;
        }
        isDuplicate = isUsernameExist(L, tempUser.username);
    }
    if(type == 1 || type == 3){
        programmer(P).username = tempUser.username;
    }
    if(type == 2 || type == 3){
        programmer(P).password = tempUser.password;
    }

    if(type != 2){
    programmerAddress Q = first(L);

        if (P == first(L)){
            first(L) = next(P);
            next(P) = NULL;
        }else{
            while(next(Q)!= P){
                Q = next(Q);
            }
            if(next(next(Q))==NULL){
                next(Q) = NULL;
            }else{
                next(Q) = next(P);
                next(P) = NULL;
            }
        }
        insertByUsername(L,P);
    }
}

void deleteDataProgrammer(programmerList &L, programmerAddress &P, relationList &R){
    programmerAddress Q = first(L);
    relationAddress rel = first(R);

    if(P!=NULL){
        if(first(R)!=NULL){
            while(rel!=NULL){
                if(up(rel) == P){
                    deleteDataAssignment(R, rel);
                }
                rel = next(rel);
            }
        }

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

programmerAddress searchProgrammerById(programmerList L, int userId){
    programmerAddress Q = first(L);
    while(Q!=NULL && programmer(Q).id != userId){
        Q = next(Q);
    }
    if(Q == NULL){
        cout<<"Data tidak di temukan"<<endl;
    }
    return Q;
}

bool isUsernameExist(programmerList L, string username){
    programmerAddress P = first(L);
    bool found = false;
    while(!found && P != NULL){
        found = programmer(P).username == username;
        P=next(P);
    }
    if(found){
        cout<<"---------------------------------------"<<endl;
        cout<<"Username Already Exist"<<endl;
        cout<<"---------------------------------------"<<endl;
    }
    return found;
}

bool isEmpty(programmerList L){
    return first(L) == NULL;
}

void getProgrammer(programmerList programmer, programmerAddress &tempProgrammer){
    int input;

    tempProgrammer = NULL;
    cout<<"---------------------------------------"<<endl;
    viewDataProgrammer(programmer);
    cout<<"---------------------------------------"<<endl;
    cout<<"Select a Programmer ID: ";
    if(tempProgrammer == NULL){
        cin>>input;
        while(!validateInput()){
            cin>>input;
        }
        tempProgrammer = searchProgrammerById(programmer, input);
    }
}
