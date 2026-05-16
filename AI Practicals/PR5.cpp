#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Utility to convert string to lowercase for easier matching
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    string input;
    cout << "--- Customer Support Bot ---" << endl;
    cout << "Type 'exit' to end the chat." << endl;
    cout << "Bot: Hello! How can I help you with your order today?" << endl;

    while (true) {
        cout << "You: ";
        getline(cin, input);
        string query = toLower(input);

        if (query == "exit" || query == "bye") {
            cout << "Bot: Thank you for visiting! Have a great day." << endl;
            break;
        }

        // Rule-based logic for common customer interactions
        if (query.find("status") != string::npos || query.find("order") != string::npos) {
            cout << "Bot: Please provide your order ID to check the status." << endl;
        } 
        else if (query.find("refund") != string::npos || query.find("return") != string::npos) {
            cout << "Bot: You can initiate a return within 30 days via our 'My Orders' page." << endl;
        } 
        else if (query.find("hours") != string::npos || query.find("open") != string::npos) {
            cout << "Bot: Our support team is available Monday to Friday, 9 AM - 6 PM." << endl;
        } 
        else if (query.find("hello") != string::npos || query.find("hi") != string::npos) {
            cout << "Bot: Hi there! How can I assist you today?" << endl;
        } 
        else {
            cout << "Bot: I'm sorry, I didn't quite catch that. Could you try rephrasing?" << endl;
        }
    }

    return 0;
}
