#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

// Function to read integers from a file and print them
void readFile(string filename){
    ifstream inFile;
    inFile.open(filename);
// Check if file opened successfully
    if(!inFile.is_open()){
        cerr << "Error opening file." << filename << endl;
        return;
    }
// Read and print integers from the file
    int currentNumber;
    while (inFile >> currentNumber){
        cout << currentNumber << endl;
    }

    inFile.close();
}

int main(){
    // List of files to read
    vector<string> filenames = {"textfile1.txt", "textfile2.txt", "textfile3.txt"};
    for(const string& filename : filenames){
        // Print the filename being read
        cout << "Reading from file: " << filename << endl;
        // Call the function to read and print integers from the file
        readFile(filename);
    }
}