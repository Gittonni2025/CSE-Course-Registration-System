#include <iostream>
using namespace std;

#define SIZE 100

struct Student {
    string name;
    string course;
    int slot;
};

struct Teacher {
    string name;
    string course;
    int slot;
};

struct Assignment {
    string studentName;
    string course;
    string teacherName;
};

// Queue-like structure for results
class AssignmentQueue {
public:
    Assignment data[SIZE];
    int front, rear;

    AssignmentQueue() {
        front = 0;
        rear = 0;
    }

    void enqueue(string student, string course, string teacher) {
        if (rear >= SIZE) {
            cout << "Assignment queue full.\n";
            return;
        }
        data[rear++] = { student, course, teacher };
    }

    void display() {
        cout << "\n--- Final Assignments ---\n";
        for (int i = front; i < rear; i++) {
            cout << "Student: " << data[i].studentName
                 << ", Course: " << data[i].course
                 << ", Teacher: " << data[i].teacherName << endl;
        }
    }
};

int main() {
    Student students[SIZE];
    Teacher teachers[SIZE];
    AssignmentQueue assigned;
    int sCount, tCount;

    cout << "--- Course Registration System ---\n";

    // Input Students
    cout << "Enter number of students: ";
    cin >> sCount;
    cin.ignore();
    for (int i = 0; i < sCount; i++) {
        cout << "Enter student name: ";
        getline(cin, students[i].name);
        cout << "Enter course name: ";
        getline(cin, students[i].course);
        cout << "Enter slot number: ";
        cin >> students[i].slot;
        cin.ignore();
    }

    // Input Teachers
    cout << "\nEnter number of teachers: ";
    cin >> tCount;
    cin.ignore();
    for (int i = 0; i < tCount; i++) {
        cout << "Enter teacher name: ";
        getline(cin, teachers[i].name);
        cout << "Enter course name: ";
        getline(cin, teachers[i].course);
        cout << "Enter slot number: ";
        cin >> teachers[i].slot;
        cin.ignore();
    }

    // Matching logic
    for (int i = 0; i < sCount; i++) {
        bool matched = false;
        for (int j = 0; j < tCount; j++) {
            if (students[i].course == teachers[j].course &&
                students[i].slot == teachers[j].slot) {
                assigned.enqueue(students[i].name, students[i].course, teachers[j].name);
                matched = true;
                break;
            }
        }
        if (!matched) {
            cout << "\nStudent: " << students[i].name
                 << " - No match found. Try next sem.\n";
        }
    }

    // Display assignments
    assigned.display();

    return 0;
}
