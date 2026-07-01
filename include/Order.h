#ifndef ORDER_H
#define ORDER_H

class Order
{
public:
    int id;
    char side;
    double price;
    int quantity;

    Order(int id,
          char side,
          double price,
          int quantity);
};

#endif