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

    It(Can_detect_if_its_a_neighbour){
        Cell cell(1, 5);
        Cell neighbour(2, 4);
        Assert::That(cell.is_neighbour_to(neighbour), IsTrue());
    }

    It(Can_detect_if_its_not_a_neighbour){
        Cell cell(4, 7);
        Cell neighbour(2, 12);
        Assert::That(cell.is_neighbour_to(neighbour), IsFalse());
    }
};
