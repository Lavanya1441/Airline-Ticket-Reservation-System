#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

int glob = 0;
int global = 10;
void registr();
int login();

class d_booking //class for domestic booking
{
	protected:
		int pnr;
	char f_d[10], toja[7], tojd[7]; //protected members
	long int doj;
	int choice, src, dest;

	public: //public member functions
		char arr[7][5];
	void d_pnr() {
		glob++;
		pnr = glob;
	}

	int j_detail() // function declaration and definition for domestic journey
	{
		cout << "\nEnter DateOfJourney(DDMMYY)." << "Please enter a valid date." << endl;
		cin >> doj;
		cout << "\1.Delhi(1) \t\2.Chennai(2) \t\3.Mumbai(3) \t\4.Kolkata(4)" << endl << endl;
		cout << "Enter Source" << endl;
		cin >> src;
		cout << "Enter destination" << endl;
		cin >> dest;
		if ((src == 1 && dest == 2) || (src == 2 && dest == 1)) {
			cout << "\t \t \tFlights Found" << endl << endl;
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Indigo(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t17:05\t\tRs.5500\t\tRefundable\n";
			cout << "\3.Air Asia(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
		} else if ((src == 1 && dest == 3) || (src == 3 && dest == 1)) {
			cout << "\t \t \tFlights Found" << endl << endl;
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Indigo(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t17:05\t\tRs.5500\t\tRefundable\n";
			cout << "\3.Air Asia(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
		} else if ((src == 1 && dest == 4) || (src == 4 && dest == 1)) {
			cout << "\t \t \tFlights Found" << endl << endl;
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Indigo(1)\t08:00\t\t11:05\t\tRs.4000\t\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t17:05\t\tRs.4250\t\tRefundable\n";
			cout << "\3.Air Asia(3)\t19:00\t\t22:05\t\tRs.6100\t\tRefundable\n";
		} else if ((src == 2 && dest == 3) || (src == 3 && dest == 2)) {
			cout << "\t \t \tFlights Found" << endl << endl;
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Indigo(1)\t08:00\t\t11:05\t\tRs.5400\t\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t17:05\t\tRs.2500\t\tRefundable\n";
			cout << "\3.Air Asia(3)\t19:00\t\t22:05\t\tRs.2890\t\tRefundable\n";
		} else if ((src == 2 && dest == 4) || (src == 4 && dest == 2)) {
			cout << "\t \t \tFlights Found" << endl << endl;
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Indigo(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t17:05\t\tRs.4500\t\tRefundable\n";
			cout << "\3.Air Asia(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
		} else if ((src == 3 && dest == 4) || (src == 4 && dest == 3)) {
			cout << "\t \t \tFlights Found" << endl << endl;
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Indigo(1)\t08:00\t\t11:05\t\tRs.5800\t\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t17:05\t\tRs.5508\t\tRefundable\n";
			cout << "\3.Air Asia(3)\t19:00\t\t22:05\t\tRs.6050\t\tRefundable\n";
		} else if (src == dest) {
			cout << "\nSource and destination can't be same.\nTry again\n\n\n" << endl;
			return j_detail();
		} else {
			cout << "\nWrong input entered\nTry again\n\n\n" << endl;
			return j_detail();
		}
	}

	int allOccupied(char arr[7][5]) {
		int count = 0;
		for (int i = 0; i < 7; i++) {
			for (int j = 1; j < 5; j++)
				if (arr[i][j] == 'X')
					count++;
		}
		if (count == 28)
			return 1;
		return 0;
	}

	//to display the seats
	void display(char arr[7][5]) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 5; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}

	//take user data
	string getData() {
		string p;
		cout << "\nEnter a valid seat number to check(like 1B) or N to end: ";
		cin >> p;
		return p;
	}


	//update seat status
	void update(char arr[7][5], int row, int col) {
		cout << "\nCongrats, your seat is valid and is reserved for you.\n";
		cout << "\nUpdated seat status..........\n";
		arr[row][col] = 'X';
	}

	//checking whether user request for his seat number can be processed or not
	int check(char arr[7][5], string s) {
		//if user input is not in the range 1A to 7D
		if (s[0] > '7' || s[0] < '1' || s[1] > 'D' || s[1] < 'A') {
			cout << "\nInvalid seat number\n"; //invalid seat number
			return 0;
		}
		int row = -1, col = -1;

		//find the row number of the user seat
		for (int i = 0; i < 7; i++) {
			if (arr[i][0] == s[0])
				row = i;
		}

		//find the column number of user seat
		for (int j = 0; j < 5; j++) {
			if (arr[row][j] == s[1])
				col = j;
		}

		//check whether seat is already occupied or not.
		if (col == -1) {
			cout << "\nSeat is already occupied\n";
			return 0;
		} else {
			//if it's a valid seat & not occupied, process the requested & update the seat as occupied
			update(arr, row, col);
		}
		return 1;
	}

	void airline(char arr[7][5]) {
		// user can stop process by pressing 'N'
		cout << "Enter N if you are done!\n";
		string s;
		// continue if not interrepted by user or there is valid seat in unoccupied state
		while (true) {
			s = getData(); //get user input
			//if user input is to stop the process
			if (s[0] == 'N')
				break;
			//process the request & check accordingly
			if (check(arr, s))
				display(arr);
			if (allOccupied(arr)) {
				//if all seats are occupied
				cout << "\nSorry, no more seats left!..." << endl;
				break;
			}
		}
		cout << "\nThanks, that's all" << endl; //end of the program
	}

	int select_seat() {
		//2-D array for storing seat number
		for (int i = 0; i < 7; i++) {
			//first column is row number
			arr[i][0] = i + 1 + '0';
			for (int j = 1; j < 5; j++) {
				//to represent seat number A,B,C,D respectively
				arr[i][j] = 'A' + j - 1;
			}
		}
		cout << "\n\nInitial seat arrangements........\n";
		display(arr);
		airline(arr); //airline function
		return 0;
	}

	int select_flight() //function declaration and definition for selecting flight
	{
		cout << "\nEnter your choice";
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "\nFlight selected:" << endl;
				cout << "Indigo" << endl;
				strcpy(f_d, "Indigo"); //copy to string
				cout << "Departure Time : 08:00" << endl;
				cout << "Arrival Time: 11:05" << endl;
				strcpy(tojd, "8:00"); //copy to string
				strcpy(toja, "11:05"); // copy to string
				break;
			case 2:
				cout << "\nFlight selected:" << endl;
				cout << "Deccan Air" << endl;
				strcpy(f_d, "Deccan Air"); //copy to string
				cout << "Departure Time : 14:00" << endl;
				cout << "Arrival Time: 17:05" << endl;
				strcpy(tojd, "14:00"); //copy to string
				strcpy(toja, "17:05"); //copy to string
				break;
			case 3:
				cout << "\nFlight selected:" << endl;
				cout << "Air Asia" << endl;
				strcpy(f_d, "Air Asia"); //copy to string
				cout << "Departure Time : 19:00" << endl;
				cout << "Arrival Time: 22:05" << endl;
				strcpy(tojd, "19:00"); //copy to string
				strcpy(toja, "22:05"); //copy to string
				break;
			default:
				cout << "Invalid input entered.\nTry again" << endl;
				return select_flight();
		}
	}
};

class i_booking //class for international booking
{
	protected:
		int pnri;
	char f_i[10], tojai[7], tojdi[7];
	long int doji;
	int srci, desti, choicei;
	public:
		char arri[7][5];
	void i_pnr() {
		global++;
		pnri = global;
	}
	int j_detaili() // function declaration and definition for journey details
	{
		cout << "Enter DateOfJourney(DDMMYY)." << "Please enter a valid date." << endl;;
		cin >> doji;
		cout << "\1.London(1) \2.Dubai(2) \3.Abu Dhabi(3) \4.Singapore(4) \5.NewYork(5) " << endl <<
			endl;
		cout << "Enter Source";
		cin >> srci;
		cout << "Enter destination";
		cin >> desti;
		cout << "\t \t \tFlights Found" << endl << endl;
		if ((srci == 1 && desti == 3) || (srci == 3 && desti == 1)) {
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.25000\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t18:05\t\tRs.21500\tRefundable\n";
			cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.24000\tRefundable\n";
		} else if ((srci == 1 && desti == 4) || (srci == 4 && desti == 1))
			86 {
				cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
				cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.25500\tRefundable\n";
				cout << "\2.Deccan Air(2)\t14:00\t\t18:05\t\tRs.21300\tRefundable\n";
				cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.24650\t\tRefundable\n";
			}
		else if ((srci == 1 && desti == 5) || (srci == 5 || desti == 1)) {
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.52500\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t18:05\t\tRs.59420\tRefundable\n";
			cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.64892\tRefundable\n";
		} else if ((srci == 2 && desti == 3) || (srci == 3 && desti == 2)) {
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.17800\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t18:05\t\tRs.14900\tRefundable\n";
			cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.18700\tRefundable\n";
		} else if ((srci == 2 && desti == 4) || (srci == 4 && desti == 2)) {
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.32000\tRefundable\n";
			cout << "\2.Deccan Air(2)\t14:00\t\t18:05\t\tRs.38500\tRefundable\n";
			cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs41259\tRefundable\n";
		} else if (srci == 2 && desti == 5 || (srci == 5 && desti == 2)) {
			cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
			cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.82500\tRefundable\n";
			87
			cout << "\2.Deccan Air(2)\t14:00\t\t18:05\t\tRs.87550\tRefundable\n";
			cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs81478\tRefundable\n";
		} else if (srci == desti) {
			cout << "Invalid input entered.\nTry again\n\n\n" << endl;
			return j_detaili();
		} else {
			cout << "Invalid input entered.\nTry again\n\n\n";
			return j_detaili();
		}
	}
	int allOccupiedi(char arri[7][5]) {
		int count = 0;
		for (int i = 0; i < 7; i++) {
			for (int j = 1; j < 5; j++)
				if (arri[i][j] == 'X')
					count++;
		}
		if (count == 28)
			return 1;
		return 0;
	}
	void displayi(char arr[7][5]) {
		for (int i = 0; i < 7; i++) {
			88
			for (int j = 0; j < 5; j++) {
				cout << arri[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	//take user data
	string getDatai() {
		string p;
		cout << "\nEnter valid seat number to check(like 1B) or N to end: ";
		cin >> p;
		return p;
	}
	//update seat status
	void updatei(char arr[7][5], int row, int col) {
		cout << "\nCongrats, your seat is available and is reserved for you\n";
		cout << "\nUpdated seat status...\n";
		arri[row][col] = 'X';
	}
	//checking whether user request for his seat number can be processed or not
	int checki(char arr[7][5], string s) {
		//if user input is not in the range 1A to 7D
		if (s[0] > '7' || s[0] < '1' || s[1] > 'D' || s[1] < 'A') {
			cout << "\nInvalid seat number\n"; //invalid seat number
			return 0;
			89
		}
		int row = -1, col = -1;
		//find the row number of the user seat
		for (int i = 0; i < 7; i++) {
			if (arri[i][0] == s[0])
				row = i;
		}
		//find the column number of user seat
		for (int j = 0; j < 5; j++) {
			if (arri[row][j] == s[1])
				col = j;
		}
		//check whether seat is already occupied or not.
		if (col == -1) {
			cout << "\nSeat is already occupied.\n";
			return 0;
		} else {
			//if it's a valid seat & not occupied, process the requested & update the seat as occupied
			updatei(arri, row, col);
		}
		return 1;
	}
	void airlinei(char arr[7][5]) {
		// user can stop process by pressing 'N'
		cout << "Enter N if you are done!\n";
		string s;
		90
		// continue if not interrepted by user or there is valid seat in unoccupied state
		while (true) {
			s = getDatai(); //get user input
			//if user input is to stop the process
			if (s[0] == 'N')
				break;
			//process the request & check accordingly
			if (checki(arr, s))
				displayi(arri);
			if (allOccupiedi(arri)) { //if all seats are occupied
				cout << "\nSorry, no more seats left!" << endl;
				break;
			}
		}
		cout << "\nThanks, that's all" << endl; //end of program
	}
	int select_seati() {
		//2-D array for storing seat number
		for (int i = 0; i < 7; i++) {
			//forst column is row number
			arri[i][0] = i + 1 + '0';
			for (int j = 1; j < 5; j++) {
				//to represent seat number A,B,C,D respectively
				arri[i][j] = 'A' + j - 1;
			}
		}
		cout << "\n\nAvailable seats...\n";
		91
		displayi(arri);
		airlinei(arri); //airline function
		return 0;
	}
	int select_flighti() //function declaration and definition for selecting flight
	{
		cout << "\nEnter your choice" << endl;
		cin >> choicei;
		switch (choicei) {
			case 1:
				cout << "\nFlight selected:" << endl;
				cout << "Vistara" << endl;
				strcpy(f_i, "Vistara"); //copy to string
				cout << "Departure Time: 10:00" << endl;
				cout << "Arrival Time: 14:05" << endl;
				strcpy(tojdi, "10:00"); //copy to string
				strcpy(tojai, "14:05"); //copy to string
				break;
			case 2:
				cout << "\nFlight selected:" << endl;
				cout << "Deccan Air" << endl;
				strcpy(f_i, "Deccan Air"); //copy to string
				cout << "Departure Time: 14:00" << endl;
				cout << "Arrival Time: 18:05" << endl;
				strcpy(tojdi, "14:00"); //copy to string
				strcpy(tojai, "18:05"); //copy to string
				break;
			case 3:
				cout << "\nFlight selected:" << endl;
				cout << "Emirates" << endl;
				92
				strcpy(f_i, "Emirates"); //copy to string
				cout << "Departure Time : 18:00" << endl;
				cout << "Arrival Time: 22:05" << endl;
				strcpy(tojdi, "18:00"); //copy to string
				strcpy(tojai, "22:05"); //copy to string
				break;
			default:
				cout << "Invalid input entered" << endl;
				return select_flighti();
		}
	}
};
class passenger: public d_booking, public i_booking //class passenger publicly inherited from
class d_booking and i_booking {
	protected: char f_name[20],
	l_name[20],
	email[50];
	int age,
	gender;
	long int c_no;
	public: int cated,
	catei;
	void p_detail(int x) //function declaration and definition
	{
		if (x == 1) //if else for domestic and international booking selection
		{
			j_detail(); //function call
			select_flight();
			cout << "\n\t1)ECONOMIC CLASS\t\t2)BUSINESS CLASS\t\t3)FIRST CLASS\n\tWhich class
			do you prefer ? ";
			cin >> cated;
			//function call
			93
			select_seat();
		} else {
			j_detaili(); //function call1353
			select_flighti();
			cout << "\n\t1)ECONOMIC CLASS\t\t2)BUSINESS CLASS\t\t3)FIRST CLASS\n\tWhich class
			do you prefer ? ";
			cin >> catei;
			select_seati(); //function call
		}
		cout << "\nEnter passenger details";
		cout << "\nFirst Name:";
		cin >> f_name;
		cout << "Last Name:";
		cin >> l_name;
	}
	int gender_check() //to check gender input as valid
	{
		cout << "Gender:\nMale-press:1::\nFemale-press:2::";
		cin >> gender;
		if (gender != 2 && gender != 1) {
			cout << "\n\nInvalid input entered.\nTry again\n\n" << endl;
			return gender_check(); //function call
		}
	}
	void more_details() //to take more details of the passenger
	{
		cout << "Age:";
		cin >> age;
		94
		cout << "Email Id:";
		cin >> email;
		cout << "Contact number:";
		cin >> c_no;
		cout << "\n\nDetails Entered:\n";
		cout << "Name:" << f_name << " " << l_name << endl;
		//displaying details
		cout << "Age:" << age << endl;
		cout << "Email id:" << email << endl;
		cout << "Contact Number:" << c_no << endl;
	}
	int getpnr() //function to get pnr for domestic booking
	{
		return pnr;
	}
	int getpnri() //function to get pnr for international booking
	{
		return pnri;
	}
	void disp() //function to display details for domestic booking
	{
		cout << "PNR:" << pnr << endl;
		cout << "Flight:" << f_d << endl;
		cout << "Name:" << f_name << " " << l_name << endl;
		cout << "DOJ:" << doj << endl;
		cout << "Departure Time:" << tojd << endl;
		cout << "Arrival Time:" << toja;
	}
	void dispi() //function to display details for international booking
	{
		cout << "PNR:" << pnri << endl;
		95
		cout << "Flight:" << f_i << endl;
		cout << "Name:" << f_name << " " << l_name << endl;
		cout << "DOJ:" << doji << endl;
		cout << "Departure Time:" << tojdi << endl;
		cout << "Arrival Time:" << tojai;
	}
	void feedback() //function to get passenger feedback
	{
		char c;
		cout << "\nWould you like to help us enhance our service by your feedback(Y/N)? " << endl;
		cin >> c;
		if ((c == 'y') || (c == 'Y')) {
			int star;
			char fb[100];
			cout << "Rate us(out of 5) based on your experience ";
			cin >> star;
			for (int i = 0; i < star; i++)
				cout << "*\t";
			cout << endl;
			cout << "Thank you for taking time out to leave your feedback!" << endl;
			cout << "Thank you for using our service!" << endl;
		}
		if ((c == 'n') || (c == 'N'))
			cout << "Thank you for using our service!" << endl;
	}
};
class payment {
	protected:
		long int choice1, bank, card, date, cvv, user_id;
	96
	char password[10];
	public:
		void pay_detail() //function declaration and definition for payment method
	{
		cout << "\n\n\nHow would you like to pay?:\n";
		cout << "\n\1.Debit Card(1) \n\2.Credit Card(2) \n\3.Net Banking(3)";
		cout << "\n\nEnter your choice";
		cin >> choice1;
		switch (choice1) {
			case 1:
				cout << "\nEnter card number:";
				cin >> card;
				cout << "\nEnter expiry date:";
				cin >> date;
				cout << "\nEnter CVV number:";
				cin >> cvv;
				cout << "\nTransaction Successful\n";
				break;
			case 2:
				cout << "\nEnter card number:";
				cin >> card;
				cout << "\nEnter expiry date:";
				cin >> date;
				cout << "\nEnter password:";
				cin >> password;
				cout << "\nTransaction Successful\n";
				break;
			case 3:
				cout << "Banks Available: \1.Kotak Mahindra Bank(1) \2.Karur Vysya Bank(2) \3.SBI(3)\
				4. IOB(4)
				";
				97
				cout << "\nSelect your bank:";
				cin >> bank;
				cout << "\nYou have selected:" << bank;
				cout << "\nEnter user id:";
				cin >> user_id;
				cout << "\nEnter password:";
				cin >> password;
				cout << "\nTransaction Successful\n";
				break;
			default:
				cout << "\nInvalid input entered.\nTry again\n\n";
				return pay_detail();
		}
	}
};
void createfile(passenger p) //file creation for domestic booking
{
	ofstream fin("domestic.txt", ios::binary | ios::app);
	fin.write((char * ) & p, sizeof(p)); //writing to file
	fin.close(); //closing file
}
void cancelticket(int x) //function to cancel ticket
{
	passenger p;
	int f = 0;
	ifstream fout("domestic.txt", ios::binary | ios::app); //for reading file
	ofstream fin("domestic1.txt", ios::binary | ios::app); //for writing to a new file
	fout.read((char * ) & p, sizeof(p)); //reading file
	while (fout) {
		if (p.getpnr() != x) //checking pnr
			98
		fin.write((char * ) & p, sizeof(p)); //writing to file
		else {
			p.disp(); //display details
			cout << "\nYour Above ticket is being canceled:\n" << "Amount refunded: Rs 1000\n";
			f++; //incrementing f if pnr found
		}
		fout.read((char * ) & p, sizeof(p)); //reading another record from file
	}
	if (f == 0) //if f==0,pnr not found
		cout << "Ticket not found\n";
	fout.close(); //closing file
	fin.close(); //closing file
	remove("domestic.txt"); //deleting old file
	rename("domestic1.txt", "domestic.txt"); //renaming new file
}
void checkticket(int x) //function to check pnr or ticket
{
	passenger p;
	int f = 0;
	ifstream fout("domestic.txt", ios::binary); //opening file
	fout.read((char * ) & p, sizeof(p)); //reading file
	while (fout) {
		if (p.getpnr() == x) //checking pnr
		{
			p.disp(); //display details
			cout << "\nYour ticket" << endl;
			f++; //incrementing f if onr found
			break;
		}
		99
		fout.read((char * ) & p, sizeof(p)); //reading another record from the same file
	}
	fout.close(); //closing file
	if (f == 0) //if f==0, pnr not found
		cout << "Ticket not found" << endl;
}
void createfilei(passenger p) //opening a file for international booking
{
	ofstream fin("international.txt", ios::binary | ios::app);
	fin.write((char * ) & p, sizeof(p)); //writing to file
	fin.close(); //closing file
}
void cancelticketi(int x) //function to cancel ticket
{
	passenger p;
	int f = 0;
	ifstream fout("international.txt", ios::binary | ios::app); //opening file
	ofstream fin("international1.txt", ios::binary | ios::app); //writing to a new file
	fout.read((char * ) & p, sizeof(p)); //reading old file
	while (fout) {
		if (p.getpnri() != x) //checking pnr
			fin.write((char * ) & p, sizeof(p)); //writing to new file;
		else {
			p.dispi(); //display details
			cout << "Your Above ticket is being deleted:\n" << "Amount refunded: Rs 1000\n";
			f++; //incrementing f if pnr found
		}
		fout.read((char * ) & p, sizeof(p)); //reading another record from old file
	}
	100
	if (f == 0) //if f==0,pnr not found
		cout << "\nTicket not found\n";
	fout.close(); //closing file
	fin.close(); //closing file
	remove("international.txt"); //deleting old file
	rename("international1.txt", "international.txt"); //renaming new file
}
void checkticketi(int x) //function to check pnr or ticket
{
	passenger p;
	int f = 0;
	ifstream fout("international.txt", ios::binary); //opening file
	fout.read((char * ) & p, sizeof(p)); //reading file
	while (fout) {
		if (p.getpnri() == x) //checking pnr
		{
			p.dispi(); //display details
			cout << "\nYour ticket" << endl;
			f++; //incrementing f if pnr found
			break;
		}
		fout.read((char * ) & p, sizeof(p)); //reading another record from the file
	}
	fout.close(); //closing file
	if (f == 0) //if f==0, pnr not found
		cout << "Sorry! No such booking has been done." << endl;
}
int credentials() {
	int choice;
	101
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n ";
	cout << " Welcome to login page \n";
	cout << "~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "1.LOGIN" << endl;
	cout << "2.REGISTER" << endl;
	cout << "3.Exit" << endl;
	cout << "\nEnter your choice :";
	cin >> choice;
	cout << endl;
	switch (choice) {
		case 1:
			login();
			break;
		case 2:
			registr();
			break;
		case 3:
			cout << "Thank you";
			break;
		default:
			cout << "Invalid choice. You must login to book a ticket.\nIf new user, register." << endl;
			return 0;
	}
}
int login() {
	int count, x;
	string user, pass, u, p;
	ifstream input("database.txt");
	102
	cout << "Please enter the following details" << endl;
	cout << "USERNAME :";
	cin >> user;
	while (input >> u) {
		if (u == user) {
			cout << "PASSWORD :";
			cin >> pass;
			while (input >> p) {
				if (p == pass)
					count = 1;
				else
					x = 3;
			}
		}
	}
	input.close();
	if (count == 1) {
		cout << "\nHello " << user << "\nLOGIN SUCCESSFUL\nWe're glad that you're here.\nThanks for
		logging in \n ";
		cin.get();
		return count;
	} else if (x == 3)
		cout << "Incorrect Password";
	else {
		103
		cout << "\nUsername does not exist. You must login to book the tickets\nIf new user, kindly
		register\ n ";
		credentials();
	}
}
void registr() {
	string reguser, regpass, u, ru, rp;
	int count;
	ifstream input("database.txt");
	cout << "Enter the username :";
	cin >> reguser;
	while (input >> u) {
		if (u == reguser) {
			cout << "Username is aldready taken.";
			exit(0);
		}
	}
	input.close();
	cout << "Enter the password :";
	cin >> regpass;
	ofstream reg("database.txt", ios::app);
	reg << reguser << ' ' << regpass << endl;
	cout << "\nRegistration Sucessful\n";
	credentials();
}
int main() {
	class d_booking d1; //object for class d_booking
	104
	class i_booking i1; //object for class i_booking
	class passenger p1; //object for class passenger
	class payment p2; //object for class payment
	int ch, ch1, n;
	char input, imp;
	imp = credentials();
	if (imp == 1) {
		do {
			cout << "\n\tWelcome To SPICEJET Reservation System" << endl << endl;
			cout << "\t<><><><><><><><><><><><><><><><><><><><><><><>\n";
			cout << "\tA Great way to Fly" << endl;
			cout << "\t<><><><><><><><><><><><><><><><><><><><><><><>";
			cout << "\n\n\t\1.Book Flight(1) \n\t\2.Cancel Fight(2) \n\t\3.Check Ticket(3) \n\t\4.Check
			Terminal details(4)\ n\ t\ 5. Exit(5)
			" << endl;
			cout << "\n\t\t Please enter your choice:";
			cin >> ch;
			switch (ch) {
				case 1:
					cout << "\n\n\1.Domestic Fights(1) \n\2.International Flights(2)" << endl;
					cout << "\nPlease enter your option:" << endl;
					cin >> ch1;
					switch (ch1) {
						case 1: //for booking domestic ticket
							p1.d_pnr();
							p1.p_detail(1); //function calls
							p1.gender_check();
							p1.more_details();
							105
							p2.pay_detail();
							p1.disp();
							p1.feedback();
							createfile(p1); //call to create file
							break;
						case 2: //for booking international ticket
							p1.p_detail(2); //function calls
							p1.i_pnr();
							p1.gender_check();
							p1.more_details();
							p2.pay_detail();
							p1.dispi();
							p1.feedback();
							createfilei(p1); //call to create file
							break;
						default:
							cout << "Invalid input entered.\nTry again\n\n\n" << endl;
							return main();
					}
					break;
				case 2:
					cout << "\1.Domestic Fights(1) \n\2.International Flights(2)" << endl;
					cout << "\nPlease enter your option:" << endl;
					cin >> ch1;
					if (ch1 == 1) {
						cout << "Please enter your PNR number:" << endl;
						cin >> n;
						cancelticket(n); //function call for domestic booking cancellation
					} else if (ch1 == 2)
						106 {
							cout << "Please enter your PNR number:" << endl;
							cin >> n;
							cancelticketi(n); //function call for international cancellation
						}
					else {
						cout << "Invalid input entered.\nTry again\n\n\n";
						return main();
					}
					break;
				case 3: //for displaying booked ticket details
					cout << "\1.Domestic Fights(1) \n\2.International Flights(2)" << endl;
					cout << "\nPlease enter your option:" << endl;
					cin >> ch1;
					if (ch1 == 1) {
						cout << "Please enter your PNR number:" << endl;
						cin >> n;
						checkticket(n);
					} //function call to display domestic ticket details
					else if (ch1 == 2) {
						cout << "Please enter your PNR number:" << endl;
						cin >> n;
						checkticketi(n); //function call to display domestic ticket details
					} else {
						cout << "Invalid input entered.\nTry again\n\n\n";
						return main();
						107
					}
					break;
				case 4:
					cout << "\nArrival
					time\ tDelay\ t\ tFlight\ t\ t\ tDestination\ tRows\ tGate\ tRemarks "<<endl;
					cout << "\n14:05\t\t00:00\t\tPS145 Vistara\t\tNew York\t3\tB\tGate
					Closed "<<endl;
					cout << "\n22:05\t\t00:00\t\tPC802 Emirates\t\tDubai\t\t10\tB\tFinal Call" << endl;
					cout << "\n18:05\t\t18:30\t\tDL3621 Deccan
					Air\ tLondon\ t\ t8\ tB\ tDelayed "<<endl;
					cout << "\n11:05\t\t00:00\t\tIA1535
					Indigo\ t\ tDelhi\ t\ t5\ tA\ tBoarding "<<endl;
					cout << "\n17:05\t\t18:00\t\tA1363 Air
					Asia\ t\ tMumbai\ t\ t5\ tB\ tDelayed "<<endl;
					cout << "\n22:05\t\t00:00\t\tDK2061 Deccan Air\tKolkata\t\t12\tB\tGate Open" << endl;
					break;
				case 5:
					cout << "\n\n\t\t\t\tCREDITS : - Team 2";
					exit(0);
					break;
					return 0;
				default:
					cout << "Invalid input entered.\nTry again\n\n\n\n" << endl;
					return main();
			}
			cout << "\n\n\nDo you wish to continue:(y/n):" << endl;
			cin >> input;
		} while (input == 'Y' || input == 'y');
	}
	return 0;
}