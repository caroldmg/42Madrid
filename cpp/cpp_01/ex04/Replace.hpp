#pragma once

#include <iostream>
#include <fstream>

class Replace
{
	private:
		std::string		filename;
		std::ifstream	infile;
		std::ofstream	outfile;
		void			findOccurrence(std::string *line, std::string s1, std::string s2);
	public:
		Replace(std::string filename);
		~Replace();
		void			replaceString(std::string s1, std::string s2);
};