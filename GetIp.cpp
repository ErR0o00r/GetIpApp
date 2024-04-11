#include "GetIp.h"

std::string CalcFileName(std::string& counter_file_name) {
    std::fstream counter_file(counter_file_name, std::ios::in);
    if (!counter_file.is_open()) {
        std::cout << "Error when opening file" << std::endl;
    }
    std::string new_file_name;
    std::getline(counter_file, new_file_name);
    counter_file.close();
    return new_file_name;
}

void UploadIpToFile(std::string& file_name) {
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    std::string command = "cmd /c ipconfig > " + file_name;
    if (CreateProcessA("C://WINDOWS//system32//cmd.exe", (LPSTR)command.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } 

}
