#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include "sources.h"

int pac::strap::install(std::string kerned)
{
	std::cout << "\nInstalling basic packages...\n";
	utils::logmsg("Installing basic packages...");

	std::string kern = (kerned == "mainline") ? "linux" : ("linux-" + kerned);
	std::string pacs = "base " + kern + " linux-firmware";
	
	std::string toinstall_s = "pacstrap /mnt --noconfirm " + pacs;

	system(utils::logop(toinstall_s).c_str());					//	< ---------------------------------------
	
	std::cout << "Done.\n";
	utils::logmsg("Done.");

	return 0;
}

int pac::strap::setmirr(std::string CC)
{
	std::cout << "\nReaching national mirror...\n";
	utils::logmsg("Reaching national mirror...");
		
	std::string toreach_s = "reflector -c \"" + CC + "\" -f 12 -l 10 -n 12 --save /etc/pacman.d/mirrorlist";

	system("cp /etc/pacman.d/mirrorlist /etc/pacman.d/mirrorlist.bak");		//	< ---------------------------------------
	std::cout << utils::logop(toreach_s) << std::endl;
	system(utils::logop(toreach_s).c_str());					//	< ---------------------------------------
	
	std::cout << "Done.\n";
	utils::logmsg("Done.");

	return 0;
}

int pac::man::refresh()
{
	std::cout << "\nSyncing packages\' repositories...\n";
	utils::logmsg("Syncing packages repositories...");

	std::cout << utils::logop("pacman -Syy") << std::endl;
	system(utils::logop("pacman -Syy").c_str());					//	< ---------------------------------------
	
	std::cout << "Done.\n";
	utils::logmsg("Done.");

	return 0;
}

int pac::man::install(std::string* pkgs)
{
	std::cout << "\nInstalling utilities...\n";
	utils::logmsg("Installing utilities...");

	std::string pacs;
	for(int i = 0; i < utils::arrsize(pkgs); i++)
	{
		pacs += " " + pkgs[i];
	}

	std::string toinstall_s = "pacman -S --noconfirm" + pacs;

	std::cout << utils::logop(toinstall_s) << std::endl;
	system(utils::logop(toinstall_s).c_str());					//	< ---------------------------------------
	
	std::cout << "Done.\n";
	utils::logmsg("Done.");

	return 0;
}
