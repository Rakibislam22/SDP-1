#include<iostream>
#include<cstdio>
#include<fstream>
#include <unistd.h>
#include<cstdlib>    // for exit() function
#include<conio.h>    // for getch() function
#include<cstdio>    // for system("cls") function

using namespace std;
class student
{

private:
    string name,address,phn_no;
    int class_,roll,fee,demand,due;
public:
    string usn;
    int s,choice,n,r,pass,total=0 ;
    void menu();
    void PasswordCng();
    void submenu();
    void insert();
    void display();
    void search();
    void delet();
    void feesMenu();
    void newFeesAdd();
    void displayFees();
    void studentFees();
    void updateFees();
};

enum IN
{

    IN_BACK = 8,
    IN_RET = 13

};

std::string hidingPas(
    char sp = '*')
{
    string passwd = "";
    char ch_ipt;

    while (true)
    {

        ch_ipt = getch();

        if (ch_ipt == IN::IN_RET)
        {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() != 0)
        {
            passwd.pop_back();

            cout << "\b \b";

            continue;
        }

        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() == 0)
        {
            continue;
        }

        passwd.push_back(ch_ipt);
        cout << sp;
    }
}

void student :: PasswordCng()
{
d:
    int passCI,passC,passN,passCo;
    system("cls");
    fstream file;
    cout<<"\n\t\t\t Enter Current PIN: ";
    passC = stoi(hidingPas());
    cout<<"\t\t\t Enter New PIN: ";
    passN = stoi(hidingPas()) ;
    cout<<"\t\t\t Enter Conform PIN: ";
    passCo = stoi(hidingPas());
    file.open("PIN.txt", ios::in);
    file>>passCI;
    if(!file)
    {
        cout<<"Error !! Try again!";
        file.close();
    }

    else if(passCI==passC)
    {
        if(passN==passCo)
        {
            fstream file;
            file.open("PIN.txt", ios::out);
            file<<passCo;
            file.close();
            cout<<"\n\t\t\tPIN Changed Successfully.. ";
            cout<<"\n\n # Press Enter key for Main menu...!";
            getch();


        }
        else
        {
            file.close();
            cout<<"\n\t\t** New PIN And Conform PIN Not Matched..!";
            cout<<"\n\n # Press Enter key for Main menu...!";
            getch();

        }
    }
    else
    {
        cout<<"\n\t\t** Incorrect Current PIN...!";
        cout<<"\n\n\n # Press Enter key for Main menu...!";
        file.close();
        getch();

    }
}

