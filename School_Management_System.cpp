#include<iostream>
#include<cstdio>
#include<fstream>
#include <unistd.h>
#include<cstdlib>    // for exit() function
#include<conio.h>    // for getch() function
#include<cstdio>    // for system("cls") function
#include<ctime>  // Import the ctime library for time

using namespace std;
class student
{

private:
    string name,address,phn_no;
    int class_,roll,fee,demand,due;
public:
    string usn,t;
    int s,choice,choice2,n,r,pass,total=0,un = 0,um = 0;
    void menu();
    void PasswordCng();
    void submenu();
    int insert();
    int display(int n);
    int search();
    void delet();
    void setDemand();
    void feesMenu();
    int newFeesAdd();
    void displayFees();
    int studentFees();
    void updateFees();
    void studentLimits();
    int check(int c);
    void upDemand(int cc,int D);
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
    cout<<"\t\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t\t|   SCHOOL MANAGEMENT SYSTEM   |"<<endl;
    cout<<"\t\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t\t Profile: "<<usn<<endl;
    cout<<"\n\t\t\t\t 1. Enter New student Record"<<endl;
    cout<<"\t\t\t\t 2. Display student Record"<<endl;
    cout<<"\t\t\t\t 3. Search student Record"<<endl;
    cout<<"\t\t\t\t 4. Delete student Record"<<endl;
    cout<<"\t\t\t\t 5. Fees Details"<<endl;
    cout<<"\t\t\t\t 6. Set Student Limit per Class"<<endl;
    cout<<"\t\t\t\t 7. Change PIN"<<endl;
    cout<<"\t\t\t\t 8. LogOut"<<endl<<endl;

    cout<<"\t\t\t\t---------------------------------"<<endl;
    cout<<"\t\t\t\tChoose Option : [1/2/3/4/5/6/7/8]"<<endl;
    cout<<"\t\t\t\t---------------------------------"<<endl;
    cout<<"Enter Your Choose: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        do
        {
            if(insert()== -1) break;
            cout<<"\n\t\t Add Another Student Record [y,n]: ";
            cin>>x;
        }
        while(x=='Y' || x=='y');
        cout<<"\n\n # Press Enter key for Main menu...!";
        break;
    case 2:
        display(0);
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
        studentLimits();
        break;

    case 7:
        PasswordCng();
        break;

    case 8:
        cout<<"\n\n\t\t\t\t   LOGOUT!\n\n\t\t\t  Thanks for using our software."<<endl<<"\n\t\t\tAll rights reserved, (c) 2024 Akatsuki."<<endl<<endl<<endl;
        usleep(3000000);
        menu();
    default:
        cout<<"\n\t\t\t\t Invalid Choice..! Please Try Again..!";
        cout<<"\n\n # Press Enter key for Main menu...!";
        break;
    }
    getch();
    goto menustart;
}

int student::insert()
{
x:
    system("cls");
    cout<<"\n----------------------------------------------------------------------";
    cout<<"\n------------------------- Add Student Details ------------------------";
    cout<<"\n\n\t\t Available Seat for Every class \n\n";
    for(int i=1; i<11; i++)
    {
        int val1 = display(i);
        int val2 = check(i);
        int val = val2 - val1;
        if(val >=0 && val2 >= val ) cout<<"\t\tClass "<<i<<" = "<<val<<" ";

        else if(val == val2+1 && val>0  ) cout<<"\t\tClass "<<i<<" = "<<val2<<" ";

        else cout<<"\t\tClass "<<i<<" = "<<"NULL ";

        if(i==2 || i==4 || i==6 || i==8 || i==10) cout<<"\n";
    }

    cout<<"\n\n\t\t\t Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "\t\t\t Enter Class: ";
    cin >> class_;
    if(class_<1 || class_>10)
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto x;

    }
    cout << "\t\t\t Enter Roll: ";
    cin >> roll;
    int limits = check(class_);
    un = 0;
    if(limits == -1)
    {
        cout<<"\n\t\t# Set limit First for Class "<<class_<<"..!\n\n";
        return -1;
    }
    if(roll > limits || roll<1)
    {
        cout<<"\n\n\t\t\tRoll Invalid! Enter Roll Under Limit.";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto x;
    }
    if(search() == 2)
        goto x;

    cin.ignore();
    cout << "\t\t\t Enter Address: ";
    getline(cin, address);
    cout << "\t\t\t Enter Phone no: ";
    getline(cin, phn_no);
    cout << "\n\t\t\t Record Saved..! "<<endl;

    fstream file;
    file.open("studentRecord.txt", ios::app | ios::out);
    file<<" "<<name<<"\n"<<roll<<" "<<class_<<"\n"<<address<<"\n"<<phn_no<<"\n";
    file.close();

}

