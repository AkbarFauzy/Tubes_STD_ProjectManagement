#include "main.h"

void createProgrammerList(programmerList &L){
    first(L) = NULL;
}

programmerAddress createProgrammerElmn(user U){
    programmerAddress P = new programmerElmn;
    programmer(P).username = U.username;
    programmer(P).password = U.password;
    programmer(P).role = U.role;
    programmer(P).id = idCounter;
    next(P) = NULL;

    return P;
}


void viewDataProgrammer(programmerList L){
    if(isEmpty(L)){
        cout<<"Tidak ada Programemr saat ini"<<endl;
    }else{
        programmerAddress P = first(L);
        cout<<"List Programmer : "<<endl;
        while(P != NULL){
            cout<<"id: "<<programmer(P).id<<" Username: "<<programmer(P).username<<endl;
            P=next(P);
        }
    }
}

void insertByUsername(programmerList &L, programmerAddress P){
    programmerAddress Q = first(L);
    if(!isEmpty(L)){
        if(programmer(Q).username > programmer(P).username){
            next(P) = Q;
            first(L) = P;
        }else{
            while(programmer(Q).username < programmer(P).username && next(Q) != NULL){
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

void updateDataProgrammer(programmerAddress &P)
{
   /* int input;
    cin>>input;
    if(){
        cin>>programmer(P).username;
    }else if(){
        cin>>programmer(P).password;
    }else if(){
        cin>>programmer(P).username;
        cin>>programmer(P).password;
    }*/
}
void deleteDataProgrammer(programmerList &L, programmerAddress &P){
    programmerAddress Q = first(L);
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
    return found;
}

bool isEmpty(programmerList L){
    return first(L) == NULL;
}

