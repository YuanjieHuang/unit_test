#include "AccountService.h"

AccountService::AccountService() {
    pAccountManager = NULL;
}

void AccountService::setAccountManager(AccountManager *pManager) {
    pAccountManager = pManager;
}

void AccountService::transfer(const string &senderId, const string &beneficiaryId, long amount) {
    Account sender = pAccountManager->findAccountForUser(senderId);
    Account beneficiary = pAccountManager->findAccountForUser(beneficiaryId);

    sender.debit(amount);
    beneficiary.credit(amount);

    pAccountManager->updateAccount(sender);
    pAccountManager->updateAccount(beneficiary);
}

bool AccountService::withdraw(const string &id, long amount) {
    Account owner = pAccountManager->findAccountForUser(id);
    if (owner.isNil()) {
        return false;
    }
    owner.debit(amount); 
    pAccountManager->updateAccount(owner);
    return true;
}

void AccountService::topup(const string &id, long amount) {
    Account owner = pAccountManager->findAccountForUser(id);
    if (owner.isNil()) {
        owner.SetId(id);
    }
    owner.credit(amount); 
    pAccountManager->updateAccount(owner);
}