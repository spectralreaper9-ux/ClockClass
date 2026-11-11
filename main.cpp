#include <iomanip>
#include <iostream>
#include <thread>

#include "Clock.h"

int main()
{
    const Clock clockOne(1, 30, 6, true);
    const Clock clockTwo(12, 30, 6, true);
    const Clock clockThree(01, 30, 06, true);
    Clock clockFour(12, 59, 59, false);
    Clock clockFive(11, 58, 30, true);

    std::cout << clockOne << "\n" << clockTwo << "\n" << clockThree << std::endl;

    if (clockOne == clockThree) {std::cout << "Clock one is equal to clock three" << std::endl;}

    if (clockOne < clockTwo) {std::cout << "Clock one is less than clock two" << std::endl;}
    else {std::cout << "Clock one is NOT less than clock two" << std::endl;}

    std::cout << "\n" << clockFour << std::endl;

    ++clockFour;

    std::cout << clockFour << std::endl;

    system("pause");

    for (int i = 0; i < 61; i++)
    {
        std::cout << clockFive << std::endl;
        ++clockFive;
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
