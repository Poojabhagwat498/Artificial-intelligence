#include <iostream>
#include <string>
using namespace std;

int main() {
    string userInput;

    cout << "🤖 Chatbot: Hello! Welcome to Customer Support.\n";
    cout << "Type 'exit' to end chat.\n\n";

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        // Convert to lowercase (simple handling)
        for (char &c : userInput) {
            c = tolower(c);
        }

        if (userInput == "exit") {
            cout << "🤖 Chatbot: Thank you! Have a great day 😊\n";
            break;
        }
        else if (userInput.find("hello") != string::npos || userInput.find("hi") != string::npos) {
            cout << "🤖 Chatbot: Hello! How can I help you?\n";
        }
        else if (userInput.find("product") != string::npos) {
            cout << "🤖 Chatbot: We offer electronics, clothing, and accessories.\n";
        }
        else if (userInput.find("price") != string::npos) {
            cout << "🤖 Chatbot: Prices vary by product. Please specify the item.\n";
        }
        else if (userInput.find("order") != string::npos) {
            cout << "🤖 Chatbot: You can place an order through our website.\n";
        }
        else if (userInput.find("delivery") != string::npos) {
            cout << "🤖 Chatbot: Delivery takes 3-5 working days.\n";
        }
        else if (userInput.find("payment") != string::npos) {
            cout << "🤖 Chatbot: We accept UPI, cards, and net banking.\n";
        }
        else if (userInput.find("refund") != string::npos) {
            cout << "🤖 Chatbot: Refunds are processed within 5-7 days.\n";
        }
        else {
            cout << "🤖 Chatbot: Sorry, I didn't understand. Can you rephrase?\n";
        }
    }

    return 0;
}