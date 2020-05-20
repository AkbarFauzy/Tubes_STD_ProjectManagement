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
            activeRole = 3;
        }else{
            logged = false;
            P = NULL;
        }
    }
}

