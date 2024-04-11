#include <iostream>
#include <string>
#include "GetIp.h"
#include <Windows.h>

int main() {
    std::string tmp = "ipfile2.txt";
    UploadIpToFile(tmp);
    return 0;
}