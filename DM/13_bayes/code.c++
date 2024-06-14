


// // // // #include <iostream>
// // // // #include <fstream>
// // // // #include <sstream>
// // // // #include <string>
// // // // #include <map>
// // // // #include <vector>
// // // // #include <algorithm>

// // // // using namespace std;

// // // // // Function to trim whitespace from the beginning and end of a string
// // // // string trim(const string& str) {
// // // //     size_t first = str.find_first_not_of(" \t\n\r");
// // // //     if (string::npos == first) {
// // // //         return str;
// // // //     }
// // // //     size_t last = str.find_last_not_of(" \t\n\r");
// // // //     return str.substr(first, (last - first + 1));
// // // // }

// // // // int main() {
// // // //     ifstream inputFile("bayes.csv");

// // // //     if (!inputFile.is_open()) {
// // // //         cerr << "Failed to open file." << endl;
// // // //         return 1;
// // // //     }

// // // //     // Maps to store probabilities
// // // //     map<pair<string,string>, double> r1, r2, r3, r4, r5;
// // // //     map<string, int> mp;
// // // //     int tot = 0;

// // // //     // Read header
// // // //     string line;
// // // //     getline(inputFile, line);

// // // //     // Process each line in the file
// // // //     while (getline(inputFile, line)) {
// // // //         istringstream ss(line);
// // // //         string token;
// // // //         char delimiter = ',';
// // // //         size_t ind = 0;
// // // //         string name, bloodType, giveBirth, canFly, liveInWater, classAttribute, animalClass;

// // // //         while (getline(ss, token, delimiter)) {
// // // //             if (ind == 0) {
// // // //                 name = trim(token);
// // // //             } else if (ind == 1) {
// // // //                 bloodType = trim(token);
// // // //             } else if (ind == 2) {
// // // //                 giveBirth = trim(token);
// // // //             } else if (ind == 3) {
// // // //                 canFly = trim(token);
// // // //             } else if (ind == 4) {
// // // //                 liveInWater = trim(token);
// // // //             } else if (ind == 5) {
// // // //                 classAttribute = trim(token);
// // // //             } else if (ind == 6) {
// // // //                 animalClass = trim(token);
// // // //             }
// // // //             ind++;
// // // //         }

// // // //         // Update counts and probabilities
// // // //         mp[animalClass]++;
// // // //         r1[{bloodType, animalClass}]++;
// // // //         r2[{giveBirth, animalClass}]++;
// // // //         r3[{canFly, animalClass}]++;
// // // //         r4[{liveInWater, animalClass}]++;
// // // //         r5[{classAttribute, animalClass}]++;
// // // //         tot++;
// // // //     }

// // // //     // Close the input file
// // // //     inputFile.close();

// // // //     // Calculate probabilities for each attribute
// // // //     for (auto& it : r1) {
// // // //         string attr = it.first.first;
// // // //         string outcome = it.first.second;
// // // //         double val = it.second;
// // // //         double update = (val) / (double) mp[outcome];
// // // //         r1[{attr, outcome}] = update;
// // // //     }

// // // //     for (auto& it : r2) {
// // // //         string attr = it.first.first;
// // // //         string outcome = it.first.second;
// // // //         double val = it.second;
// // // //         double update = (val) / (double) mp[outcome];
// // // //         r2[{attr, outcome}] = update;
// // // //     }

// // // //     for (auto& it : r3) {
// // // //         string attr = it.first.first;
// // // //         string outcome = it.first.second;
// // // //         double val = it.second;
// // // //         double update = (val) / (double) mp[outcome];
// // // //         r3[{attr, outcome}] = update;
// // // //     }

// // // //     for (auto& it : r4) {
// // // //         string attr = it.first.first;
// // // //         string outcome = it.first.second;
// // // //         double val = it.second;
// // // //         double update = (val) / (double) mp[outcome];
// // // //         r4[{attr, outcome}] = update;
// // // //     }

// // // //     for (auto& it : r5) {
// // // //         string attr = it.first.first;
// // // //         string outcome = it.first.second;
// // // //         double val = it.second;
// // // //         double update = (val) / (double) mp[outcome];
// // // //         r5[{attr, outcome}] = update;
// // // //     }

// // // //     // New instance to classify (user input)
// // // //     string name, bloodType, giveBirth, canFly, liveInWater;

