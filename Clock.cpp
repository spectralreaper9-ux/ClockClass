//
// Created by spect on 11/9/2026.
//

#include "Clock.h"

#include <iomanip>
#include <ostream>

Clock::Clock(const int hour, const int minute, const int second, const bool isCurrentlyPM)
    : hour(hour), minute(minute), second(second), isCurrentlyPM(isCurrentlyPM)
{}

bool Clock::operator<(const Clock& other) const
{
    // AM comes first in the day
    if (isCurrentlyPM == false && other.isCurrentlyPM == true)
        return true;

    else if (isCurrentlyPM == true && other.isCurrentlyPM == false)
        return false;

    const int thisHour = (hour == 12) ? 0 : hour;
    const int otherHour = (other.hour == 12) ? 0 : other.hour;

    if (thisHour != otherHour)
        return thisHour < otherHour;

    else if (minute != other.minute)
        return minute < other.minute;

    return second < other.second;
}

bool Clock::operator==(const Clock& other) const
{
    return hour == other.hour && minute == other.minute && second == other.second && isCurrentlyPM == other.isCurrentlyPM;
}

Clock& Clock::operator++()
{
    // Make clock properly increase by checking for everything bruh
    second++;
    if (second == 60)
    {
        minute++;
        second = 0;
    }
    if (minute == 60)
    {
        hour++;
        minute = 0;
    }
    if (hour == 12)
    {
        isCurrentlyPM = !isCurrentlyPM;
    }
    if (hour > 12)
    {
        hour = 1;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Clock& clock)
{
    const char oldFill = os.fill('0');

    os << std::setw(2) << clock.hour << " : "
       << std::setw(2) << clock.minute << " : "
       << std::setw(2) << clock.second
       << (clock.isCurrentlyPM ? " PM " : " AM ");

    os.fill(oldFill);

    return os;
}
