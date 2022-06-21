#include "Kubik.h"

Kubik::Kubik() {
    front.resize(3);
    back.resize(3);
    top.resize(3);
    bottom.resize(3);
    right.resize(3);
    left.resize(3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            front[i].push_back('r');
            back[i].push_back('o');
            top[i].push_back('y');
            bottom[i].push_back('w');
            right[i].push_back('g');
            left[i].push_back('b');
        }
    }
}

istream &operator>>(istream &is, Kubik &rubik) {
    rubik.front.clear();
    rubik.back.clear();
    rubik.top.clear();
    rubik.bottom.clear();
    rubik.left.clear();
    rubik.right.clear();

    rubik.front.resize(3);
    rubik.back.resize(3);
    rubik.top.resize(3);
    rubik.bottom.resize(3);
    rubik.right.resize(3);
    rubik.left.resize(3);

    for (int i = 2; i >= 0; --i)
        for (int j = 0; j < 3; ++j) {
            char x;
            is >> x;
            rubik.top[i].push_back(x);
        }

    for (int i = 2; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) {
            char x;
            is >> x;
            rubik.left[i].push_back(x);
        }

        for (int j = 0; j < 3; ++j) {
            char x;
            is >> x;
            rubik.front[i].push_back(x);
        }

        for (int j = 0; j < 3; ++j) {
            char x;
            is >> x;
            rubik.right[i].push_back(x);
        }

        for (int j = 0; j < 3; ++j) {
            char x;
            is >> x;
            rubik.back[i].push_back(x);
        }
    }

    for (int i = 2; i >= 0; --i)
        for (int j = 0; j < 3; ++j) {
            char x;
            is >> x;
            rubik.bottom[i].push_back(x);
        }
    return is;
}

ostream &operator<<(ostream &os, Kubik &rubik) {
    for (int i = 2; i >= 0; --i) {
        os << "      ";
        for (int j = 0; j < 3; ++j) {
            os << rubik.top[i][j] << " ";
            if (j == 2)
                os << endl;
        }
    }

    for (int i = 2; i >= 0; --i) {
        for (int j = 0; j < 3; ++j)
            os << rubik.left[i][j] << " ";
        for (int j = 0; j < 3; ++j)
            os << rubik.front[i][j] << " ";
        for (int j = 0; j < 3; ++j)
            os << rubik.right[i][j] << " ";
        for (int j = 0; j < 3; ++j)
            os << rubik.back[i][j] << " ";
        os << endl;
    }

    for (int i = 2; i >= 0; --i) {
        os << "      ";
        for (int j = 0; j < 3; ++j) {
            os << rubik.bottom[i][j] << " ";
            if (j == 2)
                os << endl;
        }
    }
    return os;
}

void Kubik::shuffle() {
    srand(time(nullptr));
    for (int i = 0; i < 15; ++i){
        int n = rand() % 10;
        switch (n) {
            case 1:
                PifPaf();
                break;
            case 2:
                leftPifPaf();
                break;
            case 3:
                U();
                y();
                F();
                U();
                x2();
                F_();
                break;
            case 4:
                PifPaf();
                F();
                y_();
                leftPifPaf();
                break;
            case 5:
                U();
                B();
                break;
            case 6:
                D2();
                B2();
                PifPaf();
                break;
            case 7:
                F2();
                U2();
                leftPifPaf();
                break;
            case 8:
                R2();
                L2();
                break;
            case 9:
                L_();
                y();
                U2();
                break;
            default:
                F();
                B_();
                R2();
                break;
        }
    }
}