// // // //     cout << "Enter the details of the new instance:" << endl;
// // // //     cout << "Name: ";
// // // //     getline(cin, name);
// // // //     cout << "Blood Type (warm/cold): ";
// // // //     getline(cin, bloodType);
// // // //     cout << "Give Birth (yes/no): ";
// // // //     getline(cin, giveBirth);
// // // //     cout << "Can Fly (yes/no): ";
// // // //     getline(cin, canFly);
// // // //     cout << "Live in Water (yes/no/sometimes): ";
// // // //     getline(cin, liveInWater);

// // // //     double max_prob_mammal = 0.0;
// // // //     double max_prob_not_mammal = 0.0;
// // // //     string result;

// // // //     // Calculate probabilities for each outcome (mammal or not mammal)
// // // //     for (auto& it : mp) {
// // // //         string outcome = it.first;
// // // //         double prob = (it.second / (double) tot) *
// // // //                      r1[{bloodType, outcome}] *
// // // //                      r2[{giveBirth, outcome}] *
// // // //                      r3[{canFly, outcome}] *
// // // //                      r4[{liveInWater, outcome}];

// // // //         if (outcome == "mammals" && prob > max_prob_mammal) {
// // // //             max_prob_mammal = prob;
// // // //             result = "mammal";
// // // //         } else if (outcome != "mammals" && prob > max_prob_not_mammal) {
// // // //             max_prob_not_mammal = prob;
// // // //             result = "not mammal";
// // // //         }
// // // //     }

// // // //     // Output the result
// // // //     cout << "For Animal: " << name << ", Blood Type: " << bloodType
// // // //          << ", Give Birth: " << giveBirth << ", Can Fly: " << canFly
// // // //          << ", Live in Water: " << liveInWater << endl;
// // // //     cout << "The predicted class: " << result << endl;

// // // //     return 0;
// // // // }

// // // #include <iostream>
// // // #include <fstream>
// // // #include <sstream>
// // // #include <string>
// // // #include <vector>
// // // #include <map>
// // // #include <unordered_map>
// // // #include <algorithm>
// // // #include <iomanip>

// // // using namespace std;

// // // // Function to trim whitespace from a string
// // // string trim(const string& str) {
// // //     size_t first = str.find_first_not_of(" \t\n\r");
// // //     if (string::npos == first) {
// // //         return str;
// // //     }
// // //     size_t last = str.find_last_not_of(" \t\n\r");
// // //     return str.substr(first, (last - first + 1));
// // // }

// // // int main() {
// // //     ifstream file("bayes.csv");
// // //     if (!file.is_open()) {
// // //         cerr << "Failed to open bayes.csv" << endl;
// // //         return 1;
// // //     }

// // //     // Data structures to store counts for each attribute and class
// // //     map<string, double> classCounts;
// // //     map<string, unordered_map<string, double>> attributeCounts[5];
// // //     unordered_map<string, int> totalClassCounts;
// // //     int totalCount = 0;

// // //     // Read and process each line in bayes.csv
// // //     string line;
// // //     vector<string> headers;
// // //     bool firstLine = true;
// // //     while (getline(file, line)) {
// // //         stringstream ss(line);
// // //         string token;
// // //         vector<string> tokens;

// // //         // Split the line by commas
// // //         while (getline(ss, token, ',')) {
// // //             tokens.push_back(trim(token));
// // //         }

// // //         if (firstLine) {
// // //             headers = tokens;
// // //             firstLine = false;
// // //         } else {
// // //             string classAttribute = tokens.back();
// // //             classCounts[classAttribute]++;
// // //             totalClassCounts[classAttribute]++;
// // //             totalCount++;

// // //             // Count occurrences of each attribute given the class attribute
// // //             for (size_t i = 1; i < tokens.size() - 1; ++i) {
// // //                 attributeCounts[i][tokens[i]][classAttribute]++;
// // //             }
// // //         }
// // //     }

// // //     file.close();

// // //     // Prompt user for a new instance and classify it
// // //     cout << "Enter the details of the new instance:" << endl;
// // //     string name, bloodType, giveBirth, canFly, liveInWater;
// // //     cout << "Name: ";
// // //     cin >> name;
// // //     cout << "Blood Type (warm/cold): ";
// // //     cin >> bloodType;
// // //     cout << "Give Birth (yes/no): ";
// // //     cin >> giveBirth;
// // //     cout << "Can Fly (yes/no): ";
// // //     cin >> canFly;
// // //     cout << "Live in Water (yes/no/sometimes): ";
// // //     cin >> liveInWater;

// // //     // Calculate probabilities for each class
// // //     vector<pair<string, double>> probabilities;
// // //     for (auto& classEntry : classCounts) {
// // //         string className = classEntry.first;
// // //         double priorProbability = classEntry.second / totalCount;

