#include "main.h"

int main()
{

    int activeRole, input;
    bool logged,stop;
    string username, password;

    parentList parent;
    childList child;

    createParentList(parent);
    createChildList(child);

    logged = true;
    activeRole = 1;

    while(!logged){
        //Login
        cout<<"Username :";
        cin>>username;
        cout<<"Password : ";
        cin>>password;
        Login(logged, activeRole);
    }
    while(!stop){
        input = -1;
        if(activeRole == 1){
            adminMenu(input);
            if(input == 1){

                user tempUser;
                parentAddress newProgrammer;

                cout<<"Username : ";
                cin>>tempUser.username;
                while(isUsernameExist(parent, tempUser.username)){
                    cout<<"Username : ";
                    cin>>tempUser.username;
                }
                cout<<"Password : ";
                cin>>tempUser.password;
                tempUser.role == 3;
                newProgrammer = createParentElmn(tempUser);
                insertByUsername(parent, newProgrammer);
            }else if(input == 2){

            }else if(input == 3){

            }else if(input == 4){
                viewDataProgrammer(parent);
            }else if(input == 5){

            }else if(input == 6){

            }else if(input == 7){

            }else if(input == 8){

            }else{

            }
        }else if(activeRole == 2){
            managerMenu(input);
            if(input == 1){

            }else if(input == 2){

            }else if(input == 3){

            }else if(input == 4){

            }else if(input == 5){

            }else if(input == 6){

            }else if(input == 7){

            }else if(input == 8){

            }else{

            }
        }else if(activeRole == 3){
            // programmerMenu(input);
        }else{
            logged = false;
        }
    }
    return 0;

}
