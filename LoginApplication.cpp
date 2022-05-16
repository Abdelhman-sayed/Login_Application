/*FACULTY OF COMPUTERS AND ARTIFICIAL INTELLIGENCE, CAIRO UNIVERSITY
Author :Abdelrhman sayed ali
Program Name: Login Application Program.c plus plus*/


#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <regex>
#include <vector>
#include <fstream>
#include <conio.h>
using namespace std;

/*
file .... >>>>> UsersFile    ...... >>>>  UsersFile get from user data(UserName, PhoneNum, Password, email) in vector

*/

//********************************************************************

//this function to append anew information of new user to the file
void LoadExitingUsers();
//this function to allow user to choice (Registration, login and change password) 
int displayMenu();
//user used this funtion to Registration
void Registration();
//to check this username used before anthor user or no 
void toCheckRegistration();
//to check username vaild or no in case user registration in application
void ToCheckUserName();
//to check number phone vaild or no in case user registration in application
void ToCheckPhonenumber();
//to check this email vaild or no (conected with function (User Registration))
void ToCheckEmail();
/*conected with function (User Registration) and (change password)
and this function contain enter password and confirm password*/
void ToCheckPassword();
//to cover password with (*)
void coverPassword();
//to cover confirmPassword with (*)
void coverConfirmPass();
//user used this funtion to login in this application
void Login();
//to check username vaild or no in case user will login in application 
void ToCheckUserNameLogin();
//to check username exit in data or no when user login 
void toCheckLogin();
//user used this funtion to change password
void ChangePassword();
//to check entered password without  confirm password that used it in case login 
void ToCheckPasswordWConfirm();
//this function to check password when user wanted change password(new password)
void toCheckPasswordToChangePassword();
//this function to cover new password when user wanted change password
void coverChangepassword();
//this function to cover new confirm password when user wanted change password
void coverChangeconfirmpassword();
//to change password from file and updata it with new password 
void changePassInFile();
//to save the new user and his information
void SaveData();
//to cipher password in file
void toCipherPasswordInFile();
//to check login for change password
void toCheckLoginToChangePassword();
//to cipher newpassword in file in case change password
void toCipherNewPasswordInfile();




string UserName;
string PhoneNum;
string Password;
string email;
fstream Usersfile;
string ConfirmPassword;
string newPassword;
string newConfirmPassword;

int choice;
int i = 3;

struct UsersProfile
{
    string UserName;
    string PhoneNum;
    string email;
    string Password;

};
vector<UsersProfile> users;
int main()
{
    system("cls");
   
    cout <<endl << "\n\n         >>>>>***************WELCOME TO THIS LOGIN APPLICATION PROGRAME***************<<<<<\n" << endl;
    cout << "<[============================================================================================================]>\n\n"; 
    LoadExitingUsers();
    /*for(UsersProfile user:users)
    {
        cout << user.UserName << " " << user.Password << " " << endl;
    }*/
    while(true)
    {
        int choice = displayMenu();
        if(choice == 1)
        {
           
            Registration();
            SaveData();
            cout << "\n\n\n<<<<<*********Thank you to Registration in this application********>>>>>\n\n\n" ;
            system("cls");
            displayMenu();
            


        }
        else if(choice == 2)
        {
            Login();
            system("cls");
            displayMenu();
            
            

        }
        else if(choice == 3)
        {
            ChangePassword();
            system("cls");
            displayMenu();
            

        }
        else if(choice == 4)
        {

            cout << "****THANK YOU TO USE THIS APPLICATION****\n";
            return 0;

        }

    }
    
    
}

//this function to append anew information of new user to the file
void LoadExitingUsers()
{
    //users .>> vector
    //vector ... >> nextuser ... >>> struct
    Usersfile.open("UFile.txt", ios::in);
    while (!Usersfile.eof())
    {
        UsersProfile NextUser;

        Usersfile >> NextUser.UserName;
        Usersfile >> NextUser.PhoneNum;
        Usersfile >> NextUser.email;
        Usersfile >> NextUser.Password;
        users.push_back(NextUser);
        

        
    }
  


}
//to save the new user and his information
void SaveData()
{
    Usersfile.close();
    Usersfile.open("UFile.txt", ios::app);
    Usersfile << endl;
    Usersfile << UserName;
    Usersfile <<  "  ";
    Usersfile << PhoneNum;
    Usersfile <<  "  ";
    Usersfile << email;
    Usersfile <<  "  ";
    Usersfile << Password;
    Usersfile <<  "  ";

    Usersfile.close();



}
//this function to allow user to choice (Registration, login and change password) 
int displayMenu()
{
    
    int choice;
    cout << "     <<!=============================PLEASE ENTER THE CHOICE FROM THE LIST==============================!>>\n\n";
    cout <<"(1) Registration\n";
    cout <<"(2) Login\n";
    cout <<"(3) Change Password\n";
    cout <<"(4) Exit\n";
    
    
    while(true)
    {
        cout << "Enter the operation that you want it : \n";
        cin >> choice;
        cout << endl;
        if(choice >= 1 && choice <= 4)
        {
            //system("cls");
            return choice;
            

        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "****Please enter the number (from 1 to 4)****" << endl;
            continue;
        }
        
        

    }
    
    

}

