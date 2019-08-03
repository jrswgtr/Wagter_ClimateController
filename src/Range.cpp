#include <Range.h>

Range::Range( float _min, float _max )
{
    min = _min;
    max = _max;
}
float Range::getMin() const
{
    return min;
}
float Range::getMax() const
{
    return max;
}
bool Range::inRange( float number ) const
{
    return number >= min && number <= max;
}