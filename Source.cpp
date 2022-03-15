#include <iostream>
#include <iomanip>
#define MILEAGERATE 0.585 //IRS standard milage rates for 2022 https://www.irs.gov/newsroom/irs-issues-standard-mileage-rates-for-2022

using namespace std;

int main() {
	double Miles = 0; //miles driven
	double FeesReceived = 0; //del fees given to driver
	double CPM = 0; //cents per mile driven
	double MinOwed = 0; //amount due to driver to meet standard milage rates

	cout << "Miles driven this shift: ";
	cin >>	Miles;
	cout << "Amount of money received in delivery fees: ";
	cin >> FeesReceived;
	
	CPM = FeesReceived / Miles; //calculate cents per mile
	
	MinOwed = Miles * MILEAGERATE; //calculate gross dollars owed to driver
	MinOwed = MinOwed - FeesReceived; //calculate net by subtracting gross from del fees
	
	if (CPM >= MILEAGERATE) { //If driver receives more than STD mileage rate
		cout << "You received $" << setprecision(3) << CPM << "/mi. You do not qualify for reimbursement this shift.";
	}
	if (CPM < MILEAGERATE) { //If driver receives less than STD mileage rate
		cout << "You received $" << CPM << "/mile today \n";
		cout << "To reach 0.585¢/mile you are owed $" << setprecision(3) << showpoint << MinOwed;
	}
	if (Miles == 0) { //if driver did not leave store
		cout << "You did not drive today";
	}
}