// // //         double conditionalProbability = 1.0;
// // //         conditionalProbability *= attributeCounts[1][bloodType][className] / classCounts[className];
// // //         conditionalProbability *= attributeCounts[2][giveBirth][className] / classCounts[className];
// // //         conditionalProbability *= attributeCounts[3][canFly][className] / classCounts[className];
// // //         conditionalProbability *= attributeCounts[4][liveInWater][className] / classCounts[className];

// // //         double posteriorProbability = priorProbability * conditionalProbability;
// // //         probabilities.push_back({className, posteriorProbability});
// // //     }

// // //     // Find the predicted class with the highest probability
// // //     string predictedClass;
// // //     double maxProbability = 0.0;
// // //     for (auto& prob : probabilities) {
// // //         if (prob.second > maxProbability) {
// // //             maxProbability = prob.second;
// // //             predictedClass = prob.first;
// // //         }
// // //     }

// // //     // Output the results
// // //     cout << "\nFor Animal: " << name << ", Blood Type: " << bloodType << ", Give Birth: " << giveBirth
// // //          << ", Can Fly: " << canFly << ", Live in Water: " << liveInWater << endl;
// // //     cout << "The predicted class: " << predictedClass << endl;

// // //     return 0;
// // // }

// // #include <iostream>
// // #include <fstream>
// // #include <sstream>
// // #include <string>
// // #include <vector>
// // #include <map>
// // #include <unordered_map>
// // #include <algorithm>
// // #include <iomanip>

// // using namespace std;

// // // Function to trim whitespace from a string
// // string trim(const string& str) {
// //     size_t first = str.find_first_not_of(" \t\n\r");
// //     if (string::npos == first) {
// //         return str;
// //     }
// //     size_t last = str.find_last_not_of(" \t\n\r");
// //     return str.substr(first, (last - first + 1));
// // }

// // int main() {
// //     ifstream file("bayes.csv");
// //     if (!file.is_open()) {
// //         cerr << "Failed to open bayes.csv" << endl;
// //         return 1;
// //     }

// //     // Data structures to store counts for each attribute and class
// //     map<string, double> classCounts;
// //     map<string, unordered_map<string, double>> attributeCounts[5];
// //     unordered_map<string, int> totalClassCounts;
// //     int totalCount = 0;

// //     // Read and process each line in bayes.csv
// //     string line;
// //     vector<string> headers;
// //     bool firstLine = true;
// //     while (getline(file, line)) {
// //         stringstream ss(line);
// //         string token;
// //         vector<string> tokens;

// //         // Split the line by commas
// //         while (getline(ss, token, ',')) {
// //             tokens.push_back(trim(token));
// //         }

// //         if (firstLine) {
// //             headers = tokens;
// //             firstLine = false;
// //         } else {
// //             string classAttribute = tokens.back();
// //             classCounts[classAttribute]++;
// //             totalClassCounts[classAttribute]++;
// //             totalCount++;

// //             // Count occurrences of each attribute given the class attribute
// //             for (size_t i = 1; i < tokens.size() - 1; ++i) {
// //                 attributeCounts[i][tokens[i]][classAttribute]++;
// //             }
// //         }
// //     }

// //     file.close();

// //     // Prompt user for a new instance and classify it
// //     cout << "Enter the details of the new instance:" << endl;
// //     string name, bloodType, giveBirth, canFly, liveInWater;
// //     cout << "Name: ";
// //     cin >> name;
// //     cout << "Blood Type (warm/cold): ";
// //     cin >> bloodType;
// //     cout << "Give Birth (yes/no): ";
// //     cin >> giveBirth;
// //     cout << "Can Fly (yes/no): ";
// //     cin >> canFly;
// //     cout << "Live in Water (yes/no/sometimes): ";
// //     cin >> liveInWater;

// //     // Calculate probabilities for each class
// //     vector<pair<string, double>> probabilities;
// //     for (auto& classEntry : classCounts) {
// //         string className = classEntry.first;
// //         double priorProbability = classEntry.second / totalCount;

// //         double conditionalProbability = 1.0;
// //         conditionalProbability *= (attributeCounts[1][bloodType][className] + 1) / (classCounts[className] + 2);
// //         conditionalProbability *= (attributeCounts[2][giveBirth][className] + 1) / (classCounts[className] + 2);
// //         conditionalProbability *= (attributeCounts[3][canFly][className] + 1) / (classCounts[className] + 2);
// //         conditionalProbability *= (attributeCounts[4][liveInWater][className] + 1) / (classCounts[className] + 2);

