#ifndef STOCK_H
#define STOCK_H

//I can't hide the from you, but I want you to see what happens when you have a circular dependency
#include <string>
using std::string; 

class Stock
{
	public:
		//**adding c'tor
		Stock();
		Stock(string symbol, int shares, double price = .01);
		string getStockSymbol();
		double getPrice();
		void setPrice(double price);
		int getShares();

		//**Add d'tor
		~Stock();

	private:
		string  m_symbol;
		double m_price;
		int m_shares;
};		//no ;
#endif // !STOCK_H