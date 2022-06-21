#include "Kubik.h"

using std::swap;

void Kubik::R() {
    // вспомогательно сохраняю правый ряд нижней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(bottom[i][2]);
    /* меняю местами "полоски" вокруг правой грани */
    for (int i = 0; i < 3; ++i) {
        bottom[i][2] = back[2 - i][0];
        back[2 - i][0] = top[i][2];
        top[i][2] = front[i][2];
        front[i][2] = tmp[i];
    }
    // swap'ы на грани
    vector<vector<char>> tmp1(right);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            right[i][j] = tmp1[j][2 - i];
    if (solving) {
        str += "R ";
        ++counter;
    }
}

void Kubik::R2() {
    R();
    R();
}

void Kubik::R_() {
    // вспомогательно сохраняю правый ряд нижней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(bottom[i][2]);
    /* меняю местами "полоски" вокруг правой грани */
    for (int i = 0; i < 3; ++i) {
        bottom[i][2] = front[i][2];
        front[i][2] = top[i][2];
        top[i][2] = back[2 - i][0];
        back[2 - i][0] = tmp[i];
    }
    // swap'ы на грани
    vector<vector<char>> tmp1(right);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            right[i][j] = tmp1[2 - j][i];
    if (solving) {
        str += "R' ";
        ++counter;
    }
}

void Kubik::L() {
    // вспомогательно сохраняю левый ряд нижней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(bottom[i][0]);
    /* меняю местами "полоски" вокруг левой грани */
    for (int i = 0; i < 3; ++i) {
        bottom[i][0] = front[i][0];
        front[i][0] = top[i][0];
        top[i][0] = back[2 - i][2];
        back[2 - i][2] = tmp[i];
    }
    tmp.clear();
    // swap'ы на грани
    vector<vector<char>> tmp1(left);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            left[i][j] = tmp1[j][2 - i];
    if (solving) {
        str += "L ";
        ++counter;
    }
}

void Kubik::L2() {
    L();
    L();
}

void Kubik::L_() {
    // вспомогательно сохраняю левый ряд нижней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(bottom[i][0]);
    /* меняю местами "полоски" вокруг правой грани */
    for (int i = 0; i < 3; ++i) {
        bottom[i][0] = back[2 - i][2];
        back[2 - i][2] = top[i][0];
        top[i][0] = front[i][0];
        front[i][0] = tmp[i];
    }
    // swap'ы на грани
    vector<vector<char>> tmp1(left);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            left[i][j] = tmp1[2 - j][i];
    if (solving) {
        str += "L' ";
        ++counter;
    }
}

void Kubik::F() {
    // вспомогательно сохраняю ближний ряд нижней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(bottom[2][i]);
    /* меняю местами "полоски" вокруг передней грани */
    for (int i = 0; i < 3; ++i) {
        bottom[2][i] = right[i][0];
        right[i][0] = top[0][2 - i];
        top[0][2 - i] = left[2 - i][2];
        left[2 - i][2] = tmp[i];
    }
    tmp.clear();
    // swap'ы на грани
    vector<vector<char>> tmp1(front);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            front[i][j] = tmp1[j][2 - i];
    if (solving) {
        str += "F ";
        ++counter;
    }

}

void Kubik::F2() {
    F();
    F();
}

void Kubik::F_() {
    // вспомогательно сохраняю ближний ряд нижней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(bottom[2][i]);
    /* меняю местами "полоски" вокруг передней грани */
    for (int i = 0; i < 3; ++i) {
        bottom[2][i] = left[2 - i][2];
        left[2 - i][2] = top[0][2 - i];
        top[0][2 - i] = right[i][0];
        right[i][0] = tmp[i];
    }
    // swap'ы на грани
    vector<vector<char>> tmp1(front);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            front[i][j] = tmp1[2 - j][i];
    if (solving) {
        str += "F' ";
        ++counter;
    }
}

void Kubik::B() {
    // вспомогательно сохраняю дальней ряд нижней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(bottom[0][i]);
    /* меняю местами "полоски" вокруг задней грани */
    for (int i = 0; i < 3; ++i) {
        bottom[0][i] = left[2 - i][0];
        left[2 - i][0] = top[2][2 - i];
        top[2][2 - i] = right[i][2];
        right[i][2] = tmp[i];
    }
    tmp.clear();
    // swap'ы на грани
    vector<vector<char>> tmp1(back);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            back[i][j] = tmp1[j][2 - i];
    if (solving) {
        str += "B ";
        ++counter;
    }
}

void Kubik::B2() {
    B();
    B();
}

void Kubik::B_() {
    // вспомогательно сохраняю ближний ряд нижней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(bottom[0][i]);
    /* меняю местами "полоски" вокруг задней грани */
    for (int i = 0; i < 3; ++i) {
        bottom[0][i] = right[i][2];
        right[i][2] = top[2][2 - i];
        top[2][2 - i] = left[2 - i][0];
        left[2 - i][0] = tmp[i];
    }
    // swap'ы на грани
    vector<vector<char>> tmp1(back);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            back[i][j] = tmp1[2 - j][i];
    if (solving) {
        str += "B' ";
        ++counter;
    }
}

