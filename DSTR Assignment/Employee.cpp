//#include <iostream>
//#include "Header.h"
//using namespace std;
//
//
//HR* HR_head = NULL; //create a head node for HR
//
//HR* node1 = new HR; //create node for HR 1
//HR* node2 = new HR; //create node for HR 2
//HR* node3 = new HR; //create node for HR 3
//
//void empList()
//{
//	node1->username = "hi";
//	node1->password = "123";
//	node1->name = "James";
//	node1->departmentName = "Finance";
//	node1->next = NULL;
//
//	node2->username = "hii";
//	node2->password = "123";
//	node2->name = "Ali";
//	node2->departmentName = "IT";
//	node2->next = NULL;
//
//	node3->username = "hiii";
//	node3->password = "123";
//	node3->name = "Pang";
//	node3->departmentName = "Marketing";
//	node3->next = NULL;
//
//	HR_head = node1;
//	node1->next = node2;
//	node2->next = node3;
//}
//
//void HR_MainPage()
//{
//	int category;
//	cout << "1.1. Add an Employee Record";
//	cout << "\n1.2. Display All Records";
//	cout << "\n1.3. Search by Employee ID";
//	cout << "\n1.4. Search by Employee overall performance";
//	cout << "\n1.5. Sort and display by Employee ID in ascending order";
//	cout << "\n1.6. Sort and display by Employee Salary in ascending order";
//	cout << "\n1.7. Sort and display by Employee Overall Performance in ascending order";
//	cout << "\n1.8. Modify an Employee Record";
//	cout << "\n1.9. Delete an Employee Record";
//	cout << "\n1.10. Calculate salary package of an employee";
//	cout << "\n1.11. Exit" << endl << endl;
//
//	cout << "Your option is: ";
//	cin >> category;
//
//	while (category != 11)
//	{
//		//switch (category) {
//		//case 1:
//
//		//}
//	}
//}
//
//void newHR(string username, string password, string name, string deptname)
//{
//	HR* node = new HR;
//	node->username = username;
//	node->password = password;
//	node->name = name;
//	node->departmentName = deptname;
//	node->next = NULL;
//
//	if (HR_head == NULL)
//	{
//		HR_head = node;
//	}
//	else
//	{
//		HR* curr = HR_head;
//
//		int a = 1;
//
//		while (curr != NULL)
//		{
//			if (curr->username == username)
//			{
//				cout << "\nUsername is exist" << endl;
//				curr = HR_head;
//				a = 0;//false
//				break;
//
//			}
//			else if (curr->name == name)
//			{
//				cout << "\Name is exist" << endl;
//				curr = HR_head;
//				a = 0;//false
//				break;
//			}
//			else if (curr->departmentName == deptname)
//			{
//				cout << "\Department has been created" << endl;
//				curr = HR_head;
//				a = 0;//false
//				break;
//			}
//			else
//			{
//				curr = curr->next; // Go until to the end of the list
//
//			}
//		}
//
//		if (a == 1)
//		{
//			curr = HR_head;
//			while (curr->next != NULL)
//			{
//				curr = curr->next; // Go until to the end of the list
//			}
//			curr->next = node; //Insert Successful
//			cout << "HR Staff Insert Successfully";
//		}
//		else
//		{
//			int option;
//			cout << "\n1. Retry";
//			cout << "\n2. Exit";
//			cout << "\nPlease choose your option: ";
//			cin >> option;
//
//			while (option != 2)
//			{
//				system("CLS"); //Clear Screen
//				string username, password, name, deptname;
//				cout << "Enter Username: ";
//				cin >> username;
//				cout << "Enter Password: ";
//				cin >> password;
//				cout << "Enter Full Name: ";
//				cin >> name;
//				cout << "Enter Department Name: ";
//				cin >> deptname;
//				newHR(username, password, name, deptname);
//				break;
//			}
//			system("pause");
//		}
//	}
//}
//
//void addHR()
//{
//	string username, password, name, deptname;
//	cout << "Enter Username: ";
//	cin >> username;
//	cout << "Enter Password: ";
//	cin >> password;
//	cout << "Enter Full Name: ";
//	cin >> name;
//	cout << "Enter Department Name: ";
//	cin >> deptname;
//	newHR(username, password, name, deptname);
//}