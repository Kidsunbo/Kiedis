#include "utils.h"

#include <fcntl.h>

namespace kiedis
{
    bool set_non_blocking(int sock)
    {
        auto opts = fcntl(sock, F_GETFL);
        if (opts < 0)
        {
            return false;
        }
        opts = opts | O_NONBLOCK;
        if (fcntl(sock, F_SETFL, opts) < 0)
        {
            return false;
        }
        return true;
    }

} // namespace kiedis
