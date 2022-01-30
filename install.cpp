#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include "sources.h"

int instmain()
{
	std::cout << "\nInstallation started.\n\n";
	utils::loginit();

	std::string bpkgs[2] = {"reflector", "python"};

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// MOUNTING PARTITIONS //////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	


	std::cout << "First, we need to know what partitions are you going to install the system on.\n";

	std::string mnt, swap;
partset:
	std::cout << ":: Enter the path of the main partition (format: \"/dev/sdxN\"): ";					// Requests the /mnt partition path
	std::cin >> mnt;
	std::cout << ":: Enter the path of the swap partition (format: \"/dev/sdxN\"): ";					// Requests the swap partition path
	std::cin >> swap;

	if(mnt.find("/dev/") == std::string::npos || swap.find("/dev/") == std::string::npos)					// Checks for invalid partition paths
	{
		std::cout << "\nPlease insert a valid path. Retrying.\n";
		goto partset;
	}
	else if(mnt == swap)													// Stops if /mnt and swap are the same
	{
		std::cout << "\nYou cannot use the same partition as main and swap. Retrying.\n";
		goto partset;
	}



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// CHOOSING KERNEL //////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	


	std::string kern;
	std::cout << "\nNow, there are some different editions of the Linux kernel supported by Arch Linux:\n" 			// Shows and explains supported kernels
		<< "\t#1) \"mainline\":\tThe default kernel, a good compromise between compatibility (in term of platforms) and performances (SUGGESTED);\n"
		<< "\t#2) \"hardened\":\tA kernel focused on the security of the system, still being not needed for the most of the cases;\n"
		<< "\t#3) \"lts\":\tIf you aren't interested in making this your main machine, this kernel provides long-term support drivers even without updating;\n"
		<< "\t#4) \"zen\":\tThe performances-focused kernel, optimizes the use of the resources to provide a good user experience even on old machines.\n";

kernset:
	std::cout << "\n:: What kernel edition do you want to install? (without spaces or caps) ";
	std::cin >> kern;

	if(kern != "mainline" && kern != "hardened" && kern != "lts" && kern != "zen")						// Checks for invalid inputs
	{
		std::cout << "\nPlease select a supported version of the Linux kernel. Retrying.\n";
		goto kernset;
	}

	

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// SETTING UP MIRROR ////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	std::string CC;
	std::cout << "\nTo provide you a faster download process, we need to know what country's mirror we are going to connect to.\n"
		<< ":: What country are you in? Insert the country code (ex. \"US\"): ";
	std::cin >> CC;
	


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// INSTALLATION PROCESS /////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	


	pac::man::refresh();													// Syncs pacman repos

	pac::man::install(bpkgs);												// Installs needed temporary packages
	
	part::mkfs("ext4", mnt);												// Creates mnt filesystem

	part::mkfs("swap", swap);												// Creates swap filesystem

	part::mount(mnt, swap);													// Mounts chosen partitions

	pac::strap::setmirr(CC);												// Selects the mirror

	pac::strap::install(kern);												// Installs basic pkgs and the kernel

	part::genfstab();													// Generates the filesystem table

	conf::chroot();														// Enters arch chroot environment



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}