void student :: menu()
{
a:
    system("cls");
    cout<<"\t\t\t\t-----------------------------"<<endl;
    cout<<"\t\t\t\t| SCHOOL MANAGEMENT SYSTEM  |"<<endl;
    cout<<"\t\t\t\t-----------------------------"<<endl;
    cout<<"\n\t\t\t\t   1. Admin LogIn "<<endl;
    cout<<"\t\t\t\t   2. Student Info "<<endl;
    cout<<"\t\t\t\t   3. Cancel "<<endl<<endl;
    cout<<"\t\t\t\t  ------------------------"<<endl;
    cout<<"\t\t\t\t   Choose Option : [1/2/3]"<<endl;
    cout<<"\t\t\t\t  ------------------------"<<endl;

    cout<<"Enter Your Choose: ";
    cin>>s;
    switch(s)
    {
    case 1:
    {

        system("cls");
        int pass1,pass2=1234;
        cout<<"\n\t *** Username And PIN Provided by only School Authority *** ";
        cout<<"\n\n\t\t\t Enter username: ";
        cin>>usn;
        cout<<"\n\t\t\t Enter PIN: ";
        pass1 = stoi(hidingPas());
        fstream file;
        file.open("PIN.txt",ios :: in);
        if(!file)
        {
            fstream file;
            file.open("PIN.txt", ios::out);
            file<<pass2;
            file.close();
        }
        file>>pass;
        if(pass==pass1)
        {
            file.close();
            submenu();
        }
        else
        {
            system("cls");
            cout<<"\n\t\t\t* Incorrect Username or Password!"<<endl;
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        break;
    }

    case 2:
        search();
        char de;
        cout<<"\n\n\t\t\t Do you want to see Fees Details [Y/N]: ";
        cin>>de;
        cout<<endl;
        if(de == 'Y' || de == 'y')
        {
            studentFees();
        }
        else cout<<"\n # Press Enter key for Main menu...!";
        break;
    case 3:
        cout<<"\n\n\t\t\t  Thanks for using our software."<<endl<<"\n\t\t\tAll rights reserved, (c) 2024 Akatsuki."<<endl<<endl<<endl;
        exit(0);
        break;

    default:
        cout<<"\n\t\t\t\t Invalid Choice..! Please Try Again..!";
        cout<<"\n\n # Press Enter key for Main menu...!";
        break;
    }
    getch();
    goto a;
}

void student::submenu()
{
menustart:
    char x;
    system("cls");
    cout<<"\t\t\t\t-----------------------------"<<endl;
    cout<<"\t\t\t\t| SCHOOL MANAGEMENT SYSTEM  |"<<endl;
    cout<<"\t\t\t\t-----------------------------"<<endl;
    cout<<"\t\t\t\t Profile: "<<usn<<endl;
    cout<<"\n\t\t\t\t 1. Enter New student Record"<<endl;
    cout<<"\t\t\t\t 2. Display student Record"<<endl;
    cout<<"\t\t\t\t 3. Search student Record"<<endl;
    cout<<"\t\t\t\t 4. Delete student Record"<<endl;
    cout<<"\t\t\t\t 5. Fees Details"<<endl;
    cout<<"\t\t\t\t 6. Change PIN"<<endl;
    cout<<"\t\t\t\t 7. LogOut"<<endl<<endl;

    cout<<"\t\t\t\t------------------------------"<<endl;
    cout<<"\t\t\t\t Choose Option : [1/2/3/4/5/6/7]"<<endl;
    cout<<"\t\t\t\t------------------------------"<<endl;
    cout<<"Enter Your Choose: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        do
        {
            insert();
            cout<<"\n\t\t Add Another Student Record [Y,N]: ";
            cin>>x;
        }
        while(x=='Y' || x=='y');
        cout<<"\n\n # Press Enter key for Main menu...!";
        break;
    case 2:
        display();
        break;
    case 3:
        search();
        break;
    case 4:
        delet();
        break;

    case 5:
        feesMenu();
        break;
    case 6:
        PasswordCng();
        break;

    case 7:
        cout<<"\n\n\t\t\t\t   LOGOUT!\n\n\t\t\t  Thanks for using our software."<<endl<<"\n\t\t\tAll rights reserved, (c) 2024 Akatsuki."<<endl<<endl<<endl;
        usleep(5000000);
        menu();
    default:
        cout<<"\n\t\t\t\t Invalid Choice..! Please Try Again..!";
        cout<<"\n\n # Press Enter key for Main menu...!";
        break;
    }
    getch();
    goto menustart;
}

