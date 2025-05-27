#include <iostream>
#include <vector>
#include <string>
#include <span>
#include <algorithm>

class Student{
private:
    std::string name;
    int avg;
public:
    Student(): name(""), avg(0) {}
    Student(std::string a, int b): name(a), avg(b) {}
    
    std::string getName() const { return name; }
    int getAvg() const { return avg; }

    void setName(std::string newName) { name = newName; }
    void setAvg(int newAvg) { avg = newAvg; }

    void printData() const {
        std::cout << "Name: " << name << "; Avg. score: " << avg << std::endl;
    }



};


int main() {
    std::vector<Student> students;
    students.push_back(Student("Bob", 1));
    students.push_back(Student("Eva", 5));
    students.push_back(Student("alex", 2));
    std::cout << "All students:\n";
    for (const Student& s : students) {
        s.printData();
    }
    std::cout << std::endl;


    // 1. Iterate through students to find the best and the worst
    auto worst_it=students.begin(), best_it=students.begin();
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getAvg() < worst_it->getAvg()) {
            worst_it = it;
        }
        if (it->getAvg() > best_it->getAvg()) {
            best_it = it;
        }
    }

    worst_it->printData();
    std::cout<<std::endl;
    best_it->printData();


    // 2. Output of the sublist of students
    // to compile: g++ -std=c++20 main.cpp -o main
    // .\main.exe
    std::span<Student> sublist(&students[0], 3);
    std::cout << "Sublist of students:\n";
    for (const Student& s : sublist) {
        s.printData();
    }


    // 3. Updating the average score by name
    std::string nName = "Bob";
    int nAvg = 5;
    int flag = 0;
    for (Student& s : students) {
        if (s.getName() == nName) {
            s.setAvg(nAvg);
            flag = 1;
            std::cout << "Updated student: ";
            s.printData();
            break;
        }
    }
    if (flag==0) {
        std::cout << "No such student.";
    }


    // 4. Average score for the group
    int avgAll = 0;
    for (const Student& s : students) {
        avgAll+=s.getAvg();
    }
    std::cout << "Avg. score for the group = " << avgAll/students.size();


    // 5. Sort students by score in descending order
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) { return a.getAvg() > b.getAvg(); });
    for (const Student& s : students) {
        s.printData();
    }
}