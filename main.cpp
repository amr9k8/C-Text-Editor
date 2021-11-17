#include<iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <regex>
#include <MyFileHelper.h>
#include <stdio.h>


using namespace std;




int main()
{

    MyFileHelper fileObj;
    string filename;
    vector<string> v;
    string x;
    char choice;
    bool fileStatues;

    cout << "Enter Filename you want to open in X-Note Editor  \n";
    cin >> filename;
    fileStatues = fileObj.setFilename(filename);

  while  ( !fileStatues)
  {
    cout << "Please Enter A Valid txt File  \n";
    cin >> filename;
    fileStatues = fileObj.setFilename(filename);
  }

//Clear Screen and Show Loading bar
    system("CLS");
    fileObj.loadingBar();
    system("CLS");

// Show mainMenu
    while (choice != 'e')
    {
        system("Color 0A"); //switch color to green

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "     X-Note Editor ~  Made BY NP_7         " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "- Type a to Add New Line " << endl;cout << "- Type r to Read Whole File " << endl;cout << "- Type g to get line in a File " << endl;cout << "- Type i to insert  text  in a specific LineNo# in A File " << endl;
        cout << "- Type u to update  text in a specific LineNo#  " << endl;cout << "- Type d to delete  text  in a specific LineNo# " << endl;cout << "- Type s to search  text in whole file  " << endl;cout << "- Type o to search and replace text in whole file  " << endl;
        cout << "- Type c to change file" << endl;cout << "- Type e  to exit" << endl;

        cin >> choice;


        if ( choice == 'a') {

            while(choice!='n')
            {
               cout << "\n Write text to add in file \n";
               cin.ignore();
               getline(cin,x);
                fileObj.addLine(x);
                cout << "Add new line ? Y/n  \n";
                cin >> choice;
            }

            v.clear();

        }
        else if (choice == 'r' )
        {
            // Get the contents of file in a vector
            bool result = fileObj.getFileContent(v);
            if(result)
            {
            fileObj.printVector(v);
            v.clear();
            }
        }
        else if (choice  == 'g')
        {
            int index ;
            cout << "Enter Line Number " << endl;
            cin >> index;
            fileObj.getFileContent(v); //to fill file data in our vector ( because i passed vector obj by reference )
            // Get the contents of file in a vector
            cout << fileObj.getLineByIndex(v,index) <<endl ;
            v.clear();
        }

        else if (choice  == 'i')
        {
            int index ;
            string txt;
            cout << "Enter Line Number " << endl;
            cin >> index;
            cout << "Write text to insert it \n";
            cin.ignore();
            getline(cin,txt);
            fileObj.getFileContent(v); //to fill file data in our vector ( because i passed vector obj by reference )
            fileObj.insertLineByIndex(v,index,txt);
            v.clear();
        }

        else if (choice  == 'u')
        {
            int index ;
            string txt;
            cout << "Enter Line Number " << endl;
            cin >> index;
            cout << "Write text to update in  line #no : "<< index <<  "\n";
            cin.ignore();
            getline(cin,txt);
            fileObj.getFileContent(v); //to fill file data in our vector ( because i passed vector obj by reference )
            fileObj.updateLineByIndex(v,index,txt);
            v.clear();
        }
        else if (choice  == 'd')
        {
            int index ;
            cout << "Enter Line Number to delete it " << endl;
            cin >> index;
            fileObj.getFileContent(v); //to fill file data in our vector ( because i passed vector obj by reference )
            fileObj.deleteLineByIndex(v,index);
            v.clear();
        }

        else if (choice  == 's')
        {
            int no =0;;
            vector<string> v1;
            string keyword;
            cout << "Enter keyword to search for  " << endl;
            cin.ignore();
            getline(cin,keyword);
            fileObj.getFileContent(v); //to fill file data in our vector ( because i passed vector-obj by reference )
           v1 = fileObj.searchByText(v,keyword,no);
           fileObj.printVector(v1);
           v.clear();

        }

        else if (choice  == 'o')
        {
            int no =0;
            vector<string> v1;
             string keyword;
             string replacment;
            cout << "Enter term that you want to replace in the whole file  " << endl;
            cin.ignore();
            getline(cin,keyword);
            cout << "Replace every ( "<<keyword <<" ) Found in file With ?"  << endl;
            cin >> replacment;
            fileObj.getFileContent(v); //to fill file data in our vector ( because i passed vector-obj by reference )
           v1 = fileObj.searchAndReplace(v,keyword,replacment,no);
          //cout << counter << endl;
           fileObj.printVector(v1);
           fileObj.writeVecToFile(v1);
           v.clear();
        }

          else if (choice  == 'c')
        {
            bool res= false;
            system("CLS");
            system("Color 07"); // 0 for black backgound , 7 for white text
            cout << "Enter Filename you want to open in X-Note Editor  \n";
            cin >> filename;
           res = fileObj.setFilename(filename);
            while (!res )
            {
                 cout << "Please Enter A Valid txt File  \n";
                cin >> filename;
                res = fileObj.setFilename(filename);
            }
               system("CLS");
               fileObj.loadingBar();
               system("CLS");

        }



    }






  return 0;
}





