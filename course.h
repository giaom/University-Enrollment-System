#ifndef COURSE_H
#define COURSE_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Student;

class Course {
  friend class Student;
  friend class University;
  friend class EnrollmentSystem;

  // Class constructor requires university name
  Course(string ident, string name);

  // Class deconstructor is in charge of deleting all pointers
  ~Course();

  // Returns class info in
  friend ostream &operator<<(ostream &out, const Course &course);

  // Return true if succesfully enrolled student
  bool addStudent(const Student *student);

  // Return true if sucesffully removed student
  bool removeStudent(int studentID);

  // Return class list sorted by last name of students
  string getClassListByLastName() const;

  // Return true if student is in course
  bool containsStudent(int studentID);

  // Return class list sorted by id of students
  string getClassListByID() const;

private:
  // The ID stores the course type and number
  string courseID;

  // The title excludes the ID and description
  string title;

  // Stores pointers of students enrolled in the course
  // Maps students to their respective IDs
  map<int, const Student *> studentsInCourse;
};

#endif
