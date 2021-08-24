#include "header.h"

int mfiCalculator(float mfrValue)
{
    int mfiC=0;
    mfiC=(int)(100-(100/(1+mfrValue)));
    return(mfiC);

}