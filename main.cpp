#include "main.h"

int main()
{

    int activeRole, input;
    int idCounter = 1;
    int idCounterPr = 1;
    int idCounterAss = 1;
    bool logged,stop;
    string username, password;

    programmerList programmer;
    programmerAddress tempProgrammer;
    userInfo tempUser;

    projectList project;
    projectAddress tempProject;
    ProjectInfo tempPr;

    relationList assignment;
    relationAddress tempRelation;
    assignmentInfo tempAss;

    createProgrammerList(programmer);
    createProjectList(project);
    createRelationList(assignment);

    //logged = true;
    activeRole = 2;

    while(!stop){
        //Login
        cout<<"Username : ";
        cin>>username;
        cout<<"Password : ";
        cin>>password;
        system("CLS");

        Login(username, password, programmer,logged, activeRole, tempProgrammer);

        if(username == "admin" && password == "admin"){
            logged = true;
            activeRole = 1;
        }else if(username == "manager" && password == "manager"){
            logged = true;
            activeRole = 2;
        }

        while(logged){
            input = -1;
            if(activeRole == 1){
                adminMenu(input);
                if(validateInput()){

                    if(input == 1){ // ADD PROGRAMMER

                        cout<<"Username : ";
                        cin>>tempUser.username;
                        while(isUsernameExist(programmer, tempUser.username)){
                            cout<<"Username : ";
                            cin>>tempUser.username;
                        }
                        cout<<"Password : ";
                        cin>>tempUser.password;
                        tempUser.role = 3;
                        tempUser.id = idCounter;
                        idCounter++;
                        tempProgrammer = createProgrammerElmn(tempUser);
                        insertByUsername(programmer, tempProgrammer);
                        cout<<"---------------------------------------"<<endl;
                        cout<<"\t Success"<<endl;
                    }else if(input == 2){ // UPDATE PROGRAMMER
                        getProgrammer(programmer, tempProgrammer);
                        if(tempProgrammer != NULL){
                            cout<<"What do you want to Update ?"<<endl;
                            cout<<"\t 1. Username"<<endl;
                            cout<<"\t 2. Password"<<endl;
                            cout<<"\t 3. Both"<<endl;
                            cout<<"Input Number : ";
                            cin>>input;
                            while(!validateInput()){
                                cin>>input;
                            }
                            updateDataProgrammer(programmer, tempProgrammer,input);
                        }
                    }else if(input == 3){ // DELETE PROGRAMMER
                        getProgrammer(programmer, tempProgrammer);
                        if(tempProgrammer != NULL){
                            deleteDataProgrammer(programmer, tempProgrammer);
                        }
                    }else if(input == 4){ // VIEW PROGRAMMER
                        viewDataProgrammer(programmer);
                    }else if(input == 5){ // ADD PROJECT

                        cout<<"Project Name : ";
                        cin>>tempPr.projectName;
                        cout<<"Deadline (dd mm yy) : ";
                        cin>>tempPr.deadline.dd;
                        while((tempPr.deadline.dd > 31 || tempPr.deadline.dd < 1) && !validateInput()){
                            cin>>tempPr.deadline.dd;
                        }
                        cin>>tempPr.deadline.mm;
                        while((tempPr.deadline.mm > 12 || tempPr.deadline.dd < 1) && !validateInput()){
                            cin>>tempPr.deadline.mm;
                        }
                        cin>>tempPr.deadline.yy;
                        while((tempPr.deadline.yy < 0 || tempPr.deadline.yy > 99) && !validateInput()){
                            cin>>tempPr.deadline.yy;
                        }
                        tempPr.id = idCounterPr;
                        idCounterPr++;
                        tempProject = createProjectElmn(tempPr);
                        insertLast(project, tempProject);
                    }else if(input == 6){ // UPDATE PROJECT
                        getProject(project, tempProject);
                        if(tempProject != NULL){
                            cout<<"What do you want to Update ?"<<endl;
                            cout<<"\t 1. Project Name"<<endl;
                            cout<<"\t 2. Deadline"<<endl;
                            cout<<"\t 3. Both"<<endl;
                            cout<<"Input Number : ";
                            cin>>input;
                            while(!validateInput()){
                                cin>>input;
                            }
                            updateDataProject(tempProject,input);
                        }
                    }else if(input == 7){ // DELETE PROJECT
                        getProject(project, tempProject);
                        if(tempProject != NULL){
                            deleteDataProject(project, tempProject);
                        }
                    }else if(input == 8){ // VIEW PROJECT
                        viewDataProject(project);
                    }else if(input == 9){
                        logged = false;
                        activeRole = 0;
                    }else{

                    }
                }
            }else if(activeRole == 2){
                managerMenu(input);
                if(input == 1){ // ASSIGN PROJECT TO PROGRAMMER
                    tempProgrammer = NULL;
                    tempProject = NULL;

                    //GET THE PROGRAMMER
                    cout<<"---------------------------------------"<<endl;
                    cout<<"Select the Programmer"<<endl;
                    cout<<"---------------------------------------"<<endl;
                    getProgrammer(programmer,tempProgrammer);
                    //GET THE PROJECT
                    cout<<"---------------------------------------"<<endl;
                    cout<<"Select the Project"<<endl;
                    cout<<"---------------------------------------"<<endl;
                    getProject(project, tempProject);
                    cout<<"---------------------------------------"<<endl;

                    if(isAssignmentDuplicate(tempProgrammer, tempProject, assignment)){
                        //CREATE RELATION
                        cout<<"Assignment Description : ";
                        cin>>tempAss.assignmentDesc;
                        cout<<"---------------------------------------"<<endl;
                        cout<<"Assignment Deadline (dd mm yy) : ";
                        cin>>tempAss.deadline.dd;
                        while((tempAss.deadline.dd > 31 || tempAss.deadline.dd < 1) && !validateInput()){
                            cin>>tempAss.deadline.dd;
                        }
                        cin>>tempAss.deadline.mm;
                        while((tempAss.deadline.mm > 12 || tempAss.deadline.dd < 1) && !validateInput()){
                            cin>>tempAss.deadline.mm;
                        }
                        cin>>tempPr.deadline.yy;
                        while((tempAss.deadline.yy < 0 || tempAss.deadline.yy > 99) && !validateInput()){
                            cin>>tempAss.deadline.yy;
                        }
                        cout<<"---------------------------------------"<<endl;
                        tempAss.id = idCounterAss;
                        idCounterAss++;
                        tempRelation = createRelationElmn(tempAss, tempProgrammer, tempProject);
                        insertFirstRelation(assignment, tempRelation);
                    }else{
                        cout<<"Programmer Have been Assigned to this Project";
                    }
                }else if(input == 2){// VIEW ASSIGNMENT DETAIL OF A PROGRAMMER
                    getProgrammer(programmer, tempProgrammer);
                    cout<<"---------------------------------------"<<endl;
                    viewProgrammerAssignment(assignment, tempProgrammer);
                }else if(input == 3){// VIEW ASSIGNMENT DETTAIL OF A PROJECT
                    getProject(project, tempProject);
                    cout<<"---------------------------------------"<<endl;
                    viewProjectAssignment(assignment, tempProject);
                }else if(input == 4){// VIEW ALL PROGRAMMER AND ASSIGNMENT
                    viewDataProgrammer(programmer, assignment, true);
                }else if(input == 5){// VIEW ALL PROJECT AND PROGRAMMER
                    viewDataProject(project);
                }else if(input == 6){// CHANGE ASSIGNMENT STATUS
                    viewDataAssignment(assignment);
                    getAssignment(assignment, tempRelation);
                    updateAssignmentStatus(tempRelation);
                }else if(input == 7){// DELETE AN ASSIGNMENT
                    getAssignment(assignment, tempRelation);
                    deleteDataAssignment(assignment, tempRelation);
                }else if(input == 8){
                    logged = false;
                    activeRole = 0;
                }
            }else if(activeRole == 3){
                cout<<"---------------------------------------"<<endl;
                cout<<"Yout total Assignment " << countDataProgrammerAssignment(assignment, tempProgrammer)<<endl;
                cout<<"---------------------------------------"<<endl;
                viewProgrammerAssignment(assignment,tempProgrammer);
                cout<<"---------------------------------------"<<endl;
                cout<<"Input 9 to Logout \n Your Input : ";
                cin>>input;
                if(input == 9){
                    logged = false;
                    activeRole = 0;
                }
            }else{
                logged = false;
            }
        }
    }
    return 0;

}
