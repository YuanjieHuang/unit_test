#pragma once
#include <string> 
using namespace std;

#include "Account.h" 
#include "AccountManager.h" 

class AccountService 
{ 
private: 
   AccountManager* pAccountManager; 

public: 
   AccountService(); 

   void setAccountManager(AccountManager* pManager); 

    bool withdraw(const string &id, long amount); 

    void topup(const string &id, long amount); 

   void transfer(const string& senderId, const string& beneficiaryId, long amount); 
};