int student::display(int n)
{
y:
    if(choice != 1)
    {
        system("cls");


        cout<<"\n-----------------------------------------------------------------------"<<endl;
        cout<<"\n-------------------------- Student Details ----------------------------"<<endl;
        cout<<"\n\t\t\t Enter Class(1-10): ";
        cin>>n;
    }
    int total=0,class_ = 0;
    if( (n<0 || n>10)&& choice != 1)
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto y;
    }

    else
    {
        fstream file;
        file.open("studentRecord.txt", ios::in);
        if(!file)
        {
            file.close();
            if(choice != 1)
            {
                cout<<"\n\t\t# No Data is Present for class "<<n<<"..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else return 0;
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
                        if(choice != 1)
                        {
                            cout<<"\n\t\t\t Student Name: "<<name<<endl;
                            cout<<"\t\t\t Roll: "<<roll<<endl;
                            cout<<"\t\t\t Class: "<<class_<<endl;
                            cout<<"\t\t\t Address: "<<address<<endl;
                            cout<<"\t\t\t Phone No: "<<phn_no<<endl;
                        }
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
            if(total==0 && choice != 1)
            {
                cout<<"\n\t\t# No Data is Present for class "<<n<<"..!";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else if(choice != 1)
            {
                cout<<"\n\t\t\t# Total "<<total<<" Student Found! ";
                cout<<"\n\n # Press Enter key for Main menu...!";
            }
            else if(choice == 1 && total != 0) return total;
            else if(choice == 1 && total == 0) return -1;
        }
    }

}

int student::search()
{
z:
    total = 0;
    if(choice != 1)
    {

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
            if(choice==4)
            {
                getch();
                return 2;
            }
            else
            {
                getch();
                goto z;
            }
        }
        cout<<"\t\t\t Enter Roll: ";
        cin>>r;

        int limits = check(n);
        un = 0;
        if(r > limits || r<1)
        {
            cout<<"\n\n\t\t\tRoll Invalid! Enter Roll Under Limit.";
            cout<<"\n\n\n # Press Enter key for try Again...!";
            if(choice==4)
            {
                getch();
                return 2;
            }
            else
            {
                getch();
                goto z;
            }
        }
    }
    else
    {
        r = 0;
        n = 0;
    }


    fstream file;
    file.open("studentRecord.txt", ios::in);
    if(!file && choice != 1)
    {
        cout<<"\n\t\t# No Data is Present..!";
        file.close();
        if(s != 2 )
            cout<<"\n\n # Press Enter Key for Main menu...!";
        return -1;
    }
    if(!file && choice == 1)
    {
        file.close();
        return -1;
    }
    else
    {
        int t,t2;
        string nam, mob, add;
        file.ignore();
        getline(file,nam);
        file>>t>>t2;
        file.ignore();
        getline(file,add);
        file>>mob;
        file.ignore();
        while(!file.eof())
        {

            if((r==t && n == t2) || ( t==roll && t2==class_ ))
            {
                total++;
                if(choice == 1 && total > 0)  break;
                cout<<"\n\t\t\t Student Name: "<<nam<<endl;
                cout<<"\t\t\t Roll: "<<t<<endl;
                cout<<"\t\t\t Class: "<<t2<<endl;
                cout<<"\t\t\t Address: "<<add<<endl;
                cout<<"\t\t\t Phone No: "<<mob<<endl;
                file.ignore();
                getline(file,nam);
                file>>t>>t2;
                file.ignore();
                getline(file,add);
                file>>mob;
                file.ignore();
                break;
            }
            file.ignore();
            getline(file,nam);
            file>>t>>t2;
            file.ignore();
            getline(file,add);
            file>>mob;
            file.ignore();
        }
        file.close();
        if(total==0 && choice != 1)
        {
            cout<<"\n\t\t# No Data is Present..!";
            if(s != 2 )
                cout<<"\n\n # Press Enter Key for Main menu...!";
        }

        else if(choice!=4 && s != 2 && choice != 1)
            cout<<"\n\n # Press Enter Key for Main menu...!";
        else if(choice == 1 && total > 0 )
        {
            cout<<"\n\n\t # Entered roll already exist in class "<<t2;
            cout<<"\n\n\n # Press Enter Key for Try Again...!";
            getch();
            return 2;
        }
        else return 1;
    }
}

