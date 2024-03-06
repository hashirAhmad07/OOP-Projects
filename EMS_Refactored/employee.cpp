#include "employee.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include<fstream>

using namespace std;

employee::employee()
{
    //ctor
}

void employee::loadingAnimation()
{
    char load = 219;
    cout << "\t\t\t\t Please Wait ";
    for (int i = 0; i <= 20; i++)
    {
        Sleep(100);
        cout << load;
    }
    system("cls");
}

void employee::login()
{
    system("cls");
    string adminUser = "admin";
    string adminPass = "admin";
    string ayeshaUser = "ayesha";
    string ayeshaPass = "ayesha";
    string sammadUser = "sammad";
    string sammadPass = "sammad";

    displayHeader("Login");
    string inputUser, inputPass;
    cout << "\t\t\t\t Enter User Name : ";
    cin >> inputUser;
    cout << endl << endl;
    cout << "\t\t\t\t Enter Password : ";
    cin >> inputPass;

    if ((adminUser == inputUser) && (adminPass == inputPass))
    {
        showAdminDetails("001", "XYZ", "BSCS");
    }
    else if ((ayeshaUser == inputUser && ayeshaPass == inputPass))
    {
        showAdminDetails("F2020027036", "Ayesha Tariq", "HR");
    }
    else if ((sammadUser == inputUser && sammadPass == inputPass))
    {
        showAdminDetails("F2020027039", "Abdus Sammad", "Management");
    }
    else
    {
        cout << endl << endl;
        cout << "\t\t\t\t Invalid Credentials. Please try again." << endl;
        getch();
        system("cls");
        login();
    }
}

void employee::showAdminDetails(const string& empId, const string& empName, const string& depName)
{
    loadingAnimation();
    displayHeader("Admin Details");
    cout << "\t\t\t\t ID: " << empId << endl << endl;
    cout << "\t\t\t\t Name: " << empName << endl << endl;
    cout << "\t\t\t\t Department: " << depName << endl << endl;
    cout << "\t\t\t\t*********************************";
    getch();
    system("cls");
    cout << endl << endl;
    cout << "\n\t\t\t    Welcome To Employees Management System\n\n";
    menu();
}

void employee::displayHeader(const string& title)
{
    cout << endl << endl;
    cout << "\t\t\t\t*********************************" << endl;
    cout << "\t\t\t\t*                               *" << endl;
    cout << "\t\t\t\t\t       " << title << "     " << endl;
    cout << "\t\t\t\t*                               *" << endl;
    cout << "\t\t\t\t*********************************" << endl << endl;
}

void employee::start()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Press any key to continue";
    getch();
    login();
}

void employee::menu()
{
    char userChoice;

    do
    {
        system("cls");
        userChoice = displayMenu();
        performAction(userChoice);
        getch();
    }
    while (userChoice != '9');
}

char employee::displayMenu()
{
    cout << endl << endl;
    displayHeader("Control Panel");
    cout << "\t\t\t\t 1. Insert Record" << endl;
    cout << "\t\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t\t 3. Search Record" << endl;
    cout << "\t\t\t\t 4. Modify Record" << endl;
    cout << "\t\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t\t 6. Department Record" << endl;
    cout << "\t\t\t\t 7. Search Department" << endl;
    cout << "\t\t\t\t 8. Show All Department" << endl;
    cout << "\t\t\t\t 9. Exit" << endl << endl;
    cout << "\t\t\t\t Enter Your Choice (1-9) : ";

    return getUserChoice();
}

int employee::getUserChoice()
{
    int choice;
    cin >> choice;
    loadingAnimation();
    system("cls");
    return choice;
}

void employee::performAction(int choice)
{
    switch (choice)
    {
    case 1:
        handleInsert();
        break;
    case 2:
        display();
        break;
    case 3:
        search();
        break;
    case 4:
        modify();
        break;
    case 5:
        delet();
        break;
    case 6:
        dep();
        break;
    case 7:
        search_dep();
        break;
    case 8:
        show_dep();
        break;
    case 9:
        exit(0);
        break;
    default:
        cout << "\n\t\t\t\t Invalid Choice. Please Try Again " << endl;
    }
}