// //         double posteriorProbability = priorProbability * conditionalProbability;
// //         probabilities.push_back({className, posteriorProbability});
// //     }

// //     // Find the predicted class with the highest probability
// //     string predictedClass;
// //     double maxProbability = 0.0;
// //     for (auto& prob : probabilities) {
// //         if (prob.second > maxProbability) {
// //             maxProbability = prob.second;
// //             predictedClass = prob.first;
// //         }
// //     }

// //     // Output the results
// //     cout << "\nFor Animal: " << name << ", Blood Type: " << bloodType << ", Give Birth: " << giveBirth
// //          << ", Can Fly: " << canFly << ", Live in Water: " << liveInWater << endl;
// //     cout << "The predicted class: " << predictedClass << endl;

// //     return 0;
// // }

// #include <bits/stdc++.h>
// #include <sstream>
// #include <fstream>
// #include <cctype>
// #include <string>
// #include <algorithm>

// using namespace std;

// string trim(const string& str) {
//     size_t first = str.find_first_not_of(" \t\n\r");
//     if (string::npos == first) {
//         return str;
//     }
//     size_t last = str.find_last_not_of(" \t\n\r");
//     return str.substr(first, (last - first + 1));
// }

// int main() {
//     ifstream inputFile("bayes.csv");

//     if (!inputFile.is_open()) {
//         cerr << "Failed to open file." << endl;
//         return 1;
//     }

//     string line;
//     getline(inputFile, line); // Read header line
//     map<pair<string, string>, double> r1, r2, r3, r4, r5;
//     unordered_map<string, int> mp;
//     int tot = 0;

//     while (getline(inputFile, line)) {
//         istringstream ss(line);
//         string token;
//         char delimiter = ',';
//         size_t ind = 0;
//         string name, bloodType, giveBirth, canFly, liveInWater, classAttribute, animalClass;

//         while (getline(ss, token, delimiter)) {
//             if (ind == 0) {
//                 name = trim(token);
//             } else if (ind == 1) {
//                 bloodType = trim(token);
//             } else if (ind == 2) {
//                 giveBirth = trim(token);
//             } else if (ind == 3) {
//                 canFly = trim(token);
//             } else if (ind == 4) {
//                 liveInWater = trim(token);
//             } else if (ind == 5) {
//                 classAttribute = trim(token);
//             } else if (ind == 6) {
//                 animalClass = trim(token);
//             }
//             ind++;
//         }

//         mp[animalClass]++;
//         r1[{bloodType, animalClass}]++;
//         r2[{giveBirth, animalClass}]++;
//         r3[{canFly, animalClass}]++;
//         r4[{liveInWater, animalClass}]++;
//         r5[{classAttribute, animalClass}]++;
//         tot++;
//     }
//     inputFile.close();

//     for (auto it : r1) {
//         string col = it.first.first;
//         string spe = it.first.second;
//         double val = it.second;
//         double update = (val) / (double)mp[spe];
//         r1[{col, spe}] = update;
//     }

//     for (auto it : r2) {
//         string col = it.first.first;
//         string spe = it.first.second;
//         double val = it.second;
//         double update = (val) / (double)mp[spe];
//         r2[{col, spe}] = update;
//     }

//     for (auto it : r3) {
//         string col = it.first.first;
//         string spe = it.first.second;
//         double val = it.second;
//         double update = (val) / (double)mp[spe];
//         r3[{col, spe}] = update;
//     }

//     for (auto it : r4) {
//         string col = it.first.first;
//         string spe = it.first.second;
//         double val = it.second;
//         double update = (val) / (double)mp[spe];
//         r4[{col, spe}] = update;
//     }

//     for (auto it : r5) {
//         string col = it.first.first;
//         string spe = it.first.second;
//         double val = it.second;
//         double update = (val) / (double)mp[spe];
//         r5[{col, spe}] = update;
//     }

//     // Calculate for new value

//     string name, bloodType, giveBirth, canFly, liveInWater;
//     cout << "Enter the details of the new instance:\n";
//     cout << "Name: ";
//     cin >> name;
//     cout << "Blood Type (warm/cold): ";
//     cin >> bloodType;
//     cout << "Give Birth (yes/no): ";
//     cin >> giveBirth;
//     cout << "Can Fly (yes/no): ";
//     cin >> canFly;
//     cout << "Live in Water (yes/no/sometimes): ";
//     cin >> liveInWater;

//     double ans = 0;
//     string res;
//     vector<pair<string, double>> all;

