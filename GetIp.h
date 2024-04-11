#pragma once
#include <cstdlib>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>


std::string CalcFileName(std::string& counter_file_name);

void UploadIpToFile(std::string& file_name);

