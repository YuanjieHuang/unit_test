#include "Account.h"
#include <map>
using namespace std;

class AccountHelper {
private:
    map<string, Account> m_mapAccounts;
    // an internal map to store all Accounts for test

public:
    AccountHelper(map<std::string, Account> &mAccount);
    AccountHelper() {;}

    void updateAccount(const Account &account);

    Account findAccountForUser(const std::string &userId);
}; 