#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>


class employee
{
private:
    std::string emp_id,emp_fname,emp_lname,dep_name,mobile_no,address;
    int salary;

    void getUserInput();
    bool isDepartmentExist(const std::string& );

public:
    employee();
    virtual ~employee();
    void login();
    void menu();
    void insert();
    void display();
    void search();
    void modify();
    void delet();
    void dep();
    void search_dep();
    void show_dep();
    void loadingAnimation();
    void showAdminDetails(const std::string& , const std::string& , const std::string& );
    void displayHeader(const std::string& );
    void start();
    char displayMenu();
    int getUserChoice();
    void performAction(int);
    void handleInsert();
    void getValues();
    void getDeptVal();



};

#endif // EMPLOYEE_H
