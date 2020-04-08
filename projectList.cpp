#include "main.h"

void createProjectList(projectList &L){
    first(L) == NULL;
}
void viewDataProject(projectList L){
    if (isEmpty(L)){
        cout << "Tidak ada Project saat ini." << endl;
    }else{
        cout << "List Project: " << endl;
    }
}
void insertLast(projectList &L, projectAddress P){
    projectAddress Q = first(L);
    if (first(L) != NULL){
        while (next(Q) != NULL){
            Q = next(Q);
        }
    }
    next(Q) = P;
}
void updateDataProject(){

}
void deleteDataProject(projectList &L, projectAddress &P){
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
}
