#ifndef _EXAM_DETAILS_H_
#define _EXAM_DETAILS_H_

#include <iostream>
#include <string>

namespace mtm{

/* ExamDetails class */
class ExamDetails{
    private:
    int index;
    int month;
    int day;
    double time;
    int duration;
    std::string link;

    public:
    ExamDetails(int index, int month, int day, double time,int duration, std::string link = ""); 
    ExamDetails(const ExamDetails& exam) = default;
    ExamDetails& operator=(const ExamDetails& exam) = default;
    std::string getLink() const {
        return std::string(this->link);
    }
    void setLink(const std::string str){
        this->link = str;
    }
    bool operator<(const ExamDetails& exam) const;
    int operator-(const ExamDetails& exam) const;

    friend std::ostream& operator<<(std::ostream& , const ExamDetails& exam);

    /* static founction for mtm exam */
    static ExamDetails makeMatamExam();

    /*classes for error in date */
    class InvalidDateException{};
    class InvalidTimeException{};
    class InvalidArgsException{};
};

}

#endif //_EXAM_DETAILS_H_