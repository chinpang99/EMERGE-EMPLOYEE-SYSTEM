#include <iostream>
#include <sstream> //ToString function
#include <string>  //ToString function
#include <cctype> //ToUpper function
#include <algorithm> //Transform function
#include<iomanip>  //Set Width function
using namespace std;

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

struct HR {
	string hr_id, username, password, name, departmentName, role;
}hr;

struct Employee_Details {
	string emp_name, emp_phone, emp_address, emp_depart_name, emp_leave_date,role;
	double emp_salary;
	int emp_depart_no, emp_overall_performance, emp_id;
}emp;

struct Employee {
	Employee_Details emp_details;
	HR hr_details;
	Employee* next;
	Employee* prev;
};

Employee* EMP_head = NULL; // create a head node for Employee
Employee* EMP_tail = NULL; // create a tail node for Employee
Employee* e_node1 = new Employee; //create node for Employee 1
Employee* e_node2 = new Employee; //create node for Employee 2
Employee* e_node3 = new Employee; //create node for Employee 3
Employee* e_node4 = new Employee; //create node for Employee 4
Employee* e_node5 = new Employee; //create node for Employee 5
Employee* hr_node1 = new Employee; //create node for HR 1
Employee* hr_node2 = new Employee; //create node for HR 2
Employee* hr_node3 = new Employee; //create node for HR 3
Employee* hr_node4 = new Employee; //create node for HR 4
Employee* hr_node5 = new Employee; //create node for HR 5
Employee* HR_current = NULL; //create a node for Current HR logged in

double salary = 0;
int hi = 0;

void HRList()
{
	hr_node1->hr_details.hr_id = "S01";
	hr_node1->hr_details.username = "hi";
	hr_node1->hr_details.password = "123";
	hr_node1->hr_details.name = "James";
	hr_node1->hr_details.departmentName = "Finance";
	hr_node1->hr_details.role = "HR";
	hr_node1->next = NULL;

	hr_node2->hr_details.hr_id = "S02";
	hr_node2->hr_details.username = "hii";
	hr_node2->hr_details.password = "123";
	hr_node2->hr_details.name = "Ali";
	hr_node2->hr_details.departmentName = "IT";
	hr_node2->hr_details.role = "HR";
	hr_node2->next = NULL;

	hr_node3->hr_details.hr_id = "S03";
	hr_node3->hr_details.username = "hiii";
	hr_node3->hr_details.password = "123";
	hr_node3->hr_details.name = "Chia";
	hr_node3->hr_details.departmentName = "Marketing";
	hr_node3->hr_details.role = "HR";
	hr_node3->next = NULL;

	hr_node4->hr_details.hr_id = "S04";
	hr_node4->hr_details.username = "hiiii";
	hr_node4->hr_details.password = "123";
	hr_node4->hr_details.name = "Chin";
	hr_node4->hr_details.departmentName = "Engineering";
	hr_node4->hr_details.role = "HR";
	hr_node4->next = NULL;

	hr_node5->hr_details.hr_id = "S05";
	hr_node5->hr_details.username = "hiiiii";
	hr_node5->hr_details.password = "123";
	hr_node5->hr_details.name = "Pang";
	hr_node5->hr_details.departmentName = "Multimedia";
	hr_node5->hr_details.role = "HR";
	hr_node5->next = NULL;
}

void empList()
{
	e_node1->emp_details.emp_id = 2002;
	e_node1->emp_details.emp_name = "Micheal";
	e_node1->emp_details.emp_salary = 3601;
	e_node1->emp_details.emp_phone = "012-3456789";
	e_node1->emp_details.emp_address = "APU";
	e_node1->emp_details.emp_depart_no = 1;
	e_node1->emp_details.emp_depart_name = "IT";
	e_node1->emp_details.emp_overall_performance = 3;
	e_node1->emp_details.emp_leave_date = "NULL";
	e_node1->emp_details.role = "EMPLOYEE";
	e_node1->next = NULL;

	e_node2->emp_details.emp_id = 1001;
	e_node2->emp_details.emp_name = "Micheall";
	e_node2->emp_details.emp_salary = 3600;
	e_node2->emp_details.emp_phone = "012-3456788";
	e_node2->emp_details.emp_address = "APU";
	e_node2->emp_details.emp_depart_no = 1;
	e_node2->emp_details.emp_depart_name = "Finance";
	e_node2->emp_details.emp_overall_performance = 2;
	e_node2->emp_details.emp_leave_date = "03/11/2019";
	e_node2->emp_details.role = "EMPLOYEE";
	e_node2->next = NULL;

	e_node3->emp_details.emp_id = 2001;
	e_node3->emp_details.emp_name = "Ahmad";
	e_node3->emp_details.emp_salary = 2900;
	e_node3->emp_details.emp_phone = "012-3456787";
	e_node3->emp_details.emp_address = "APU";
	e_node3->emp_details.emp_depart_no = 2;
	e_node3->emp_details.emp_depart_name = "IT";
	e_node3->emp_details.emp_overall_performance = 4;
	e_node3->emp_details.emp_leave_date = "01/01/2019";
	e_node3->emp_details.role = "EMPLOYEE";
	e_node3->next = NULL;

	e_node4->emp_details.emp_id = 3001;
	e_node4->emp_details.emp_name = "Ali";
	e_node4->emp_details.emp_salary = 2900;
	e_node4->emp_details.emp_phone = "012-3456790";
	e_node4->emp_details.emp_address = "APU";
	e_node4->emp_details.emp_depart_no = 2;
	e_node4->emp_details.emp_depart_name = "Marketing";
	e_node4->emp_details.emp_overall_performance = 4;
	e_node4->emp_details.emp_leave_date = "01/12/2019";
	e_node4->emp_details.role = "EMPLOYEE";
	e_node4->next = NULL;

	e_node5->emp_details.emp_id = 4001;
	e_node5->emp_details.emp_name = "Abu";
	e_node5->emp_details.emp_salary = 2900;
	e_node5->emp_details.emp_phone = "012-3456799";
	e_node5->emp_details.emp_address = "APU";
	e_node5->emp_details.emp_depart_no = 2;
	e_node5->emp_details.emp_depart_name = "Engineering";
	e_node5->emp_details.emp_overall_performance = 4;
	e_node5->emp_details.emp_leave_date = "01/12/2018";
	e_node5->emp_details.role = "EMPLOYEE";
	e_node5->next = NULL;

	/*Linked-List Connection*/
	EMP_head = e_node1;
	e_node1->prev = EMP_tail;
	e_node1->next = e_node3;
	e_node3->prev = e_node1;
	e_node3->next = hr_node1;
	hr_node1->prev = e_node3;
	hr_node1->next = hr_node2;
	hr_node2->prev = hr_node1;
	hr_node2->next = hr_node3;
	hr_node3->prev = hr_node2;
	hr_node3->next = e_node4;
	e_node4->prev = hr_node3;
	e_node4->next = hr_node4;
	hr_node4->prev = e_node4;
	hr_node4->next = e_node5;
	e_node5->prev = hr_node4;
	e_node5->next = hr_node5;
	hr_node5->prev = e_node5;
	hr_node5->next = e_node2;
	e_node2->prev = hr_node5;
	EMP_tail = e_node2;

}

/*Convert String to UpperCase*/
char change_case(char c) {
	return toupper(c); // Convert each characters into UpperCase using toupper function
}

/*Function to swap the nodes */
struct Employee* swap(struct Employee* ptr1, struct Employee* ptr2)
{
	if (ptr1 == EMP_head && ptr2 == EMP_tail) // If the linked list have ONLY 2 NODES
	{
		ptr2->prev = ptr1->prev; //Second Node prev point to head
		ptr1->next = NULL; //First Node next point to NULL
		ptr1->prev = ptr2; // First Node prev point to Second Node
		ptr2->next = ptr1; //Second Node next point to First Node
		EMP_head = ptr2; // Head Node change from First Node to Second Node
		EMP_tail = ptr1; // Tail Node change from Second Node to First Node
	}
	else if (ptr1 == EMP_head) //If the First Node is Head Node
	{
		ptr2->prev = NULL; // Second Pointer prev point to NULL
		ptr1->next = ptr2->next; //First Node next point to the Second Node next point
		ptr2->next->prev = ptr1; // The node after Second Node prev point to First Node
		ptr1->prev = ptr2; //First Node prev point to Second Node
		ptr2->next = ptr1; //Second Node next point to First Node
		EMP_head = ptr2; //Head Node change from First Node to Second Node

	}
	else if (ptr2 == EMP_tail) //If the Second Node is Tail Node
	{
		ptr1->prev->next = ptr2; //The node before First Node next point to Second Node
		ptr2->prev = ptr1->prev; //Second Node prev point to the First Node prev point
		ptr1->next = NULL; //First Node next point to NULL
		ptr1->prev = ptr2; //First Node prev point to Second Node
		ptr2->next = ptr1; //Second NOde next point to First Node
		EMP_tail = ptr1; //Tail Node change from Second Node to First Node
	}
	else
	{
		ptr1->prev->next = ptr2; //The node before First Node next point to Second Node
		ptr2->prev = ptr1->prev; //Second Node prev point to the First Node prev point
		ptr1->next = ptr2->next; //First Node next point to the Second Node next point
		ptr2->next->prev = ptr1; // The node after Second Node prev point to First Node
		ptr1->prev = ptr2; //First Node prev point to Second Node
		ptr2->next = ptr1; //Second Node next point to First Node
	}
	return ptr2;
}

