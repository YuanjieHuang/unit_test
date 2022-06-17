#include "AccountHelper.h"

AccountHelper::AccountHelper(std::map<std::string, Account> &mAccount) {
    m_mapAccounts = mAccount;
}

void AccountHelper::updateAccount(const Account &account) {
    m_mapAccounts[account.getAccountId()] = account;
}

Account AccountHelper::findAccountForUser(const std::string &userId) {
    if (m_mapAccounts.find(userId) != this->m_mapAccounts.end()) 
        return this->m_mapAccounts[userId];
    return Account();
} 