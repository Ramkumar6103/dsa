#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spreadsheet {
    vector<vector<int>> cells;
public:
    Spreadsheet(int rows) {
        cells = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        cells[row][col] = value;
    }

    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int getValue(string formula) {
        int idx = formula.find('+');
        string left = formula.substr(1, idx - 1);
        string right = formula.substr(idx + 1);

        int valLeft =
            isalpha(left[0])
            ? cells[stoi(left.substr(1)) - 1][left[0] - 'A']
            : stoi(left);

        int valRight =
            isalpha(right[0])
            ? cells[stoi(right.substr(1)) - 1][right[0] - 'A']
            : stoi(right);

        return valLeft + valRight;
    }
};

int main() {
    Spreadsheet sheet(5); // Create a spreadsheet with 5 rows

    // Set some cell values
    sheet.setCell("A1", 10);
    sheet.setCell("B2", 20);
    sheet.setCell("C3", 30);

    // Reset a cell
    sheet.resetCell("B2");

    // Evaluate formulas
    cout << "Value of =A1+5: " << sheet.getValue("=A1+5") << endl;     // 10 + 5 = 15
    cout << "Value of =10+C3: " << sheet.getValue("=10+C3") << endl;   // 10 + 30 = 40
    cout << "Value of =A1+B2: " << sheet.getValue("=A1+B2") << endl;   // 10 + 0 = 10

    return 0;
}
