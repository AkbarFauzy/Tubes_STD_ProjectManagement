#include "main.h"

void createProjectList(projectList &L){
    first(L) = NULL;
}

projectAddress createProjectElmn(ProjectInfo P){
    projectAddress Q = new projectElmn;
    project(Q).projectName = P.projectName;
    project(Q).deadline = P.deadline;
    project(Q).id = P.id;
    next(Q) = NULL;

    return Q;
}

void viewDataProject(projectList L, relationList A, bool isGetProgrammer){
    projectAddress P = first(L);
    relationAddress R;
    int counter;

    if (first(L) == NULL){
        cout << "Tidak ada Project saat ini." << endl;
    }else{
        cout<<"---------------------------------------"<<endl;
        cout << "List Project: " << endl;
        if (isGetProgrammer){
            cout <<"ID\t\tProject Name\t\tTotal Programmer\t\tDeadline"<<endl;
        }else{
            cout <<"ID\t\tProject Name\t\tDeadline"<<endl;
        }
        while(P!=NULL){
            if(isGetProgrammer){
                R = first(A);
                counter = 0;
                cout<<"Project "<<project(P).projectName<<" Programmer : "<<endl;
                while(R != NULL){
                    if(down(R) == P){
                        counter++;
                    }
                    R = next(R);
                }
                cout<<project(P).id<<"\t\t"<<project(P).projectName<<"\t\t"<<counter<<"\t"<<project(P).deadline.dd<<"-"<<project(P).deadline.mm<<"-"<<project(P).deadline.yy<<endl;
            }else{
                cout<<project(P).id<<"\t\t"<<project(P).projectName<<"\t\t"<<"\t"<<project(P).deadline.dd<<"-"<<project(P).deadline.mm<<"-"<<project(P).deadline.yy<<endl;
            }
            P = next(P);
        }
    }
}

void insertLast(projectList &L, projectAddress P){
    projectAddress Q = first(L);

    if (first(L) == NULL){
        first(L) = P;
    }else{
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }

}

void updateDataProject(projectAddress &P, int type){
    ProjectInfo tempProject;
    if(type == 1 || type == 3){
            cout<<"---------------------------------------"<<endl;
            cout<<"Old Project Name : "<< project(P).projectName<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"New Project Name : ";
            cin>>tempProject.projectName;
            cout<<"---------------------------------------"<<endl;
    }
    if(type == 2 || type == 3){
            cout<<"---------------------------------------"<<endl;
            cout<<"Old Deadline : "<< project(P).projectName<<"\t\t"<<project(P).deadline.dd<<"-"<<project(P).deadline.mm<<"-"<<project(P).deadline.yy<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"New Deadline (dd mm yy): ";
            cin>>tempProject.deadline.dd;
            while(!validateInput() || tempProject.deadline.dd > 31 || tempProject.deadline.dd < 1 ){
                cout<<"Hari tidak valid (1-31), masukan ulang :";
                cin>>tempProject.deadline.dd;
            }
            cin>>tempProject.deadline.mm;
            while(!validateInput() || tempProject.deadline.mm > 12 || tempProject.deadline.dd < 1){
                cout<<"Bulan tidak valid (1-12), masukan ulang :";
                cin>>tempProject.deadline.mm;
            }
            cin>>tempProject.deadline.yy;
            while(!validateInput() || tempProject.deadline.yy < 0 || tempProject.deadline.yy > 99){
                cout<<"Tahun tidak valid (0-99), masukan ulang :";
                cin>>tempProject.deadline.yy;
            }
            cout<<"---------------------------------------"<<endl;
    }

    if(type == 1 || type == 3){
        project(P).projectName = tempProject.projectName;
    }
    if(type == 2 || type == 3){
        project(P).deadline = tempProject.deadline;
    }
}

void deleteDataProject(projectList &L, projectAddress &P, relationList &R){
    projectAddress Q = first(L);
    relationAddress rel = first(R);

    if(P!=NULL){
        if(first(R)!=NULL){
            while(rel!=NULL){
                if(down(rel) == P){
                    deleteDataAssignment(R, rel);
                }
                rel = next(rel);
            }
        }

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
}

projectAddress searchProjectById(projectList L, int projectId){
    projectAddress Q = first(L);
    while(Q!=NULL && project(Q).id != projectId){
        Q = next(Q);
    }
    if(Q == NULL){
        cout<<"Data tidak di temukan"<<endl;
    }
    return Q;
}

void getProject(projectList project, projectAddress &tempProject){
    int input;
    tempProject = NULL;
    cout<<"---------------------------------------"<<endl;
    viewDataProject(project);
    cout<<"---------------------------------------"<<endl;
    cout<<"Select a Project ID: ";
    if(tempProject == NULL){
        cin>>input;
        while(!validateInput()){
            cin>>input;
        }
        tempProject = searchProjectById(project, input);
    }
}