void student :: delet()
{
v:
    system("cls");
    cout<<"\n-----------------------------------------------------------------------"<<endl;
    cout<<"\n---------------------- Delete Student Details -------------------------"<<endl;
    if(search()==2)
        goto v;
    else
    {
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
}

void student :: feesMenu()
{
menustart1:
    char x;
    system("cls");
    cout<<"\n\t\t\t\t          F E E S            "<<endl;
    cout<<"\t\t\t\t-----------------------------"<<endl;
    cout<<"\n\t\t\t\t 1. Set Demand for Each class"<<endl;
    cout<<"\t\t\t\t 2. Add New Fees Details"<<endl;
    cout<<"\t\t\t\t 3. Display Fees Details"<<endl;
    cout<<"\t\t\t\t 4. Update Fees"<<endl;
    cout<<"\t\t\t\t 5. Back to Previous menu"<<endl<<endl;

    cout<<"\t\t\t\t------------------------------"<<endl;
    cout<<"\t\t\t\t Choose Option : [1/2/3/4/5]"<<endl;
    cout<<"\t\t\t\t------------------------------"<<endl;
    cout<<"Enter Your Choose: ";
    cin>>choice2;

    switch(choice2)
    {
    case 1:
        setDemand();
        break;
    case 2:
        do
        {
            if( newFeesAdd() == 1 ) break;
            cout<<"\n\t\t Add Another Student Record [Y,N]: ";
            cin>>x;
        }
        while(x=='Y' || x=='y');
        cout<<"\n\n # Press Enter key for fees menu...!";
        break;
    case 3:
        displayFees();
        break;
    case 4:
        studentFees();
        break;
    case 5:
        submenu();
        break;
    default:
        cout<<"\n\t\t\t\t Invalid Choice..! Please Try Again..!";
        cout<<"\n\n # Press Enter key for Try Agin...!";
        break;
    }
    getch();
    goto menustart1;
}

int student :: newFeesAdd()
{
x1:
    r = 0;
    n = 0;
    system("cls");
    cout<<"\n----------------------------------------------------------------------";
    cout<<"\n------------------------- Add Fees Details ------------------------";
    int coun = 0;
    fstream fileD2;
    fileD2.open("demand.txt", ios::in);
    if(!fileD2)
    {
        fileD2.close();
    }
    else
    {
        while(!fileD2.eof())
        {
            coun++;
            int clas, dama;
            fileD2>>clas>>dama;
        }
        fileD2.close();
    }
    if(11-coun != 0 && coun != 0)
        cout << "\n\n\t\t\t"<<11-coun<<" Classes Demand Not set yet!";
    else if(10-coun != 0 && coun == 0)
        cout << "\n\n\t\t\t"<<10-coun<<" Classes Demand Not set yet!";

    cout << "\n\n\t\t\t Enter Class: ";
    cin >> n;
    if(n<1 || n>10)
    {
        cout<<"\n\n\t\t\tClass Invalid!";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto x1;
    }
    cout << "\t\t\t Enter Roll: ";
    cin >> r;
    int limits = check(n);
    un = 0;
    if(r > limits || r<1)
    {
        cout<<"\n\n\t\t\tRoll Invalid! Enter Roll Under Limit.";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto x1;
    }
    if(studentFees() == 5)
    {
        cout<<"\n\n\t # Entered roll already exist in class "<<n<<"..!";
        cout<<"\n\n\n # Press Enter key for try Again...!";
        getch();
        goto x1;
    }

    int w = 0;
    fstream fileD;
    fileD.open("demand.txt", ios::in);
    if(!fileD)
    {
        cout<<"\n\t\t# Set Demand First for Class "<<n<<"..!";
        fileD.close();
        return 1;
    }
    else
    {

        int class_2, demand2;
        while(!fileD.eof())
        {
            if( n == class_2)
            {
                demand = demand2;
                fileD.close();
                w = 1;
                break;
            }

            fileD>>class_2>>demand2;
        }
        if(w == 0)
        {
            cout<<"\n\t\t# Set Demand First for Class "<<n<<"..!";
            return 1;
        }
    }


    cout << "\t\t\t Enter Payment Amount: ";
    cin >> fee;

    due = demand - fee ;
    time_t timestamp;
    time(&timestamp);
    t = ctime(&timestamp);
    cout << "\n\t\t\t Record Saved..! "<<endl;

    fstream filef;
    filef.open("fees.txt", ios::app | ios::out);
    filef<<" "<<r<<" "<<n<<" "<<demand<<" "<<fee<<" "<<due<<"\n"<<t<<"\n";
    filef.close();
}

void student :: displayFees()
{
y1:
    system("cls");
    fstream file;
    int n = 0, total=0, class_ = 0;
    cout<<"\n-----------------------------------------------------------------------"<<endl;
    cout<<"\n------------------ Class Wise Student Fees Details --------------------"<<endl;
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
            string t;
            while(!file.eof())
            {


                if( n == class_)
                {
                    total++;
                    int m, k,k2, prev, ckR = 0;
                    cout<<"\t\t\t Roll: "<<roll<<endl;
                    k2 = roll;
                    cout<<"\t\t\t Class: "<<class_<<endl;
                    cout<<"\t\t\t Demand for this year:  "<<demand<<" TK"<<endl;


                    string time3;
                    fstream receipt;
                    receipt.open("recepit.txt", ios::in );
                    if(!receipt)
                    {
                        receipt.close();
                    }
                    else
                    {

                        while(receipt >> k >> m >> prev)
                        {
                            receipt.ignore();
                            getline(receipt, time3);
                            if(n == m && k == k2 )
                            {

                                cout<<"\t\t\t previously Paid:\t"<<prev<<" TK"<<" [ Date: "<<time3<<" ]"<<endl;
                            }

                        }
                        receipt.close();
                    }

                    cout<<"\t\t\t Last time Paid:\t"<<fee<<" TK"<<" [ Date: "<<t<<" ]"<<endl;
                    if(due >= 0)
                        cout<<"\t\t\t Due Payment: \t\t"<<due<<" TK"<<endl<<endl<<endl;
                    else
                        cout<<"\t\t\t Advance Payment: \t"<<abs(due)<<" TK"<<endl<<endl<<endl;
                }

                file>>roll>>class_>>demand>>fee>>due;
                file.ignore();
                getline(file,t);
            }
            file.close();
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

    }
}

