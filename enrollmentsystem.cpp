#include "enrollmentsystem.h"
#include "university.h"

#include <cassert>
#include <map>
#include <vector>

using namespace std;

EnrollmentSystem::~EnrollmentSystem() {
  for (auto &itr : universities) {
    delete itr.second;
  }
}

bool EnrollmentSystem::addUniversity(const string &name) {
  // Check if the university already exists in the map
  if (universities.find(name) != universities.end()) {
    return false;
  }

  // Create a new university and add it to the map
  University *newUniversity = new University(name);
  universities[name] = newUniversity;
  return true;
}

bool EnrollmentSystem::setCurrentUniversity(const string &name) {
  // Check if the university exists in the map
  if (universities.find(name) == universities.end()) {
    return false;
  }

  // Set the current university
  currentUniversity = universities[name];
  return true;
}

string EnrollmentSystem::getUniversityName() const {
  if (nullptr != currentUniversity) {
    return currentUniversity->universityName;
  }
  return "";
}

bool EnrollmentSystem::readStudentList(const string &filename) {
  if (nullptr == currentUniversity) {
    return false;
  }
  return currentUniversity->readStudentList(filename);
}

bool EnrollmentSystem::readCourseList(const string &filename) {
  if (nullptr == currentUniversity) {
    return false;
  }
  return currentUniversity->readCourseList(filename);
}

bool EnrollmentSystem::readEnrollmentInfo(const string &filename) {
  if (nullptr == currentUniversity) {
    return false;
  }
  return currentUniversity->readEnrollmentInfo(filename);
}

bool EnrollmentSystem::dropCourse(int studentID, const string &courseNumber) {
  if (nullptr == currentUniversity) {
    return false;
  }
  return currentUniversity->dropCourse(studentID, courseNumber);
}

bool EnrollmentSystem::addCourse(int studentID, const string &courseNumber) {
  if (nullptr == currentUniversity) {
    return false;
  }
  return currentUniversity->addCourse(studentID, courseNumber);
}

bool EnrollmentSystem::isInCourse(int studentID,
                                  const string &courseNumber) const {
  if (nullptr == currentUniversity) {
    return false;
  }
  return currentUniversity->isInCourse(studentID, courseNumber);
}

string EnrollmentSystem::getEnrolledCourses(int studentID) const {
  if (nullptr == currentUniversity) {
    return "";
  }
  return currentUniversity->getEnrolledCourses(studentID);
}

string EnrollmentSystem::getCourseTitle(const string &courseNumber) {
  string courseTitle;

  if (nullptr != currentUniversity) {
    courseTitle = currentUniversity->getCourseTitle(courseNumber);
  }

  return courseTitle;
}

string
EnrollmentSystem::getClassListByLastName(const string &courseNumber) const {
  string classList;

  if (nullptr != currentUniversity) {
    classList = currentUniversity->getClassListByLastName(courseNumber);
  }
  return classList;
}

string EnrollmentSystem::getClassListByID(const string &courseNumber) const {
  string classList;

  if (nullptr != currentUniversity) {
    classList = currentUniversity->getClassListByID(courseNumber);
  }
  return classList;
}
