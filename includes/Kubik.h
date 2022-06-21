
#ifndef KUBIK_H
#define KUBIK_H

#include <vector>
#include <iostream>
#include <ctime>
template<typename T>
using vector = std::vector<T>;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream;
using std::ostream;
using string = std::string;
class Kubik {
private:
    vector<vector<char>> front;
    vector<vector<char>> right;
    vector<vector<char>> left;
    vector<vector<char>> top;
    vector<vector<char>> bottom;
    vector<vector<char>> back;

    bool solving = false;
    int counter = 0;
    string str;

    char c1, c2;

    bool IsCollected() const;

    void whiteCross();

    void rightWhiteCross();

    void firstLayer();

    void secondLayer();

    void yellowCross();

    void rightYellowCross();

    void shuffleThirdLayer();

    bool correctPlace();

    void thirdLayer();

public:
    Kubik();

    // ввод-вывод
    friend istream &operator>>(istream &is, Kubik &rubik);

    friend ostream &operator<<(ostream &os, Kubik &rubik);

    // случайный шаффл
    void shuffle();
    // правая грань
    void R();

    void R2();

    void R_();

    //левая грань
    void L();

    void L2();

    void L_();

    // передняя грань
    void F();

    void F2();

    void F_();

    //задняя грань
    void B();

    void B2();

    void B_();

    // верхняя грань
    void U();

    void U2();

    void U_();

    // нижняя грань
    void D();

    void D2();

    void D_();

    // повороты хвата по горизонтали
    void y();

    void y2();

    void y_();

    // поворты хвата по вертикали
    void x();

    void x2();

    void x_();

    // пиф-пафы
    void PifPaf();

    void leftPifPaf();

    // автосборка кубика
    void solve();

};


#endif
