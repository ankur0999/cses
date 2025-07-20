#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int t = 7;
    for (int i = 1; i <= t; i++) {
        string input = "C:/Users/0anku/Downloads/tests (5)/" + to_string(i) + ".in";
        string output = "C:/Users/0anku/Downloads/tests (5)/" + to_string(i) + ".out";
        
        ifstream inputFile(input);
        ifstream outputFile(output);
        if (!inputFile || !outputFile) {
            cerr << "Error: Could not open file for test case " << i << endl;
            continue;
        }

        string line;
        try {
            getline(inputFile, line);
            int n = stoi(line);
            getline(inputFile, line);
            cout << "Test " << i << ", n: " << n << endl;

            vector<long long> arr;
            stringstream ss(line);
            string token;
            while (ss >> token) {
                arr.push_back(stoll(token));
            }
            if (arr.size() != n) {
                cerr << "Test case " << i << ": Expected " << n << " elements, got " << arr.size() << endl;
                continue;
            }
            

            long long steps = 0;
            for (int j = 1; j < n; j++) {
                if (arr[j] < arr[j-1]) {
                    steps += (arr[j-1] - arr[j]);
                    arr[j] = arr[j-1];
                }
            }

            getline(outputFile, line);
            long long result = stoll(line);
            cout << "Steps: " << steps << endl;
            result == steps ? cout << "Accepted" << endl : cout << "Failed on test case " << i << endl;
        } catch (const exception& e) {
            cerr << "Error in test case " << i << ": " << e.what() << endl;
            continue;
        }

        inputFile.close();
        outputFile.close();
    }
    return 0;
}