#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP

#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

enum class Side{
   BUY,
   SELL
};



struct Order{
  int id;
  Side side;
  double price;
  int quantity;
  long long timestamp;
};

class OrderBook{
public:

 void addOrder(const Order &order);
 void cancelOrder(int id);

 void matchOrders();


 void printOrderBook() const;


private:
  std::multimap<double,Order,std::greater<double>> buyOrders;
  std::multimap<double,Order> sellOrders;

  std::map<int,std::pair<Side,std::multimap<double,Order>::iterator>> orderIndex;

  void matchBuyOrder(const Order& order);
  void matchSellOrder(const Order& order);
};
#endif