void employee::handleInsert() {
    char x;
    do {
        // Call your existing insert function here
        insert();
        cout << endl << endl;
        cout << "\t\t\t\t Do You Want To Add Another Record (y,n) : ";
        cin >> x;
    } while (x == 'y');
}

void employee::insert() {
    system("cls");

    displayHeader("Insert Record");
    getUserInput();

    // Write employee details to employees.txt
    ofstream employeeFile("employees.txt", ios::out | ios::app);
    employeeFile << " " << emp_id << " " << emp_fname << " " << emp_lname << " " << salary << " " << mobile_no << " " << address << " " << dep_name << endl;
    employeeFile.close();

    // Write department details to department.txt
    ofstream departmentFile("department.txt", ios::out | ios::app);
    departmentFile << " " << dep_name << " " << emp_id << " " << emp_fname << " " << emp_lname << " " << salary << endl;
    departmentFile.close();

    // Update department names in departname.txt
    if (!isDepartmentExist(dep_name)) {
        ofstream departmentNameFile("departname.txt", ios::app | ios::out);
        departmentNameFile << " " << dep_name << endl;
        departmentNameFile.close();
    }

    cout << "\t\t\t\t New Record Inserted Successfully.";
}

void employee::getUserInput() {
    cout << "\t\t\t\t Employee ID: ";
    cin >> emp_id;
    cout << endl << endl;
    cout << "\t\t\t\t Employee First Name: ";
    cin >> emp_fname;
    cout << endl << endl;
    cout << "\t\t\t\t Employee Last Name: ";
    cin >> emp_lname;
    cout << endl << endl;
    cout << "\t\t\t\t Employee Salary: ";
    cin >> salary;
    cout << endl << endl;
    cout << "\t\t\t\t Employee Mobile No.: ";
    cin >> mobile_no;
    cout << endl << endl;
    cout << "\t\t\t\t Employee Address: ";
    cin >> address;
    cout << endl << endl;
    cout << "\t\t\t\t Employee Department (Capital Letter): ";
    cin >> dep_name;
    cout << endl << endl;
}

