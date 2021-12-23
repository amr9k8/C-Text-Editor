#ifndef MYFILEHELPER_H
#define MYFILEHELPER_H
#include<iostream>
#include "StackArr.h"
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <regex>
#include <MyFileHelper.h>
using namespace std;


class MyFileHelper
{
private:
    string fileName;
    public:

//To Determine Working File
        bool setFilename(string name);

//Function to Save Vector inside a TextFile
        void writeVecToFile(vector<string> vec2);

//Function to Load Every Line of TextFile in Vector
        bool getFileContent(vector<string> & vecOfStrs);

//Function to Search an keyword in a line of text
        void searchSubStr(string txt , string keyword ,int& n);

// Function to return Vector Contain all Result of Searching Process
        vector<string> searchByText(vector<string> vec2,string keyword,int &n);


//Function to  Search&Replace an keyword with another in a line of text
        string replaceSubStr( string txt ,string keyword ,string Replace );

// Function to return Vector Contain all Result of Replacement Process
        vector<string> searchAndReplace(vector<string> vec2,string keyword,string Replace ,int &n);

//Other Functions to Edit Text in Files
        void addLine(string x);
        string getLineByIndex(vector<string> vec,int i);
        void insertLineByIndex(vector<string> &vec2,int i,string x);
        void updateLineByIndex(vector<string> &vec2,int i,string x);
        void deleteLineByIndex(vector<string> &vec2,int i);

// Function to Display Vector's data  in Pretty Way
        void printVector(vector<string> vec2);

//Function To Display Loading
        void loadingBar();



};

#endif // MYFILEHELPER_H