int student :: studentFees()
{
z:

    total = 0;
    if(s != 2 && choice2 != 2)
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
        int limits = check(n);
        un = 0;
        if(limits == -1 )
        {
            cout<<"\n\n\t\t\tNo Data is Present...!";
            cout<<"\n\n\n # Press Enter key for try Again...!";
            return -1;
        }
        else if(r > limits || r<1)
        {
            cout<<"\n\n\t\t\tRoll Invalid! Enter Roll Under Limit.";
            cout<<"\n\n\n # Press Enter key for try Again...!";
            getch();
            goto z;
        }
    }

    fstream fileC;
    fileC.open("fees.txt", ios::in);
    if(!fileC && choice2 != 2)
    {
        cout<<"\n\t\t# No Data is Present..!";
        fileC.close();
        cout<<"\n\n # Press Enter Key for Main menu...!";
    }
    else if(!fileC && choice2 == 2) return 10;
    else
    {
        int roll2, class_2, demand3,fee2, due2;
        string t2;
        fileC>>roll2>>class_2>>demand3>>fee2>>due2;
        fileC.ignore();
        getline(fileC,t2);
        while(!fileC.eof())
        {
            if(r==roll2 && n == class_2 )
            {
                total++;
                if(choice2 != 2)
                {
                    if(s != 2)
                    {
                        cout<<"\n\t\t\t Roll: "<<roll2<<endl;
                        cout<<"\t\t\t Class: "<<class_2<<endl;
                    }
                    cout<<"\t\t\t Demand for this year:  "<<demand3<<" TK"<<endl;
                    int m, k, prev;
                    string time4;
                    fstream receipt;
                    receipt.open("recepit.txt", ios::in );
                    if(!receipt)
                    {
                        receipt.close();
                    }
                    else
                    {

                        while(receipt >> k >> m >> prev)
                        {
                            receipt.ignore();
                            getline(receipt, time4);
                            if(n == m && k == r )
                            {

                                cout<<"\t\t\t previously Paid:\t"<<prev<<" TK"<<" [ Date: "<<time4<<" ]"<<endl;
                            }

                        }
                        receipt.close();
                    }

                    cout<<"\t\t\t Last time Paid:\t"<<fee2<<" TK"<<" [ Date: "<<t2<<" ]"<<endl;
                    if(due2 >= 0)
                        cout<<"\t\t\t Due Payment: \t\t"<<due2<<" TK"<<endl<<endl<<endl;
                    else
                        cout<<"\t\t\t Advance Payment: \t"<<abs(due2)<<" TK"<<endl<<endl<<endl;
                }
                fileC>>roll2>>class_2>>demand3>>fee2>>due2;
                fileC.ignore();
                getline(fileC,t2);

            }

            fileC>>roll2>>class_2>>demand3>>fee2>>due2;
            fileC.ignore();
            getline(fileC,t2);
        }
        fileC.close();
        if(total==0 && choice2 != 2)
        {
            cout<<"\n\t\t# No Data is Present..!";
            cout<<"\n\n # Press Enter Key for Main menu...!";
        }
        else if(total>0 && choice2 == 2) return 5;
        else if(choice2 == 4 ) updateFees();
        else if(choice2 != 2)  cout<<"\n\n # Press Enter Key for Main menu...!";
    }
}