void Kubik::U() {
    // вспомогательно сохраняю верхний ряд задней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(back[2][i]);
    /* меняю местами "полоски" вокруг передней грани */
    for (int i = 0; i < 3; ++i) {
        back[2][i] = left[2][i];
        left[2][i] = front[2][i];
        front[2][i] = right[2][i];
        right[2][i] = tmp[i];
    }
    tmp.clear();
    // swap'ы на грани
    vector<vector<char>> tmp1(top);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            top[i][j] = tmp1[j][2 - i];
    if (solving) {
        str += "U ";
        ++counter;
    }
}

void Kubik::U2() {
    U();
    U();
}

void Kubik::U_() {
    // вспомогательно сохраняю верхний ряд задней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(back[2][i]);
    /* меняю местами "полоски" вокруг передней грани */
    for (int i = 0; i < 3; ++i) {
        back[2][i] = right[2][i];
        right[2][i] = front[2][i];
        front[2][i] = left[2][i];
        left[2][i] = tmp[i];
    }
    // swap'ы на грани
    vector<vector<char>> tmp1(top);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            top[i][j] = tmp1[2 - j][i];
    if (solving) {
        str += "U' ";
        ++counter;
    }
}

void Kubik::D() {
    // вспомогательно сохраняю верхний ряд задней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(back[0][i]);
    /* меняю местами "полоски" вокруг передней грани */
    for (int i = 0; i < 3; ++i) {
        back[0][i] = right[0][i];
        right[0][i] = front[0][i];
        front[0][i] = left[0][i];
        left[0][i] = tmp[i];
    }
    tmp.clear();
    // swap'ы на грани
    vector<vector<char>> tmp1(bottom);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            bottom[i][j] = tmp1[j][2 - i];
    if (solving) {
        str += "D ";
        ++counter;
    }
}

void Kubik::D2() {
    D();
    D();
}

void Kubik::D_() {
    // вспомогательно сохраняю верхний ряд задней грани
    vector<char> tmp;
    for (int i = 0; i < 3; ++i)
        tmp.push_back(back[0][i]);
    /* меняю местами "полоски" вокруг передней грани */
    for (int i = 0; i < 3; ++i) {
        back[0][i] = left[0][i];
        left[0][i] = front[0][i];
        front[0][i] = right[0][i];
        right[0][i] = tmp[i];
    }
    // swap'ы на грани
    vector<vector<char>> tmp1(bottom);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            bottom[i][j] = tmp1[2 - j][i];
    if (solving) {
        str += "D' ";
        ++counter;
    }
}

void Kubik::y() {
    front.swap(right);
    right.swap(back);
    back.swap(left);
    left.swap(front);
    front.swap(left);

    vector<vector<char>> tmp1(top);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            top[i][j] = tmp1[j][2 - i];
    vector<vector<char>> tmp2(bottom);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            bottom[i][j] = tmp2[2 - j][i];
    if (solving) {
        str += "y ";
        ++counter;
    }
}

void Kubik::y2() {
    y();
    y();
}

void Kubik::y_() {
    front.swap(left);
    left.swap(back);
    back.swap(right);
    right.swap(front);
    front.swap(right);

    vector<vector<char>> tmp1(top);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            top[i][j] = tmp1[2 - j][i];

    vector<vector<char>> tmp2(bottom);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            bottom[i][j] = tmp2[j][2 - i];
    if (solving) {
        str += "y' ";
        ++counter;
    }
}

void Kubik::PifPaf() {
    R();
    U();
    R_();
    U_();
}

void Kubik::leftPifPaf() {
    L_();
    U_();
    L();
    U();
}

void Kubik::x() {
    vector<vector<char>> tmp(top);
    top.swap(front);
    front.swap(bottom);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            bottom[i][j] = back[2 - i][2 - j];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            back[i][j] = tmp[2 - i][2 - j];

    vector<vector<char>> tmp1(right);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            right[i][j] = tmp1[j][2 - i];
    vector<vector<char>> tmp2(left);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            left[i][j] = tmp2[2 - j][i];
    if (solving) {
        str += "x ";
        ++counter;
    }
}

void Kubik::x2() {
    x();
    x();
}

void Kubik::x_() {
    vector<vector<char>> tmp(bottom);
    bottom.swap(front);
    front.swap(top);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            top[i][j] = back[2 - i][2 - j];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            back[i][j] = tmp[2 - i][2 - j];
    vector<vector<char>> tmp1(right);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            right[i][j] = tmp1[2 - j][i];
    vector<vector<char>> tmp2(left);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            left[i][j] = tmp2[j][2 - i];
    if (solving) {
        str += "x' ";
        ++counter;
    }
}







