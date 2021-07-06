#include <iostream>
#include <string>
#ifndef WAIFU_H
#define WAIFU_H
struct Waifu
{
	std::string Gender;
	std::string Race;
};
class MW
{
	private:
		int lineNumber;
	public:
		MW();
		~MW();
		void DeleteWaifu(struct Waifu W);
		int ListOfWaifu();
		int SelectWaifu(struct Waifu *&W);
		void PrintWaifu(struct Waifu *W);
		int ChangeWaifu(struct Waifu *&W);
		void CreateWaifu(struct Waifu*& W);
};
#endif

