//
// created by Vlad Savchuk on 11/12/2020.
//

#ifndef SAVCHUK_NOSPECIFIEDELLIPTICCURVEEXCEPTION_H
#define SAVCHUK_NOSPECIFIEDELLIPTICCURVEEXCEPTION_H


#include <exception>
#include <string>

class NoSpecifiedEllipticCurveException : public std::exception {
private:
    std::string message;
public:
    explicit NoSpecifiedEllipticCurveException() {
        message = "Elliptic curve not specified for current points.";
    };

    const char *what() const noexcept override;
};

#endif //SAVCHUK_NOSPECIFIEDELLIPTICCURVEEXCEPTION_H
