#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int Find_Three_Oklyk(char* str, int index = 0, int count = 0) {
    if (strlen(str) < 3 || str[index] == '\0') {
        return count;
    }

    if (str[index] == '!' && str[index + 1] == '!' && str[index + 2] == '!') {
        return Find_Three_Oklyk(str, index + 3, count + 1);
    }
    else {
        return Find_Three_Oklyk(str, index + 1, count);
    }
}

void Replace_Group_With_Oklyk(char* str, int index = 0) {
    if (str[index] == '\0' || str[index + 1] == '\0' || str[index + 2] == '\0') {
        return;
    }

    if (str[index] == '!' && str[index + 1] == '!' && str[index + 2] == '!') {
        str[index] = '*';
        str[index + 1] = '*';
        memmove(str + index + 2, str + index + 3, strlen(str + index + 3) + 1);
        Replace_Group_With_Oklyk(str, index);
    }
    else {
        Replace_Group_With_Oklyk(str, index + 1);
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    int result = Find_Three_Oklyk(str);
    cout << "Number of groups with three ! = " << result << endl;
    Replace_Group_With_Oklyk(str);
    cout << str << endl;
    return 0;
}