class Cell{
    int x_;
    int y_;

    public:
    Cell(int x, int y) : x_(x), y_(y)
    {
    }

    int get_x() const
    {
        return x_;
    }

    int get_y() const
    {
        return y_;
    }
};
