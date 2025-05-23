#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs=filesystem;

void createFile(string fileName) 
{
    ofstream file(fileName);
    if(file) 
    {
        cout<<"File created successfully!"<<endl;
        file.close();
    } 
    else 
    {
        cout<<"Failed to create file!"<<endl;
    }
}

void writeFile(string fileName,string data) 
{
    ofstream file(fileName);
    if(file) 
    {
        file<<data;
        cout<<"Successfully written!"<<endl;
        file.close();
    } 
    else 
    {
        cout<<"File not opened!"<<endl;
    }
}

void deleteFile(string fileName) 
{
    if(remove(fileName.c_str())==0) 
    {
        cout<<"File deleted successfully!"<<endl;
    } 
    else 
    {
        cout<<"Failed to delete file!"<<endl;
    }
}

void copyFile(string source,string dest) 
{
    ifstream in(source);
    ofstream out(dest);
    if(!in || !out) 
    {
        cout<<"Copy failed!"<<endl;
        return;
    }
    string line;
    while(getline(in,line)) 
    {
        out<<line<<endl;
    }
    in.close();
    out.close();
    cout<<"File copied successfully!"<<endl;
}

void moveFile(string source,string dest) 
{
    if(fs::exists(source)) 
    {
        fs::rename(source,dest);
        cout<<"File moved successfully!"<<endl;
    } 
    else 
    {
        cout<<"Move failed! Source file does not exist."<<endl;
    }
}

int main() 
{
    int choice;
    string file1,file2,data;

    while(true) 
    {
        cout<<"\n1. Create File\n2. Write File\n3. Delete File\n4. Copy File\n5. Move File\n6. Exit\nEnter choice: ";
        cin>>choice;
        cin.ignore();

        if(choice==1) 
        {
            cout<<"Enter file name to create: ";
            getline(cin,file1);
            createFile(file1);
        }
        else if (choice==2) 
        {
            cout<<"Enter file name to write to: ";
            getline(cin,file1);
            cout<<"Enter text: ";
            getline(cin, data);
            writeFile(file1,data);
        }
        else if(choice==3) 
        {
            cout<<"Enter file name to delete: ";
            getline(cin,file1);
            deleteFile(file1);
        }
        else if(choice==4) 
        {
            cout<<"Enter source file: ";
            getline(cin,file1);
            cout<<"Enter destination file: ";
            getline(cin,file2);
            copyFile(file1,file2);
        }
        else if(choice==5) {
            cout<<"Enter source file: ";
            getline(cin,file1);
            cout<<"Enter destination file: ";
            getline(cin,file2);
            moveFile(file1,file2);
        }
        else if(choice==6) 
        {
            cout<<"Done with File Handling"<<endl;
            break;
        }
        else 
        {
            cout<<"Invalid choice! Try again."<<endl;
        }
    }

    return 0;
}
