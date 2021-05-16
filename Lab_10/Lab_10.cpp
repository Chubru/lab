#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1
#include <cstdio>
#include "logic.h"
#include <iostream>

#include <string>
#include <iostream>
#include <experimental/filesystem>

#pragma warning(disable : 4996)  

namespace fs = std::experimental::filesystem;

int main(int argc, char* argv[])
{
	std::cout << argc;
	prolog();
	for (int i = 0; i < argc; i++) {
		std::string h;

		for (int j = 0; argv[i][j] != '\0'; j++) {
			h += argv[i][j];
		}

		std::cout << h << std::endl;
		if (h == "-p") {
			i++;
			std::string path;

			for (int j = 0; argv[i][j] != '\0'; j++) {
				path += argv[i][j];
			}

			for (fs::path p : fs::directory_iterator(path)) {
				//std::cout << p.extension() << std::endl;
				if (p.extension() == ".c") {


					FILE* ptrFile = fopen(p.string().c_str(), "rt");
					if (ptrFile == NULL) {
						return -1;
					}
					filterDataHead = filterDataStrHead();
					for (;;) {
						int dat = fgetc(ptrFile);
						if (dat < 0)
							break;
						filter1(dat);
					}


				}

			}
		}
	}
	epilog();
}