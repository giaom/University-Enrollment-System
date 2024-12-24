#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Course;

class Student {
  friend class Course;
  friend class University;
  friend class EnrollmentSystem;

  // Class constructor accepts "ID First Last"
  explicit Student(string nameAndID);

  // Class Constructor
  Student(int id, string first, string last);

  // Uses studentInfo string
  friend ostream &operator<<(ostream &out, const Student &student);

  // Return the student’s info in “last_name, first_name (ID)” format
  string studentInfo() const;

  // Return true if succesfully added or already in course
  bool addCourse(Course *course);

  // Return true if sucesfully remove from course, or already not enrolled
  bool removeCourse(Course *course);

  // Return true if enrolled in course
  bool isInCourse(const Course *course);

  // Compares students' last names
  static int cmpLastName(string othersLastName);

  // Compare students IDs
  static int cmpID(string otherID);

private:
  // Student's have unique IDs
  int ID;

  // Stores first name
  string firstName;

  // Stores last and (possibly middle) name.
  string lastName;

  // Stores const pointers of classes the student is enrolled in
  // Maps courses to their respective IDs
  map<string, const Course *> courses;
};

#endif