#include<iostream>
#include<vector>
#include<algorithm>
#include<conio.h>
//#include "stdafx.h"
using namespace std;

static const char* oper[] =
{
    " Do X ra ngoai : ",
    " Do day binh X : ",
    " Do Y ra ngoai : ",
    " Do day binh Y : ",
    " Do tu X --> Y : ",
    " Do tu Y --> X : "
    };
struct State
{
    int _x; //Lượng nước trong thùng X
    int _y; //Lượng nước trong thùng y. 
    int _o; /* Toán tử tạo ra trạng thái này. */
    int _p; /* Chỉ số của "trạng thái cha". */

    static int maxX; /* Lượng nước tối đa thùng X. */
    static int maxY; /* Lượng nước tối đa thùng Y. */

State(int x, int y, int oper = -1) : _x(x), _y(y), _o(oper), _p(-1) {}
inline State create(int oper) const
{
switch (oper)
    {
        case 0: // x --> 0
        return State(0, _y, oper);
        case 1: // x --> maxX
        return State(maxX, _y, oper);
        case 2: // y --> 0
        return State(_x, 0, oper);
        case 3: // y --> maxY
        return State(_x, maxY, oper);
        case 4: // x --> y
        return State(_x + _y > maxY ? _x + _y - maxY : 0, _x + _y > maxY ? maxY : _x + _y, oper);
        case 5: // y --> x
        return State(_x + _y > maxX ? maxX : _x + _y, _x + _y > maxX ? _x + _y - maxX : 0, oper);
}
        return State(0, 0);
}
inline bool final(int z)
{
    return _x == z || _y == z;
}
    friend bool operator==(const State& state1,const State &state2)
{
    return (state1._x == state2._x && state1._y == state2._y);
}
};
int State::maxX(0);
int State::maxY(0);


int BFS(int x, int y, int z)
{
/* Tạo trạng thái đầu vào. */
State::maxX = x;
State::maxY = y;

std::vector<State> que;

/* Hai thùng đều rỗng. */
que.push_back(State(0, 0));

int iPos(0);
do
{
/* Tạo các trạng thái mới từ trạng thái hiện tại.*/
for(int i(0); i < 6; i++)
{
/* Tạo trạng thái. */
State newState = que.at(iPos).create(i);
/* Tìm xem có trạng thái này hay chưa, nếu chưa có thì thêm vào. */
if(que.end() == find(que.begin(), que.end(), newState))
{
    newState._p = iPos;
    que.push_back(newState);
}
/* Đây là trạng thái cuối? */
if(newState.final(z))
{
    std::vector<int> index;

    /* Duyệt ngược cây lấy chỉ số. */
    for(int i(iPos); -1 != i;)
    index.push_back(i), i = que.at(i)._p;

    int stepCount(0);

    cout << "Bat dau 2 binh rong " << endl;

    for(std::vector<int>::const_reverse_iterator it = index.rbegin(); it != index.rend(); it++)
    if (que.at(*it)._o != -1)
        cout << "Buoc "<< ++stepCount << oper[que.at(*it)._o] << que.at(*it)._x << " " << que.at(*it)._y <<endl;

        cout << "Buoc "<< ++stepCount << oper[newState._o] << newState._x << " " << newState._y <<endl;
            return stepCount;
}
}   
    iPos++;
}
while (iPos < que.size());

return -1;
}


int main(){
int x(0), y(0), z(0);

            cout << "Nhap dung tich binh thu nhat : "; 
            cin >> x;
            cout << "Nhap dung tich binh thu hai : "; 
            cin >> y;
            cout << "Nhap dung tich can dong : ";
            cin >> z;
            cout << endl;
            cout << "De bai : Co 2 binh co dung tich " << x << " va " << y << " lit." << endl;
            cout << "Tim cach do de lay duoc " << z << " lit." << endl;
            cout << "=================================" << endl;    

    int A = BFS(x, y, z);
    if(A!= -1)
        cout << "Sau " << A << " buoc, ta lay duoc "<< z <<" lit. :D" << endl;
    else
        cout << "No way ! :(" << endl;
        cout.flush();
    _getch();
    return 0;
    }