void student::insert()
{
x:
    system("cls");
    fstream file;
    cout<<"\n----------------------------------------------------------------------";
    cout<<"\n------------------------- Add Student Details ------------------------";
    cout<<"\n\n\t\t\t Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\t\t\t Enter Roll: ";
    cin >> roll;
    cout << "\t\t\t Enter Class: ";
    cin >> class_;
    if(class_<0 || class_>10)
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto x;

    }
    cin.ignore();
    cout << "\t\t\t Enter Address: ";
    getline(cin, address);
    cout << "\t\t\t Enter Phone no: ";
    getline(cin, phn_no);
    cout << "\n\t\t\t Record Saved..! "<<endl;

    file.open("studentRecord.txt", ios::app | ios::out);
    file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
    file.close();
}
void student::display()
{
y:
    system("cls");
    fstream file;
    int n = 0, total=0 ,class_ = 0;
    cout<<"\n-----------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------- Student Details ----------------------------"<<endl;
    cout<<"\n\t\t\t Enter Class(1-10): ";
    cin>>n;
    if(n<0 || n>10)
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto y;
    }
    else
    {
        file.open("studentRecord.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present for class "<<n<<"..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        else
        {
            while(!file.eof())
            {
                int c = 0;
                file.ignore();
                getline(file,name);
                file>>roll>>class_;
                file.ignore();
                getline(file,address);
                file>>phn_no;
                file.ignore();

                while(!file.eof())
                {
                    if( n == class_)
                    {
                        total++;
                        cout<<"\n\t\t\t Student Name: "<<name<<endl;
                        cout<<"\t\t\t Roll: "<<roll<<endl;
                        cout<<"\t\t\t Class: "<<class_<<endl;
                        cout<<"\t\t\t Address: "<<address<<endl;
                        cout<<"\t\t\t Phone No: "<<phn_no<<endl;
                        file.ignore();
                        getline(file,name);
                        file>>roll>>class_;
                        file.ignore();
                        getline(file,address);
                        file>>phn_no;
                        file.ignore();
                    }
                    else
                    {
                        file.ignore();
                        getline(file,name);
                        file>>roll>>class_;
                        file.ignore();
                        getline(file,address);
                        file>>phn_no;
                        file.ignore();
                    }
                }
                file.ignore();
                getline(file,name);
                file>>roll>>class_;
                file.ignore();
                getline(file,address);
                file>>phn_no;
                file.ignore();
            }
            file.close();
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present for class "<<n<<"..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else
            {
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
        }
    }

}

void student::search()
{
z:
    fstream file;
    total = 0;
    if(choice!=4)
    {
        system("cls");
        cout<<"\n-----------------------------------------------------------------------"<<endl;
        cout<<"\n---------------------- Search Student Details -------------------------"<<endl;
    }
    cout<<"\n\t\t\t Enter Class(1-10): ";
    cin>>n;
    if(n<1 || n>10)
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n # Press Enter key for try Again...!";
        getch();
        goto z;

    }
    cout<<"\t\t\t Enter Roll: ";
    cin>>r;

    file.open("studentRecord.txt", ios::in);
    if(!file)
    {
        cout<<"\n\t\t# No Data is Present..!";
        file.close();
        if(s != 2 )
            cout<<"\n\n # Press Enter Key for Main menu...!";
    }
    else
    {
        file.ignore();
        getline(file,name);
        file>>roll>>class_;
        file.ignore();
        getline(file,address);
        file>>phn_no;
        file.ignore();
        while(!file.eof())
        {

            if(r==roll && n == class_)
            {
                total++;
                cout<<"\n\t\t\t Student Name: "<<name<<endl;
                cout<<"\t\t\t Roll: "<<roll<<endl;
                cout<<"\t\t\t Class: "<<class_<<endl;
                cout<<"\t\t\t Address: "<<address<<endl;
                cout<<"\t\t\t Phone No: "<<phn_no<<endl;
                file.ignore();
                getline(file,name);
                file>>roll>>class_;
                file.ignore();
                getline(file,address);
                file>>phn_no;
                file.ignore();
                break;
            }
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();
        }
        file.close();
        if(total==0)
        {
            cout<<"\n\t\t# No Data is Present..!";
            if(s != 2 )
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

        else if(choice!=4 && s != 2 )
            cout<<"\n\n # Press Enter Key for Main menu...!";
    }
}

void student :: delet()
{
    system("cls");
    cout<<"\n-----------------------------------------------------------------------"<<endl;
    cout<<"\n---------------------- Delete Student Details -------------------------"<<endl;
    search();
    char s;
    if(total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp.txt");
            fstream file;
            file.open("studentRecord.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r != roll && n == class_)
                {
                    temf<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
                }

                else if(r == roll && n != class_)
                {
                    temf<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
                }

                else if(r!=roll && n != class_)
                {
                    temf<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
                }

                file.ignore();
                getline(file,name);
                file>>roll>>class_;
                file.ignore();
                getline(file,address);
                file>>phn_no;
                file.ignore();
            }
            file.close();
            temf.close();
            remove("studentRecord.txt");
            rename("temp.txt","studentRecord.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }
}

void student :: feesMenu()
{
menustart1:
    char x;
    system("cls");
    cout<<"\n\t\t\t\t          F E E S            "<<endl;
    cout<<"\t\t\t\t-----------------------------"<<endl;
    cout<<"\n\t\t\t\t 1. Add New Fees Details"<<endl;
    cout<<"\t\t\t\t 2. Display Fees Details"<<endl;
    cout<<"\t\t\t\t 3. Update Fees"<<endl;
    cout<<"\t\t\t\t 4. Back to Previous menu"<<endl<<endl;

    cout<<"\t\t\t\t------------------------------"<<endl;
    cout<<"\t\t\t\t Choose Option : [1/2/3/4]"<<endl;
    cout<<"\t\t\t\t------------------------------"<<endl;
    cout<<"Enter Your Choose: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        do
        {
            newFeesAdd();
            cout<<"\n\t\t Add Another Student Record [Y,N]: ";
            cin>>x;
        }
        while(x=='Y' || x=='y');
        cout<<"\n\n # Press Enter key for fees menu...!";
        break;
    case 2:
        displayFees();
        break;
    case 3:
        //updateFees();
        break;
    case 4:
        submenu();
        break;
    }
    getch();
    goto menustart1;
}

void student :: newFeesAdd()
{
x1:
    system("cls");
    fstream file;
    cout<<"\n----------------------------------------------------------------------";
    cout<<"\n------------------------- Add Fees Details ------------------------";

    cout << "\n\n\t\t\t Enter Class: ";
    cin >> class_;
    if(class_<0 || class_>10)
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto x1;
    }
    cout << "\t\t\t Enter Roll: ";
    cin >> roll;
    cout << "\t\t\t Demand for this year: ";
    cin>>demand;
    cout << "\t\t\t Enter Payment Amount: ";
    cin >> fee;
    due = demand - fee ;
    cout << "\n\t\t\t Record Saved..! "<<endl;


    file.open("fees.txt", ios::app | ios::out);
    file<<" "<<roll<<" "<<class_<<" "<<demand<<" "<<fee<<" "<<due<<"\n";
    file.close();
}

void student :: displayFees()
{
y1:
    system("cls");
    fstream file;
    int n = 0, total=0 , class_ = 0;
    cout<<"\n-----------------------------------------------------------------------"<<endl;
    cout<<"\n------------------ Class Waise Student Fees Details --------------------"<<endl;
    cout<<"\n\t\t\t Enter Class(1-10): ";
    cin>>n;
    cout<<endl;
    if(n<0 || n>10)
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto y1;
    }
    else
    {
        file.open("fees.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Fees menu...!";
        }
        else
        {

            while(!file.eof())
            {
                if( n == class_)
                {
                    total++;
                    cout<<"\t\t\t Roll: "<<roll<<endl;
                    cout<<"\t\t\t Class: "<<class_<<endl;
                    cout<<"\t\t\t Demand for this year: "<<demand<<" TK"<<endl;
                    cout<<"\t\t\t Last time Paid: "<<fee<<" TK"<<endl;
                    cout<<"\t\t\t Due Payment: "<<due<<" TK"<<endl<<endl<<endl;
                }

                file>>roll>>class_>>demand>>fee>>due;
            }
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present..!";
                cout<<"\n\n # Press Enter key for fees menu...!";
            }
            else
            {
                cout<<"\n\t\t\t# Total "<<total<<" Student details Found! ";
                cout<<"\n\n # Press Enter key for fees menu...!";
            }
        }
        file.close();
    }
}

