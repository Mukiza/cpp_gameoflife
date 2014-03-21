#include <igloo/igloo_alt.h>
#include "./../lib/cell.h"
using namespace igloo;

Describe(A_Cell)
{
    It(Should_have_coordinates){
        Cell cell(2, 3);
        Assert::That(cell.get_x(), Equals(2));
        Assert::That(cell.get_y(), Equals(3));
    }
};
