#include "../../libraries.h"

#define M_PIl 3.141592653589793238462643383279502884L

double radian2degree(double RADIAN) {

    return -(RADIAN * (180 / M_PIl));

}

double degree2radian(double DEGREE) {

    return -(DEGREE * (M_PIl / 180));

}