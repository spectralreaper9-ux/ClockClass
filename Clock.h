//
// Created by spect on 11/9/2026.
//

#ifndef CLOCKCLASSOVERLOAD_CLOCK_H
#define CLOCKCLASSOVERLOAD_CLOCK_H
#include <iosfwd>


class Clock
{
    int hour{};
    int minute{};
    int second{};
    bool isCurrentlyPM{};

public:
    Clock() = default;
    Clock(int hour, int minute, int second, bool isCurrentlyPM);

    bool operator < (const Clock& other) const;
    bool operator == (const Clock& other) const;
    Clock& operator++();
    friend std::ostream& operator << (std::ostream& os, const Clock& clock);
};


#endif //CLOCKCLASSOVERLOAD_CLOCK_H
