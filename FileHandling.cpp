#include <iostream>
#include <fstream>

using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Open input file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    // Read the number of elements from the first line of input file
    int numElements;
    inputFile >> numElements;

    // Dynamically allocate memory for the array
    int *data = new int[numElements];

    // Read data from input file into the array
    for (int i = 0; i < numElements; i++) {
        inputFile >> data[i];
    }
    inputFile.close();

    // Sort the data using bubble sort
    bubbleSort(data, numElements);

    // Open output file
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error opening output file!" << endl;
        delete[] data; // Free dynamically allocated memory
        return 1;
    }

    // Write sorted data to output file
    for (int i = 0; i < numElements; i++) {
        outputFile << data[i] << " ";
    }
    outputFile.close();

    // Free dynamically allocated memory
    delete[] data;

    cout << "Data sorted and written to output.txt successfully!" << endl;

    return 0;
}
