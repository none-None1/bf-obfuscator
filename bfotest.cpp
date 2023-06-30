#include "bf-obfuscator.h"
#include <fstream>
#include <iostream>
int main(int argc,char **argv) {
	if (argc < 3) return std::cout << "Usage: bfotest infile outfile",0;
	std::fstream f(argv[1],std::ios::in);
	std::fstream f2(argv[2], std::ios::out);
	std::string bf = "",t;
	while (std::getline(f, t)) {
		bf += t;
	}
	f2 << obfuscate(bf, 20, 20, REDUNDANT_ALL);
	return 0;
}