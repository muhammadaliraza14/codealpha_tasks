#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAX_QUESTIONS = 5;
const int MAX_USERS = 10;

struct Question {
    string questionText;
    string options[4];
    char correctAnswer;
};

struct User {
    string username;
    int score;
};

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"A. Berlin", "B. Madrid", "C. Paris", "D. Rome"}, 'C'},
    {"What is 2 + 2?", {"A. 3", "B. 4", "C. 5", "D. 6"}, 'B'},
    {"Who is the author of 'Hamlet'?", {"A. Charles Dickens", "B. Jane Austen", "C. Mark Twain", "D. William Shakespeare"}, 'D'},
    {"What is the chemical symbol for water?", {"A. O2", "B. CO2", "C. H2O", "D. NaCl"}, 'C'},
    {"What is the largest planet in our solar system?", {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"}, 'C'}
};

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        cout << "User limit reached. Cannot register more users." << endl;
        return;
    }
    cout << "Enter username: ";
    cin >> users[userCount].username;
    cout << endl;
    users[userCount].score = 0;
    userCount++;
    cout << "User registered successfully!" << endl << endl;
}

void startQuiz(User &user) {
    char answer;
    cout << endl;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        cout << questions[i].questionText << endl << endl;
        for (int j = 0; j < 4; j++) {
            cout << questions[i].options[j] << endl;
        }
        cout << endl << "Enter your answer (A/B/C/D): ";
        cin >> answer;
        cout << endl;
        if (toupper(answer) == questions[i].correctAnswer) {
            user.score++;
        }
    }
}

void displayResults(User &user) {
    cout << endl << "Quiz completed!" << endl << endl;
    cout << "Your score: " << user.score << "/" << MAX_QUESTIONS << endl;
    cout << "Correct answers:" << endl;
    cout << endl;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        cout << questions[i].questionText << endl;
        cout << "Correct answer: " << questions[i].correctAnswer << endl;
        cout << endl;
    }
}

void loginUser() {
    string username;
    cout << "Enter username: ";
    cin >> username;
    cout << endl;
    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username) {
            cout << "Login successful!" << endl;
            startQuiz(users[i]);
            displayResults(users[i]);
            return;
        }
    }
    cout << endl << "User not found. Please register first." << endl;
}

int main() {
    int choice;
    do {
        cout << "1. Register \n2. Login and Start Quiz \n3. Exit \n \nEnter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again. \n" << endl;
        }
    } while (choice != 3);

    return 0;
}
