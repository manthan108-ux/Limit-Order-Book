#ifndef ORDER_H
#define ORDER_H

class Order {
public:
    int id;
    char side;
    double price;
    int quantity;

    Order(int id_, char side_, double price_, int quantity_)
        : id(id_), side(side_), price(price_), quantity(quantity_) {}
};

#endif // ORDER_H