#include <iostream>
using std::cout;
using std::endl;

#include<string>
using std::string; 

#include "Debugging.h"

//**made default 
Stock::Stock() : m_symbol(), m_shares(0), m_price(0.1)
{
	cout << "Default c'tor" << endl;
}
Stock::Stock(string symbol, int shares, double price)
	: m_symbol(symbol), m_shares(shares), m_price(price)//m_price(shares)
{
	cout << "3 arg c'tor for: " << symbol << endl;
}
string Stock::getStockSymbol()
{
	return m_symbol;
}
double Stock::getPrice()
{
	return m_price;
}
void Stock::setPrice(double price)
{
	m_price = price;	//was prices and backwards 
}
int Stock::getShares()
{
	return m_shares;	//was price
}
Stock::~Stock()
{
	cout << "\nIn " << m_symbol << " d'tor." << endl;
}