//user used this funtion to Registration
void Registration()
{
    
    cout <<"\n                                     Welcome to register on this site\n";
    ToCheckUserName();
    ToCheckPhonenumber();
    ToCheckEmail();
    ToCheckPassword();
    toCipherPasswordInFile();
}


//to check this username used before anthor user or no 
void toCheckRegistration()
{

    for(UsersProfile user:users)
    {
        
         if(UserName == user.UserName)
         {
            
            cout << "****Try to enter anthor username because this user is already existed by another user with same name****" << endl;
            Registration();
            break;
            
            


         }
         else 
         {
             
            
             //we try to append this new username to file
        }

    }
}




//to check username vaild or no in case user registration in application
void ToCheckUserName()
{
    
    while (true)
    {
        
        cout << ">>>>Please, Enter a username : \n";
        cin >> UserName;

        regex filter("[a-zA-Z0-9]{4,20}");

        std::regex_match(UserName,filter);
        if (std::regex_match(UserName,filter) == 1)
        {
            cout << "****This username is valid****\n" << endl;
            toCheckRegistration();
            break;
        }
        else 
        {
            cout << "****Please.Try again****" << endl;
            cout << "****Enter at least 4 (chars and digits) are allowed****" << endl;
            continue;
        }
    }
}


//to check number phone vaild or no in case user registration in application
void ToCheckPhonenumber()
{
    while (true)
    {
        
        cout << ">>>>Please, Enter you number phone : \n";
        cin >> PhoneNum;

        regex filter("(01)+(0|1|2|5){1}[0-9]{8}");

        std::regex_match(PhoneNum,filter);
        if (std::regex_match(PhoneNum,filter) == 1)
        {

            cout << "****This number phone is valid****" << endl;
            break;
        }
        else 
        {
            cout << "****Please enter the mobile number formats for Egyptian mobile numbers****\n";
            continue;
        }
        
        
    }
    
}

//to check this email vaild or no (conected with function (User Registration))
void ToCheckEmail()
{

    while (true)
    {
        cout << "\n>>>>Please, Enter you email : \n";
        cin >> email;
        regex filter("[a-zA-Z0-9]+[a-zA-Z0-9(\\.)]+((\\w)+)?@[a-z]+[a-z(\\.)]+\\.com");

        std::regex_match(email,filter);
        if (std::regex_match(email,filter) == 1)
        {
            cout << "****This email is valid****" << endl;
            break;
        }
        else 
        {
            cout << "Try again.Please enter email like this form (chars + @ + (char) + . + com)" << endl;
            continue;
            
        }
    }
    

}
/*conected with function (User Registration) and (change password)
and this function contain enter password and confirm password*/
void ToCheckPassword()
{
    
    while (true)
    {
        
        cout << "\n>>>>Please, Enter you password : \n";
        
        coverPassword();
        cout << endl << Password << endl; 
        regex filter("([#-&@]{2,15}[a-zA-Z0-9]{7,20})|([a-zA-Z0-9]{7,20}[#-&@]{2,15})");
       
        std::regex_match(Password,filter);
        if (std::regex_match(Password,filter) == 1)
        {
            cout << "****This password is valid****" << endl;
            cout << "\n>>>>Please, Enter you confirm password : \n";
            
            coverConfirmPass();
            cout << endl << ConfirmPassword << endl;
            
            if(ConfirmPassword == Password)
            {

                cout << "\n****The password has been entered successfully****\n";
                break;
            }
            else
            {
                cout << "****Please, Try enter the password again****\n"; 
                continue;
            }
        }
        else 
        {
            cout << "\n****Please try to enter at least 2(special chars) and at least 7 (chars and digits)****\n" ;
            continue;
        
        }
        
    }
}

