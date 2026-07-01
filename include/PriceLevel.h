#ifndef PRICE_LEVEL_H
#define PRICE_LEVEL_H

#include <list>
#include "Order.h"

class PriceLevel {
public:
    double price;
    int totalQuantity;
    std::list<Order> orders;

    PriceLevel(double price_)
        : price(price_), totalQuantity(0) {}

    void addOrder(const Order &order) {
        totalQuantity += order.quantity;
        orders.push_back(order);
    }

    int removeOrder(std::list<Order>::iterator it) {
        int qty = it->quantity;
        totalQuantity -= qty;
        orders.erase(it);
        return qty;
    }

    bool empty() const {
        return orders.empty();
    }
};

#endif // PRICE_LEVEL_H