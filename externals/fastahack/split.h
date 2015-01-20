#ifndef __SPLIT_H
#define __SPLIT_H

// functions to split a string by a specific delimiter
#include <string>
#include <vector>
#include <sstream>
#include <string.h>

// thanks to Evan Teran, http://stackoverflow.com/questions/236129/how-to-split-a-string/236803#236803

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

std::vector<std::string> &split(const std::string &s, const std::string& delims, std::vector<std::string> &elems) {
    char* tok;
    char cchars [s.size()+1];
    char* cstr = &cchars[0];
    strcpy(cstr, s.c_str());
    tok = strtok(cstr, delims.c_str());
    while (tok != NULL) {
        elems.push_back(tok);
        tok = strtok(NULL, delims.c_str());
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, const std::string& delims) {
    std::vector<std::string> elems;
    return split(s, delims, elems);
}

#endif