//to check entered password without  confirm password that used it in case login 
void ToCheckPasswordWConfirm()
{
    
    while (true)
    {
        
        cout << "\n>>>>Please, Enter you password : \n";
        
        coverPassword();
        regex filter("([#-&@]{2,15}[a-zA-Z0-9]{7,20})|([a-zA-Z0-9]{7,20}[#-&@]{2,15})");
        cout << endl << Password << endl;
        std::regex_match(Password,filter);
        if (std::regex_match(Password,filter) == 1)
        {
            cout << "****This password is valid****" << endl;
           
            break;
            
        }
        else 
        {
            cout << "\n****Please try to enter at least 2(special chars) and at least 7 (chars and digits)****\n" ;
            continue;
        
        }
        
    }
}

//to cover password with (*)
void coverPassword()
{
    Password = "";
    
    char a = _getch();
   
    while ( (a = _getch()) != 13)
        {
             if(a == 8)
            {
                cout << "\b \b";
                if (Password.size() == 0)
                {
                    continue;
                }
                else 
                {
                    Password.pop_back();

                }
            

            }
            else
            {
                putchar('*');
                Password += a;
            
            }
        }
      
        
}
 

//to cover confirmPassword with (*)
void coverConfirmPass()
{
    ConfirmPassword = "";
    char c = _getch();
    while ( (c = _getch()) != 13)
        {
             if(c == 8)
            {
                cout << "\b \b";
                if (ConfirmPassword.size() == 0)
                {
                    continue;
                }
                else 
                {
                    ConfirmPassword.pop_back();

                }
            

            }
            else
            {
                putchar('*');
                ConfirmPassword += c;
            }
        }
        
       
}
    

//user used this funtion to login in this application
void  Login()
{
    cout << "\n                                    ******HALLO USER TO LOGIN******\n" << endl;
    cout << "<[============================================================================================================]>\n"; 
     ToCheckUserNameLogin();
     ToCheckPasswordWConfirm();
     toCipherPasswordInFile();
     toCheckLogin();
     
}

//to check username vaild or no in case user will login in application 
void ToCheckUserNameLogin()
{
    while (true)
    {
        
        cout << ">>>>Please, Enter a username : \n";
        cin >> UserName;

        regex filter("[a-zA-Z0-9]{4,20}");

        std::regex_match(UserName,filter);
        if (std::regex_match(UserName,filter) == 1)
        {
            cout << "****This username is valid****" << endl;
           
            break;
        }
        else 
        {
            cout << "****Please.Try again****" << endl;
            cout << "****Enter at least 4 (chars and digits) are allowed****" << endl;
            continue;
        }
        
        
        
    }
    

}

//to check username exit in data or no when user login 
void toCheckLogin()
{
    
    int flag = 0;
     for(UsersProfile user:users)
     {
        if((UserName == user.UserName) && (Password == user.Password))
        {
            
            flag = 1;
            break;

        }
        else
        {
            flag = 0;
        }

    }
    if(flag == 1)
    {
        cout << "\n<<<<<*****You have successfully entered the site*****>>>>>\n\n" ;
        displayMenu();


    }
    else if(flag == 0)
    {
        cout << "\n*****The password you entered is wrong, try entering the correct password*****\n";
        cout << "****Failed login. Try again****\n" << endl;
        system("cls");
        if(i != 0)
        {
            cout << "<<<<You have " << i << " attempts left>>>>" << endl;
        }

        //system("cls");

        while( i > 0)
        {   
            i -= 1;
            ToCheckUserNameLogin();
            ToCheckPasswordWConfirm();
            toCheckLogin();
            if(i == 0)
            {
                displayMenu();
            }
        }
    
        

    }
}

//user used this funtion to change password
void ChangePassword()
{
    cout << "\n<<<<In order to change the password, you must login first and then allow you to change the password>>>>\n\n";
    ToCheckUserNameLogin();
    ToCheckPasswordWConfirm();
    toCipherPasswordInFile();
    toCheckLoginToChangePassword();
    


    cout << "\n                                    ******Now you are allowed to change your password******\n" << endl;
    cout << "<[============================================================================================================]>\n"; 
    
    toCheckPasswordToChangePassword();
    toCipherNewPasswordInfile();
    changePassInFile();
    cout << "\n<<<<<********Password changed successfully********>>>>>\n\n";
    
}


