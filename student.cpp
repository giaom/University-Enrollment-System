#include "student.h"
#include "course.h"

#include <sstream>

using namespace std;

Student::Student(int id, string first, string last)
    : ID(id), firstName(first), lastName(last) {}

ostream &operator<<(ostream &out, const Student &student) {
  string str = student.studentInfo();
  out << str;
  return out;
}

bool Student::addCourse(Course *course) {
  bool result = false;

  if (!isInCourse(course)) {
    courses[course->courseID] = course;
    result = true;
  }

  // result =
  //    (courses.insert(pair<string, Course>(course->courseID, course)).second);
  return result;
}

bool Student::removeCourse(Course *course) {
  ulong erased = courses.erase(course->courseID);
  return (erased > 0);
}

bool Student::isInCourse(const Course *course) {
  auto itr = course->studentsInCourse.find(ID);
  return (itr != course->studentsInCourse.end());
}

// Return the student’s info in “last_name, first_name (ID)” format
string Student::studentInfo() const {
  string studentStr = lastName + ", " + firstName;
  studentStr += " (" + to_string(ID) + ")";
  return studentStr;
}