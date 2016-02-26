//
//  main.cpp
//  LCS
//
//  Created by Alok on 2/22/16.
//  Copyright © 2016 Alok. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


vector<string> input;
string line;
int line_count;
string str1;
string str2;
int arg_count;
int counter = 0;

void find_all_LCS(int m, int n)
{
    int L[m+1][n+1];
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (str1[i-1] == str2[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    
    int index = L[m][n];
    int LCS_length = L[m][n];
    
    char lcs[index+1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (str1[i-1] == str2[j-1])
        {
            lcs[index-1] = str1[i-1];
            i--;
            j--;
            index--;
        }
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    
    cout << LCS_length << " " << lcs << endl;
}

int main(int argc, const char * argv[]) {
    
    while(getline(cin,line)) {
        line_count = 0;
        string ss;
        istringstream iss(line);
        while(iss >> ss) {
            line_count++;
        }
        
        if (line_count > 2) {
            continue;
        }
        
        if(line_count == 1){
            arg_count = stoi(ss);
            continue;
        }
        
        istringstream iss2(line);
        iss2 >> str1 >> str2;
        if (!iss2) {
            iss2.clear();
            continue;
        }
        
        input.push_back(str1);
        input.push_back(str2);
        counter++;
        if(counter == arg_count){
            break;
        }
    }
    
    str1 = "";
    str2 = "";
    
    for(int i = 0; i < input.size(); i += 2){
        str1 = input[i];
        str2 = input[i+1];
        int str1_length = str1.length();
        int str2_length = str2.length();
        find_all_LCS(str1_length, str2_length);
    }

    return 0;
}
