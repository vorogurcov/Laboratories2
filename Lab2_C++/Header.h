#pragma once

#ifndef HEADER_H

#define HEADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class Teacher;
class Student;

class Answer
{
private:
	int number;
	std::string surname;
	std::vector<double> solution;
public:
	friend class Teacher;
	void FillTheAnswer(int number, std::string surname, std::vector<double> solution)
	{
		this->number = number;
		this->surname = surname;
		this->solution = solution;
	}
};




class Teacher
{
private:
	std::vector <std::vector<double>> CorrectSolutions;
	std::vector<std::vector<Answer>> StudentsAnswers;
	std::map<std::string, double> scores;
public:
	void GetCorrectSolution(std::ifstream& Solutuons);
	void GetScores(); 
	void PrintScores();
	void GetStudentsAnswers(std::vector<Student*>);
};

class Student
{
protected:
	std::vector <Answer> solution;
	std::string surname;
public:
	Student(std::string surname);
	virtual void FindSolutions(std::ifstream& Task) = 0;
	std::vector <Answer> GetSolutions();
};

class NormalStudent : public Student
{
	using Student::Student;
public:
	void FindSolutions(std::ifstream& Task) override;
};


class BadStudent : public Student
{
	using Student::Student;
public:
	void FindSolutions(std::ifstream& Task) override;
};

class GoodStudent :public Student
{
	using Student::Student;
public:
	void FindSolutions(std::ifstream& Task) override;
};

#endif // !HEADER_H
