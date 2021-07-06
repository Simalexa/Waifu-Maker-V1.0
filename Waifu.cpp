#include "Waifu.h"
#include <fstream>
#include <sstream>

MW::MW()
{
	lineNumber = 0;
};
MW::~MW()
{
};
void MW::DeleteWaifu(struct Waifu W)
{
};
int MW::ListOfWaifu()
{
	std::ifstream file;
	file.open("BD.txt");
	std::string ID, Gender, Race;
	while (file >> ID >> Gender >> Race)
	{
		std::cout << ID << " " << Gender << " " << Race << " " << std::endl;
		lineNumber++;
	}
	file.close();
	return 0;
}
int MW::SelectWaifu(struct Waifu *&W)
{
	int a;
	std::cout << "Select Waifu ID (print 0 to exit): " << std::endl;
	std::cin >> a;
	if (a > lineNumber)
	{
		std::cout << "Waifu not exist" << std::endl;
		return 0;
	}
	if (a == 0)
		return 0;
	if (a < lineNumber)
	{
		std::ifstream file;
		file.open("BD.txt");
		std::string WID, WGender, WRace;
		int number = 0;
		while (file >> WID >> WGender >> WRace)
		{
			if (a == number)
			{
				W = new Waifu;
				W->Gender = WGender;
				W->Race = WRace;
				PrintWaifu(W);
				return 0;
			}
			number++;
		}
		file.close();
		return 0;
	}
}
void MW::PrintWaifu(struct Waifu *W)
{
	if(W!=NULL)
		std::cout << "Gender: " << W->Gender << " Race: " << W->Race << std::endl;
}

int MW::ChangeWaifu(struct Waifu*& W)
{
	std::string change;
	std::ifstream file;
	int number = 0;
	file.open("PossibleMaker.txt");
	std::cout << "Change: ";
	std::cin >> change;
	if (change == "Gender")
	{
		number = 1;
	}
	else if (change == "Race")
	{
		number = 2;
	}
	else
	{
		std::cout << "Error" << std::endl;
		return 0;
	}

	std::string NewParameter, str, Word;
	int linecounter = 1;
	std::cin >> NewParameter;
		while (std::getline(file, str))
		{
			if (linecounter == number)
			{
					std::istringstream Words (str);
					while (Words >> Word)
					{
						if (Word == NewParameter)
							if (number == 1)
							{
								W->Gender = NewParameter;
								return 0;
							}
							if (number == 2)
							{
								W->Race = NewParameter;
								return 0;
							}
					}
			}
			linecounter++;
		}
	file.close();
	PrintWaifu(W);
}

void MW::CreateWaifu(struct Waifu*& W)
{
	std::string change;
	std::ifstream file;
	int linecounter = 0;
	W = new Waifu;
	file.open("PossibleMaker.txt");
	std::string NewParameter, str, Word;
	while (std::getline(file, str))
	{
		if (linecounter == 0)
		{
			std::cout << "Gender (print 0 to skip): ";
			std::cin >> NewParameter;
			if (NewParameter != "0")
			{
				std::istringstream Words(str);
				while (Words >> Word)
				{
					if (Word == NewParameter)
						W->Gender = NewParameter;
				}
				if (W->Gender == "")
					std::cout << "Error" << std::endl;
			}
		}
		if (linecounter == 1)
		{
			std::cout << "Race (print 0 to skip): ";
			std::cin >> NewParameter;
			if (NewParameter != "0")
			{
				std::istringstream Words(str);
				while (Words >> Word)
				{
					if (Word == NewParameter)
						W->Race = NewParameter;
				}
				if (W->Race == "")
					std::cout << "Error" << std::endl;
			}
		}
		linecounter++;
	}
	file.close();
	PrintWaifu(W);
}