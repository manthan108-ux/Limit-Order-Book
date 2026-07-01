#include "PriceLevel.h"

PriceLevel::PriceLevel(double price)
    : price(price),
      totalQuantity(0)
{
}

void PriceLevel::addOrder(const Order &order)
{
    totalQuantity += order.quantity;
    orders.push_back(order);
}

int PriceLevel::removeOrder(std::list<Order>::iterator it)
{
    int qty = it->quantity;

    totalQuantity -= qty;

    orders.erase(it);

    return qty;
}

bool PriceLevel::empty() const
{
    return orders.empty();
}