bool employee::isDepartmentExist(const string& department) {
    ifstream file("departname.txt", ios::in);
    if (!file) {
        return false;
    }

    string depart_name;
    while (file >> depart_name) {
        if (depart_name == department) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void employee::display()
{
    system("cls");
    int count=1;
    fstream file;
    cout<<endl<<endl;

    cout<<"\t\t\t\t*********************************"<<endl;
    cout<<"\t\t\t\t*				*"<<endl;
    cout<<"\t\t\t\t*\t  Display Record	*"<<endl;
    cout<<"\t\t\t\t*				*"<<endl;
    cout<<"\t\t\t\t*********************************"<<endl<<endl;

    file.open("employees.txt",ios::in);
    if(!file)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t Your Database is Empty ";
        getch();
        menu();
    }
    file>>emp_id>>emp_fname>>emp_lname>>salary>>mobile_no>>address>>dep_name;

    while(!file.eof())
    {
        cout<<"\t\t\t\t =========="<<endl;
        cout<<"\t\t\t\t Empolyee "<<count<<endl;
        cout<<"\t\t\t\t =========="<<endl<<endl;
        cout<<"\t\t\t\t Employee ID: "<<emp_id;
        cout<<endl<<endl;
        getValues();
        file>>emp_id>>emp_fname>>emp_lname>>salary>>mobile_no>>address>>dep_name;
        count++;
    }
    file.close();

}

void employee::getValues()
{
       cout<<"\t\t\t\t Employee First Name: "<<emp_fname;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee last Name: "<<emp_lname;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee Salary: "<<salary;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee Mobile No.: "<<mobile_no;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee Address: "<<address;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee Department: "<<dep_name;
        cout<<endl<<endl;
}
void employee::search()
{
    system("cls");
    string ID;
    int found=0;
    fstream file;
    cout<<endl<<endl;
    displayHeader("Search Record");
    file.open("employees.txt",ios::in);
    if(!file)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\tYour Database is Empty ";
        getch();
        menu();
    }
    cout<<"\t\t\t\t Enter Employee ID: ";
    cin>>ID;
    file>>emp_id>>emp_fname>>emp_lname>>salary>>mobile_no>>address>>dep_name;
    while(!file.eof())
    {
        if (ID==emp_id)
        {

            system("cls");
            cout<<endl<<endl;
            displayHeader("Search Record");
            cout<<"\t\t\t\t Employee ID: "<<emp_id;
            cout<<endl<<endl;
            getValues();
            found++;

        }
        file>>emp_id>>emp_fname>>emp_lname>>salary>>mobile_no>>address>>dep_name;

    }
    file.close();

    if(found == 0)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee ID Can't Found.";
    }

}
void employee::modify()
{
    system("cls");
    int modi_sal,found=0;
    string fname1,lname2,address1,modi_id,modi_dep,mobile1;
    fstream file,file1,file2,file3;
    cout<<endl<<endl;
    displayHeader("Modify Record");
    file.open("employees.txt",ios::in);
    file1.open("department.txt",ios::in);
    if(!file||!file1)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\tYour Database is Empty ";
        getch();
        menu();
    }
    cout<<"\t\t\t\t Enter Employee ID: ";
    cin>>modi_id;
    file2.open("employees1.txt",ios::app|ios::out);
    file>>emp_id>>emp_fname>>emp_lname>>salary>>mobile_no>>address>>dep_name;
    while(!file.eof())
    {
        if(modi_id==emp_id)
        {
            system("cls");
            cout<<endl<<endl;
            displayHeader("Modify Record");
            cout<<"\t\t\t\t Employee First Name: ";
            cin>>fname1;
            cout<<endl<<endl;
            cout<<"\t\t\t\t Employee last Name: ";
            cin>>lname2;
            cout<<endl<<endl;
            cout<<"\t\t\t\t Employee Salary: ";
            cin>>modi_sal;
            cout<<endl<<endl;
            cout<<"\t\t\t\t Employee Mobile No.: ";
            cin>>mobile1;
            cout<<endl<<endl;
            cout<<"\t\t\t\t Employee Address: ";
            cin>>address1;
            cout<<endl<<endl;
            cout<<"\t\t\t\t Employee Department: ";
            cin>>modi_dep;
            cout<<endl<<endl;
            file2<<" "<<emp_id<<" "<<fname1<<" "<<lname2<<" "<<modi_sal<<" "<<mobile1<<" "<<address1<<" "<<modi_dep<<endl;
            found++;
        }
        else
        {
            file2<<" "<<emp_id<<" "<<emp_fname<<" "<<emp_lname<<" "<<salary<<" "<<mobile_no<<" "<<address<<" "<<dep_name<<endl;

        }
        file>>emp_id>>emp_fname>>emp_lname>>salary>>mobile_no>>address>>dep_name;
    }
    file.close();
    file2.close();
    remove("employees.txt");
    rename("employees1.txt","employees.txt");

    file3.open("department1.txt",ios::app|ios::out);
    file1>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;

    while(!file1.eof())
    {
        if(modi_id == emp_id)

            file3<<" "<<modi_dep<<" "<<emp_id<<" "<<fname1<<" "<<lname2<<" "<<modi_sal<<" "<<endl;

        else
            file3<<" "<<dep_name<<" "<<emp_id<<" "<<emp_fname<<" "<<emp_lname<<" "<<salary<<" "<<endl;
        file1>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;
    }
    file1.close();
    file3.close();
    remove("department.txt");
    rename("department1.txt","department.txt");
    if(found == 0)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee ID Can't Found.";
    }
    else
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t Record Modify Successfully.";
    }


}
void employee::delet()
{
    system("cls");
    int found=0;
    string del_id;
    fstream file,file1,file2,file3;
    cout<<endl<<endl;
    displayHeader("Delete Record");
    file.open("employees.txt",ios::in);
    file1.open("department.txt",ios::in);
    if(!file||!file1)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\tYour Database is Empty ";
        getch();
        menu();
    }
    cout<<"\t\t\t\t Enter Employee ID: ";
    cin>>del_id;
    file2.open("employees1.txt",ios::app|ios::out);
    file>>emp_id>>emp_fname>>emp_lname>>salary>>mobile_no>>address>>dep_name;
    while(!file.eof())
    {
        if(del_id==emp_id)
        {
            cout<<endl<<endl;
            cout<<"\t\t\t\t Record Deleted Successfully.";
            found++;
        }
        else
        {
            file2<<" "<<emp_id<<" "<<emp_fname<<" "<<emp_lname<<" "<<salary<<" "<<mobile_no<<" "<<address<<" "<<dep_name<<endl;

        }
        file>>emp_id>>emp_fname>>emp_lname>>salary>>mobile_no>>address>>dep_name;
    }
    file.close();
    file2.close();
    remove("employees.txt");
    rename("employees1.txt","employees.txt");

    file3.open("department1.txt",ios::app|ios::out);
    file1>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;

    while(!file1.eof())
    {
        if(del_id != emp_id)

            file3<<" "<<dep_name<<" "<<emp_id<<" "<<emp_fname<<" "<<emp_lname<<" "<<salary<<" "<<dep_name<<endl;
        file1>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;
    }
    file1.close();
    file3.close();
    remove("department.txt");
    rename("department1.txt","department.txt");
    if(found == 0)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee ID Can't Found.";
    }


}



