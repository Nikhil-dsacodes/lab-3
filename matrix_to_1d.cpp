
#include<iostream>
using namespace std;
int main(){
    int nR, nC, i, j;
    cout<<"Number of ROWS: ";
    cin>>nR;
    cout<<"Number of COLUMNS: ";
    cin>>nC;
cout<<endl;

// passing values to the 1D array 
int count = 0;
int arr[nR * nC];
for(i=0; i<nR*nC; i++){
    arr[i] = rand() % 10;
}

// printing the array in the form of table to the user
for(i=0; i<nR*nC; i++){
    cout<<arr[i]<<"  ";
    count = count + 1;
    if(count == nC){
        cout<<endl;
        count = 0;
    }
}
cout<<endl;

int x,y;
cout<<"Enter the cordinate of the Number: ";
cin>>x>>y;
if(x > nC || y > nR){
    cout<<"Please enter VALID cordinates! ";
    return 0;
}

cout<<"The number whose cordinate is ("<<x<<","<<y<<") is "
        <<arr[(y-1)*(nC) + (x-1)];

    return 0;
}
