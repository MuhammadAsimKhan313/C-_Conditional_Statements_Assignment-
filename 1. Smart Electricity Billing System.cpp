#include <iostream>
#include <iomanip>
using namespace std;

int main()
 {
    int units;
    long long dueDate, paidDate;   // format: YYYYMMDD

    cout << "Enter units consumed: ";
    if (!(cin >> units) || units < 0) {
        cerr << "Invalid units.\n";
        return 1;
    }

    cout << "Due date (YYYYMMDD): ";
    cin >> dueDate;
    cout << "Payment date (YYYYMMDD): ";
    cin >> paidDate;

    double bill;
    if (units <= 100)      bill = units * 10.0;
    else if (units <= 200) bill = 100 * 10.0 + (units - 100) * 15.0;
    else if (units <= 500) bill = 100 * 10.0 + 100 * 15.0 + (units - 200) * 20.0;
    else                   bill = 100 * 10.0 + 100 * 15.0 + 300 * 20.0 + (units - 500) * 25.0;

    if (bill > 10000) bill *= 1.05;          // 5% surcharge
    if (paidDate > dueDate) bill *= 1.10;    // 10% late fee

    cout << fixed << setprecision(2);
    cout << "Final Bill: Rs. " << bill << endl;
    return 0;
}
