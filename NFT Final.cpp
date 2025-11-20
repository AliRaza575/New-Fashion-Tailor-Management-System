#include <iostream>
#include <string>
#include<fstream>
#include <windows.h>
using namespace std;
const int d=100;
bool performLogin();
void Header();
int Main_Menu();
//   Declaration of Functions
void Add_Cust_Record();
void Place_Order();
void view_Cust_Record();
void view_order_Record();
void update_record();
void Delete_Cust_Record();
//   Declaration of Variables
string name[d];
int contactNumber[d];
int length[d];
string address[d];
int order[d];
string Item_Name[d];
int quantity[d];
int Price[d];
int id[d];
int custno;
int custcount=0;
int opt;
int b;
fstream data;
fstream odata;
int main() {
	bool login=performLogin();
	if (!login) {
		cout << "Exiting the program due to unsuccessful login." << endl;
		return 1;
		int opt = -1;
	}
	do {
		system("cls");
		Header();
		opt = Main_Menu();
		switch(opt) {
			case 1:
				Add_Cust_Record();
				break;
			case 2:
				Place_Order();
				break;
			case 3:
				view_Cust_Record();
				break;
			case 4:
				view_order_Record();
				break;
			case 5:
				Delete_Cust_Record();
				break;
			case 6:
				update_record();
				break;
		}
		cout << "Press Enter to continue...";
		cin.ignore();
		cin.get();
	} while (opt != 7);
	return 0;
}

// Function to display the header
void Header() {
	cout << "*******************************************************" << endl;
	cout << "***************New Fashion Tailors*********************" << endl;
	cout << "*******************************************************" << endl;
}

// Function to display the main menu and get user choice
int Main_Menu() {
	int choice = -1;
	cout << "-------------------------------------------------------" << endl;
	cout << "----------------------Main Menu------------------------" << endl;
	cout << "1-Add customer                                        #" << endl;
	cout << "2-Place Order                                         #" << endl;
	cout << "3-View customer record                                #" << endl;
	cout << "4-View Order Information                              #" << endl;
	cout << "5-Delete customer record                              #" << endl;
	cout << "6-Update customer record                              #" << endl;
	cout << "7-Exit/terminate program                              #" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Choose an option from the above: ";
	cin >> choice;

	return choice;
}

