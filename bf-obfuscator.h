
#pragma once

#include <iostream>
#include <string>
#include <random>
#ifdef _WIN32
#define A __declspec(dllexport)
#include <windows.h>
extern "C"
WINBASEAPI
ULONGLONG
WINAPI
GetTickCount64(
    VOID
);
#else
#define A
#endif
std::string A add_redundant_plus_minus(std::string in, int obfuscate_times, int obfuscate_level,int *tms);
std::string A add_redundant_left_right(std::string in, int obfuscate_times, int obfuscate_level,int *tms);
std::string A add_redundant_pars(std::string in, int obfuscate_times, int obfuscate_level,int *tms);
std::string A add_redundant_chars(std::string in, int obfuscate_times, int obfuscate_level,int *tms);
std::string A add_redundant_code(std::string in, int obfuscate_times, int obfuscate_level,int *tms);
std::string A obfuscate(std::string in, int obfuscate_times, int obfuscate_level, int obfuscate_mode);
// TODO: 在此处引用程序需要的其他标头。
#define REDUNDANT_PLUS_MINUS 1
#define REDUNDANT_LEFT_RIGHT 2
#define REDUNDANT_LOOPS 4
#define REDUNDANT_CHARS 8
#define REDUNDANT_CODE 16
#define REDUNDANT_ALL 31
#define REDUNDANT_DEFAULT (REDUNDANT_ALL^REDUNDANT_CHARS)