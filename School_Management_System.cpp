#include<iostream>
#include <cstdio>
#include<fstream>
#include<cstdlib>    // for exit() function
#include<conio.h>    // for getch() function
#include <cstdio>    // for system("cls") function

using namespace std;
class student
{

private:
    string name,address,phn_no;
    int class_,roll;
public:
    string usn;
    int choice,n,r,pass, total=0;
    void menu();
    void PasswordCng();
    void submenu();
    void insert();
    void display();
    void search();
    void delet();
};

void student :: PasswordCng()
{
d:
    int passCI,passC,passN,passCo;
    system("cls");
    fstream file;
    cout<<"\n\t\t\t Enter Current PIN: ";
    cin>>passC;
    cout<<"\t\t\t Enter New PIN: ";
    cin>>passN;
    cout<<"\t\t\t Enter Conform PIN: ";
    cin>>passCo;
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
    int s;
    cout<<"\t\t\t\t-----------------------------"<<endl;
    cout<<"\t\t\t\t| SCHOOL MANAGEMENT SYSTEM  |"<<endl;
    cout<<"\t\t\t\t-----------------------------"<<endl;
    cout<<"\n\t\t\t\t   1. Teacher LogIn "<<endl;
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
        cin>>pass1;
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
        break;
    case 3:
        cout<<"\n\n\t\t\t  Thanks for using our software."<<endl<<"\n\t\t\tAll rights reserved, Akatsuki 2024."<<endl<<endl<<endl;
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
    cout<<"\t\t\t\t 5. Change PIN"<<endl;
    cout<<"\t\t\t\t 6. LogOut"<<endl<<endl;

    cout<<"\t\t\t\t------------------------------"<<endl;
    cout<<"\t\t\t\t Choose Option : [1/2/3/4/5]"<<endl;
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
        PasswordCng();
        break;

    case 6:
        cout<<"\n\n\t\t\t  Thanks for using our software."<<endl<<"\n\t\t\tAll rights reserved, Akatsuki 2024."<<endl<<endl<<endl;
        exit(0);
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
x:  system("cls");
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

    if(class_==1)
    {
        file.open("studentRecord1.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }
    else if(class_==2)
    {
        file.open("studentRecord2.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }
    else if(class_==3)
    {
        file.open("studentRecord3.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }
    else if(class_==4)
    {
        file.open("studentRecord4.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }
    else if(class_==5)
    {
        file.open("studentRecord5.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }
    else if(class_==6)
    {
        file.open("studentRecord6.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }
    else if(class_==7)
    {
        file.open("studentRecord7.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }
    else if(class_==8)
    {
        file.open("studentRecord8.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }
    else if(class_==9)
    {
        file.open("studentRecord9.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }
    else if(class_==10)
    {
        file.open("studentRecord10.txt", ios::app | ios::out);
        file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
        file.close();
    }

}
void student::display()
{
y:  system("cls");
    fstream file;
    int n, total=0;
    cout<<"\n-----------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------- Student Details ----------------------------"<<endl;
    cout<<"\n\t\t\t Enter Class(1-10): ";
    cin>>n;
    if(n==1)
    {
        file.open("studentRecord1.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        file.close();
    }
    else if(n==2)
    {
        file.open("studentRecord2.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        file.close();
    }
    else if(n==3)
    {
        file.open("studentRecord3.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        file.close();
    }
    else if(n==4)
    {
        file.open("studentRecord4.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present..!";
                cout<<"\n\n # Press Enter for Main menu...!";
            }
            else
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        file.close();
    }
    else if(n==5)
    {
        file.open("studentRecord5.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        file.close();
    }
    else if(n==6)
    {
        file.open("studentRecord6.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        file.close();
    }
    else if(n==7)
    {
        file.open("studentRecord7.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        file.close();
    }
    else if(n==8)
    {
        file.open("studentRecord8.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
                if(total==0)
                {
                    cout<<"\n\t\t# No Data is Present..!";
                    cout<<"\n\n # Press Enter key for Main menu...!";
                }
                else
                    cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            file.close();
        }
    }
    else if(n==9)
    {
        file.open("studentRecord9.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
                if(total==0)
                {
                    cout<<"\n\t\t# No Data is Present..!";
                    cout<<"\n\n # Press Enter key for Main menu...!";
                }
                else
                    cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            file.close();
        }
    }
    else if(n==10)
    {
        file.open("studentRecord10.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
            cout<<"\n\n # Press Enter key for Main menu...!";
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
            if(total==0)
            {
                cout<<"\n\t\t# No Data is Present..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
            cout<<"\n\n # Press Enter key for Main menu...!";
        }
        file.close();
    }
    else
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n # Press Enter key for try Again...!";
        getch();
        goto y;
    }
}

void student::search()
{
z:  fstream file;
    if(choice!=4)
    {
        system("cls");
        cout<<"\n-----------------------------------------------------------------------"<<endl;
        cout<<"\n---------------------- Search Student Details -------------------------"<<endl;
    }
    cout<<"\n\t\t\t Enter Class(1-10): ";
    cin>>n;
    if(n<1||n>10)
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n # Press Enter key for try Again...!";
        getch();
        goto z;

    }
    cout<<"\t\t\t Enter Roll: ";
    cin>>r;
    if(n==1)
    {
        file.open("studentRecord1.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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
                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==2)
    {
        file.open("studentRecord2.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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

                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==3)
    {
        file.open("studentRecord3.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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

                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==4)
    {
        file.open("studentRecord4.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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

                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==5)
    {
        file.open("studentRecord5.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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

                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==6)
    {
        file.open("studentRecord6.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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

                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==7)
    {
        file.open("studentRecord7.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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

                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==8)
    {
        file.open("studentRecord8.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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

                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==9)
    {
        file.open("studentRecord9.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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

                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==10)
    {
        file.open("studentRecord10.txt", ios::in);
        if(!file)
        {
            cout<<"\n\t\t# No Data is Present..!";
            file.close();
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

                if(r==roll)
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
                cout<<"\n\n # Press Enter Key for Main menu...!";
            }

            else if(choice!=4)
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

    }

    else
    {
        cout<<"\n\n\t\t\tError!";
        cout<<"\n\n # Press Enter key for try Again...!";
        getch();
        goto z;

    }
}

void student ::delet()
{
    system("cls");
    cout<<"\n-----------------------------------------------------------------------"<<endl;
    cout<<"\n---------------------- Delete Student Details -------------------------"<<endl;
    search();
    char s;
    if(n==1 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord1.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord1.txt");
            rename("temp1.txt","studentRecord1.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==2 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord2.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord2.txt");
            rename("temp1.txt","studentRecord2.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==3 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord3.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord3.txt");
            rename("temp1.txt","studentRecord3.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==4 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord4.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord4.txt");
            rename("temp1.txt","studentRecord4.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==5 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord5.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord5.txt");
            rename("temp1.txt","studentRecord5.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==6 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord6.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord6.txt");
            rename("temp1.txt","studentRecord6.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==7 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord7.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord7.txt");
            rename("temp1.txt","studentRecord7.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==8 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord8.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord8.txt");
            rename("temp1.txt","studentRecord8.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==9 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord9.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord9.txt");
            rename("temp1.txt","studentRecord9.txt");

            cout<<"\n\t\t\t Record Deleted..!";
            cout<<"\n\n\n # Press Enter Key for Main menu...!";

        }

        else
        {
            cout<<"\n\t\t\t Record not Deleted..!";

            cout<<"\n\n\n # Press Enter Key for Main menu...!";
        }

    }

    else if(n==10 && total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s;
        if(s=='y'||s=='Y')
        {
            ofstream temf;
            temf.open("temp1.txt");
            fstream file;
            file.open("studentRecord10.txt", ios::in);
            file.ignore();
            getline(file,name);
            file>>roll>>class_;
            file.ignore();
            getline(file,address);
            file>>phn_no;
            file.ignore();

            while(!file.eof())
            {
                if(r!=roll)
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
            remove("studentRecord10.txt");
            rename("temp1.txt","studentRecord10.txt");

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

int main()
{
    student project;
    project.menu();


    return 0;
}
