

#include "bf-obfuscator.h"

std::string A add_redundant_plus_minus(std::string in,int obfuscate_times,int obfuscate_level,int *tms) {
#ifdef _WIN32
	std::mt19937 mt(GetTickCount64());
#else
	std::random_device rd;
	std::mt19937 mt(rd());
#endif
	if (!obfuscate_times) return in;
	int times = mt() % obfuscate_times+1;
	*tms = obfuscate_times - times;
	while (times--) {
		int num = mt() % obfuscate_level+1;
		int pos = mt() % in.size();
		int pfirst = mt() % 2;
		if (pfirst) {
			for (int i = 1; i <= num; i++) {
				in.insert(in.begin() + pos, '+');
			}
			for (int i = 1; i <= num; i++) {
				in.insert(in.begin() + pos, '-');
			}
		}
		else {
			for (int i = 1; i <= num; i++) {
				in.insert(in.begin() + pos, '-');
			}
			for (int i = 1; i <= num; i++) {
				in.insert(in.begin() + pos, '+');
			}
		}
	}
	return in;
}

std::string A add_redundant_left_right(std::string in, int obfuscate_times, int obfuscate_level, int* tms) {
#ifdef _WIN32
	std::mt19937 mt(GetTickCount64());
#else
	std::random_device rd;
	std::mt19937 mt(rd());
#endif
	if (!obfuscate_times) return in;
	int times = mt() % obfuscate_times+1;
	*tms = obfuscate_times - times;
	while (times--) {
		int num = mt() % obfuscate_level + 1;
		int pos = mt() % in.size();
		for (int i = 1; i <= num; i++) {
			in.insert(in.begin() + pos, '<');
		}
		for (int i = 1; i <= num; i++) {
			in.insert(in.begin() + pos, '>');
		}
	}
	return in;
}
std::string A add_redundant_pars(std::string in, int obfuscate_times, int obfuscate_level, int* tms) {
#ifdef _WIN32
	std::mt19937 mt(GetTickCount64());
#else
	std::random_device rd;
	std::mt19937 mt(rd());
#endif
	if (!obfuscate_times) return in;
	int times = mt() % obfuscate_times+1;
	*tms = obfuscate_times - times;
	in += "[";
	int pf = mt() % 2;
	if (pf) {
		int a = mt() % obfuscate_level+2;
		int b = mt() % (a - 1) + 1;
		if ((a-b) % 2 == 0) b--;
		for (int i = 1; i <= a; i++) in += '+';
		for (int i = 1; i <= b; i++) in += '-';
	}
	else {
		int a = mt() % obfuscate_level+2;
		int b = mt() % (a - 1) + 1;
		if ((a - b) % 2 == 0) b--;
		for (int i = 1; i <= a; i++) in += '-';
		for (int i = 1; i <= b; i++) in += '+';
	}
	in += "]";
	while (times--) {
		std::string tmp = "[",ins="+-,.>";
		int a = mt() % obfuscate_level;
		for (int i = 1; i <= a; i++) {
			tmp += ins[mt() % 4];
		}
		in += tmp+"]";
	}
	return in;
}
std::string A add_redundant_chars(std::string in, int obfuscate_times, int obfuscate_level, int* tms) {
#ifdef _WIN32
	std::mt19937 mt(GetTickCount64());
#else
	std::random_device rd;
	std::mt19937 mt(rd());
#endif
	if (!obfuscate_times||!obfuscate_level) return in;
	int times = mt() % (obfuscate_times*obfuscate_level*10)+1;
	*tms = obfuscate_times - mt()% obfuscate_times;
	while (times--) {
		int a = mt() % in.size(),b=mt()%26,c=mt()%2;
		if (c) {
			in.insert(in.begin()+a, b + 'A');
		}
		else {
			in.insert(in.begin() + a, b + 'a');
		}
	}
	return in;
}
std::string A add_redundant_code(std::string in, int obfuscate_times, int obfuscate_level,int *tms) {
#ifdef _WIN32
	std::mt19937 mt(GetTickCount64());
#else
	std::random_device rd;
	std::mt19937 mt(rd());
#endif
	if (!obfuscate_times) return in;
	int times = mt() % obfuscate_times+1;
	*tms = obfuscate_times - times;
	int it=0;
	while (times--) {
		it = in.find(']', it);
		if (it==std::string::npos) break;
		std::string tmp = "[", ins = "+-,.>";
		int a = mt() % obfuscate_level;
		for (int i = 1; i <= a; i++) {
			tmp += ins[mt() % 4];
		}
		in.insert(it+1, tmp + "]");
	}
	return in;
}
std::string A obfuscate(std::string in,int obfuscate_times,int obfuscate_level,int obfuscate_mode) {
	while (obfuscate_times) {
		if (obfuscate_mode & REDUNDANT_PLUS_MINUS) {
			in = add_redundant_plus_minus(in, obfuscate_times, obfuscate_level, &obfuscate_times);
		}
		if (obfuscate_mode & REDUNDANT_LEFT_RIGHT) {
			in = add_redundant_left_right(in, obfuscate_times, obfuscate_level, &obfuscate_times);
		}
		if (obfuscate_mode & REDUNDANT_LOOPS) {
			in = add_redundant_pars(in, obfuscate_times, obfuscate_level, &obfuscate_times);
		}
		if (obfuscate_mode & REDUNDANT_CHARS) {
			in = add_redundant_chars(in, obfuscate_times, obfuscate_level, &obfuscate_times);
		}
		if (obfuscate_mode & REDUNDANT_CODE) {
			in = add_redundant_code(in, obfuscate_times, obfuscate_level, &obfuscate_times);
		}
	}
	return in;
}