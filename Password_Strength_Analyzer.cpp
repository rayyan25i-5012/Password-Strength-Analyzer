#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Check common passwords using a simple array
bool isCommonPassword(const string& password){
    const string commonPasswords[] = {
        "123456", "password", "123456789", "qwerty",
        "abc123", "password123", "111111", "123123", "1234"
    };
int size = sizeof(commonPasswords) / sizeof(commonPasswords[0]);

    for (int i = 0; i < size; i++){
        if (password == commonPasswords[i])
            return true;}
    return false;
}

//Calculate entropy
double calculateEntropy(const string& password){
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, hasSpecial = false;

    for (char c : password){
        if (islower(c)) hasLower = true;
        else if (isupper(c)) hasUpper = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }

    int poolSize = 0;
    if (hasLower) poolSize += 26;
    if (hasUpper) poolSize += 26;
    if (hasDigit) poolSize += 10;
    if (hasSpecial) poolSize += 32;
    if (poolSize == 0) return 0;

    return password.length() * log2(poolSize);
}

int main(){
    string password;

    while (true){
        cout << "\nEnter your password = ";
        getline(cin, password);

        bool hasLower = false, hasUpper = false;
        bool hasDigit = false, hasSpecial = false;

        for (char c : password){
            if (islower(c)) hasLower = true;
            else if (isupper(c)) hasUpper = true;
            else if (isdigit(c)) hasDigit = true;
            else hasSpecial = true;
        }

        bool isValid = true;

        cout << "\n - - - Password Analysis - - -\n";

        if (password.length() < 8){
            cout << " Too short! (minimum 8 characters required)\n";
            isValid = false;
        }

        if (!hasLower){
            cout << " Add lowercase letters!\n";
            isValid = false;
        }

        if (!hasUpper){
            cout << " Add uppercase letters!\n";
            isValid = false;
        }

        if (!hasDigit){
            cout << " Add digits!\n";
            isValid = false;
        }

        if (!hasSpecial){
            cout << " Add special characters!\n";
            isValid = false;
        }

        if (isCommonPassword(password)){
            cout << " This is a common password! Extremely unsafe.\n";
            isValid = false;
        }

        if(!isValid){
            cout << "\nPlease try again :/\n";
            continue;
        }

        double entropy = calculateEntropy(password);
        cout << "\nEntropy = " << entropy << " bits\n";
        cout << "Password Accepted. Strong Password!\n";
        break;}
return 0;
}