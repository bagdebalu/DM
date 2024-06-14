// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <sstream>
// #include<bits/stdc++.h>

// using namespace std;

// vector<int> readData(const string &filename)
// {
//     vector<int> data;
//     fstream file(filename, ios::in);

//     if (!file.is_open())
//     {
//         cerr << "Error in opening input file: " << filename << endl;
//         exit(1);
//     }

//     string line, value;
//     int lineCount = 0;

//     while (getline(file, line))
//     {
//         if (lineCount > 0)
//         {
//             stringstream ss(line);
//             getline(ss, value, ',');
//             data.push_back(stoi(value));
//         }
//         lineCount++;
//     }

//     file.close();
//     return data;
// }

// // float calculateCorrelationCoefficient(const vector<int> &a, const vector<int> &b)
// // {
// //     int n = a.size();
// //     int a_plus = 0, b_plus = 0, ab_plus = 0;

// //     for (int i = 0; i < n; i++)
// //     {
// //         a_plus += a[i] == 1 ? 1 : 0;
// //         b_plus += b[i] == 1 ? 1 : 0;
// //         ab_plus += (a[i] == 1 && b[i] == 1) ? 1 : 0;
// //     }

// //     if (a_plus == 0 || b_plus == 0)
// //     {
// //         return 0.0; // To handle cases where division by zero may occur
// //     }

// //     return static_cast<float>(ab_plus) / (a_plus * b_plus);
// // }

// float calculateCorrelationCoefficient(const vector<int> &a, const vector<int> &b)
// {
//     int n = a.size();
//     if (n != b.size() || n == 0)
//     {
//         cerr << "Error: Vectors a and b must be of the same non-zero length." << endl;
//         exit(1);
//     }

//     float mean_a = 0, mean_b = 0;
//     for (int i = 0; i < n; i++)
//     {
//         mean_a += a[i];
//         mean_b += b[i];
//     }
//     mean_a /= n;
//     mean_b /= n;

//     float sum_dev_a = 0, sum_dev_b = 0, sum_dev_prod = 0;
//     for (int i = 0; i < n; i++)
//     {
//         float dev_a = a[i] - mean_a;
//         float dev_b = b[i] - mean_b;
//         sum_dev_prod += dev_a * dev_b;
//         sum_dev_a += dev_a * dev_a;
//         sum_dev_b += dev_b * dev_b;
//     }

//     return sum_dev_prod / sqrt(sum_dev_a * sum_dev_b);
// }

// void writeCorrelationCoefficient(const string &filename, float corr_coeff)
// {
//     ofstream file(filename, ios::out);

//     if (!file.is_open())
//     {
//         cerr << "Error in opening output file: " << filename << endl;
//         exit(1);
//     }

//     file << "Pearson Correlation Coefficient"
//          << "," << corr_coeff << endl;
//     file.close();
// }

// int main()
// {
//     string inputFileName = "correlation_input.csv";
//     string outputFileName = "correlation_output.csv";

//     vector<int> a = readData(inputFileName);
//     vector<int> b = readData(inputFileName);

//     float corr_coeff = calculateCorrelationCoefficient(a, b);

//     writeCorrelationCoefficient(outputFileName, corr_coeff);

//     cout << "Correlation coefficient calculated and saved in '" << outputFileName << "'." << endl;

//     return 0;
// }

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

void readData(const string &filename, vector<int> &a, vector<int> &b)
{
    fstream file(filename, ios::in);

    if (!file.is_open())
    {
        cerr << "Error in opening input file: " << filename << endl;
        exit(1);
    }

    string line;
    int lineCount = 0;

    while (getline(file, line))
    {
        if (lineCount > 0)
        {
            stringstream ss(line);
            string value;

            getline(ss, value, ',');
            a.push_back(stoi(value));

            getline(ss, value, ',');
            b.push_back(stoi(value));
        }
        lineCount++;
    }

    file.close();
}

float calculateCorrelationCoefficient(const vector<int> &a, const vector<int> &b)
{
    int n = a.size();
    if (n != b.size() || n == 0)
    {
        cerr << "Error: Vectors a and b must be of the same non-zero length." << endl;
        exit(1);
    }

    float mean_a = 0, mean_b = 0;
    for (int i = 0; i < n; i++)
    {
        mean_a += a[i];
        mean_b += b[i];
    }
    mean_a /= n;
    mean_b /= n;

    float sum_dev_a = 0, sum_dev_b = 0, sum_dev_prod = 0;
    for (int i = 0; i < n; i++)
    {
        float dev_a = a[i] - mean_a;
        float dev_b = b[i] - mean_b;
        sum_dev_prod += dev_a * dev_b;
        sum_dev_a += dev_a * dev_a;
        sum_dev_b += dev_b * dev_b;
    }

    return sum_dev_prod / sqrt(sum_dev_a * sum_dev_b);
}

void writeCorrelationCoefficient(const string &filename, float corr_coeff)
{
    ofstream file(filename, ios::out);

    if (!file.is_open())
    {
        cerr << "Error in opening output file: " << filename << endl;
        exit(1);
    }

    file << "Pearson Correlation Coefficient," << corr_coeff << endl;
    file.close();
}

int main()
{
    string inputFileName = "correlation_input.csv";
    string outputFileName = "correlation_output.csv";

    vector<int> a, b;
    readData(inputFileName, a, b);

    float corr_coeff = calculateCorrelationCoefficient(a, b);

    writeCorrelationCoefficient(outputFileName, corr_coeff);

    cout << "Correlation coefficient calculated and saved in '" << outputFileName << "'." << endl;

    return 0;
}
