#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include "sources.h"

int part::mkfs(std::string fst, std::string part)
{
	std::cout << "\nCreating " << part << " filesystem...\n";
	utils::logmsg("Creating " + part + " filesystem...");

	std::string tomake_s = (fst == "swap" ? "mkswap" : "mkfs." + fst) + " " + part;

	std::cout << utils::logop(tomake_s) << std::endl;

	system(utils::logop(tomake_s).c_str());							//	< ---------------------------------------
	
	std::cout << "Done.\n";
	utils::logmsg("Done.");

	return 0;
}

int part::mount(std::string mnt, std::string swap)
{
	std::cout << "\nMounting Partitions...\n";
	utils::logmsg("Mounting Partitions...");

	std::string tomnt_s = "mount " + mnt + " /mnt";
	std::string toswap_s = "swapon " + swap;

	std::cout << utils::logop("sample_command") << std::endl;

	system(utils::logop(tomnt_s).c_str());							//	< ---------------------------------------
	system(utils::logop(toswap_s).c_str());							//	< ---------------------------------------

	std::cout << "Done.\n";
	utils::logmsg("Done.");

	return 0;
}

int part::genfstab()
{
	std::cout << "\nGenerating the filesystem table...\n";
	utils::logmsg("Generating the filesystem table...");

	system("genfstab -U /mnt >> /mnt/etc/fstab");				//	< ---------------------------------------

	std::cout << "Done.\n";
	utils::logmsg("Done.");

	return 0;
}
