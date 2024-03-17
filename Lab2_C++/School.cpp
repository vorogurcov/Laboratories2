#include "Header.h"
using namespace std;

const int EquationAmount = 8;
const int SolutionsAmount = 2;

void Teacher::GetStudentsAnswers(std::vector<Student> Students)
{
	for (auto& Student : Students)
		StudentsAnswers.push_back(Student.GetSolutions());
};

void Teacher::GetScores()
{

}


void Teacher::GetCorrectSolution(std::ifstream Solutions)
{	
	vector<int> OneSol(SolutionsAmount);
	for (size_t i = 0; i < EquationAmount; i++)
	{
		for (size_t j = 0; j < SolutionsAmount; j++)
		{
			int TempSol;
			Solutions >> TempSol;
			OneSol.push_back(TempSol);
		}
		CorrectSolutions.push_back(OneSol);
	}
};

void Student::FindSolutions(std::ifstream Task)
{

};

void BadStudent::FindSolutions(std::ifstream Task)
{

};

void GoodStudent::FindSolutions(std::ifstream Task)
{

};

vector <Answer> Student::GetSolutions()
{
	return solution;
};