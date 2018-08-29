#include <iostream>
#include <string>
#include <fstream>

using namespace std;	

int main()
{
	class data{
	public:
		string jobName;
		string jobTalent;
		double jobPaid;
	};

	data badboyz[1000];
	int count = 0;

	ifstream inFile("C:\\Users\\cz162938\\Desktop\\badboys.txt");
	if(inFile.good())
	{
		while (!inFile.eof())
		{			
			inFile >> badboyz[count].jobName;
			inFile >> badboyz[count].jobTalent;
			inFile >> badboyz[count].jobPaid;							
			count++;
		}		 
	}
	inFile.close();

	while (true)
	{
		cout << "Bad Boys" << endl;
		//Menu
		cout << "1- Add a New Record " << endl;
		cout << "2- Display Talents By Job" << endl;
		cout << "3- Display All" << endl;
		cout << "0- Exit" << endl;

		//choice
		cout << "What do you want to do?" << endl;
		int choice;
		cin >> choice;

		//Add New Record
		if (choice == 1)
		{
			cout << "Enter job name: " << endl;
			cin >> badboyz[count].jobName;

			cout << "Enter talent name: " << endl;
			cin >> badboyz[count].jobTalent;

			cout << "Enter payment: " << endl;
			cin >> badboyz[count].jobPaid;

			count++;	

			ofstream outFile ("C:\\Users\\cz162938\\Desktop\\badboys.txt");
			for(int i = 0; i < count; i++)
			{
				outFile << badboyz[i].jobName << " ";
				outFile << badboyz[i].jobTalent << " "; 
				outFile << badboyz[i].jobPaid << endl;
			}
			outFile.close();
		}

		//Display Talents By Job
		if (choice == 2)
		{
			cout << "Enter job name: " << endl;
			string jobsName;
			cin >> jobsName;

			double sumjobs = 0;

			for (int i = 0; i < count; i++)
			{
				if (jobsName == badboyz[i].jobName)
				{					
					cout << badboyz[i].jobTalent << " $" << badboyz[i].jobPaid << endl;
					sumjobs += badboyz[i].jobPaid;							
				}				
			}
			//Total amount paid
			cout << "Total Amount Paid: $" << sumjobs << endl;

			//Average	
			double avg = sumjobs / count;				
			cout << "Average: " << avg << endl;

			//Maximum
			int max = 0;
			for (int i = 0; i < count; i++)
			{
				if (jobsName == badboyz[i].jobName && badboyz[i].jobPaid > max)
				{
					max = badboyz[i].jobPaid;
				}
			}
			cout << "Max: " << max << endl;

			//Minimum
			int min = 999;
			for (int i = 0; i < count; i++)
			{
				if (jobsName == badboyz[i].jobName && badboyz[i].jobPaid < min)
				{
					min = badboyz[i].jobPaid;
				}
			}
			cout << "Min: " << min << endl;
		}

		//Display All
		if (choice == 3)
		{
			for (int i = 0; i < count; i++)
			{
				cout << badboyz[i].jobName << " " << badboyz[i].jobTalent << " " <<  badboyz[i].jobPaid << endl;

				int repcount = count;
				if(repcount > 100)
				{
					repcount = 100;
				}
			}
		}

		//Break
		if (choice == 0)
		{
			break;
		}
	}

	system ("pause");
	return 0;
}