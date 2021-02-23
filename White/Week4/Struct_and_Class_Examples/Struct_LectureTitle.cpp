#include <iostream>

using namespace std;

struct Week
{
    string val;

    explicit Week(string new_val) : val(new_val)
    {}
};

struct Specialization
{
    string val;

    explicit Specialization(string new_val) : val(new_val)
    {}
};

struct Course
{
    string val;

    explicit Course(string new_val) : val(new_val)
    {}
};



struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization s, Course c, Week w)
  {
      specialization = s.val;
      course = c.val;
      week = w.val;
  }
};