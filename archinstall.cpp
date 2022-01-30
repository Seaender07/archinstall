#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include "sources.h"

int main(void)
{
	std::cout << "\nWelcome to ArchInstall: a simple, lightweight ArchLinux installer!\n\n";

	std::cout << "Here there are some settings that are not supported and must be done by yourself.\n"
		<< "Before starting the installation you will need to:\n"
		<< "\t#1) Set the shell's keyboard layout;\n"
		<< "\t#2) Setup the wired/wireless connection;\n"
		<< "\t#3) Create and setup partitions.\n";

	std::cout << "\nIf you already did this, type \"YES\", otherwise \"no\".\n"
		<< "WARNING: You can always stop the process inserting CTRL+C, but this can leave your computer unable to boot.\n"
		<< "\nAre you ready? ";

	std::string ifinstall;
	std::cin >> ifinstall;

	if(ifinstall == "YES")
	{
		std::cout << "Install entered.\n";

		instmain();
	}
	else
	{
		std::cout << "Quitted.\n";
		return 1;
	}
}
