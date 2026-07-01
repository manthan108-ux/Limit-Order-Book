#ifndef PRICE_LEVEL_H
#define PRICE_LEVEL_H

#include <list>
#include "Order.h"

class PriceLevel
{
public:
    double price;
    int totalQuantity;
    std::list<Order> orders;

    PriceLevel(double price);

    void addOrder(const Order &order);

    int removeOrder(std::list<Order>::iterator it);

    bool empty() const;
};

#endif