void student :: updateFees()
{
    char s5;
    int r2, n2, d2, fee2,due2, due4 ;
    string time2, date;
    if(total!=0)
    {
        cout<<"\n\t\t\t Are you Sure...[y,n] ";
        cin>>s5;
        if(s5=='y'||s5=='Y')
        {
            ofstream temf;
            temf.open("temp.txt");
            fstream file;
            file.open("fees.txt", ios::in);
            file>>roll>>class_>>demand>>fee>>due;
            file.ignore();
            getline(file,time2);

            while(!file.eof())
            {
                if(r == roll && n == class_)
                {
                    r2 = roll;
                    n2 = class_;
                    d2 = demand ;
                    due2 = due;
                    fstream receipt;
                    receipt.open("recepit.txt", ios::app | ios::out );
                    receipt<<" "<<r2<<" "<<n2<<" "<<fee<<"\n"<<time2<<"\n";
                    receipt.close();
                }
                else if(r != roll && n == class_)
                {
                    temf<<" "<<roll<<" "<<class_<<" "<<demand<<" "<<fee<<" "<<due<<"\n"<<time2<<"\n";
                }

                else if(r == roll && n != class_)
                {
                    temf<<" "<<roll<<" "<<class_<<" "<<demand<<" "<<fee<<" "<<due<<"\n"<<time2<<"\n";
                }

                else if(r!=roll && n != class_)
                {
                    temf<<" "<<roll<<" "<<class_<<" "<<demand<<" "<<fee<<" "<<due<<"\n"<<time2<<"\n";
                }

                file>>roll>>class_>>demand>>fee>>due;
                file.ignore();
                getline(file,time2);
            }
            cout << "\n\n\t\t\t Enter Payment Amount: ";
            cin >> fee2;
            due4 = due2 - fee2 ;

            time_t now = time(0);
            date = ctime(&now);

            temf<<" "<<r2<<" "<<n2<<" "<<d2<<" "<<fee2<<" "<<due4<<"\n"<<date<<"\n";

            file.close();
            temf.close();
            remove("fees.txt");
            rename("temp.txt","fees.txt");

            cout<<"\n\t\t\t Record Updated..!";
            cout<<"\n\n\n # Press Enter Key for Fees menu...!";
        }
        else
        {
            cout<<"\n\t\t\t Record not Updated..!";

            cout<<"\n\n\n # Press Enter Key for Fees menu...!";
        }
    }
}

