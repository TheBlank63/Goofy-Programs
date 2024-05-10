#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void EnterToComtinue();

int main() {
    ofstream outputFile("file.txt");
    outputFile.close();

    ifstream inputFile("file.txt");
    int arr[200];
    int num = 0;

    cout<<"Text editor will be opened after pressing enter, please paste all the data in the file and save it\n";
    EnterToComtinue();
    system("file.txt");

    while (inputFile >> arr[num]) {
        num++;
    }

    inputFile.close();

    cout<<num<<endl;
    
    double x = 0, xp2 = 0;
    
    for(int i = 0; i < num; i++)
    {
        x += arr[i];
        xp2 += pow(arr[i], 2);
    }
    
    cout<<"x : "<<x<<endl<<"x^2 : "<<xp2<<endl;
    double var = (xp2 - (pow(x,2)/num))/(num - 1);
    cout<<"variance : "<<var<<endl;
    cout<<"standard deviation : "<<sqrt(var)<<endl;
    return 0;
}

void EnterToComtinue()
{
    char *a = new char;
    cout<<"\n[PRESS ENTER TO CONTINUE]";
    *a = getchar();
    delete a;
} 
