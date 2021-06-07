#include <iostream>
#include <string>
#include "ExamDetails.h"

#define MTM_details 234124,7,28,13.00,3,"https://tinyurl.com/59hzps6m"
const int number_of_month_in_year = 12;
const int number_of_days_in_month = 30;

namespace mtm {

using std::cout;
using std::endl;
using std::string;
using mtm::ExamDetails;

static bool IsTimeNotValid(double time);

ExamDetails::ExamDetails(int index, int month, int day, double time, int duration, std::string link)
{
    bool is_month_not_valid = (month > number_of_month_in_year || month < 1);
    bool is_day_not_valid = (day > number_of_days_in_month || day < 1) ;
    bool is_duration_not_valid = duration < 1 ;
    bool is_time_not_valid = IsTimeNotValid(time);

    if(is_month_not_valid || is_day_not_valid){
        throw InvalidDateException();
    }
    if(is_time_not_valid || is_duration_not_valid){ 
        throw InvalidTimeException();
    }
    if(is_time_not_valid){
        throw InvalidArgsException();
    }
    this->index = index;
    this->month = month;
    this->day = day;
    this->time = time;
    this->duration = duration;
    this->link = link;
}

ExamDetails makeMatamExam(){
    return ExamDetails(MTM_details);
}

bool ExamDetails::operator<(const ExamDetails& exam)const{
    if(this->month < exam.month){
        return true;
    }
    if((this->month == exam.month) && (this->day < exam.day)){
        return true;
    }
    return false;
}

int ExamDetails::operator-(const ExamDetails& exam) const {
    return this->day - exam.day;
}

std::ostream& operator<<(std::ostream& , const ExamDetails& exam){
    cout << "Course number:" << exam.index << endl << "Time" << exam.time <<
    endl << "Duration" << exam.duration << endl << "Zoom Link:" << exam.link << endl; 
}
}

//this is Jenia's ongoing project