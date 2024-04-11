#pragma once
#include <cstdlib>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

void InitFiles(std::string counter_file_name);

std::string CalcFileName(std::string& counter_file_name);

void UploadIpToFile(std::string& file_name);

