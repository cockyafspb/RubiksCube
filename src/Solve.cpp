#include "Kubik.h"

bool Kubik::IsCollected() const {
    bool flag = true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            if (front[i][j] != front[0][0]) flag = false;
            if (left[i][j] != left[0][0]) flag = false;
            if (right[i][j] != right[0][0]) flag = false;
            if (top[i][j] != top[0][0]) flag = false;
            if (back[i][j] != back[0][0]) flag = false;
            if (bottom[i][j] != bottom[0][0]) flag = false;
        }
    return flag;
}

void Kubik::solve() {
    solving = true;
    str.clear();
    c1 = bottom[1][1];
    c2 = top[1][1];
    whiteCross();
    rightWhiteCross();
    firstLayer();
    secondLayer();
    yellowCross();
    rightYellowCross();
    shuffleThirdLayer();
    thirdLayer();
    cout << str << endl;
    solving = false;
}

void Kubik::whiteCross() {
    // поднимаем белый центр наверх
    if (front[1][1] == c1) {
        x();
    } else if (left[1][1] == c1) {
        y_();
        x();
    } else if (right[1][1] == c1) {
        y();
        x();
    } else if (back[1][1] == c1) {
        x_();
    } else if (bottom[1][1] == c1) {
        x2();
    } else if (top[1][1] != c1) {
        cerr << "Incorrect input data";
        exit(0);
    }

    // поднимаем белые ребра наверх
    while (!(top[0][1] == c1 && top[1][0] == c1 && top[2][1] == c1 && top[1][2] == c1)) {
        if (front[1][0] == c1) {
            while (top[1][0] == c1) {
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            L_();
        } else if (front[1][2] == c1) {
            while (top[1][2] == c1) {
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            R();
        } else if (front[2][1] == c1) {
            F();
            while (top[1][2] == c1) {
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            R();
        } else if (front[0][1] == c1) {
            bool flag = false;
            if (top[0][1] == c1)
                flag = true;
            F_();
            while (top[1][2] == c1) {
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            R();
            if (!flag)
                F();
        } else if (bottom[2][1] == c1) {
            while (top[0][1] == c1) {
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            F2();
        } else {
            y();
        }
        if (counter > 500) {
            cerr << "Incorrect input data";
            exit(0);
        }
    }
}

void Kubik::rightWhiteCross() {
    while (!(front[2][1] == front[1][1] && left[2][1] == left[1][1] && right[2][1] == right[1][1] &&
             back[2][1] == back[1][1])) {
        if (front[2][1] == front[1][1]) {
            if (right[2][1] == right[1][1]) {
                y();
                PifPaf();
                R();
            } else if (left[2][1] == left[1][1]) {
                PifPaf();
                R();
            } else if (back[2][1] == back[1][1]) {
                PifPaf();
                R();
            } else {
                U();
                y();
            }
        } else {
            while (front[2][1] != front[1][1]) {
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
        }

        if (counter > 500) {
            cerr << "Incorrect input data";
            exit(0);
        }
    }
}

void Kubik::firstLayer() {
    x2();
    while (!(front[0][0] == front[0][2] && front[0][2] == front[1][1] && left[0][0] == left[0][2] &&
             left[0][2] == left[1][1] && right[0][0] == right[0][2] && right[0][2] == right[1][1] &&
             back[0][0] == back[0][2] && back[0][2] == back[1][1])) {
        if (top[0][2] == c1) {
            while (!(front[2][2] == right[1][1] && right[2][0] == front[1][1])) {
                y_();
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            for (int i = 0; i < 3; ++i) PifPaf();
        } else if (front[2][2] == c1) {
            while (!(top[0][2] == front[1][1] && right[2][0] == right[1][1])) {
                y_();
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            for (int i = 0; i < 5; ++i) PifPaf();
        } else if (right[2][0] == c1) {
            while (!(front[2][2] == front[1][1] && top[0][2] == right[1][1])) {
                y_();
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            PifPaf();
        } else if (front[0][2] == c1 || right[0][0] == c1) {
            PifPaf();
        } else {
            y_();
        }
        if (counter > 500) {
            cerr << "Incorrect input data";
            exit(0);
        }
    }
}

void Kubik::secondLayer() {
    while (!(front[1][0] == front[1][1] && front[1][1] == front[1][2] && right[1][0] == right[1][1] &&
             right[1][1] == right[1][2] && back[1][0] == back[1][1] && back[1][1] == back[1][2] &&
             left[1][0] == left[1][1] && left[1][1] == left[1][2])) {
        bool flag = false;
        solving = false;
        for (int i = 0; i < 4; ++i) {
            U();
            if (front[2][1] != c2 && top[0][1] != c2)
                flag = true;
        }
        solving = true;

        if (flag) {
            while (!(front[2][1] != c2 && top[0][1] != c2)) {
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            while (front[2][1] != front[1][1]) {
                y_();
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            if (top[0][1] == right[1][1]) {
                U();
                PifPaf();
                y();
                leftPifPaf();
            } else if (top[0][1] == left[1][1]) {
                U_();
                leftPifPaf();
                y_();
                PifPaf();
            }
        } else {
            while (front[1][1] == front[1][2] && right[1][0] == right[1][1]) { y_(); }
            U();
            PifPaf();
            y();
            leftPifPaf();
            if (counter > 500) {
                cerr << "Incorrect input data";
                exit(0);
            }
        }
        if (counter > 500) {
            cerr << "Incorrect input data";
            exit(0);
        }
    }
}

void Kubik::yellowCross() {
    while (!(top[1][0] == c2 && top[1][0] == top[1][2] && top[1][0] == top[0][1])) {
        if (top[1][0] == top[1][2] && top[1][0] == c2) {
            F();
            PifPaf();
            F_();
        } else if (top[0][1] == top[2][1] && top[0][1] == c2) {
            y();
            F();
            PifPaf();
            F_();
        } else if (top[1][0] == top[2][1] && top[1][0] == c2) {
            F();
            PifPaf();
            PifPaf();
            F_();
        } else if (top[1][0] == top[0][1] && top[1][0] == c2) {
            y();
            F();
            PifPaf();
            PifPaf();
            F_();
        } else if (top[0][1] == top[1][2] && top[0][1] == c2) {
            y2();
            F();
            PifPaf();
            PifPaf();
            F_();
        } else if (top[1][2] == top[2][1] && top[1][2] == c2) {
            y_();
            F();
            PifPaf();
            F_();
        } else {
            F();
            PifPaf();
            PifPaf();
            F_();
            U2();
            F();
            PifPaf();
            PifPaf();
            F_();
        }
        if (counter > 500) {
            cerr << "Incorrect input data";
            exit(0);
        }
    }
}

void Kubik::rightYellowCross() {
    while (!(right[1][1] == right[2][1] && front[1][1] == front[2][1] && left[1][1] == left[2][1] &&
             back[1][1] == back[2][1])) {
        bool flag = false;
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                U();
                if (right[2][1] == right[1][1] && back[2][1] == back[1][1]) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            y();
        }

        if (flag) {
            /* while (!(right[2][1] == right[1][1] && back[2][1] == back[1][1])) { U(); } */
            R();
            U();
            R_();
            U();
            R();
            U2();
            R_();
            U();
        } else {
            while (!(front[1][1] == front[2][1] && back[1][1] == back[2][1])) {
                U();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            R();
            U();
            R_();
            U();
            R();
            U2();
            R_();
        }
        if (counter > 500) {
            cerr << "Incorrect input data";
            exit(0);
        }
    }
}

bool Kubik::correctPlace() {
    bool res = true;
    solving = false;
    for (int i = 0; i < 4; ++i) {
        if (!((front[1][1] == front[2][2] || front[1][1] == top[0][2] || front[1][1] == right[2][0]) &&
              (right[1][1] == front[2][2] || right[1][1] == top[0][2] || right[1][1] == right[2][0])))
            res = false;
        y();
    }
    solving = true;
    return res;
}


void Kubik::shuffleThirdLayer() {
    while (!correctPlace()) {
        bool flag = false;
        int count = 0;
        solving = false;
        for (int i = 0; i < 4; ++i) {
            if (!((front[1][1] == front[2][0] || front[1][1] == top[0][0] || front[1][1] == left[2][2]) &&
                  (left[1][1] == front[2][0] || left[1][1] == top[0][0] || left[1][1] == left[2][2]))) {
                y();
                ++count;
            } else {
                flag = true;
            }
        }
        solving = true;
        if (flag) {
            for (int i = 0; i < count; ++i)
               str += "y ";
        }
        R();
        U_();
        L_();
        U();
        R_();
        U_();
        L();
        U();
        if (counter > 500) {
            cerr << "Incorrect input data";
            exit(0);
        }
    }
}

void Kubik::thirdLayer() {
    x2();
    int count = 0;
    while (!IsCollected()) {
        if (count == 0) {
            while (front[0][2] != front[1][1] || right[0][0] != right[1][1]) {
                PifPaf();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            ++count;
            D_();
        } else if (count == 1) {
            while (front[0][2] != right[1][1] || right[0][0] != back[1][1]) {
                PifPaf();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            ++count;
            D_();
        } else if (count == 2) {
            while (front[0][2] != back[1][1] || right[0][0] != left[1][1]) {
                PifPaf();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            ++count;
            D_();
        } else if (count == 3) {
            while (front[0][2] != left[1][1] || right[0][0] != front[1][1]) {
                PifPaf();
                if (counter > 500) {
                    cerr << "Incorrect input data";
                    exit(0);
                }
            }
            ++count;
            D_();
        } else {
            D_();
        }
        if (counter > 500) {
            cerr << "Incorrect input data";
            exit(0);
        }
    }
}