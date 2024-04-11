#include <iostream>
#include <string>
#include "GetIp.h"
#include <Windows.h>

std::string COUNTER_FILE = ".counter_file.json";

int main() {
    std::string file_name = CalcFileName(COUNTER_FILE);
    UploadIpToFile(file_name);
    return 0;
}