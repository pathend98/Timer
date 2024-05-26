#pragma once

enum class Orientation
{
    HORIZONTAL,
    VERTICAL
};

class DLine
{
    private:
        Orientation orientation;
        bool on;

    public:
        DLine(const Orientation o);
        void turnOn();
        void turnOff();
        bool isOn();
};
