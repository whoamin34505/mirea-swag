#include <iostream>
#include <vector>
#include <string>

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


int main(){
    std::vector<Student> students;
    students.push_back(Student("Bob", 5));
    students.push_back(Student("Eva", 2));
    students.push_back(Student("alex", 3));
    std::cout << "All students:\n";
    for (const Student& s : students) {
        s.printData();
    }
    std::cout << std::endl;
    
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
}