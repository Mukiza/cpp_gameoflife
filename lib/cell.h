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

    bool is_neighbour_to(const Cell& other) const
    {
        return abs(x_ - other.x_) <= 1 && abs(y_ - other.y_) <= 1;
    }
};
