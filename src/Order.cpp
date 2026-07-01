#include "Order.h"

Order::Order(int id,
             char side,
             double price,
             int quantity)
    : id(id),
      side(side),
      price(price),
      quantity(quantity)
{
}