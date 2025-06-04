/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zblume <zblume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:41:07 by zblume            #+#    #+#             */
/*   Updated: 2025/04/14 10:45:31 by zblume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open input file " << filename << std::endl;
		return;
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: could not create output file " << filename + ".replace" << std::endl;
		inputFile.close();
		return;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while (true)
		{
			pos = line.find(s1, pos);
			if (pos == std::string::npos)
				break;
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line;
		if (!inputFile.eof())
			outputFile << '\n';
	}
	inputFile.close();
	outputFile.close();
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
	replaceInFile(filename, s1, s2);
	return 0;
}
