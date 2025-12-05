#pragma once
struct Coords
{
    public:
        int X;
        int Y;

        bool operator==(const Coords& other)
        {
            return X == other.X && Y == other.Y;
        }

        bool operator<(const Coords& other)
        {
            return X < other.X && Y < other.Y;
        }
};
