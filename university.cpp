#include "university.h"
#include "student.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Deconstructor
University::~University() {
  // Delete all dynamically allocated courses
  for (auto it = coursesInUni.begin(); it != coursesInUni.end(); ++it) {
    delete it->second;
  }
  coursesInUni.clear();

  // Delete all dynamically allocated students
  for (auto it = studentsInUni.begin(); it != studentsInUni.end(); ++it) {
    delete it->second;
  }
  studentsInUni.clear();
}

// Read the student list for current active university
// return true if file successfully read
bool University::readStudentList(const string &filename) {
  bool successfulRead = false;
  ifstream file(filename);

  if (file) {
    string currLine;

    while (getline(file, currLine)) {
      string currStr = currLine;
      istringstream iss(currStr);
      string curr = currLine;
      int id;
      string firstName;
      string lastName;

      if (!(iss >> id >> firstName >> lastName)) {
        continue;
      }

      if (studentsInUni.count(id) == 0) {
        // Add student to map if they DNE
        studentsInUni[id] = new Student(id, firstName, lastName);
      }
    }
    file.close();
    successfulRead = true;
  }

  return successfulRead;
}

// Read the course list for current active university
// return true if file successfully read
bool University::readCourseList(const string &filename) {
  bool successfulRead = false;
  ifstream file(filename);

  if (file) {
    string currLine;

    while (getline(file, currLine)) {
      string currStr = currLine;
      istringstream iss(currStr);
      string curr = currLine;
      string courseID;
      string courseName;

      if (!(iss >> courseID)) {
        continue;
      }
      courseName = currStr.substr(courseID.length() + 1);

      // check to see if course is already there
      if (coursesInUni.count(courseID) == 0) {
        // Add course to map
        coursesInUni[courseID] = new Course(courseID, courseName);
      }
    }

    file.close();
    successfulRead = true;
  }
  return successfulRead;
}

// Read the student enrollment information for current active university
// return true if file successfully read
bool University::readEnrollmentInfo(const string &filename) {
  bool successfulRead;

  ifstream file(filename);
  if (file) {
    int studentID;
    string courseID;

    while (file >> studentID >> courseID) {
      addCourse(studentID, courseID);
    }

    file.close();
    successfulRead = true;
  }

  return successfulRead;
}

// Drop student from given course, return true if successful
bool University::dropCourse(int studentID, const string &courseNumber) {
  bool successfulDrop = false;

  // Check if university has course
  if (coursesInUni.count(courseNumber) > 0) {
    if (studentsInUni.count(studentID) > 0) {
      Student *student = studentsInUni.at(studentID);
      Course *course = coursesInUni.at(courseNumber);

      student->removeCourse(course);
      successfulDrop = course->removeStudent(studentID);
    }
  }

  return successfulDrop;
}

// Add student to the given course, return true if successful
bool University::addCourse(int studentID, const string &courseNumber) {
  bool successfulAdd = false;

  // University must already contain course
  if (coursesInUni.count(courseNumber) > 0) {
    // University must already contain student
    if (studentsInUni.count(studentID) > 0) {
      Student *student = studentsInUni.at(studentID);
      Course *course = coursesInUni.at(courseNumber);

      // Add course and student to one another's containers
      successfulAdd =
          (student->addCourse(course) && course->addStudent(student));
    }
  }

  return successfulAdd;
}

// Return true if student is in the given course
bool University::isInCourse(int studentID, const string &courseNumber) const {
  bool found = false;

  // Check if uni has course
  if (coursesInUni.count(courseNumber) > 0) {
    Course *course = coursesInUni.at(courseNumber);

    // Check if course contains student
    if (course->containsStudent(studentID)) {
      found = true;
    }
  }

  return found;
}

// Return the courses student is enrolled in
// The returned courses are separated by commas and sorted by course name
string University::getEnrolledCourses(int studentID) const {
  string courses = "[";

  if (studentsInUni.count(studentID) > 0) {
    Student *student = studentsInUni.at(studentID);

    int j = 0;
    for (auto i : student->courses) {
      const Course *course = i.second;
      if (j++ > 0) {
        courses += ", ";
      }
      courses += course->courseID;
    }
  }

  courses += "]";
  return courses;
}

// Return the title for the course
string University::getCourseTitle(const string &courseNumber) {
  string courseTitle;

  if (coursesInUni.count(courseNumber) > 0) {
    courseTitle = coursesInUni.at(courseNumber)->title;
  }

  return courseTitle;
}

// Return class list sorted by last name of students
string University::getClassListByLastName(const string &courseNumber) const {
  string classes;

  if (coursesInUni.count(courseNumber) > 0) {
    Course *course = coursesInUni.at(courseNumber);
    classes = course->getClassListByLastName();

  } else {
    classes = "[]";
  }

  return classes;
}

// Return class list sorted by id of students
string University::getClassListByID(const string &courseNumber) const {
  string classes;

  if (coursesInUni.count(courseNumber) > 0) {
    Course *course = coursesInUni.at(courseNumber);
    classes = course->getClassListByID();

  } else {
    classes = "[]";
  }

  return classes;
}
