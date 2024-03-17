#include "Header.h"
#include "SquareEquationHeader.h"
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
	vector<double> OneSol(SolutionsAmount);
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

Student::Student(string surname)
{
	this->surname = surname;
};
void Student::FindSolutions(std::ifstream Task)
{
	Answer SomeAnswer;
	Equation* OurEquation = new Equation;
	Solution* OurSolution = new Solution;


	for (size_t i = 0; i < SolutionsAmount; i++)
	{

		double a, b, c;
		Task >> a >> b >> c;
		GetParameters(OurEquation, a, b, c);
		GetSolution(OurEquation, OurSolution);
		vector<double> sol;

		srand(time(0));
		((rand() % 100) < 55) ? sol = { OurSolution->x1, OurSolution->x2 } : sol = { 0, 0 };

		SomeAnswer.FillTheAnswer(i, surname, sol );
		solution.push_back(SomeAnswer);
	}
};

void BadStudent::FindSolutions(std::ifstream Task)
{
	Answer SomeAnswer;
	for (size_t i = 0; i < SolutionsAmount; i++)
	{
		SomeAnswer.FillTheAnswer(i, surname, { 0,0 });
		solution.push_back(SomeAnswer);
	}
};


void GoodStudent::FindSolutions(ifstream Task)
{
	Answer SomeAnswer;
	Equation* OurEquation = new Equation;
	Solution* OurSolution = new Solution;

	
	for (size_t i = 0; i < SolutionsAmount; i++)
	{

		double a, b, c;
		Task >> a >> b >> c;
		GetParameters(OurEquation, a, b, c);
		GetSolution(OurEquation, OurSolution);

		SomeAnswer.FillTheAnswer(i, surname, { OurSolution->x1,OurSolution->x2 });
		solution.push_back(SomeAnswer);
	}
};

vector <Answer> Student::GetSolutions()
{
	return solution;
};