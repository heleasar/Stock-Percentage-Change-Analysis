#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stock {
    string name;
    float price1;
    float price2;
    float percent_change;
};

int main() {
    int num_stocks;
    cout << "How many stocks will you enter? ";
    cin >> num_stocks;

    vector<stock> stocks(num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        cout << "Enter stock " << i+1 << " name: ";
        cin >> stocks[i].name;
        cout << "Enter stock " << i+1 << " price on day 1: ";
        cin >> stocks[i].price1;
        cout << "Enter stock " << i+1 << " price on day 2: ";
        cin >> stocks[i].price2;

        stocks[i].percent_change = (stocks[i].price2 - stocks[i].price1) / stocks[i].price1 * 100;
    }

    int max_change_idx = 0;
    for (int i = 1; i < num_stocks; i++) {
        if (stocks[i].percent_change > stocks[max_change_idx].percent_change) {
            max_change_idx = i;
        }
    }

    cout << "The stock whose percent change increased the most is:\n";
    cout << "Name: " << stocks[max_change_idx].name << endl;
    cout << "Price on day 1: " << stocks[max_change_idx].price1 << endl;
    cout << "Price on day 2: " << stocks[max_change_idx].price2 << endl;
    cout << "Percent change: " << stocks[max_change_idx].percent_change << "%" << endl;

    return 0;
}
