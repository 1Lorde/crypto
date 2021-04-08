//
// created by Vlad Savchuk on 11/12/2020.
//

#include "NoSpecifiedEllipticCurveException.h"

const char *NoSpecifiedEllipticCurveException::what() const noexcept {
    return message.data();
}
