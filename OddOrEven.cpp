#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

        // if (num & 1) {
        //     cout << num << " is Odd" << endl;
        // } else {
        //     cout << num << " is Even" << endl;
        // }

        // if(num % 2 == 0){
		// 	cout << num << " is Even" << endl;
		// }
		// else{
		// 	 cout << num << " is Odd" << endl;
		// }

        int div = num / 2;
		int mul = div * 2;
		
		if(num  == mul){
           cout << num << " is Even" << endl;
        }
		else{
            cout << num << " is Odd" << endl;
        }


    return 0;
}
