#pragma once

#ifndef HEADER_H

#define HEADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class Answer
{
	int number;
	std::string surname;
	std::vector<int> solution;
};


class Student;

class Teacher
{
private:
	std::vector <std::vector<int>> CorrectSolutions;
	std::vector<std::vector<Answer>> StudentsAnswers;
	std::map<std::string, int> scores;
public:
	void GetCorrectSolution(std::ifstream Solutuons);
	void GetScores(); 
	void GetStudentsAnswers(std::vector<Student>);
};

class Student
{
private:
	std::vector <Answer> solution;
	std::string surname;
public:
	void FindSolutions(std::ifstream Task);
	std::vector <Answer> GetSolutions();
};

class BadStudent :public Student
{
public:
	void FindSolutions(std::ifstream Task);
};

class GoodStudent :public Student
{
public:
	void FindSolutions(std::ifstream Task);
};

#endif // !HEADER_H
