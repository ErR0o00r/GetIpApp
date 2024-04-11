#include "GetIp.h"

using json = nlohmann::json;

void InitFiles(std::string counter_file_name) {
    std::fstream counter_file(counter_file_name, std::ios::out);
    if (!counter_file.is_open()) {
        std::cerr << "file not open" << std::endl;
        return;
    }
    json conf_json;
    conf_json["counter"] = 0;
    counter_file << conf_json;
    counter_file.close();
}

std::string CalcFileName(std::string& counter_file_name) {
    std::fstream counter_file(counter_file_name, std::ios::in);
    if (!counter_file.is_open()) {
        std::cerr << "error when opening file" << std::endl;
        exit(1);
    }
    int counter = NULL;
    std::string new_file_name;
    try {
        json file = json::parse(counter_file);
        counter = file["counter"].get<int>();
        new_file_name = "ip_file_" + std::to_string(counter) + ".txt";
        counter_file.close();
        counter_file.open(counter_file_name, std::ios::out);
        file["counter"] = counter + 1;
        counter_file << file;
        counter_file.close();
    }
    catch (std::exception ex) {
        std::cerr << ex.what() << std::endl;
        counter_file.close();
        return "error";
    }
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
