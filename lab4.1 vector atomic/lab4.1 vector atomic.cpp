/*
Реализуйте функцию, которая должна увеличивать на единицу ОДНО! принятое в качестве параметра значение. 
Посредством этой функции ПАРАЛЛЕЛЬНО инкрементируйте значения всех элементов вектора.
*/
#include <iostream>
#include <atomic>
#include <vector>
#include <thread>

using namespace std;

void my_inc(vector<int>& v, atomic<int>& ind)
{
    int i = ind.fetch_add(1, memory_order_relaxed);
    v[i]++;
}

/*
1.б Модифицируйте задание 1.а -реализуйте функцию, которая тоже должна инкрементировать каждый элемент вектора, 
но принимать в качестве параметра будет принимать указатель на этот элемент.
*/
void fPtr(atomic<int*>& x)
{
    int* pLocal = x.fetch_add(1, memory_order_relaxed);
    (*pLocal)++;
}

int main()
{
    atomic<int> current_ind{};
    vector<int> v{ 1,2,3,4,5 };
    {
        vector<jthread> v_thr;
        v_thr.reserve(v.size());
        for (size_t i = 0; i < v.size(); i++)
            v_thr.emplace_back(jthread(&my_inc, ref(v), ref(current_ind)));
    }
    atomic<int*> c_ind = &v[0];
    {
        vector<jthread> v_thr;
        v_thr.reserve(v.size());
        for (size_t i = 0; i < v.size(); i++)
            v_thr.emplace_back(jthread(&fPtr, ref(c_ind)));
    }

    return 0;
}

