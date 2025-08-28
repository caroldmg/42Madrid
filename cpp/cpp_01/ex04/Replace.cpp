#include "Replace.hpp"

Replace::Replace(std::string filename)
{
	const std::string out = filename + ".replace";
	this->filename = filename;
	infile.open(filename, std::ifstream::in);
	if (!infile.is_open())
	{
		std::cout << "No se puede abrir el archivo de lectura" << std::endl;
		return ;
	}
	outfile.open(out.c_str(), std::ofstream::out);
	// outfile.open(out.c_str(), std::ios::out);
	if (!outfile)
	{
		infile.close();
		std::cout << "No se puede abrir el archivo de escritura" << std::endl;
		return ;
	}
}

Replace::~Replace()
{
	if (infile.is_open())
		infile.close();
	if (outfile.is_open())
		outfile.close();
}

void	Replace::findOccurrence(std::string *line, std::string s1, std::string s2)
{
	std::string newLine = *line;

	for (int i = newLine.find(s1);
		i != std::string::npos;
		i = newLine.find(s1, i + s2.length()))
	{
		newLine.erase(i, s1.length());
		newLine.insert(i, s2);
	}

	outfile.write(newLine.c_str(), newLine.length());
}

void	Replace::replaceString(std::string s1, std::string s2)
{
	std::string line;

	while (std::getline(infile, line))
	{
		findOccurrence(&line, s1, s2);
		outfile.write("\n", 1);
	}
}
