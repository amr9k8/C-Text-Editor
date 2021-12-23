#include "MyFileHelper.h"
fstream writefile;



bool MyFileHelper::setFilename(string name)
{
     ifstream in( name.c_str() );

    // Check if object is valid
    if(!in)
    {
        cout << "This File Doesn't Exist \n"<<endl;
        return false;
    }
    else
    fileName = name;
}

bool MyFileHelper::getFileContent(vector<string> & vecOfStrs)
{
    // Open the File
    ifstream in(fileName.c_str());

    // Check if object is valid
    if(!in)
    {
        cout << "This File Doesn't Exist "<<endl;
        return false;
    }

    string str;
    // Read the next line from File untill it reaches the end.
    while (getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if(str.size() > 0)
            vecOfStrs.push_back(str);
    }

    //Close The File
    in.close();
    return true;
}



void MyFileHelper::writeVecToFile(vector<string> vec2 )
{

    writefile.open(fileName.c_str(),ios::out);//over write of old data

  for(int i=0;i<vec2.size();++i){
		writefile<<vec2[i]<<endl;
	}
	writefile.close();

}


void MyFileHelper::searchSubStr(string txt , string keyword ,int& n)
{
  //txt = "hello world hello"  (index ,total charaters to move from index)
  // txt.substr(6,5); => world

    string test;

    for(int i=0; i<= txt.length(); i++ )
    {
        test =  txt.substr(i,keyword.length());

       if (test.compare(keyword) == 0)
            n++; //increase no of occurrence
    }

}



vector<string> MyFileHelper::searchByText(vector<string> vec2,string keyword,int &n)
{
   vector<string> v1 ;
    string result;
    ostringstream convert;

     for(int i=0;i<vec2.size();++i)
   {
    result ="";
    convert.str(""); //empty it every line to prevent string concatiation
    searchSubStr(vec2[i],keyword,n) ;
    convert << n;
    result =  "found :" + convert.str() + " times ";
    if(n >= 1){
    for (int i=0; i<=n-1; i++)
        result += keyword + "  ";
    }
    v1.push_back(result);
    n=0;
   }

   return v1;
}




string MyFileHelper::replaceSubStr( string txt ,string keyword ,string Replace )
{
    string test;
    test = std::regex_replace(txt, std::regex(keyword), Replace); // replace 'keyword' -> 'replace'
    return test;
}



vector<string> MyFileHelper::searchAndReplace(vector<string> vec2,string keyword,string Replace ,int &n)
{
   vector<string> v1 ; //to save new results and load it in files
   string result;

     for(int i=0;i<vec2.size();++i)
   {
    result ="";
    result = replaceSubStr(vec2[i],keyword,Replace);
   // cout  << "keyword :" << keyword << " replace value : " << Replace << "changed from " << vec2[i] << " to " << result << endl;
    v1.push_back(result);
    n=0;
   }
   return v1;
}




void  MyFileHelper::addLine(string x)
{
    writefile.open(fileName.c_str(),ios::out|ios::app);
    writefile << x << endl ;
    writefile.close();
}

string MyFileHelper::getLineByIndex(vector<string> vec,int i)
{
   return vec[i]; //string (line of text )
}


void MyFileHelper::insertLineByIndex(vector<string> &vec2,int i,string x)
{
   vec2.insert(vec2.begin()+i,x);
   writeVecToFile(vec2);
}



void MyFileHelper::updateLineByIndex(vector<string> &vec2,int i,string x)
{
   vec2[i]=x;
   writeVecToFile(vec2);
}


void MyFileHelper::deleteLineByIndex(vector<string> &vec2,int i)
{
   vec2.erase(vec2.begin()+i);
   writeVecToFile(vec2);
}


void MyFileHelper::printVector(vector<string> vec2)
{
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "#No |" << setw(50) <<"Content"<< endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl;

    // Print the vector contents
    for(int i=0; i < vec2.size(); i++)
    cout << setw(3)<< i << " | " << vec2[i] << endl;


    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << setw(55) <<"End of File"<< endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" << endl<<endl<<endl;
}

void MyFileHelper::loadingBar()
{
    // 0 - black background,
    // 4 - red Foreground
    system("color 04");

    char a = 177; // A Graphic character, medium density dotted
    char  b = 219;// A Graphic character, high density solid

    printf("\n\n\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t  Welcome  To  X-Note  Editor \n");
    printf("\n\t\t\t\t\t\t  Loading ... \n\n");
    printf("\t\t\t");

    // Print Length of Initial Bar
    for (int i = 0; i < 60; i++)
        printf("%c", a);

// Set the cursor again starting point of screen
    printf("\r");
// Move 3  \t  to start at  Initial Bar Position
printf("\t\t\t");

    // Print loading bar progress
    for (int i = 0; i < 60; i++) {
        printf("%c", b);
        Sleep(20);
    }
}




