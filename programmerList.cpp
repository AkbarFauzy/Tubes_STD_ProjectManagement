#include "main.h"

void createParentList(parentList &L){
    first(L) = NULL;
}

parentAddress createParentElmn(user U){
    parentAddress P = new programmerElmn;
    programmer(P).username = U.username;
    programmer(P).password = U.password;
    programmer(P).role = U.role;
    next(P) = NULL;
    return P;
}


void viewDataProgrammer(parentList L){
    if(isEmpty(L)){
        cout<<"Tidak ada Programemr saat ini"<<endl;
    }else{
        parentAddress P = first(L);
        cout<<"List Programmer : "<<endl;
        while(P != NULL){
            cout<<programmer(P).username<<endl;
            P=next(P);
        }
    }
}

void insertByUsername(parentList &L, parentAddress P){
    parentAddress Q = first(L);
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

void updateDataProgrammer()
{

}
void deleteDataProgrammer(){

}

bool isUsernameExist(parentList L, string username){
    parentAddress P = first(L);
    bool found = false;
    while(!found && P != NULL){
        found = programmer(P).username == username;
        P=next(P);
    }
    return found;
}

bool isEmpty(parentList L){
    return first(L) == NULL;
}

