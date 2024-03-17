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
	for (auto& OneStudentAnswer : StudentsAnswers)
	{
		int score = 0;
		string StudentSurname = OneStudentAnswer[0].surname;//Since surname is the same in any string of the Answer, we can get any of them.
		for (auto& OneEquationAnswer : OneStudentAnswer)
			for (size_t i = 0; i < EquationAmount; i++)
				if (OneEquationAnswer.solution == CorrectSolutions[i])
					score++;
			
		scores.insert({ StudentSurname, score });
	}
}

void Teacher::PrintScores()
{
	for (auto& OneStudentScore : scores)
		cout << "Student: " << OneStudentScore.first << " has grades " << OneStudentScore.second << "/" << EquationAmount << endl;
};

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