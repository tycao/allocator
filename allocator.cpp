#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
    std::allocator<std::string> alloc;  // 可以分配string的allocator对象
    // 分配100个未初始化的string
    auto const p = alloc.allocate(10);
    string s;
    string *q = p;  // q指向第一个string
    while (cin >> s && q != p + 10)
    {
        alloc.construct(q++, s);    // 用s初始化*q，即q指向的对象
        if (s == "q")
            break;
    }
    const size_t size = q - p;  // 记录读取了多少个string

    // 使用数组
    for (size_t i = 0; i != size; ++i)
        cout << p[i] << " ";
    cout << endl;

    while (q != p)
        alloc.destroy(--q);     // 使用完毕后，释放已经构造的string
    alloc.deallocate(p, 10);    // 释放内存

    return 0;
}