void student :: setDemand()
{
x1:
    char x2;
    do
    {
        system("cls");
        cout<<"\n\t\t\t         Set Demand          "<<endl;
        cout<<"\t\t\t-----------------------------"<<endl;

        cout<<"\n\nThe Demand Set Earlier Are :";
        for(int i=1; i<11; i++)
        {
            int dd = check(i);
            if(i==3 || i==5 || i==9 || i==7 ) cout<<"\t\t\t    ";
            if( dd > 0 )
                cout<<"\tClass "<<i<<" = "<< dd;
            else
                cout<<"\tClass "<<i<<" = "<<"NULL";
            if(i==2 || i==4 || i==6 || i==8 || i==10) cout<<"\n";
        }
        um++;


        int coun = 0;
        fstream fileD2;
        fileD2.open("demand.txt", ios::in);
        if(!fileD2)
        {
            fileD2.close();
        }
        else
        {
            while(!fileD2.eof())
            {
                coun++;
                int clas, dama;
                fileD2>>clas>>dama;
            }
            fileD2.close();
        }
        if(11-coun != 0 && coun != 0)
            cout << "\n\n\t\t\t"<<11-coun<<" Classes Demand Not set yet!";
        else if(10-coun != 0 && coun == 0)
            cout << "\n\n\t\t\t"<<10-coun<<" Classes Demand Not set yet!";
        else
            cout << "\n\n\t\t"<<"All Classes Demand set![ For this Input Demand has Updated ]";

        cout << "\n\n\t\t\t Enter Class: ";
        cin >> class_;
        if(class_<1 || class_>10)
        {
            cout<<"\n\n\t\t\t\t Class Invalid!";
            cout<<"\n\n\n # Press Enter key for try Again...!";
            getch();
            goto x1;
        }
        int dom = check(class_);
        um = 0;

        if(dom == 2 || dom == -1)
        {
            cout << "\t\t\t Demand for this year: ";
            cin>>demand;
            fstream file;
            file.open("demand.txt", ios::app | ios::out);
            file<<" "<<class_<<" "<<demand<<"\n";
            file.close();
            if(dom == 2) upDemand(class_, demand );
            cout<<"\n\t\t Demand Set Successfully..!";
        }
        else if(dom == -2) cout<<"\n\t\t Demand Not Update..!";

        cout<<"\n\n\n\t\t Set Another Class Demand [Y,N]: ";
        cin>>x2;
    }
    while(x2=='Y' || x2=='y');
    cout<<"\n\n\n # Press Enter Key for Fees menu...!";

}

void student :: studentLimits()
{
    system("cls");
    cout<<"\n\n\t\t\t **Before Set Student limit, Delete Previous Data** \n\n";
    cout<<"\n\nThe Limits Set Earlier Are :";
    for(int i=1; i<11; i++)
    {
        int lii;
        lii = check(i);

        if(i==3 || i==5 || i==9 || i==7 ) cout<<"\t\t\t    ";
        if( lii >= 0 )
            cout<<"\tClass "<<i<<" = "<< lii;
        else
            cout<<"\tClass "<<i<<" = "<<"NULL";
        if(i==2 || i==4 || i==6 || i==8 || i==10) cout<<"\n";
    }
    un++;
    int cl;
    fstream file;
    cout<<"\n\n\t\t\t\t Enter Class: ";
    cin>>cl;
    int don = check(cl);
    un = 0;
    if(don == 2 || don == -1)
    {

        cout<<"\n\t\t\t\t Enter Student limit: ";
        int limit;
        cin>>limit;
        file.open("limit.txt", ios::app | ios::out);
        file<<cl<<" "<<limit<<"\n";
        file.close();
        cout<<"\n\n\t\t\t\t Limit Set Successfully..!";

    }
    else if(don == -2)
    {
        cout<<"\n\n\t\t\t\t Limit not Update..!";
    }
    char xx;
    cout<<"\n\n\t\t\t\t Do You want to set Another[y/n]: ";
    cin>>xx;
    if(xx == 'y' || xx == 'Y')
        studentLimits();
    else
        cout<<"\n\n\n # Press Enter Key for Main menu...!";

}