// Function to add a customer record
void Add_Cust_Record() {
	cout<<"Enter number of customer you want to add=";
	cin>>custno;
	system("CLS");
	// Clears the screen
	Header();
	for(int i=0; i<custno; i++) {
		cout<<"..........................................."<<endl;
		cin.ignore();
		cout << "Enter the name of the customer: ";
		getline(cin, name[i]);
		cout << "Enter the contact number: ";
		cin >> contactNumber[i];
		cout<<"Enter Id:";
		cin>>id[i];
		cout << "Enter the length of the garment (in inches): ";
		cin >> length[i];
		cin.ignore(); // To clear input buffer before getline
		cout << "Enter customer Address: ";
		getline(cin, address[i]);
		cout<<"............................................"<<endl;
	}
	data.open("cust record.txt",ios::app);
	for(int i=0; i<custno; i++) {
		data<<name[i]<<",";
		data<<id[i]<<",";
		data<<contactNumber[i]<<",";
		data<<length[i]<<",";
		data<<address[i]<<"\n";
	}
	data.close();
}
//   Perform Login
bool performLogin() {
	string username, password;
	const string correctUsername = "ali";
	const string correctPassword = "123";

	cout << "Welcome to the Login Screen!" << endl;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	if (username == correctUsername && password == correctPassword) {
		cout << "Login successful. Welcome, " << username << "!" << endl;
		Sleep(1000);
		return true;
	} else {
		cout << "Login failed. Incorrect username or password." << endl;
		Sleep(1000);
		return false;
	}
}
//  PLace Order
void Place_Order() {
	cout<<"Enter number of Orders you want to Place=";
	cin>>b;
	system("cls");
	Header();
	for(int j=0; j<b; j++) {
		cout<<"..................................."<<endl;
		cout<<"     Enter order Information       "<<endl;
		cout<<"..................................."<<endl;
		cout<<"Enter order id=";
		cin>>order[j];
		cout<<"Enter Item Name=";
		cin>>Item_Name[j];
		cout<<"Enter Quantitiy of Order=";
		cin>>quantity[j];
		cout<<"Enter Price of Order in Rs=";
		cin>>Price[j];
		cout<<"............................................"<<endl;
	}
	odata.open("order record.txt",ios::app);
	for(int i=0; i<b; i++) {
		odata<<order[i]<<",";
		odata<<Item_Name[i]<<",";
		odata<<quantity[i]<<",";
		odata<<Price[i]<<"\n";
	}
	odata.close();
	Sleep(200);
}
//   Update Customer Record
void update_record() {
	int update;
	cout << "Enter id of customer you want to update: ";
	cin >> update;

	// Read existing records from the file
	data.open("cust record.txt", ios::in);
	if (!data.is_open()) {
		cout << "Error opening the file for reading." << endl;
		return;
	}

	// Use local arrays for each customer
	string tempName[d];
	int tempId[d];
	int tempContactNumber[d];
	int tempLength[d];
	string tempAddress[d];

	for (int i = 0; i < custno; i++) {
		data >> tempName[i];
		data >> tempId[i];
		data >> tempContactNumber[i];
		data >> tempLength[i];
		data >> tempAddress[i];
	}

	data.close();

	// Update the record in memory
	for (int i = 0; i < custno; i++) {
		if (id[i] == update) {
			cout << "Enter updated name of the customer: ";
			cin.ignore();  // Ignore the newline character left in the buffer
			getline(cin, tempName[i]);
			name[i]=tempName[i];
			cout << "Enter updated contact number: ";
			cin >> tempContactNumber[i];
			contactNumber[i]=tempContactNumber[i];
			cout << "Enter updated length of the garment (in inches): ";
			cin >> tempLength[i];
			length[i]=tempLength[i];
			cin.ignore();
			cout << "Enter updated customer Address: ";
			getline(cin, tempAddress[i]);

			address[i]=tempAddress[i];
			cout << "Record Updated Successfully" << endl;
		}
	}

	// Write the updated records back to the file
	data.open("cust record.txt", ios::out);
	if (!data.is_open()) {
		cout << "Error opening the file for writing." << endl;
		return;
	}

	for (int i = 0; i < custno; i++) {
		data << tempName[i] << ",";
		data << tempId[i] << ",";
		data << tempContactNumber[i] << ",";
		data << tempLength[i] << ",";
		data << tempAddress[i] << "\n";
	}

	data.close();
}
//    Delete Customer Record
void Delete_Cust_Record() {
	int Delete;
	cout << "Enter Id of the Customer to delete: ";
	cin >> Delete;

	for (int i = 0; i < custno; ++i) {
		if (Delete == id[i]) {
			for (int j = i; j < custno - 1; ++j) {
				name[j] = name[j + 1];
				contactNumber[j] = contactNumber[j + 1];
				length[j] = length[j + 1];
				address[j] = address[j + 1];
				id[j] = id[j + 1];
			}

			// Clear the last record
			name[custno - 1].clear();
			contactNumber[custno - 1] = 0;
			length[custno - 1] = 0;
			address[custno - 1].clear();
			id[custno - 1] = 0;

			cout << "Record Deleted Successfully" << endl;
			custno--;
			break; // Exit the loop after deleting the record
		}
	}

	// Rewrite the entire updated array to the file
	data.open("cust record.txt", ios::out);
	if (data.is_open()) {
		for (int i = 0; i < custno; i++) {
			data << name[i] << ",";
			data << id[i] << ",";
			data << contactNumber[i] << ",";
			data << length[i] << ",";
			data << address[i] << "\n";
		}
		data.close();
	} else {
		cout << "Error opening the file for writing." << endl;
	}
}
//   View Customer Record
void view_Cust_Record() {
	cout<<"Following Customers exist in record"<<endl;
	cout<<"Name"<<"\t"<<"id"<<"\t"<<"Contact Number"<<"\t"<<"Legnth of Garment"<<"\t"<<"Address"<<endl;
	for(int i=0; i<custno; i++) {
		cout<<name[i]<<"\t"<<id[i]<<"\t"<<contactNumber[i]<<"\t\t"<<length[i]<<"\t\t\t"<<address[i]<<"\t"<<endl;
	}
}
//   View Order Record
void view_order_Record() {
	cout<<"Following Order exist in record"<<endl;
	cout<<"Order Id"<<"\t"<<"Item Name"<<"\t"<<"Quantity"<<"\t"<<"Price"<<endl;
	for(int i=0; i<b; i++) {
		cout<<order[i]<<"\t\t"<<Item_Name[i]<<"\t\t"<<quantity[i]<<"\t\t"<<Price[i]<<"\t"<<endl;
	}
}
