#include "main.h"


void viewTotalAssignment(){

}
void viewAssignProject(){

}
void programmerMenu(){
    //cout<<""<<endl;
    cout<<"1. View all project"<<endl;
    cout<<"2. View all project deadline"<<endl;
}
void managerMenu(int &input){
    cout<<"1. Assign Project to Programmer"<<endl;
    cout<<"2. View Assignment Detail of a Programmer"<<endl;
    cout<<"3. View Assignment Detail of a Project"<<endl;
    cout<<"4. View All Programmer and Assignment"<<endl;
    cout<<"5. View All Project and Programmer"<<endl;
    cout<<"6. Change Assignment Status"<<endl;
    cout<<"7. Delete an Assignment"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Your Input : ";
    cin>>input;
}


void adminMenu(int &input){
    cout<<"1. Add a Programmer"<<endl;
    cout<<"2. Update a Programmer"<<endl;
    cout<<"3. Delete a Programmer"<<endl;
    cout<<"4. View All Programmer"<<endl;
    cout<<"5. Add a Project"<<endl;
    cout<<"6. Update a Project"<<endl;
    cout<<"7. Delete a Project"<<endl;
    cout<<"8. View all Project"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Your Input : ";
    cin>>input;
}
void Login(bool &logged, int &activeUser){

}
