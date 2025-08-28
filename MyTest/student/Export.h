#pragma once
#ifndef EXPORT_H
#define EXPORT_H

#include <vector>
#include <string>
#include <fstream>
#include "Grade.h"
#include "Login.h"

using namespace std;

class Export {
private:
    Login& login;
public:
    Export(Login& login);
    void exportToCSV();
    vector<Grade> getAllGradesFromLogin();
};

#endif // EXPORT_H