int student :: check(int c)
{
    if(choice2 == 1)
    {
        int ck1 = 0;
        fstream demands;
        demands.open("demand.txt", ios::in);
        if(!demands) return -1;
        else
        {
            int rr, dema;
            while(demands>>rr>>dema)
            {
                if(rr == c)
                {
                    ck1 = 1;
                    demands.close();
                    if(um == 0)
                        return dema;
                }
            }
            if(ck1 == 1 && um != 0 )
            {
                char com;
                int rr2, demma;
                cout<<"\n\n\t\t\t\tClass "<<c<<" Demand Already Set...!";
                cout<<"\n\n\t\t\t\tDo You want to Update [y/n]: ";
                cin>>com;
                cout<<endl;
                if(com == 'y' || com == 'Y')
                {
                    ofstream temp5;
                    temp5.open("temp5.txt");
                    fstream file;
                    file.open("demand.txt", ios::in);
                    while(file>>rr2>>demma)
                    {
                        if(c != rr2)
                        {
                            temp5<<rr2<<" "<<demma<<"\n";
                        }
                    }
                    file.close();
                    temp5.close();
                    remove("demand.txt");
                    rename("temp5.txt","demand.txt");
                    return 2;
                }
                return -2;
            }

            return -1;
        }
    }

    else
    {
        int ck = 0 ;
        fstream file;
        file.open("limit.txt", ios::in);
        if(!file) return -1;
        else
        {
            int limit, c2;
            while(file>>c2>>limit)
            {
                if(c == c2)
                {
                    ck = 1;
                    file.close();
                    if(un == 0 || choice ==1 )
                        return limit;
                }
            }
            if(ck == 1 && choice != 1 && un !=0)
            {
                char con;
                int c3, lim;
                cout<<"\n\n\n\t\t\t\tClass "<<c<<" Limit Already Set...!";
                cout<<"\n\n\n\t\t\t\tDo You want to Update [y/n]: ";
                cin>>con;
                cout<<endl;
                if(con == 'y' || con == 'Y')
                {
                    ofstream temp1;
                    temp1.open("temp1.txt");
                    fstream file;
                    file.open("limit.txt", ios::in);
                    while(file>>c3>>lim)
                    {
                        if(c != c3)
                        {
                            temp1<<c3<<" "<<lim<<"\n";
                        }
                    }
                    file.close();
                    temp1.close();
                    remove("limit.txt");
                    rename("temp1.txt","limit.txt");
                    return 2;
                }
                return -2;
            }

            file.close();
            return -1;
        }
    }

}

void student :: upDemand(int cc,int D)
{
    ofstream temp10;
    temp10.open("temp10.txt");
    fstream upD;
    upD.open("fees.txt", ios::in );
    if(!upD) return;
    else
    {
        int rb, coo, dema, lp, rd;
        string daa;
        while(upD>>rb>>coo>>dema>>lp>>rd)
        {
            upD.ignore();
            getline(upD,daa);

            if( cc == coo)
            {
                int doc = dema - rd ;
                dema = D;
                rd = D - doc;
            }

            temp10<<" "<<rb<<" "<<coo<<" "<<dema<<" "<<lp<<" "<<rd<<"\n"<<daa<<"\n";

        }
        upD.close();
        temp10.close();
        remove("fees.txt");
        rename("temp10.txt","fees.txt");
    }
}

int main()
{
    student project;
    project.menu();


    return 0;
}