/*Function to Calculate Salary */
double CalcSalary(double& emp_salary)
{
	if (emp_salary != 0) //If the Employee Salary is calculated
	{
		return emp_salary;
	}
start:
	string basic_salary;
	int convert_basic_salary = 0, house_rent = 0, conveyance = 0, medical = 0;
	string option, allowance_name;
	bool valid = false;

	cout << "Please Enter Employee\'s Basic Salary		                       : RM ";
	cin >> basic_salary;
	cin.clear(); cin.ignore(10000, '\n');
	for (auto& i : basic_salary) //Validation each character
	{
		if (!isdigit(i)) //If got 1 Character is NOT Integer
		{
			valid = false; //It is not a Valid Input
			break;
		}
		else {
			valid = true; //It is a Valid Employee Input
		}
	}
	while (valid == false) {
		cout << "Invalid input. Only INTEGER" << endl;
		cout << "\nPlease Enter Employee\'s Basic Salary		                       : RM ";
		cin >> basic_salary;
		cin.clear(); cin.ignore(10000, '\n');
		for (auto& i : basic_salary) //Validation Again
		{
			if (!isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}
	convert_basic_salary = stoi(basic_salary);
	cout << "Does Employee Taking Company House Rent? (Y = YES/N = NO)	       : ";
	cin >> option;
	while (option != "Y" && option != "y" && option != "N" && option != "n")// validating if user input NOT Y , y , N or n
	{
		cout << "Only Accept Alphabet Y (YES) or N (NO) " << endl;
		cout << "Does Employee Taking Company House Rent? (Y = YES/N = NO)	       : ";
		cin.clear();
		cin >> option;
	}
	if (option == "Y" || option == "y")
	{
		house_rent = convert_basic_salary * 0.5;
		cout << "House Rent : RM " << house_rent << endl; //Calculating Conveyance Allowance by Basic Salary * 50%
	}
	else if (option == "N" || option == "n")
	{
		house_rent = 0;
	}
	cout << "Does Employee Taking any Admissible Allowances? (Y = YES/N = NO)       : ";
	cin >> option;
	while (option != "Y" && option != "y" && option != "N" && option != "n") // validating if user input NOT Y , y , N or n
	{
		cout << "Only Accept Alphabet Y (YES) or N (NO) " << endl;
		cout << "Does Employee Taking any Admissible Allowances? (Y = YES/N = NO)       : ";
		cin.clear();
		cin >> option;
	}
	if (option == "Y" || option == "y") //Validating if user input Y or y
	{
		conveyance = convert_basic_salary * 0.05; //Calculating Conveyance Allowance by Basic Salary * 5%
		medical = 200;
		cout << "Conveyance (5%) : RM " << conveyance << endl;
		cout << "Medical         : RM " << medical << endl;
	}
	cout << "\n--------------------------------------";
	int total;
	cout << "\nBasic Salary                : RM " << basic_salary << endl;
	cout << "House Rent Fees             : RM " << house_rent << endl;
	cout << "Conveyance Allowance        : RM " << conveyance << endl;
	cout << "Medical Allowance           : RM " << medical << endl;
	cout << "--------------------------------------" << endl;
	cout << "Total Salary                : ";
	total = convert_basic_salary + house_rent + conveyance + medical; // Calculating Total Salary
	cout << "RM " << total << endl << endl;
	cout << "Is it ok for you? (Y = YES/N = NO)     : ";
	cin >> option;
	while (option != "Y" && option != "y" && option != "N" && option != "n")// validating if user input NOT Y , y , N or n
	{
		cout << "Only Accept Alphabet Y (YES) or N (NO) " << endl;
		cout << "Is it ok for you? (Y = YES/N = NO)     : ";
		cin.clear();
		cin >> option;
	}
	if (option == "Y" || option == "y")
	{
		emp_salary = total;
	}
	else
	{
		system("CLS");
		goto start;
	}
	system("CLS");
	return emp_salary;
}

/* Function to Add Employee*/
void addEmployee()
{
	int set_emp_id = 1001, emp_depart_no = 1;
	string emp_overall_performance;
	int convert_emp_overall_performance;
	bool valid = false;

	Employee* emp_id = EMP_head;
	while (emp_id != NULL) //Generating Employee's Department ID
	{
		if (emp_id->hr_details.role != "HR") //If the current node is not HR Role
		{
			emp_id = emp_id->next;
		}
		else
		{
			if (emp_id->hr_details.departmentName == HR_current->hr_details.departmentName) //If the current node department name same as the department name in HR
			{
				break;
			}
			else // Else it will +1000 and traversal to next HR Details to check whether same Department Name as the Current HR Department Name
			{
				set_emp_id = set_emp_id + 1000;
				emp_depart_no++;
				emp_id = emp_id->next;
			}
		}
	}

	Employee* curr = EMP_head;
	while (curr != NULL) //Generating Employee ID
	{
		if (curr->emp_details.emp_id == set_emp_id) //If the Generated ID is used, then the Generated ID will +1 and move back to the head to check again
		{
			set_emp_id = set_emp_id + 1;
			curr = EMP_head;
		}
		else
		{
			curr = curr->next;
		}
	}

	emp.emp_id = set_emp_id;
	emp.emp_depart_no = emp_depart_no;
	emp.emp_depart_name = HR_current->hr_details.departmentName;
	CalcSalary(salary); //Calculate Salary Function
	emp.emp_salary = salary;
	emp.emp_leave_date = "NULL";
	emp.role = "EMPLOYEE";

	Employee* validation = EMP_head;
	cout << "Employee ID                        : " << set_emp_id << endl;
	cout << "Enter Employee Name                : ";
	if (hi != 1)
	{
		cin.get(); //Start getting input
	}
	getline(cin, emp.emp_name, '\n'); //Get User Input including blank space
	start:
	for (auto& i : emp.emp_name) //Validation each character in Employee Name
	{
		if (isdigit(i)) //If got 1 Character is Integer in Employee Name
		{
			valid = false; //It is not a Valid Employee Name
			break;
		}
		else {
			valid = true; //It is a Valid Employee Name
		}
	}
	while (valid == false) {
		cout << "Invalid name. Please try again!" << endl;
		cout << "\nEnter Employee Name                : ";
		getline(cin, emp.emp_name, '\n');
		for (auto& i : emp.emp_name) //Validation Again
		{
			if (isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}
	validation = EMP_head;
	while (validation != NULL) //Validation for Employee Name is Exist or not
	{
		if (validation->emp_details.emp_name == emp.emp_name)
		{
			cout << "\nEmployee Name is exist" << endl;
			validation = EMP_head;
			cout << "\nEnter Employee Name                : ";
			getline(cin, emp.emp_name, '\n');
			goto start;
		}
		else
		{
			validation = validation->next;
		}
	}
	cout << "Employee Salary                    : ";
	cout << "RM " << salary << endl;
	cout << "Enter Employee Phone Number        : ";
	getline(cin, emp.emp_phone, '\n');
	while (emp.emp_phone == "") //Validation if the user left blank in Employee Phone Number
	{
		cout << "\nEmployee Phone Number is Empty" << endl;
		cout << "\nEnter Employee Phone Number        : ";
		getline(cin, emp.emp_phone, '\n');
	}
	validation = EMP_head;
	while (validation != NULL) //Validation for Employee Phone Number is Exist or not
	{
		if (validation->emp_details.emp_phone == emp.emp_phone)
		{
			cout << "\nEmployee Phone is exist" << endl;
			validation = EMP_head;
			cout << "\nEnter Employee Phone Number        : ";
			getline(cin, emp.emp_phone, '\n');
		}
		else
		{
			validation = validation->next;
		}
	}
	cout << "Enter Employee Address             : ";
	getline(cin, emp.emp_address, '\n');
	while (emp.emp_address == "") //Validation if the user left blank in Employee Address
	{
		cout << "\nEmployee Addressis Empty" << endl;
		cout << "\nEnter Employee Address             : ";
		getline(cin, emp.emp_address, '\n');
	}
	validation = EMP_head;
	while (validation != NULL) //Validation for Employee Address is Exist or not
	{
		if (validation->emp_details.emp_address == emp.emp_address)
		{
			cout << "\nEmployee Address is exist" << endl;
			validation = EMP_head;
			cout << "Enter Employee Address             : ";
			getline(cin, emp.emp_address, '\n');
		}
		else
		{
			validation = validation->next;
		}
	}
	cout << "Enter Employee Overall Performance : ";
	cin >> emp_overall_performance;
	cin.clear(); cin.ignore(10000, '\n');
	start_1:
	for (auto& i : emp_overall_performance) //Validation each character
	{
		if (!isdigit(i)) //If got 1 Character is NOT Integer
		{
			valid = false; //It is not a Valid Input
			break;
		}
		else {
			valid = true; //It is a Valid Employee Input
		}
	}
	while (valid == false) {
		cout << "Invalid input. Only INTEGER" << endl;
		cout << "Enter Employee Overall Performance : ";
		cin >> emp_overall_performance;
		cin.clear(); cin.ignore(10000, '\n');
		for (auto& i : emp_overall_performance) //Validation Again
		{
			if (!isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}
	convert_emp_overall_performance = stoi(emp_overall_performance);
	while (convert_emp_overall_performance < 1 || convert_emp_overall_performance >4) //Validation for User insert NOT INTEGER or Out Of The Overall Performance Range (1 - 4)
	{
		cout << "\nPlease Enter the Overall Performance between 1 - 4: ";
		cin >> emp_overall_performance;
		cin.clear(); cin.ignore(10000, '\n');
		goto start_1;
	}
	emp.emp_overall_performance = convert_emp_overall_performance;
	hi = 0;
	/*Start Insert Node into the Linked List*/
	Employee* node = new Employee;
	node->emp_details = emp;
	node->next = NULL;
	node->prev = EMP_tail;
	EMP_tail = node;
	node->prev->next = node;
	cout << "\nInsert Successfully" << endl << endl << flush; //pause the screen after a cout statement
	salary = 0; //Reset the Salary Amount
	system("PAUSE"); //Pause the screen before proceed to next function
	system("CLS"); //Clear the Screen

}

/* Function to print the Employee list from head*/
void printList(struct Employee* curr)
{
	while (curr != NULL) //If the Current Node is Not NULL
	{
		if (curr->emp_details.role != "EMPLOYEE") //If the Current Node Role is HR
		{
			curr = curr->next;
		}
		else
		{
			cout << endl << "___________________________________________________________________________________________________________" << endl << endl;
			cout << "Employee ID                  : " << curr->emp_details.emp_id << endl;
			cout << "Employee Name                : " << curr->emp_details.emp_name << endl;
			cout << "Employee Salary              : " << curr->emp_details.emp_salary << endl;
			cout << "Employee Phone               : " << curr->emp_details.emp_phone << endl;
			cout << "Employee Address             : " << curr->emp_details.emp_address << endl;
			cout << "Employee Department No       : " << curr->emp_details.emp_depart_no << endl;
			cout << "Employee Department Name     : " << curr->emp_details.emp_depart_name << endl;
			cout << "Employee Overall Performance : " << curr->emp_details.emp_overall_performance << endl;
			cout << "Employee Leaving Date        : " << curr->emp_details.emp_leave_date << endl;

			curr = curr->next;
		}
	}
	cout << "\n";
}

/* Function to print the Employee list from tail*/
void printList_Tail(struct Employee* curr)
{
	while (curr != NULL) //If the Current Node is Not NULL
	{
		if (curr->emp_details.role != "EMPLOYEE") //If the Current Node Role is HR
		{
			curr = curr->prev;
		}
		else
		{
			cout << endl << "___________________________________________________________________________________________________________" << endl << endl;
			cout << "Employee ID                  : " << curr->emp_details.emp_id << endl;
			cout << "Employee Name                : " << curr->emp_details.emp_name << endl;
			cout << "Employee Salary              : " << curr->emp_details.emp_salary << endl;
			cout << "Employee Phone               : " << curr->emp_details.emp_phone << endl;
			cout << "Employee Address             : " << curr->emp_details.emp_address << endl;
			cout << "Employee Department No       : " << curr->emp_details.emp_depart_no << endl;
			cout << "Employee Department Name     : " << curr->emp_details.emp_depart_name << endl;
			cout << "Employee Overall Performance : " << curr->emp_details.emp_overall_performance << endl;
			cout << "Employee Leaving Date        : " << curr->emp_details.emp_leave_date << endl;

			curr = curr->prev;
		}
	}
	cout << "\n";
}

/* Bubble Sort by Employee Name*/
int bubbleSort_EMP_NAME(struct Employee** head, int count)
{
	struct Employee** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {
		h = head;
		swapped = 0; //swapped = false

		for (j = 0; j < count - i - 1; j++) {
			struct Employee* p1 = *h;
			struct Employee* p2 = p1->next;
			string a = p1->emp_details.emp_name; //retrieve employee name in first node
			string b = p2->emp_details.emp_name; //retrieve employee name in second node

			transform(a.begin(), a.end(), a.begin(), change_case); //transform first node employee name to uppercase
			transform(b.begin(), b.end(), b.begin(), change_case); //transform second node employee name to uppercase

			if (a > b) { //if the ASCII Code of first node employee name is higher than second node employee name

				/* update the link after swapping */
				*h = swap(p1, p2); //swap between first node and second node
				swapped = 1; // swapped = true
			}

			h = &(*h)->next; //transverse to next node
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
	return 0;
}

/* Display All Employee Records */
void displayEmployee()
{
	Employee* emp_head = EMP_head; //Start at head
	int count = 0; //Initialize Linked List Size = 0

	while (emp_head != NULL)
	{
		count++;  //Count Linked List Size
		emp_head = emp_head->next;
	}

	emp_head = EMP_head;
	if (emp_head == NULL) //No Employee
	{
		cout << HR_current->hr_details.name << ", there is no employee list" << endl;
	}
	else
	{
		bubbleSort_EMP_NAME(&emp_head, count); //Sort By Employee Name is Alphabet Sequence
		printList(EMP_head); //Print Employee List
	}
	cout << endl;
	system("pause");
	system("CLS");
}

/* Search Employee Records in Specific Department */
void searchByDepartment(string departName, int& employee_exist)
{
	int num = 1, emp_record = 0;
	string convert_departName;
	cout << "You're searching employee in Department " << departName << endl;

	Employee* emp_head = EMP_head;
	while (emp_head != NULL)
	{
		convert_departName = emp_head->emp_details.emp_depart_name;
		transform(convert_departName.begin(), convert_departName.end(), convert_departName.begin(), change_case); //Transform department name to all uppercase

		if (departName == convert_departName)
		{
			cout << endl << "___________________________________________________________________________________________________________" << endl << endl;
			cout << "Employee ID                  : " << emp_head->emp_details.emp_id << endl;
			cout << "Employee Name                : " << emp_head->emp_details.emp_name << endl;
			cout << "Employee Salary              : " << emp_head->emp_details.emp_salary << endl;
			cout << "Employee Phone               : " << emp_head->emp_details.emp_phone << endl;
			cout << "Employee Address             : " << emp_head->emp_details.emp_address << endl;
			cout << "Employee Department No       : " << emp_head->emp_details.emp_depart_no << endl;
			cout << "Employee Department Name     : " << emp_head->emp_details.emp_depart_name << endl;
			cout << "Employee Overall Performance : " << emp_head->emp_details.emp_overall_performance << endl;

			emp_head = emp_head->next;
			emp_record = 1; // Employee record found in the specific department
		}
		else
		{
			emp_head = emp_head->next;
		}
	}

	if (emp_record == 0) // Employee record not found in the specific department
	{
		cout << "\nNo record found in " << departName << endl << endl;
		employee_exist = 0; //No Employee in this department

		system("Pause");
		system("CLS");
	}

}

/* Search Result by Employee ID from All Employee Records*/
void searchResultByID(int emp_id)
{
	int emp_found = 0;
	Employee* emp_head = EMP_head;

	system("CLS");

	while (emp_head != NULL)
	{
		if (emp_id == emp_head->emp_details.emp_id)
		{
			cout << endl << "___________________________________________________________________________________________________________" << endl << endl;
			cout << "Employee ID                  : " << emp_head->emp_details.emp_id << endl;
			cout << "Employee Name                : " << emp_head->emp_details.emp_name << endl;
			cout << "Employee Salary              : " << emp_head->emp_details.emp_salary << endl;
			cout << "Employee Phone               : " << emp_head->emp_details.emp_phone << endl;
			cout << "Employee Address             : " << emp_head->emp_details.emp_address << endl;
			cout << "Employee Department No       : " << emp_head->emp_details.emp_depart_no << endl;
			cout << "Employee Department Name     : " << emp_head->emp_details.emp_depart_name << endl;
			cout << "Employee Overall Performance : " << emp_head->emp_details.emp_overall_performance << endl;

			cout << "\nEmployee Found!" << endl << endl;
			system("Pause");
			system("CLS");
			emp_found = 1; //The employee found = true
			break;
		}
		else
		{
			emp_head = emp_head->next;
		}
	}

	if (emp_found == 0) //The employee found = false
	{
		cout << "\nNo record found" << endl << endl;
		system("Pause");
		system("CLS");
	}

}

/* Search Result by Employee ID from Specific Department Records*/
void searchDeptResultByID(string depart_name, int emp_id)
{
	Employee* emp_head = EMP_head;
	int emp_found = 0;
	string convert_departName;

	system("CLS");

	while (emp_head != NULL)
	{
		convert_departName = emp_head->emp_details.emp_depart_name;
		transform(convert_departName.begin(), convert_departName.end(), convert_departName.begin(), change_case); //Transform department name to all uppercase

		if (depart_name == convert_departName && emp_id == emp_head->emp_details.emp_id)
		{
			cout << endl << "___________________________________________________________________________________________________________" << endl << endl;
			cout << "Employee ID                  : " << emp_head->emp_details.emp_id << endl;
			cout << "Employee Name                : " << emp_head->emp_details.emp_name << endl;
			cout << "Employee Salary              : " << emp_head->emp_details.emp_salary << endl;
			cout << "Employee Phone               : " << emp_head->emp_details.emp_phone << endl;
			cout << "Employee Address             : " << emp_head->emp_details.emp_address << endl;
			cout << "Employee Department No       : " << emp_head->emp_details.emp_depart_no << endl;
			cout << "Employee Department Name     : " << emp_head->emp_details.emp_depart_name << endl;
			cout << "Employee Overall Performance : " << emp_head->emp_details.emp_overall_performance << endl;

			cout << "\nEmployee Found!" << endl << endl;
			system("Pause");
			system("CLS");
			emp_found = 1; // Employee Records exists in this department
			break;
		}
		else
		{
			emp_head = emp_head->next;
		}
	}

	if (emp_found == 0)  // Employee Records not exists in this department
	{
		cout << "\nNo record found" << endl << endl;
		system("Pause");
		system("CLS");
	}
}

/* Search by Employee ID */
void searchByEmployeeID()
{
	Employee* curr_emp = EMP_head;
	int num = 0, convert_emp_id, found = 1, count = 0, convert_option;
	string dept_name, option, emp_id;
	bool valid = false;

	while (curr_emp != NULL)
	{
		count++; //Count Linked List Size
		curr_emp = curr_emp->next;
	}

	curr_emp = EMP_head;

	cout << "1. Search by All Records " << endl;
	cout << "2. Search by Departments " << endl;
	cout << "3. Back to MainPage " << endl;
	cout << "\nPlease select your option: ";
	cin >> option;
	cin.clear(); cin.ignore(100000, '\n');
	start_1:
	for (auto& i : option) //Validation each character
	{
		if (!isdigit(i)) //If got 1 Character is NOT Integer
		{
			valid = false; //It is not a Valid Input
			break;
		}
		else {
			valid = true; //It is a Valid Input
		}
	}
	while (valid == false) {
		cout << "Invalid input. Only INTEGER" << endl;
		cout << "\nPlease select your option: ";
		cin >> option;
		cin.clear(); cin.ignore(100000, '\n');
		for (auto& i : option) //Validation Again
		{
			if (!isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}
	convert_option = stoi(option);
	while (convert_option < 0 || convert_option >3)
	{
		cout << "\nPlease Choose AN Option between 1 to 3: ";
		cin >> option;
		cin.clear(); cin.ignore(100000, '\n');
		goto start_1;
	}

	system("CLS");

	bubbleSort_EMP_NAME(&curr_emp, count); //Sort Employee Name in Alphabet Sequence

	while (option != "3")
	{
		switch (convert_option)
		{
		case 1:
			printList(curr_emp); //Print Employee List
			cout << "\nPlease insert Employee ID to search : ";
			cin >> emp_id;
			cin.clear(); cin.ignore(100000, '\n');
			for (auto& i : emp_id) //Validation each character
			{
				if (!isdigit(i)) //If got 1 Character is NOT Integer
				{
					valid = false; //It is not a Valid Input
					break;
				}
				else {
					valid = true; //It is a Valid Employee Input
				}
			}
			while (valid == false) {
				cout << "Invalid input. Only INTEGER" << endl;
				cout << "\nPlease insert Employee ID to search : ";
				cin >> emp_id;
				cin.clear(); cin.ignore(100000, '\n');
				for (auto& i : emp_id) //Validation Again
				{
					if (!isdigit(i))
					{
						valid = false;
						break;
					}
					else {
						valid = true;
					}
				}
			}
			convert_emp_id = stoi(emp_id);
			searchResultByID(convert_emp_id); //Search Result By Insert Employee ID from All Department
			break;
		case 2:
			cout << "Please Insert Department Name: ";
			//cin.get();
			getline(cin, dept_name, '\n'); //Get All String Input including blank space
			transform(dept_name.begin(), dept_name.end(), dept_name.begin(), change_case); //Transform input department name to all uppercase
			searchByDepartment(dept_name, found); //Search Employee Records in Specific Department
			if (found == 1)
			{
				cout << "\nPlease insert Employee ID to search : ";
				cin >> emp_id;
				cin.clear(); cin.ignore(100000, '\n');	
				for (auto& i : emp_id) //Validation each character
				{
					if (!isdigit(i)) //If got 1 Character is NOT Integer
					{
						valid = false; //It is not a Valid Input
						break;
					}
					else {
						valid = true; //It is a Valid Employee Input
					}
				}
				while (valid == false) {
					cout << "Invalid input. Only INTEGER" << endl;
					cout << "\nPlease insert Employee ID to search : ";
					cin >> emp_id;
					cin.clear(); cin.ignore(100000, '\n');
					for (auto& i : emp_id) //Validation Again
					{
						if (!isdigit(i))
						{
							valid = false;
							break;
						}
						else {
							valid = true;
						}
					}
				}
				convert_emp_id = stoi(emp_id);
				searchDeptResultByID(dept_name, convert_emp_id); //Search Result by Insert Employee ID from Specific Department
			}
			break;
		}
		break;
	}
}

/*Search Result by Employee Overall Performance from All Employee Records*/
void searchAllResultByOverallPerformance(int overall_performance)
{
	int departNo = 1, found = 0;
	Employee* currr = EMP_head;

	system("CLS");

	while (currr != NULL)
	{
		if (overall_performance == currr->emp_details.emp_overall_performance)
		{
			cout << endl << "___________________________________________________________________________________________________________" << endl << endl;
			cout << "Employee ID                  : " << currr->emp_details.emp_id << endl;
			cout << "Employee Name                : " << currr->emp_details.emp_name << endl;
			cout << "Employee Salary              : " << currr->emp_details.emp_salary << endl;
			cout << "Employee Phone               : " << currr->emp_details.emp_phone << endl;
			cout << "Employee Address             : " << currr->emp_details.emp_address << endl;
			cout << "Employee Department No       : " << currr->emp_details.emp_depart_no << endl;
			cout << "Employee Department Name     : " << currr->emp_details.emp_depart_name << endl;
			cout << "Employee Overall Performance : " << currr->emp_details.emp_overall_performance << endl;
			found = 1;
			currr = currr->next;
		}
		else
		{
			currr = currr->next;
		}
	}

	if (found == 0)
	{
		cout << "\nNo record found" << endl << endl;
		system("Pause");
		system("CLS");
	}
	else
	{
		cout << "\nEmployee Found!" << endl << endl;
		system("Pause");
		system("CLS");
	}
}

/*Search by Employee Overall Performance from All Employee Records*/
void searchDeptResultByOverallPerformance(string depart_name, int overall_performance)
{
	Employee* EMP_cur = EMP_head;
	int departNo = 1, emp_found = 0;
	string convert_departName;

	system("CLS");

	while (EMP_cur != NULL)
	{
		convert_departName = EMP_cur->emp_details.emp_depart_name;
		transform(convert_departName.begin(), convert_departName.end(), convert_departName.begin(), change_case); //Transform department name to all uppercase

		if (depart_name == convert_departName && overall_performance == EMP_cur->emp_details.emp_overall_performance)
		{
			cout << endl << "___________________________________________________________________________________________________________" << endl << endl;
			cout << "Employee ID                  : " << EMP_cur->emp_details.emp_id << endl;
			cout << "Employee Name                : " << EMP_cur->emp_details.emp_name << endl;
			cout << "Employee Salary              : " << EMP_cur->emp_details.emp_salary << endl;
			cout << "Employee Phone               : " << EMP_cur->emp_details.emp_phone << endl;
			cout << "Employee Address             : " << EMP_cur->emp_details.emp_address << endl;
			cout << "Employee Department No       : " << EMP_cur->emp_details.emp_depart_no << endl;
			cout << "Employee Department Name     : " << EMP_cur->emp_details.emp_depart_name << endl;
			cout << "Employee Overall Performance : " << EMP_cur->emp_details.emp_overall_performance << endl;

			emp_found = 1;
			EMP_cur = EMP_cur->next;
		}
		else
		{
			EMP_cur = EMP_cur->next;
		}
	}

	if (emp_found == 0)
	{
		cout << "\nNo record found" << endl << endl;
		system("Pause");
		system("CLS");
	}
	else
	{
		cout << "\nEmployee Found!" << endl << endl;
		system("Pause");
		system("CLS");
	}
}

/* Search by Overall Performance */
void searchByOverallPerformance()
{
	Employee* curr_emp = EMP_head;
	int num = 0, found = 1, count = 0,convert_option,convert_overall_performance;
	string dept_name, option, overall_performance;
	bool valid = false;

	while (curr_emp != NULL)
	{
		count++; //Counting Linked List size
		curr_emp = curr_emp->next;
	}

	curr_emp = EMP_head;

	cout << "1. Search by All Records " << endl;
	cout << "2. Search by Departments " << endl;
	cout << "3. Back to MainPage " << endl;
	cout << "\nPlease select your option: ";
	cin >> option;
	cin.clear(); cin.ignore(100000, '\n');
	start_1:
	for (auto& i : option) //Validation each character
	{
		if (!isdigit(i)) //If got 1 Character is NOT Integer
		{
			valid = false; //It is not a Valid Input
			break;
		}
		else {
			valid = true; //It is a Valid Employee Name
		}
	}
	while (valid == false) {
		cout << "Invalid input. Only INTEGER" << endl;
		cout << "\nPlease select your option: ";
		cin >> option;
		cin.clear(); cin.ignore(100000, '\n');
		for (auto& i : option) //Validation Again
		{
			if (!isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}
	convert_option = stoi(option);
	while (convert_option < 0 || convert_option >3) //Validation if User not Input Integer or Insert the integer not between 1 - 3 option
	{
		cout << "\nPlease Choose AN Option between 1 to 3: ";
		cin >> option;
		cin.clear(); cin.ignore(100000, '\n');
		goto start_1;
	}

	system("CLS");
	bubbleSort_EMP_NAME(&curr_emp, count); //Sort Employee Name in Alphabet Sequence

	while (convert_option != 3)
	{
		switch (convert_option)
		{
		case 1:
			printList(curr_emp);
			cout << "\nPlease insert Overall Performance to search : ";
			cin >> overall_performance;
			cin.clear(); cin.ignore(10000, '\n');
			start_2:
			for (auto& i : overall_performance) //Validation each character
			{
				if (!isdigit(i)) //If got 1 Character is NOT Integer
				{
					valid = false; //It is not a Valid Input
					break;
				}
				else {
					valid = true; //It is a Valid Employee Input
				}
			}
			while (valid == false) {
				cout << "Invalid input. Only INTEGER" << endl;
				cout << "\nPlease insert Overall Performance to search : ";
				cin >> overall_performance;
				cin.clear(); cin.ignore(100000, '\n');
				for (auto& i : overall_performance) //Validation Again
				{
					if (!isdigit(i))
					{
						valid = false;
						break;
					}
					else {
						valid = true;
					}
				}
			}
			convert_overall_performance = stoi(overall_performance);
			while (convert_overall_performance < 1 || convert_overall_performance >4) //Validation if User not Input Integer or Insert the integer not between 1 - 4
			{
				cout << "\nPlease Enter the Overall Performance between 1 - 4: ";
				cin >> overall_performance;
				cin.clear(); cin.ignore(10000, '\n');
				goto start_2;
			}
			searchAllResultByOverallPerformance(convert_overall_performance); //Search Result by Insert Employee Overall Performance from All Employee Records
			break;
		case 2:
			//cin.get();
			cout << "Please Insert Department Name: ";
			getline(cin, dept_name, '\n');
			transform(dept_name.begin(), dept_name.end(), dept_name.begin(), change_case); //Transform input department name to all uppercase
			searchByDepartment(dept_name, found); //Search Employee Records in Specific Department
			if (found == 1)
			{
				cout << "\nPlease insert Overall Performance to search : ";
				cin >> overall_performance;
				cin.clear(); cin.ignore(10000, '\n');
				start_3:
				for (auto& i : overall_performance) //Validation each character
				{
					if (!isdigit(i)) //If got 1 Character is NOT Integer
					{
						valid = false; //It is not a Valid Input
						break;
					}
					else {
						valid = true; //It is a Valid Employee Input
					}
				}
				while (valid == false) {
					cout << "Invalid input. Only INTEGER" << endl;
					cout << "\nPlease insert Overall Performance to search : ";
					cin >> overall_performance;
					cin.clear(); cin.ignore(100000, '\n');
					for (auto& i : overall_performance) //Validation Again
					{
						if (!isdigit(i))
						{
							valid = false;
							break;
						}
						else {
							valid = true;
						}
					}
				}
				convert_overall_performance = stoi(overall_performance);
				while (convert_overall_performance < 1 || convert_overall_performance >4) //Validation if User not Input Integer or Insert the integer not between 1 - 4
				{
					cout << "\nPlease Enter the Overall Performance between 1 - 4: ";
					cin >> overall_performance;
					cin.clear(); cin.ignore(10000, '\n');
					goto start_3;
				}
				searchDeptResultByOverallPerformance(dept_name, convert_overall_performance); ///Search Result by Insert Employee Overall Performance from Specific Department
			}
			break;
		}
		break;
	}
}

/*Delete Employee Records*/
void deleteEmp(int emp_id)
{
	Employee* emp_prev = NULL, * emp_delete = EMP_head, * curr = EMP_head, * beforeLast = EMP_head;
	string status = "", date, day, month, year;
	int head = 0, leave_date = 0, exist = 0;
	time_t t = time(nullptr);
	tm* ltm = localtime(&t); //Obtain System Time
	char mbstr[100];

	while (curr != NULL)
	{
		if (emp_id == curr->emp_details.emp_id)
		{
			exist = 1; //Employee Found
			if (curr->emp_details.emp_leave_date == "NULL") //If the Employee Leave Date is Null
			{
				if (strftime(mbstr, sizeof(mbstr), "%d/%m/%Y", ltm)) { //Convert Date into DD/MM/YYYY String Format
					date = mbstr;
				}
				curr->emp_details.emp_leave_date = date;
				leave_date = 1; //Leave Date Added
			}
			break;
		}
		else
		{
			curr = curr->next;
		}
	}

	curr = EMP_head;

	while (curr != NULL) {
		if (emp_id == curr->emp_details.emp_id && head == 0) //If the employee found and it is head node
		{
			exist = 1;
			if (leave_date == 1) //If the Employee Leave Date is today added
			{
				break;
			}
			day = curr->emp_details.emp_leave_date.substr(0, 2); //Retrieve Day using Sub-String
			month = curr->emp_details.emp_leave_date.substr(3, 2); //Retrieve Month using Sub-String
			year = curr->emp_details.emp_leave_date.substr(6, 4); //Retrieve Year using Sub-String
			int int_day = stoi(day); //Convert Day from string to integer
			int int_month = stoi(month); //Convert Month from string to integer
			int int_year = stoi(year); //Convert Year from string to integer
			int est_month = int_month + 6; //Estimation month for able to delete (the month after 6 months)
			int est_year = int_year; //Estimation year for able to delete

			if (est_month > 12) //If estimation month is more than 12
			{
				est_year++;
				est_month = est_month - 12;
			}

			int dayy = ltm->tm_mday;
			int monthh = 1 + ltm->tm_mon;
			int yearr = 1900 + ltm->tm_year;

			if (int_day == dayy && est_month == monthh && est_year == yearr) //If today date is same day, month, year as estimation day, month, year
			{
				status = "first";
			}
			else if (yearr > est_year) //If today year more than estimation year
			{
				status = "first";
			}
			else
			{
				if (monthh > est_month&& yearr == est_year) //If today year is same as estimation year but month is more than estimation month
				{
					status = "first";
				}
				else
				{
					if (monthh == est_month && yearr == est_year) //If today year and month is same as estimation year and month
					{
						if (dayy > int_day) //If today day is higher than estimation day
						{
							status = "first";
						}
						else
						{
							status = "NO";
						}
					}
					else
					{
						status = "NO";
					}
				}
			}
			break;
		}
		else
		{
			head++;
			if (emp_id == curr->emp_details.emp_id && curr->next == NULL) //If the employee node is tail
			{
				exist = 1; //Employee Found
				if (leave_date == 1)
				{
					break;
				}
				day = curr->emp_details.emp_leave_date.substr(0, 2);
				month = curr->emp_details.emp_leave_date.substr(3, 2);
				year = curr->emp_details.emp_leave_date.substr(6, 4);
				int int_day = stoi(day);
				int int_month = stoi(month);
				int int_year = stoi(year);
				int est_month = int_month + 6;
				int est_year = int_year;

				if (est_month > 12)
				{
					est_year++;
					est_month = est_month - 12;
				}

				int dayy = ltm->tm_mday;
				int monthh = 1 + ltm->tm_mon;
				int yearr = 1900 + ltm->tm_year;

				if (int_day == dayy && est_month == monthh && est_year == yearr)
				{
					status = "last";
				}
				else if (yearr > est_year)
				{
					status = "last";
				}
				else
				{
					if (monthh > est_month&& yearr == est_year)
					{
						status = "last";
					}
					else
					{
						if (monthh == est_month && yearr == est_year)
						{
							if (dayy > int_day)
							{
								status = "last";
							}
							else
							{
								status = "NO";
							}
						}
						else
						{
							status = "NO";
						}
					}
				}
				break;
			}
			else
			{
				status = "middle";
				curr = curr->next;
			}
		}
	}

	curr = EMP_head;

	while (curr != NULL)
	{
		if (leave_date == 1)
		{
			cout << "Add leaving date successfully" << endl;
			break;
		}
		else if (status == "NO")
		{
			cout << "Employee is not more than 6 months yet!" << endl;
			break;
		}
		else if (status == "first")
		{
			EMP_head = EMP_head->next;
			if (EMP_head == NULL)
			{
				EMP_tail = NULL;
			}
			else
			{
				emp_delete->next->prev = emp_delete->prev;
			}
			delete emp_delete;
			break;
			cout << "Delete Empoyee Successfully" << endl;
		}

		else if (status == "last")
		{
			while (beforeLast->next->next != NULL)
			{
				beforeLast = beforeLast->next;
			}
			EMP_tail = beforeLast;
			delete beforeLast->next;
			beforeLast->next = NULL;
			break;
			cout << "Delete Empoyee Successfully" << endl;
		}
		else
		{
			if (emp_id == curr->emp_details.emp_id) //If the employee node is not head and tail
			{
				exist = 1;
				if (head == 1)
				{
					break;
				}
				day = curr->emp_details.emp_leave_date.substr(0, 2);
				month = curr->emp_details.emp_leave_date.substr(3, 2);
				year = curr->emp_details.emp_leave_date.substr(6, 4);
				int int_day = stoi(day);
				int int_month = stoi(month);
				int int_year = stoi(year);
				int est_month = int_month + 6;
				int est_year = int_year;

				if (est_month > 12)
				{
					est_year++;
					est_month = est_month - 12;
				}

				int dayy = ltm->tm_mday;
				int monthh = 1 + ltm->tm_mon;
				int yearr = 1900 + ltm->tm_year;

				if (int_day == dayy && est_month == monthh && est_year == yearr)
				{
					cout << "Delete Empoyee Successfully" << endl;
					emp_delete->prev->next = emp_delete->next;
					emp_delete->next->prev = emp_delete->prev;
					delete emp_delete;
				}
				else if (yearr > est_year)
				{
					cout << "Delete Empoyee Successfully" << endl;
					emp_delete->prev->next = emp_delete->next;
					emp_delete->next->prev = emp_delete->prev;
					delete emp_delete;
				}
				else
				{
					if (monthh > est_month&& yearr == est_year)
					{
						cout << "Delete Empoyee Successfully" << endl;
						emp_delete->prev->next = emp_delete->next;
						emp_delete->next->prev = emp_delete->prev;
						delete emp_delete;
					}
					else
					{
						if (monthh == est_month && yearr == est_year)
						{
							if (dayy > int_day)
							{
								cout << "Delete Empoyee Successfully" << endl;
								emp_delete->prev->next = emp_delete->next;
								emp_delete->next->prev = emp_delete->prev;
								delete emp_delete;
							}
							else
							{
								cout << "Employee unable to delete because it is not more than 6 months yet!" << endl;
							}
						}
						else
						{
							cout << "Employee unable to delete because it is not more than 6 months yet!" << endl;
						}
					}
				}
				break;
			}
			else {
				curr = curr->next;
				emp_delete = emp_delete->next;
			}
		}

	}

	if (exist == 0)
	{
		cout << "No record found" << endl;
		system("pause");
		system("CLS");
	}
	else
	{
		system("pause");
		system("CLS");
	}
}

/*Update Employee Records*/
void updateEmp(int emp_id)
{
	Employee* curr = EMP_head;
	Employee* validation = EMP_head;
	string option, emp_name, emp_phone,emp_address;
	bool emp_found = false,valid = false;

	while (curr != NULL)
	{
		if (curr->emp_details.emp_id == emp_id)
		{
			system("CLS");
			emp_found = true;
			cout << "Employee ID					   : " << curr->emp_details.emp_id << endl << endl;
			cout << "Old Employee Name				   : " << curr->emp_details.emp_name << endl << endl;
			cout << "Do you want to update Employee Name? (Y/N)         : ";
			cin >> option;
			while (option != "Y" && option != "y" && option != "N" && option != "n")// validating if user input NOT Y , y , N or n
			{
				cout << "Only Accept Alphabet Y (YES) or N (NO) " << endl;
				cout << "Do you want to update Employee Name? (Y/N)         : ";
				cin.clear();
				cin >> option;
			}
			while (option == "Y" || option == "y")
			{
				cin.get();
				cout << "\nPlease Insert New Employee Name                    : ";
				getline(cin, emp_name, '\n');
				for (auto& i : emp_name) //Validating is it a valid Employee Name
				{
					if (isdigit(i)) //If Employee Name contain number
					{
						valid = false;
						break;
					}
					else {
						valid = true;
					}
				}
				while (valid == false) {
					cout << "Invalid name. Please try again!" << endl;
					cout << "\nPlease Insert New Employee Name                    : ";
					getline(cin, emp_name);
					for (auto& i : emp_name)
					{
						if (isdigit(i))
						{
							valid = false;
							break;
						}
						else {
							valid = true;
						}
					}
				}
				while (validation != NULL) //Check Employee Name is exist or not
				{
					if (validation->emp_details.emp_name == emp_name)
					{
						cout << "\nEmployee Name is exist" << endl;
						validation = EMP_head;
						cout << "\nPlease Insert New Employee Name                    : ";
						getline(cin, emp_name, '\n');
						for (auto& i : emp_name)
						{
							if (isdigit(i))
							{
								valid = false;
								break;
							}
							else {
								valid = true;
							}
						}
						while (valid == false) {
							cout << "Invalid name. Please try again!" << endl;
							cout << "\nPlease Insert New Employee Name                    : ";
							getline(cin, emp_name);
							for (auto& i : emp_name)
							{
								if (isdigit(i))
								{
									valid = false;
									break;
								}
								else {
									valid = true;
								}
							}
						}
					}
					else
					{
						validation = validation->next;
					}
				}
				curr->emp_details.emp_name = emp_name;
				break;
			}
			cout << "\nOld Employee Phone				   : " << curr->emp_details.emp_phone << endl;
			cout << "\nDo you want to update Employee Phone? (Y/N)        : ";
			cin >> option;
			while (option != "Y" && option != "y" && option != "N" && option != "n")// validating if user input NOT Y , y , N or n
			{
				cout << "Only Accept Alphabet Y (YES) or N (NO) " << endl;
				cout << "\nDo you want to update Employee Phone? (Y/N)        : ";
				cin.clear();
				cin >> option;
			}
			while (option == "Y" || option == "y")
			{
				cin.get();
				cout << "\nPlease Insert New Employee Phone                   : ";
				getline(cin, emp_phone, '\n');
				while (emp_phone == "")
				{
					cout << "\nPlease Insert New Employee Phone                   : ";
					getline(cin, emp_phone, '\n');
				}
				validation = EMP_head;
				while (validation != NULL)
				{
					if (validation->emp_details.emp_phone == emp_phone)
					{
						cout << "\nEmployee Phone is exist" << endl;
						validation = EMP_head;
						cout << "\nPlease Insert New Employee Phone                   : ";
						getline(cin, emp_phone, '\n');
					}
					else
					{
						validation = validation->next;
					}
				}
				curr->emp_details.emp_phone = emp_phone;
				break;
			}
			cout << "\nOld Employee Address			           : " << curr->emp_details.emp_address << endl;
			cout << "\nDo you want to update Employee Address? (Y/N)      : ";
			cin >> option;
			while (option != "Y" && option != "y" && option != "N" && option != "n")// validating if user input NOT Y , y , N or n
			{
				cout << "Only Accept Alphabet Y (YES) or N (NO) " << endl;
				cout << "\nDo you want to update Employee Address? (Y/N)      : ";
				cin.clear();
				cin >> option;
			}
			while (option == "Y" || option == "y")
			{
				cin.get();
				cout << "\nPlease Insert New Employee Address                 : ";
				getline(cin, emp_address, '\n');
				while (emp_address == "")
				{
					cout << "\nPlease Insert New Employee Address                 : ";
					getline(cin, emp_address, '\n');
				}
				validation = EMP_head;
				while (validation != NULL) //Validation for Employee Address is Exist or not
				{
					if (validation->emp_details.emp_address == emp_address)
					{
						cout << "\nEmployee Address is exist" << endl;
						validation = EMP_head;
						cout << "\nPlease Insert New Employee Address                 : ";
						getline(cin, emp_address, '\n');
					}
					else
					{
						validation = validation->next;
					}
				}
				curr->emp_details.emp_address = emp_address;
				break;
			}
			cout << "\nEmployee Salary				           : " << curr->emp_details.emp_salary << endl;
			cout << "\nEmployee Overall Performance	                   : " << curr->emp_details.emp_overall_performance << endl;
			cout << "\nEdit Successfully" << endl << endl;

			system("Pause");
			system("CLS");
		}
		curr = curr->next;
	}

	if (emp_found == false)
	{
		cout << "\nNo Employee Found!" << endl << endl;
		system("Pause");
		system("CLS");
	}
}

/*Generate Vacancy List*/
void vacancyList()
{
	Employee* emp_curr = EMP_head;
	Employee* hr_curr = EMP_head;
	int total_number_employee = 10;

	while (hr_curr != NULL)
	{
		if (hr_curr->hr_details.role == "HR")
		{
			while (emp_curr != NULL)
			{
				if (hr_curr->hr_details.departmentName == emp_curr->emp_details.emp_depart_name)
				{
					total_number_employee = total_number_employee - 1;
				}
				emp_curr = emp_curr->next;
			}

			cout << hr_curr->hr_details.departmentName << " : " << total_number_employee << endl;
			total_number_employee = 10;
			emp_curr = EMP_head;
			hr_curr = hr_curr->next;
		}
		else
		{
			hr_curr = hr_curr->next;
		}
	}
	cout << endl;
	system("pause"); system("CLS");
}

/*Bubble Sort*/

int bubbleSort_EMP_ID(struct Employee** head, int count)
{
	struct Employee** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {
		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++) {
			struct Employee* p1 = *h;
			struct Employee* p2 = p1->next;

			if (p1->emp_details.emp_id > p2->emp_details.emp_id) {

				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
	Employee* emp_head = EMP_head;
	Employee* emp_tail = EMP_tail;
	int convert_option;
	string option;
	bool valid = false;
	cout << "1. Sort by Employee\'s ID in Ascending Order" << endl;
	cout << "2. Sort by Employee\'s ID in Descending Order" << endl;
	cout << "Please Choose Your Option: ";
	cin >> option;
	cin.clear(); cin.ignore(10000, '\n');
	start_1:
	for (auto& i : option) //Validation each character
	{
		if (!isdigit(i)) //If got 1 Character is NOT Integer
		{
			valid = false; //It is not a Valid Input
			break;
		}
		else {
			valid = true; //It is a Valid Employee Input
		}
	}
	while (valid == false) {
		cout << "Invalid input. Only INTEGER" << endl;
		cout << "\nPlease Choose Your Option: ";
		cin >> option;
		cin.clear(); cin.ignore(10000, '\n');
		for (auto& i : option) //Validation Again
		{
			if (!isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}
	convert_option = stoi(option);
	while (convert_option < 1 || convert_option >2)
	{
		cout << "\nPlease Enter the Range Between 1 - 2: ";
		cin >> option;
		cin.clear(); cin.ignore(10000, '\n');
		goto start_1;
	}

	if (option == "1")
	{
		system("CLS");
		cout << "Sort by Employee\'s ID in Ascending Order" << endl;
		printList(emp_head);
	}
	else
	{
		system("CLS");
		cout << "Sort by Employee\'s ID in Descending Order" << endl;
		printList_Tail(emp_tail);
	}

	return 0;
}

int bubbleSort_EMP_SALARY(struct Employee** head, int count)
{
	struct Employee** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {
		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++) {
			struct Employee* p1 = *h;
			struct Employee* p2 = p1->next;

			if (p1->emp_details.emp_salary > p2->emp_details.emp_salary) {

				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
	Employee* emp_head = EMP_head;
	Employee* emp_tail = EMP_tail;
	int convert_option;
	string option;
	bool valid = false;
	cout << "1. Sort by Employee\'s Salary in Ascending Order" << endl;
	cout << "2. Sort by Employee\'s Salary in Descending Order" << endl;
	cout << "Please Choose Your Option: ";
	cin >> option;
	cin.clear(); cin.ignore(10000, '\n');
	start_1:
	for (auto& i : option) //Validation each character
	{
		if (!isdigit(i)) //If got 1 Character is NOT Integer
		{
			valid = false; //It is not a Valid Input
			break;
		}
		else {
			valid = true; //It is a Valid Employee Input
		}
	}
	while (valid == false) {
		cout << "Invalid input. Only INTEGER" << endl;
		cout << "\nPlease Choose Your Option: ";
		cin >> option;
		cin.clear(); cin.ignore(10000, '\n');
		for (auto& i : option) //Validation Again
		{
			if (!isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}
	convert_option = stoi(option);
	while (convert_option < 1 || convert_option >2)
	{
		cout << "\nPlease Enter the Range Between 1 - 2: ";
		cin.clear();
		cin >> option;
		cin.clear(); cin.ignore(10000, '\n');
		goto start_1;
	}

	if (option == "1")
	{
		system("CLS");
		cout << "Sort by Employee\'s Salary in Ascending Order" << endl;
		printList(emp_head);
	}
	else
	{
		system("CLS");
		cout << "Sort by Employee\'s Salary in Descending Order" << endl;
		printList_Tail(emp_tail);
	}
	return 0;
}

int bubbleSort_OVERALL_PERFORMANCE(struct Employee** head, int count)
{
	struct Employee** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {
		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++) {
			struct Employee* p1 = *h;
			struct Employee* p2 = p1->next;

			if (p1->emp_details.emp_overall_performance > p2->emp_details.emp_overall_performance) {

				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
	Employee* emp_head = EMP_head;
	Employee* emp_tail = EMP_tail;
	int convert_option;
	string option;
	bool valid = false;
	cout << "1. Sort by Employee\'s Overall Performance in Ascending Order" << endl;
	cout << "2. Sort by Employee\'s Overall Performance in Descending Order" << endl;
	cout << "Please Choose Your Option: ";
	cin >> option;
	cin.clear(); cin.ignore(10000, '\n');
	start_1:
	for (auto& i : option) //Validation each character
	{
		if (!isdigit(i)) //If got 1 Character is NOT Integer
		{
			valid = false; //It is not a Valid Input
			break;
		}
		else {
			valid = true; //It is a Valid Employee Input
		}
	}
	while (valid == false) {
		cout << "Invalid input. Only INTEGER" << endl;
		cout << "\nPlease Choose Your Option: ";
		cin >> option;
		cin.clear(); cin.ignore(10000, '\n');
		for (auto& i : option) //Validation Again
		{
			if (!isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}
	convert_option = stoi(option);
	while (convert_option < 1 || convert_option >2)
	{
		cout << "\nPlease Enter the Range Between 1 - 2: ";
		cin.clear();
		cin >> option;
		cin.clear(); cin.ignore();
		goto start_1;
	}

	if (option == "1")
	{
		system("CLS");
		cout << "Sort by Employee\'s Overall Performance in Ascending Order" << endl;
		printList(emp_head);
	}
	else
	{
		system("CLS");
		cout << "Sort by Employee\'s Overall Performance in Descending Order" << endl;
		printList_Tail(emp_tail);
	}
	return 0;
}

void HR_MainPage()
{
	string category;
	int convert_category = 0;
	bool valid = false;

	cout << "Staff: " << HR_current->hr_details.name << " ( " << HR_current->hr_details.hr_id << " )" << endl;
	cout << "1. Add an Employee Record";
	cout << "\n2. Display All Records";
	cout << "\n3. Search by Employee ID";
	cout << "\n4. Search by Employee overall performance";
	cout << "\n5. Sort and display by Employee ID";
	cout << "\n6. Sort and display by Employee Salary";
	cout << "\n7. Sort and display by Employee Overall Performance";
	cout << "\n8. Modify an Employee Record";
	cout << "\n9. Delete an Employee Record";
	cout << "\n10. Calculate Salary Package Of An Employee";
	cout << "\n11. Generate Vacancy Report";
	cout << "\n12. Log Out" << endl << endl;

	cout << "Your option is: ";
	cin >> category;
	cin.clear(); cin.ignore(100000, '\n');
	start_1:
	for (auto& i : category) //Validation each character in Employee Name
	{
		if (!isdigit(i)) //If got 1 Character is NOT Integer in Employee Name
		{
			valid = false; //It is not a Valid Employee Name
			break;
		}
		else {
			valid = true; //It is a Valid Employee Name
		}
	}
	while (valid == false) {
		cout << "Invalid input. Only INTEGER" << endl;
		cout << "Your option is: ";
		cin >> category;
		cin.clear(); cin.ignore(100000, '\n');
		for (auto& i : category) //Validation Again
		{
			if (!isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}
	convert_category = stoi(category);
	while (convert_category < 0 || convert_category >12)
	{
		cout << "\nPlease Choose AN Option between 1 to 12: ";
		cin >> category;
		cin.clear(); cin.ignore(100000, '\n');
		goto start_1;
	}

	Employee* a = EMP_head;
	Employee* b = EMP_head;
	int countt = 0,convert_emp_id;
	string emp_id;

	while (b != NULL)
	{
		countt++;
		b = b->next;
	}
	while (category != "12")
	{
		if (category == "1")
		{
			system("CLS");
			addEmployee();
		}
		else if (category == "2")
		{
			system("CLS");
			displayEmployee();
		}
		else if (category == "3")
		{
			system("CLS");
			searchByEmployeeID();
		}
		else if (category == "4")
		{
			system("CLS");
			searchByOverallPerformance();
		}
		else if (category == "5")
		{
			system("CLS");
			a = EMP_head;
			bubbleSort_EMP_ID(&a, countt);
			system("pause"); system("CLS");
		}
		else if (category == "6")
		{
			system("CLS");
			a = EMP_head;
			bubbleSort_EMP_SALARY(&a, countt);
			system("pause"); system("CLS");
		}
		else if (category == "7")
		{
			system("CLS");
			a = EMP_head;
			bubbleSort_OVERALL_PERFORMANCE(&a, countt);
			system("pause"); system("CLS");
		}
		else if (category == "8")
		{
			cout << "Enter the Employee ID to edit: ";
			cin >> emp_id;
			cin.clear(); cin.ignore(10000, '\n');
			for (auto& i : emp_id) //Validation each character
			{
				if (!isdigit(i)) //If got 1 Character is NOT Integer
				{
					valid = false; //It is not a Valid Input
					break;
				}
				else {
					valid = true; //It is a Valid Employee Input
				}
			}
			while (valid == false) {
				cout << "Invalid input. Only INTEGER" << endl;
				cout << "\nEnter the Employee ID to edit: ";
				cin >> emp_id;
				cin.clear(); cin.ignore(10000, '\n');
				for (auto& i : emp_id) //Validation Again
				{
					if (!isdigit(i))
					{
						valid = false;
						break;
					}
					else {
						valid = true;
					}
				}
			}
			convert_emp_id = stoi(emp_id);
			updateEmp(convert_emp_id);
		}
		else if (category == "9")
		{
			cout << "Please enter Employee ID to delete: ";
			cin >> emp_id;
			cin.clear(); cin.ignore(10000, '\n');
			for (auto& i : emp_id) //Validation each character
			{
				if (!isdigit(i)) //If got 1 Character is NOT Integer
				{
					valid = false; //It is not a Valid Input
					break;
				}
				else {
					valid = true; //It is a Valid Employee Input
				}
			}
			while (valid == false) {
				cout << "Invalid input. Only INTEGER" << endl;
				cout << "\nPlease enter Employee ID to delete: ";
				cin >> emp_id;
				cin.clear(); cin.ignore(10000, '\n');
				for (auto& i : emp_id) //Validation Again
				{
					if (!isdigit(i))
					{
						valid = false;
						break;
					}
					else {
						valid = true;
					}
				}
			}
			convert_emp_id = stoi(emp_id);
			deleteEmp(convert_emp_id);
		}
		else if (category == "10")
		{
			system("CLS");
			salary = 0;
			hi = 1;
			CalcSalary(salary);
		}
		else if (category == "11")
		{
			system("CLS");
			vacancyList();
		}
		else
		{
			cout << "Invalid Input" << endl;
		}

		Employee* b = EMP_head;
		countt = 0;
		while (b != NULL)
		{
			countt++;
			b = b->next;
		}
		cout << "Staff: " << HR_current->hr_details.name << " ( " << HR_current->hr_details.hr_id << " )" << endl;
		cout << "1. Add an Employee Record";
		cout << "\n2. Display All Records";
		cout << "\n3. Search by Employee ID";
		cout << "\n4. Search by Employee overall performance";
		cout << "\n5. Sort and display by Employee ID";
		cout << "\n6. Sort and display by Employee Salary";
		cout << "\n7. Sort and display by Employee Overall Performance";
		cout << "\n8. Modify an Employee Record";
		cout << "\n9. Delete an Employee Record";
		cout << "\n10. Calculate Salary Package Of An Employee";
		cout << "\n11. Generate Vacancy Report";
		cout << "\n12. Log Out" << endl << endl;

		cout << "Your option is: ";
		cin >> category;
		cin.clear(); cin.ignore(100000, '\n');
		start_2:
		for (auto& i : category) //Validation each character in Employee Name
		{
			if (!isdigit(i)) //If got 1 Character is NOT Integer in Employee Name
			{
				valid = false; //It is not a Valid Employee Name
				break;
			}
			else {
				valid = true; //It is a Valid Employee Name
			}
		}
		while (valid == false) {
			cout << "Invalid input. Only INTEGER" << endl;
			cout << "Your option is: ";
			cin >> category;
			cin.clear(); cin.ignore(100000, '\n');
			for (auto& i : category) //Validation Again
			{
				if (!isdigit(i))
				{
					valid = false;
					break;
				}
				else {
					valid = true;
				}
			}
		}
		convert_category = stoi(category);
		while (convert_category < 0 || convert_category >12)
		{
			cout << "\nPlease Choose AN Option between 1 to 12: ";
			cin >> category;
			cin.clear(); cin.ignore(100000, '\n');
			goto start_2;
		}
	}
	salary = 0;
}

/*Log In Function*/
void logIn(string username, string password, int& quit)
{
	int login_status = 0;

	Employee* curr = EMP_head;

	while (curr != NULL)
	{
		if (curr->hr_details.username == username && curr->hr_details.password == password)
		{
			login_status = 1;
			break;
		}
		else
		{
			curr = curr->next;
		}

	}

	if (login_status == 1)
	{
		system("CLS");
		HR_current = curr;
		HR_MainPage();
	}
	else
	{
		string option;
		start:
		bool valid = false;
		cout << "Login Failed";
		cout << "\n1. Retry";
		cout << "\n2. Exit";
		cout << "\nPlease choose your option: ";
		cin >> option;
		cin.clear(); cin.ignore(100000, '\n');
		for (auto& i : option) //Validation each character in Employee Name
		{
			if (!isdigit(i)) //If got 1 Character is NOT Integer in Employee Name
			{
				valid = false; //It is not a Valid Employee Name
				break;
			}
			else {
				valid = true; //It is a Valid Employee Name
			}
		}
		while (valid == false) {
			cout << "Invalid input. Only INTEGER" << endl;
			cout << "\nPlease choose your option: ";
			cin >> option;
			cin.clear(); cin.ignore(100000, '\n');
			for (auto& i : option) //Validation Again
			{
				if (!isdigit(i))
				{
					valid = false;
					break;
				}
				else {
					valid = true;
				}
			}
		}

		while (option != "1" && option != "2")
		{
			cout << "\nPlease Choose AN Option between 1 and 2: ";
			cin >> option;
			cin.clear(); cin.ignore(100000, '\n');
		}

		while (option == "1")
		{
			system("CLS");
			cout << "Enter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> password;
			logIn(username, password, quit);
			break;
		}
		if (option != "1")
		{
			quit = 1;
		}
	}
}

int main()
{
	HRList();
	empList();
	string option;
start_1:
	bool valid = false;
	Employee* head = EMP_head;
	cout << "-------------------------------" << endl;
	cout << "    EMERGE EMPLOYEE SYSTEM     " << endl;
	cout << "-------------------------------";
	cout << "\n1. Log In";
	cout << "\n2. Exit";
	cout << "\n\nPlease Choose AN Option: ";
	cin >> option;
	cin.clear(); cin.ignore(10000, '\n');
	start_2:
	int quit = 0;
	for (auto& i : option) //Validation each character in Employee Name
	{
		if (!isdigit(i)) //If got 1 Character is NOT Integer in Employee Name
		{
			valid = false; //It is not a Valid Employee Name
			break;
		}
		else {
			valid = true; //It is a Valid Employee Name
		}
	}
	while (valid == false) {
		cout << "Invalid input. Only INTEGER" << endl;
		cout << "\nPlease Choose AN Option: ";
		cin >> option;
		cin.clear(); cin.ignore(10000, '\n');
		for (auto& i : option) //Validation Again
		{
			if (!isdigit(i))
			{
				valid = false;
				break;
			}
			else {
				valid = true;
			}
		}
	}

	while (option != "1" && option != "2")
	{
		cout << "\nPlease Choose AN Option between 1 and 2: ";
		cin >> option;
		cin.clear(); cin.ignore(10000, '\n');
		goto start_2;
	}
	if (option == "1")
	{
		system("CLS");
		string username, password;
		cout << "Enter Username: ";
		cin >> username;
		cout << "Enter Password: ";
		cin >> password;
		logIn(username, password, quit);

		if (quit == 1)
		{
			system("pause");
		}
		else
		{
			system("CLS");
			goto start_1;
		}

	}
	else if (option == "2")
	{
		system("pause");
	}
	return 0;
}