#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void adminlogin();
void userlogin();
void userregistor();
void userforgot();
void addfood();
void selectfood();
void selectfood1();

int counter = counter + 1;
string fName;
int fPrice, SrNo, fQuantity, total;
int main()
{
    int choice;
    cout << "\t\t\t____________________________________________________________________\n\n\n";
    cout << "\t\t\t                         Welcome to Login Page                      \n\n\n";
    cout << "\t\t\t___________________      Food Order System           _______________\n\n\n";
    cout << "                                                                          \n\n";
    cout << "\t Press 1 to Admin Login                        " << endl;
    cout << "\t Press 2 to User Login                         " << endl;
    cout << "\t Press 3 to Forgot Password for User           " << endl;
    cout << "\n\tEnter your choice : ";
    cin >> choice;
    switch (choice)
    {   
    case 1:
        adminlogin();
        break;

    case 2:
        userlogin();
        break;

    case 3:
        userforgot();
        break;

    default:
        cout << "Please select Right Option \n"
             << endl;
        // system("cls");
        main();
    }
    return 0;
}

void adminlogin()
{
    string Admin, pass;
    cout << "Enter AdminID: " << endl;
    cin >> Admin;
    cout << "Enter Password: " << endl;
    cin >> pass;
    if (Admin == "Admin" && pass == "Admin123")
    {
        cout << "Login Success! ";
        addfood();
    }
    else
    {
        cout << "\n\n\nWrong Id or Password! \n";
        main();
    }
}

void userlogin()
{
    int count;
    string userid, password, id, pass;
    system("cls");
    cout << "Please enter UserName: " << endl;
    cin >> userid;
    cout << "Please enter PassWord: " << endl;
    cin >> password;

    ifstream input("record.txt"); // reads from record file
    while (input >> id >> pass)
    {
        if (id == userid && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << userid << " Your Login is Successful \n";
        selectfood();
    }
    else
    {
        userregistor();
    }
}

void userregistor()
{
    string ruser, rpassword; //, rid, rpass;
    system("cls");
    cout << "Please do Register! \n\n\n";
    cout << "\t Enter UserName: " << endl;
    cin >> ruser;
    cout << "\t Enter Password: " << endl;
    cin >> rpassword;

    ofstream f1("record.txt", ios::app); // open record file to write
    f1 << ruser << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration successful! \n";
    main();
}

void userforgot()
{
    int option;
    // system("cls");
    cout << " Press 1 to search your Password by username " << endl;
    cout << " Press 2 to Main Menu " << endl;
    cout << " Enter your choice : ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suser, sid, spass;
        cout << "\n\t\t Enter the username which you remembered : ";
        cin >> suser;

        ifstream f2("record.txt"); // read from record file
        while (f2 >> sid >> spass)
        {
            if (sid == suser)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account found! \n";
            cout << "\n\n Your password is : " << spass;
            main();
        }
        else
        {
            cout << "Your account not found \n Please Create new account... \n";
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }
    default:
        cout << "\t\t\t Wrong choice! Please try again... " << endl;
        userforgot();
    }
}

void addfood()
{
    int choice;
    system("cls");
    cout << "\t\t\t____________________________________________________________________\n\n\n";
    cout << "\t\t\t                         Welcome to Admin Page                      \n\n\n";
    cout << "\t\t\t___________________      Food Order System           _______________\n\n\n";
    cout << "                                                                            \n\n";
    cout << "\t Press 1 to Add food                           " << endl;
    cout << "\t Press 2 to Exit                               " << endl;
    cout << "\n\tEnter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        SrNo = counter;
        counter++;
        cout << "Enter Food name: " << endl;
        cin >> fName;
        cout << "Enter Food Price (in Rs): " << endl;
        cin >> fPrice;
        cout << "Enter Food quantity: " << endl;
        cin >> fQuantity;
        ofstream f9("record1.txt", ios::app); // Write in record1
        f9 << SrNo << " " << fName << "       " << ':' << " " << fPrice << "Rs"
           << " " << fQuantity << "(items left)" << endl;
        cout << "Food Added Successfully...";
        addfood();
    }

    case 2:
    {
        main();
        break;
    }

    default:
        cout << "Please select Right Option... \n"
             << endl;
        system("cls");
        addfood();
    }
}

void selectfood()
{
    int choice;
    cout << "\t\t\t_____________________________________________________________________\n\n\n";
    cout << "\t\t\t                         Welcome to Select Food                      \n\n\n";
    cout << "\t\t\t___________________      Food Order System           ________________\n\n\n";
    cout << "                                                                             \n\n";
    cout << "\t Press 1 to Select Food                          " << endl;
    cout << "\t Press 2 to Exit                               " << endl;
    cout << "\n\tEnter your choice : ";
    cin >> choice;
    switch (choice)
    {

    case 1:
    {
        string st;
        ifstream f5("record1.txt"); // read from record1 and shows output
        while (f5.eof() == 0)
        {
            getline(f5, st);
            cout << st << endl;
        }
        f5.close();
        selectfood1();
        break;
    }

    case 2:
    {
        main();
    }

    default:
        cout << "Please select right option...";
    }
}

void selectfood1()
{
    int choice;
    cout << "\n\tEnter your Food Number : ";
    cin >> choice;
    while (choice != 0)
    {
        int Quant123;
        cout << "Enter Quantity you want : " << endl;
        cin >> Quant123;
        total = Quant123 * 20;
        cout << total << endl;
        break;
    }
}