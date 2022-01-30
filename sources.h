#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>

#define webpage "https://github.com/Seaender07/archinstall"

#define nulloutp " > /dev/null"
#define logoutps " > ./archinstall.log"
#define logoutp " >> ./archinstall.log"

int instmain();

namespace part
{
	int mkfs(std::string fst, std::string part);		//
	int mount(std::string mnt, std::string swap);		//
	int genfstab();						//
};

namespace pac
{
	namespace strap
	{
		int install(std::string kerned);		//
		int setmirr(std::string CC);			//
	};
	namespace man
	{
		int refresh();					//
		int update();
		int install(std::string* pkgs);			//
	};
};

namespace conf
{
	int chroot();						//
};

namespace utils
{
	int arrsize(std::string* arr);				//
	std::string nullop(std::string nul);			//
	std::string logop(std::string log);			//
	std::string echomd(std::string echo);			//
	int loginit();						//
	int logmsg(std::string msg);				//
};
