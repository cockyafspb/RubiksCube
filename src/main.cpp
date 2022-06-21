/// github: @cockyafspb
/// Program arguments:
/// --input=filename.txt
/// --output=filename.txt
/// Terminal commands:
/// R, R', R2, L, L', L2, F, F', F2, B, B', B2, U, U', U2, D, D', D2 & print & shuffle & solve & stop
/// gl hf
#include "Kubik.h"
#include <fstream>
#include <cstring>

void check_command(const string &command, Kubik &cube, bool &flag) {
    if (command == "U") {
        cube.U();
    } else if (command == "U'") {
        cube.U_();
    } else if (command == "D") {
        cube.D();
    } else if (command == "D'") {
        cube.D_();
    } else if (command == "F") {
        cube.F();
    } else if (command == "F'") {
        cube.F_();
    } else if (command == "B") {
        cube.B();
    } else if (command == "B'") {
        cube.B_();
    } else if (command == "L") {
        cube.L();
    } else if (command == "L'") {
        cube.L_();
    } else if (command == "R") {
        cube.R();
    } else if (command == "R'") {
        cube.R_();
    } else if (command == "U2") {
        cube.U2();
    } else if (command == "D2") {
        cube.D2();
    } else if (command == "F2") {
        cube.F2();
    } else if (command == "B2") {
        cube.B2();
    } else if (command == "L2") {
        cube.L2();
    } else if (command == "R2") {
        cube.R2();

    } else if (command == "solve") {
        cube.solve();
    } else if (command == "shuffle") {
        cube.shuffle();
    }
    else if (command == "print"){
        cout << cube;
    }
    else if (command == "stop") {
        flag = false;
    }
    else if (command == "y2"){
        cube.y2();
    }
    else if(command == "y"){
        cube.y();
    }
    else if (command == "y'"){
        cube.y_();
    }
    else if(command == "x"){
        cube.x();
    }
    else if (command == "x'"){
        cube.x_();
    }
    else if (command == "x2"){
        cube.x2();

    }
}

void parse(string str, Kubik &cube, bool &flag) {
    int i = 0;
    string tmp;
    while (i < str.size()) {
        if (str[i] != ' ') {
            tmp += str[i];
        } else {
            check_command(tmp, cube, flag);
            tmp = "";
        }
        ++i;
    }
    check_command(tmp, cube, flag);
}

int main(int argc, char *argv[]) {
    string input, output;
    for (int i = 1; i < argc; ++i) {
        if (strlen(argv[i]) <= 8 || argv[i][0] != '-' || argv[i][1] != '-') {
            cerr << "wrong command's input\ncheck documentation";
            return 0;
        } else {
            if (argv[i][2] == 'i' && argv[i][3] == 'n' && argv[i][4] == 'p' && argv[i][5] == 'u' && argv[i][6] == 't' &&
                argv[i][7] == '=') {
                for (size_t j = 8; j < strlen(argv[i]); ++j)
                    input += argv[i][j];
            } else if (strlen(argv[i]) > 9 && argv[i][2] == 'o' && argv[i][3] == 'u' && argv[i][4] == 't' &&
                       argv[i][5] == 'p' && argv[i][6] == 'u' && argv[i][7] == 't' && argv[i][8] == '=') {
                for (size_t j = 9; j < strlen(argv[i]); ++j)
                    output += argv[i][j];
            }
        }
    }

    std::ifstream in(input);
    std::ofstream out(output);

    if (!in || !out) {
        cerr << "files do not exist";
    } else {
        Kubik rubik;
        in >> rubik;

        string buf;
        bool flag = true;
        while (flag) {
            cin >> buf;
            parse(buf, rubik, flag);
        }

        out << rubik;
    }
}