//     for (auto it : mp) {
//         string s = it.first;
//         int get = it.second;
//         double prob = (get / (double)tot) *
//                       (r1[{bloodType, s}]) *
//                       (r2[{giveBirth, s}]) *
//                       (r3[{canFly, s}]) *
//                       (r4[{liveInWater, s}]);
//         all.push_back({s, prob});
//         if (ans < prob) {
//             ans = prob;
//             res = s;
//         }
//     }
//     for (int i = 0; i < all.size(); i++) {
//         cout << all[i].first << " " << all[i].second << endl;
//     }
//     cout << endl;
//     cout << "For Animal: " << name << ", Blood Type: " << bloodType << ", Give Birth: " << giveBirth << ", Can Fly: " << canFly << ", Live in Water: " << liveInWater << endl;
//     cout << "The predicted class: " << res << endl;

//     return 0;
// }

#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

int main() {
    ifstream inputFile("bayes.csv");

    if (!inputFile.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string line;
    getline(inputFile, line); // Read header line
    map<pair<string, string>, double> r1, r2, r3, r4, r5;
    unordered_map<string, int> mp;
    int tot = 0;

    while (getline(inputFile, line)) {
        istringstream ss(line);
        string token;
        char delimiter = ',';
        size_t ind = 0;
        string name, bloodType, giveBirth, canFly, liveInWater, classAttribute, animalClass;

        while (getline(ss, token, delimiter)) {
            if (ind == 0) {
                name = trim(token);
            } else if (ind == 1) {
                bloodType = trim(token);
            } else if (ind == 2) {
                giveBirth = trim(token);
            } else if (ind == 3) {
                canFly = trim(token);
            } else if (ind == 4) {
                liveInWater = trim(token);
            } else if (ind == 5) {
                classAttribute = trim(token);
            } else if (ind == 6) {
                animalClass = trim(token);
            }
            ind++;
        }

        mp[animalClass]++;
        r1[{bloodType, animalClass}]++;
        r2[{giveBirth, animalClass}]++;
        r3[{canFly, animalClass}]++;
        r4[{liveInWater, animalClass}]++;
        r5[{classAttribute, animalClass}]++;
        tot++;
    }
    inputFile.close();

    for (auto it : r1) {
        string col = it.first.first;
        string spe = it.first.second;
        double val = it.second;
        double update = (val) / (double)mp[spe];
        r1[{col, spe}] = update;
    }

    for (auto it : r2) {
        string col = it.first.first;
        string spe = it.first.second;
        double val = it.second;
        double update = (val) / (double)mp[spe];
        r2[{col, spe}] = update;
    }

    for (auto it : r3) {
        string col = it.first.first;
        string spe = it.first.second;
        double val = it.second;
        double update = (val) / (double)mp[spe];
        r3[{col, spe}] = update;
    }

    for (auto it : r4) {
        string col = it.first.first;
        string spe = it.first.second;
        double val = it.second;
        double update = (val) / (double)mp[spe];
        r4[{col, spe}] = update;
    }

    for (auto it : r5) {
        string col = it.first.first;
        string spe = it.first.second;
        double val = it.second;
        double update = (val) / (double)mp[spe];
        r5[{col, spe}] = update;
    }

    // Calculate for new value

    string name, bloodType, giveBirth, canFly, liveInWater;
    cout << "Enter the details of the new instance:\n";
    cout << "Name: ";
    cin >> name;
    cout << "Blood Type (warm/cold): ";
    cin >> bloodType;
    cout << "Give Birth (yes/no): ";
    cin >> giveBirth;
    cout << "Can Fly (yes/no): ";
    cin >> canFly;
    cout << "Live in Water (yes/no/sometimes): ";
    cin >> liveInWater;

    double ans = 0;
    string res;
    vector<pair<string, double>> all;

    for (auto it : mp) {
        string s = it.first;
        int get = it.second;
        double prob = (get / (double)tot) *
                      (r1[{bloodType, s}]) *
                      (r2[{giveBirth, s}]) *
                      (r3[{canFly, s}]) *
                      (r4[{liveInWater, s}]);
        all.push_back({s, prob});
        cout << "Class: " << s << " Probability: " << prob << endl; // Debug statement
        if (ans < prob) {
            ans = prob;
            res = s;
        }
    }
    for (int i = 0; i < all.size(); i++) {
        cout << all[i].first << " " << all[i].second << endl;
    }
    cout << endl;
    cout << "For Animal: " << name << ", Blood Type: " << bloodType << ", Give Birth: " << giveBirth << ", Can Fly: " << canFly << ", Live in Water: " << liveInWater << endl;
    cout << "The predicted class: " << res << endl;

    return 0;
}

