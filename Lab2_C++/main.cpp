#include "Header.h"

using namespace std;
int main(int argc, char* argv[])
{
	NormalStudent S1("Frolov"), S2("Kuricin"), S3("Boyboy");
	BadStudent S4("Kapelkin"), S5("Sigmovich"), S6("Bulkin");
	GoodStudent S7("Bombin"), S8("Nervov"), S9("Sobachkin");
	Teacher Alla_Petrovna;
	srand(time(0));

	ifstream Solution("Solutions.txt");
	Alla_Petrovna.GetCorrectSolution(Solution);
	Solution.close();

	ifstream Task("Equations.txt");
	vector<Student*> Students = { &S1,&S2,&S3,&S4, &S5, &S6, &S7, &S8, &S9 };
	for (auto& pStudent : Students)
	{
		pStudent->FindSolutions(Task);
		Task.seekg(0, ios::beg);
	}

	Alla_Petrovna.GetStudentsAnswers(Students);
	Alla_Petrovna.GetScores();
	Alla_Petrovna.PrintScores();
	return 0;
}