//this function to check password when user wanted change password(new password)
void toCheckPasswordToChangePassword()
{
    while (true)
    {
        
        cout << "\n>>>>Please, Enter you new password : \n";
        
        coverChangepassword();
        cout << endl << newPassword << endl; 
        regex filter("([#-&@]{2,15}[a-zA-Z0-9]{7,20})|([a-zA-Z0-9]{7,20}[#-&@]{2,15})");
        
        std::regex_match(newPassword,filter);
        if (std::regex_match(newPassword,filter) == 1)
        {
            cout << "****This password is valid****" << endl;
            cout << "\n>>>>Please, Enter you new confirm password : \n";
            coverChangeconfirmpassword();
            
            cout << endl << newConfirmPassword << endl;
            
            if(newConfirmPassword == newPassword)
            {
                cout << "\n****The password has been entered successfully****\n\n";
                break;
            }
            else
            {
                cout << "****Please, Try enter the password again****\n"; 
                continue;
            }
        }
        else 
        {
            cout << "\n****Please try to enter at least 2(special chars) and at least 7 (chars and digits)****\n" ;
            continue;
        
        }
        
    }


}

//to check login for change password
void toCheckLoginToChangePassword()
{
    int flag = 0;
     for(UsersProfile user:users)
     {
        if((UserName == user.UserName) && (Password == user.Password))
        {
            
            flag = 1;
            break;

        }
        else
        {
            flag = 0;
        }

    }
    if(flag == 1)
    {
        cout << "\n<<<<<*****You have successfully entered the site*****>>>>>\n\n" ;
        


    }
    else if(flag == 0)
    {
        cout << "\n*****The password you entered is wrong, try entering the correct password*****\n";
        cout << "****Failed login. Try again****\n" << endl;
        system("cls");
        if(i != 0)
        {
            cout << "<<<<You have " << i << " attempts left>>>>" << endl;
        }

        //system("cls");

        while( i > 0)
        {   
            i -= 1;
            ToCheckUserNameLogin();
            ToCheckPasswordWConfirm();
            toCheckLoginToChangePassword();
            
            if(i == 0)
            {
                displayMenu();
            }
        }
    
        

    }


}
//this function to cover new password when user wanted change password
void coverChangepassword()
{
    
    newPassword = "";
    
    char x = _getch();
   
    while ( (x = _getch()) != 13)
        {
             if(x == 8)
            {
                cout << "\b \b";
                if (newPassword.size() == 0)
                {
                    continue;
                }
                else 
                {
                    newPassword.pop_back();

                }
            

            }
            else
            {
                putchar('*');
                newPassword += x;
            
            }
        }
      
}

//this function to cover new confirm password when user wanted change password
void coverChangeconfirmpassword()
{
    newConfirmPassword = "";
    
    char y = _getch();
   
    while ( (y = _getch()) != 13)
        {
             if(y == 8)
            {
                cout << "\b \b";
                if (newConfirmPassword.size() == 0)
                {
                    continue;
                }
                else 
                {
                    newConfirmPassword.pop_back();

                }
            

            }
            else
            {
                putchar('*');
                newConfirmPassword += y;
            
            }
        }
   
}

//to cipher password in file
void toCipherPasswordInFile()
{
    
    for (int i = 0; i < Password.size(); i++)
    {
        Password[i] = char(int(Password[i] + 1));
        
    }
    cout << Password << endl;
    
}

//to cipher newpassword in file in case change password
void toCipherNewPasswordInfile()
{
    for (int i = 0; i < newPassword.size(); i++)
    {
        newPassword[i] = char(int(newPassword[i] + 1));
        
    }
    cout << newPassword << endl;

}

//to change password from file and updata it with new password 
void changePassInFile()
{
    char line[100];
    
    vector<string> text;
    int k=0;
    Usersfile.close();
    Usersfile.open("UFile.txt");

    while (!Usersfile.eof()) 
    {
        Usersfile.getline(line, 100, '\n');
        text.push_back(string(line));
    }
    int x ,z;
    for (int i=0 ; i<text.size() ; i++)
    {
        if (text[i].find(Password,0)<1000)
        {
            x = text[i].find(Password,0);
            z =i;
        }
    }


    for (int j =x ; j < (x+newPassword.size()) ; j++ )
    {
        text[z][j]=newPassword[k];
        k++;
    }
    Usersfile.close();
    Usersfile.open("UFile.txt",ios::out);
    
    for (int i = 0; i< text.size() ; i++)
    {
        Usersfile << text[i];
        Usersfile << '\n';

    }

    Usersfile.close();

}


//old passord
//new password
//confime new passord

//registration .. >>> after
//login ... >>> before
//change ... >>> after

