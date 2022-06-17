#pragma once
#include <string>
using namespace std;

class Account {
private:
    string m_strAccountId;
    long m_nBalance;

public:
    Account() : m_strAccountId(""), m_nBalance(0) {;}

    Account(const string &initAccountId, long initialBalance) : m_strAccountId(initAccountId), m_nBalance(initialBalance) {;}

    bool isNil() {
        return m_strAccountId == "";
    }

    void debit(long amount) {
        m_nBalance -= amount;
    }

    void credit(long amount) {
        m_nBalance += amount;
    }

    long getBalance() const {
        return m_nBalance;
    }

    string getAccountId() const {
        return m_strAccountId;
    }

    void SetId(const string &id) {
        m_strAccountId = id;
    }
}; 