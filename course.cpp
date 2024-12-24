#include "course.h"
#include "student.h"
#include <algorithm>
#include <cassert>
#include <set>
#include <sstream>

using namespace std;

// Class constructor requires course ID and title
Course::Course(string ident, string name)
    : courseID(std::move(ident)), title(std::move(name)){};

Course::~Course() {
  // delete courseID;
  // delete title;
}

// Returns class info
ostream &operator<<(ostream &out, const Course &course) {
  out << course.courseID << " " << course.title;
  return out;
}

// Return true if succesfully enrolled student
bool Course::addStudent(const Student *student) {
  // Check if the student is already enrolled
  if (studentsInCourse.count(student->ID) > 0) {
    return false;
  }

  // Add the student to the course
  studentsInCourse[student->ID] = student;
  return true;
}

// Return true if sucesffully removed student
bool Course::removeStudent(int studentID) {
  // Check if the student is enrolled in the course
  if (studentsInCourse.count(studentID) == 0) {
    return false;
  }

  // Remove the student from the course
  studentsInCourse.erase(studentID);
  return true;
}

// Return true if student is in course
bool Course::containsStudent(int studentID) {
  return (studentsInCourse.count(studentID) > 0);
}

// Return class list sorted by last name of students
string Course::getClassListByLastName() const {
  string students = "[";
  set<string> studentSet;

  for (auto itr : studentsInCourse) {
    const Student student = *(itr.second);
    studentSet.insert(student.studentInfo());
  }

  // https://www.geeksforgeeks.org/set-vs-unordered_set-c-stl/
  // By default, elements will be sorted in ascending order
  int index = 0;
  for (auto studentInfo : studentSet) {
    if (index++ > 0) {
      students += ", ";
    }
    students += studentInfo;
  }

  students += "]";
  return students;
}

// Return class list sorted by id of students
string Course::getClassListByID() const {
  // https://www.geeksforgeeks.org/map-vs-unordered_map-c/
  // By default, maps are ordered in increasing order of keys.
  // Since the map uses the student IDs as keys, students are already "sorted"
  string students = "[";

  int index = 0;
  for (auto itr = studentsInCourse.begin(); itr != studentsInCourse.end();
       itr++) {
    const Student student = *(itr->second);
    if (index++ > 0) {
      students += ", ";
    }
    students += student.studentInfo();
  }

  students += "]";
  return students;
}
