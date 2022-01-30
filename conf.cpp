#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include "sources.h"

int conf::chroot()
{
	//system("cp /bin/archconfig /mnt/bin/archconfig; chmod +x /bin/archconfig");		< -------------------------------
	
	std::cout << "\nThe system is installed. You can find more details in the file \"/etc/archinstall.log\".\n"
		<< "\nIf you want to configure your system with our help, just type \"archconfig\" in the shell that will appear, answer some questions and get your ready-to-go system!\n"
		<< "Otherwise, thanks for choosing us! You can find this code at " << webpage << std::endl;

	std::cout << "\nEntering system as root for the configuration...\n";
	utils::logmsg("Entering system as root for the configuration...");

	//system("arch-chroot /mnt");								< -------------------------------
	
	return 0;
}
