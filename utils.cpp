#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include "sources.h"

int utils::arrsize(std::string* arr)
{
	int i = 0;
	while(!arr[i].empty())
		i++;

	return (i - 1);
}

std::string utils::nullop(std::string nul)
{
	std::string tonull = nul + nulloutp;

	return tonull;
}

std::string utils::logop(std::string log)
{
	std::string tolog = log + logoutp;

	return tolog;
}

std::string utils::echomd(std::string echo)
{
	std::string toecho = "echo " + echo;

	return toecho;
}

int utils::loginit()
{
	system((utils::echomd("Install started.") + logoutps).c_str());

	return 0;
}

int utils::logmsg(std::string msg)
{
	system(utils::logop(utils::echomd(msg)).c_str());

	return 0;
}	