void student :: studentFees()
{
z:
    fstream file;
    total = 0;
    if(s != 2)
    {
        system("cls");
        cout<<"\n-------------------------------------------------------------------"<<endl;
        cout<<"\n---------------------- Updating Fees Data -------------------------"<<endl;

        cout<<"\n\t\t\t Enter Class(1-10): ";
        cin>>n;
        if(n<1 || n>10)
        {
            cout<<"\n\n\t\t\tClass Invalid!";
            cout<<"\n\n # Press Enter key for try Again...!";
            getch();
            goto z;

        }
        cout<<"\t\t\t Enter Roll: ";
        cin>>r;
    }
    file.open("fees.txt", ios::in);
    if(!file)
    {
        cout<<"\n\t\t# No Data is Present..!";
        file.close();
        cout<<"\n\n # Press Enter Key for Main menu...!";
    }
    else
    {
        file>>roll>>class_>>demand>>fee>>due;
        while(!file.eof())
        {
            if(r==roll && n == class_ )
            {
                total++;
                if(s != 2)
                {
                    cout<<"\n\t\t\t Roll: "<<roll<<endl;
                    cout<<"\t\t\t Class: "<<class_<<endl;
                }
                cout<<"\t\t\t Demand for this year: "<<demand<<" TK"<<endl;
                cout<<"\t\t\t Last time Paid: "<<fee<<" TK"<<endl;
                cout<<"\t\t\t Due Payment: "<<due<<" TK"<<endl<<endl<<endl;
                file>>roll>>class_>>demand>>fee>>due;

            }

            file>>roll>>class_>>demand>>fee>>due;
        }
        file.close();
        if(total==0)
        {
            cout<<"\n\t\t# No Data is Present..!";
            cout<<"\n\n # Press Enter Key for Main menu...!";
        }

        else  cout<<"\n\n # Press Enter Key for Main menu...!";
    }
}

int main()
{
    student project;
    project.menu();


    return 0;
}
