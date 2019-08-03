#include <Lock.h>

bool Lock::isLocked()
{
    return locked;
}
void Lock::setLocked( bool _locked )
{
    locked = _locked;
}