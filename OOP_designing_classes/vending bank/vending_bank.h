#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <iostream>
#include <string>
using namespace std;

class VendingBank
{
public:
	//constructors
	VendingBank();
	VendingBank(int id);
	VendingBank(int id, double total_money);
	VendingBank(int id, double total_money, double total_coin);
	VendingBank(int id, double total_money, double penny, double nickel, double dime, double quarter, double half_Dollar, double dollar);
	
	//getters & setters
	int id() const;
	double total_money()const;
	double total_coin()const;
	double penny()const;
	double nickel()const;
	double dime()const;
	double quarter()const;
	double half_dollar()const;
	double dollar()const;
	double snack()const;
	void set_id(int id);
	void set_total_coin(double total_coin);
	void set_total_money(double total_money);
	void set_snack(int snack);
	void set_coins(double penny, double nickel, double dime, double quarter, double half_Dollar, double dollar);

	//actions
	bool InsertCoin(const double coin& payment);
	bool AddCoins(double penny, double nickel, double dime, double quarter, double half_Dollar, double dollar);
	bool GetChange(double value, double returned_penny, double  returned_nickel, double  returned_dime, double  returned_quarter, double  returned_half_Dollar, double  returned_dollar);
	
	
	bool operator==(const VendingBank& bank) const;
	bool operator!=(const VendingBank& bank) const;
	bool operator<(const VendingBank& rhs) const;
	bool operator<=(const VendingBank& rhs) const;
	bool operator>(const VendingBank& rhs) const;
	bool operator>=(const VendingBank& rhs) const;

	friend ostream& operator<<(ostream& stream, const VendingBank& bank);
	
private:
	int id_;
	double total_money_;
	double total_coin_;
	double penny_, nickel_, dime_, quarter_, half_dollar_, dollar_;
	int snack_;
};
#endif
