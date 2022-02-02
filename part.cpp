#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include "sources.h"

int part::mkfs(std::string fst, std::string part)
{
	std::cout << ylw << "\nCreating " << part << " filesystem...\n" << def;
	utils::logmsg("Creating " + part + " filesystem...");

	std::string tomake_s = (fst == "swap" ? "mkswap" : "mkfs." + fst) + " " + part;

	system(utils::logop(tomake_s).c_str());							//	< ---------------------------------------
	
	std::cout << grn << "Done.\n" << def;
	utils::logmsg("Done.");

	return 0;
}

int part::mount(std::string mnt, std::string swap)
{
	std::cout << ylw << "\nMounting Partitions...\n" << def;
	utils::logmsg("Mounting Partitions...");

	std::string tomnt_s = "mount " + mnt + " /mnt";
	std::string toswap_s = "swapon " + swap;

	system(utils::logop(tomnt_s).c_str());							//	< ---------------------------------------
	system(utils::logop(toswap_s).c_str());							//	< ---------------------------------------

	std::cout << grn << "Done.\n" << def;
	utils::logmsg("Done.");

	return 0;
}

int part::genfstab()
{
	std::cout << ylw << "\nGenerating the filesystem table...\n" << def;
	utils::logmsg("Generating the filesystem table...");

	system("genfstab -U /mnt >> /mnt/etc/fstab");				//	< ---------------------------------------

	std::cout << grn << "Done.\n" << def;
	utils::logmsg("Done.");

	return 0;
}
