
/* ADT on ORDERED LIST */

#include <iostream>
#include <algorithm>
#include <cstring> // For strcmp
using namespace std;

int BS_Rec(int arr[], int x, int low, int high) {
    if (low > high) {
        return -1; 
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x) {
        return mid; 
    } 
    else if (arr[mid] < x) {
        return BS_Rec(arr, x, mid + 1, high);
    } 
    else {
        return BS_Rec(arr, x, low, mid - 1);
    }
}

int main() {
    int n = 15;
    char op[20];
    cout << "ORDERED LIST..." << endl << endl;
    int arr[15] = {3, 5, 9, 19, 32, 50, 58, 59, 64, 70, 77, 89, 91, 94, 99};
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    cout << "\n\nWhich Operation you want to perform on the array: ";
    cin >> op;

    // INSERTION 
    if (strcmp(op, "insertion") == 0) {
        
        int num_after_insert, num_before_insert, aNum, bNum;
        char after_or_before[6];
        cout << "After or Before: ";
        cin >> after_or_before;

        /* After */
        if (strcmp(after_or_before, "after") == 0) {
            cout << "After which number: ";
            cin >> num_after_insert;
            cout << "The number you want to insert: ";
            cin >> aNum;

            int indexOf_num_after_insert = BS_Rec(arr, num_after_insert, 0, n - 1);
            if (indexOf_num_after_insert == -1) {
                cout << "Number not found." << endl;
                return 0; // Exit if number is not found
            }

            int newArr[16]; // New array for the new size
            for (int i = 0; i <= indexOf_num_after_insert; i++) {
                newArr[i] = arr[i];
            }
            newArr[indexOf_num_after_insert + 1] = aNum;
            for (int i = indexOf_num_after_insert + 2; i < 16; i++) {
                newArr[i] = arr[i - 1];
            }
            n++; // Increase size
            for (int i = 0; i < n; i++) {
                cout << newArr[i] << "  ";
            }
            cout << endl;
        }

        /* Before */
        else if (strcmp(after_or_before, "before") == 0) {
            cout << "Before which number: ";
            cin >> num_before_insert;
            cout << "Number you want to insert: ";
            cin >> bNum;

            int indexOf_num_before_insert = BS_Rec(arr, num_before_insert, 0, n - 1);
            if (indexOf_num_before_insert == -1) {
                cout << "Number not found." << endl;
                return 0; // Exit if number is not found
            }

            int newArr[16]; // New array for the new size
            for (int i = 0; i < indexOf_num_before_insert; i++) {
                newArr[i] = arr[i];
            }
            newArr[indexOf_num_before_insert] = bNum;
            for (int i = indexOf_num_before_insert + 1; i < 16; i++) {
                newArr[i] = arr[i - 1];
            }
            n++; // Increase size
            for (int i = 0; i < n; i++) {
                cout << newArr[i] << "  ";
            }
            cout << endl;
        }
    }
    
    // DELETION
    if (strcmp(op, "deletion") == 0) {
            int del_num;
              cout<<"The number you want to delete: ";
              cin>>del_num;
              int newArr[n-1];
              int index = BS_Rec(arr, del_num, 0, n-1);
             
              for(int i=0; i<index; i++){
                  newArr[i] = arr[i];
              }
              for(int i=index; i<n-1; i++){
                  newArr[i] = arr[i+1];
              }
              for(int i=0; i<n-1; i++){
                  cout<<newArr[i]<<"  ";
              }
            }
        
    // UPDATE 
    if (strcmp(op, "update") == 0) {
        int x, newNum;
        cout<<"Number you want to Update: ";
        cin>>x;
        int index = BS_Rec(arr, x, 0, n-1);
    cout<<"Number you want to pass at the place of "<<x<<": ";
        cin>>newNum;
        arr[index] = newNum;
        for(int i = 0; i<n; i++){
            cout<<arr[i]<<"  ";
        }
    }

    return 0;
}