void employee::dep()
{
    system("cls");
    fstream file;
    cout<<endl<<endl;
    displayHeader("Department Record");
    file.open("department.txt",ios::in);
    if(!file)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\tYour Database is Empty ";
        getch();
        menu();

    }
    file>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;
    while(!file.eof())
    {
        getDeptVal();
        file>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;
    }
    file.close();
}

void employee::getDeptVal()
{
    cout<<endl<<endl;
        cout<<"\t\t\t\t Employee Department: "<<dep_name;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee ID: "<<emp_id;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee First Name: "<<emp_fname;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee last Name: "<<emp_lname;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee Salary: "<<salary;
        cout<<endl<<endl;

}
void employee::search_dep()
{

    system("cls");
    string search_name;
    int found=0,empolyee_count=0,salary_count=0,total_salary;
    fstream file;
    cout<<endl<<endl;
    displayHeader("Search Record");
    file.open("department.txt",ios::in);
    if(!file)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\tYour Database is Empty ";
        getch();
        menu();
    }
    cout<<endl<<endl;
    cout<<"\t\t\t\t Department Name(Capital Letter) : ";
    cin>>search_name;
    system("cls");
    cout<<endl<<endl;
    displayHeader("Search Record");
    file>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;
    while(!file.eof())
    {
        if(search_name == dep_name)
        {
            getDeptVal();
            file>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;
            found++;
            empolyee_count++;

        }
        file>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;

    }
    file.close();
    if(found!=0)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee Department: "<<search_name;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Total Employee : "<<empolyee_count;
        cout<<endl<<endl;

    }
    else
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t Department name Can't Found.";
    }
}
void employee::show_dep()
{

    system("cls");
    int employee_count=0,salary_count=0,employee_total=0,salary_total=0;
    string show_dep;
    fstream file,file1;
    cout<<endl<<endl;
    displayHeader("Show All Deparment");
    file.open("departname.txt",ios::in);
    if(!file)
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\tYour Database is Empty ";
        getch();
        menu();
    }
    file>>show_dep;
    while(!file.eof())
    {
        file1.open("department.txt",ios::in);
        file1>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;
        while(!file1.eof())
        {
            if(show_dep == dep_name)
            {
                employee_count++;
                salary_count += salary;
                employee_total++;
                salary_total += salary;
            }
            file1>>dep_name>>emp_id>>emp_fname>>emp_lname>>salary;
        }
        file1.close();
        cout<<endl<<endl;
        cout<<"\t\t\t\t Employee Department: "<<show_dep;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Total employees: "<<employee_count;
        cout<<endl<<endl;
        cout<<"\t\t\t\t Total salary: "<<salary_count;
        employee_count=0;
        salary_count=0;
        file>>show_dep;
    }
    file.close();
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t Over All Employee : "<<employee_total;
    cout<<endl<<endl;
    cout<<"\t\t\t\t Over All Salary : "<<salary_total;

}

employee::~employee()
{
    //dtor
}
