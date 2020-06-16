#include "Admin.h"
#include "ChildAccount.h"
#include "FamillyAccount.h"
#include "SavingsAccount.h"
#include "Card.h"
#include "CreditCard.h"
#include "DebitCard.h"
#include "RetirementFund.h"
#include "SavingsFund.h"
#include "Encryptor.h"

int Admin::idProvider = 0;
std::map<int, LogInData> Admin::usersMap = std::map<int, LogInData>();

Admin::Admin(const LogInData &data) : LogInData(data), manager(0) {}

Admin::~Admin() {}

/*
 *  Method which creates user and adds him to user map
 */
bool Admin::CreateUser(std::string p_login, std::string p_password, std::string p_email) {
    LogInData data(++idProvider, p_login, p_password, p_email, "");
    if(data.IsValid()) {
        if(!FindExistingUser(data)){
            password = data.GetPassword();
            salt = data.GetSalt();
            Encryptor::encode(password, salt);
            data.SetPassword(password);
            data.SetSalt(salt);
            usersMap.insert({data.GetID(), data});
            std::cerr << "User " << data.GetLogin() << " created" << std::endl;
        }
        else{
            std::cerr << "User " << data.GetLogin() << " already exist" << std::endl;
            return false;
        }
    }
    else {
        return false;
    }
    return true;
}

/*
 * Basic account adding method
*/
bool Admin::AddAccount(int ownerID, std::string number, double balance) {
    Account newAcc(number, balance, ownerID);
    return AddAccountToMap(std::make_shared<Account>(newAcc));
}

/*
 * Add Child Account with a supervisor and daily limit
*/
bool Admin::AddAccount(int supervisorID, int childID, std::string number, double balance,
                       double dailyTransactionLimit) {
    ChildAccount newAcc(number, balance, supervisorID, dailyTransactionLimit, childID);
    return AddAccountToMap(std::make_shared<ChildAccount>(newAcc));
}

/*
 * Familly account with one supervisor and memebers of an account
*/
bool Admin::AddAccount(int supervisorID, std::string number, double balance,
                          std::list<int> memberIdList) {
    FamillyAccount newAcc(number, balance, supervisorID, memberIdList);
    return AddAccountToMap(std::make_shared<FamillyAccount>(newAcc));
}

/*
 * Savings account with interest multiplying balance in detailed amount of time
 */
bool Admin::AddAccount(int ownerID, std::string number, double balance, double interest) {
    SavingsAccount newAcc(number, balance, ownerID, interest);
    return AddAccountToMap(std::make_shared<SavingsAccount>(newAcc));
}

/*
 * Normal card with connected acc number, card number, ccv and transaction limit
 */
bool Admin::AddCard(std::string accountNumber, std::string number, int ccv, double transactionLimit) {
    Card newCard(accountNumber, number, ccv, transactionLimit);
    return AddCardToMap(std::make_shared<Card>(newCard));
}

/*
 * Credit card with connected acc number, card number, ccv, transaction limit, max credit on card and billing date
 */
bool Admin::AddCard(std::string accountNumber, std::string number, int ccv, double transactionLimit,
                    double maxCredit, std::string billingDate) {
    CreditCard newCard(accountNumber, number, ccv, transactionLimit, maxCredit, billingDate);
    return AddCardToMap(std::make_shared<CreditCard>(newCard));
}

/*
 * Debit card with connected acc number, card number, ccv, transaction limit and max debt on card
 */
bool Admin::AddCard(std::string accountNumber, std::string number, int ccv, double transactionLimit,
                    double maxDebt) {
    DebitCard newCard(accountNumber, number, ccv, transactionLimit, maxDebt);
    return AddCardToMap(std::make_shared<DebitCard>(newCard));
}

///*
// * Basic fund with ownerID, minimal amount, maximal rate, fee and balance
// */
//bool Admin::AddFund(int ownerID, double minAmount, double maxRate, double fee, double balance) {
//    Fund newFund(minAmount, maxRate, fee, balance, ownerID);
//    return AddFundToMap(std::make_shared<Fund>(newFund));
//}

/*
 * Retirement fund with monthly in amount and is person retired informations
 */
bool Admin::AddFund(int ownerID, double minAmount, double maxRate, double fee, double balance,
                    bool isRetired, double monthlyIn) {
    RetirementFund newFund(minAmount, maxRate, fee, balance, isRetired, monthlyIn, ownerID);
    return AddFundToMap(std::make_shared<RetirementFund>(newFund));
}

/*
 * Savings fund with starting and ending date
 */
bool Admin::AddFund(int ownerID, double minAmount, double maxRate, double fee, double balance,
                    std::string startDate, std::string endDate) {
    SavingsFund newFund(minAmount, maxRate, fee, balance, startDate, endDate, ownerID);
    return AddFundToMap(std::make_shared<SavingsFund>(newFund));
}

void Admin::OnLogIn() {
    std::cerr << "\nAdmin logged";
    FillUserMap();
    LoadData();
    std::cerr<<"\nData loaded";
}

void Admin::OnLogOut() {
    std::cerr<<"\nAdmin logged out";
    SaveUserMap();
    SaveData();
    std::cerr<<"\nData saved";
}

void Admin::LoadData()
{
     std::list<std::string> p{};
     manager.ParseData(p,Bank::accountMap);
     manager.ParseData(Bank::fundMap);
     manager.ParseData(Bank::cardMap);

}

void Admin::SaveData()
{
     manager.SerializeData(Bank::accountMap,Config::accountJSONPath);
     manager.SerializeData(Bank::fundMap,Config::fundJSONPath);
     manager.SerializeData(Bank::cardMap,Config::cardJSONPath);
}

std::list<std::string> Admin::GetUsersStringList() {
    std::list<std::string> result;
    for(map<int, LogInData>::iterator it = usersMap.begin(); it != usersMap.end(); ++it){
        result.push_back(std::to_string(it->first) + " (" + it->second.GetLogin() + ")");
    }
    return result;
}

std::list<std::string> Admin::GetAccStringList() {
    std::list<std::string> result;
    for(auto it = Bank::accountMap.begin(); it != Bank::accountMap.end(); ++it){
        result.push_back(it->first.data());
    }
    return result;
}

void Admin::FillUserMap() {
    std::fstream file;
    file.open(Config::logInDataPath, std::ios::in);
    if(file.is_open()){
        file.exceptions( std::fstream::badbit );
        try {
            std::string line;
            while(std::getline(file, line)){
                LogInData logInDataFromLine = Authorization::proccesedData(line);
                usersMap.insert(std::make_pair(logInDataFromLine.GetID(), logInDataFromLine));
                idProvider = logInDataFromLine.GetID();
            }
        }
        catch (std::fstream::failure & ex) {
            std::cerr << "Log in data parsing failure: "<< ex.what() << std::endl;
        }
    }
    else{
        std::cerr << "Could not open file with log in data" << std::endl;
    }
    file.close();
}

void Admin::SaveUserMap() {
    std::fstream file;
    file.open(Config::logInDataPath, std::ios::out | std::ios::trunc);
    if(file.is_open()){
        file.exceptions( std::fstream::badbit );
        try {
            for(map<int, LogInData>::iterator it = usersMap.begin(); it != usersMap.end(); ++it){
                file  << it->second << std::endl;
            }
        }
        catch (std::fstream::failure & ex) {
            std::cerr << "Log in data parsing failure: "<< ex.what() << std::endl;
        }
    }
    else{
        std::cerr << "Could not open file with log in data" << std::endl;
    }
    file.close();
}

bool Admin::FindExistingUser(LogInData& data) {
    for(map<int, LogInData>::iterator it = usersMap.begin(); it != usersMap.end(); ++it){
        if(it->second.GetEmail() == data.GetEmail() && it->second.GetLogin() == data.GetLogin()){
            return true;
        }
    }
    return false;
}

bool Admin::AddAccountToMap(std::shared_ptr<Account> acc) {
    if(Bank::accountMap.find(acc->GetNumber()) == Bank::accountMap.end()){
        Bank::accountMap.insert(std::make_pair(acc->GetNumber(), acc));
        return true;
    }
    return false;
}

bool Admin::AddCardToMap(std::shared_ptr<Card> card) {
    if(Bank::cardMap.find(card->GetAccountNumber()) == Bank::cardMap.end()){
        Bank::cardMap.insert({card->GetAccountNumber(), card});
        return true;
    }
    return false;
}

bool Admin::AddFundToMap(std::shared_ptr<Fund> fund) {
    if(Bank::fundMap.find(fund->GetOwnerId()) == Bank::fundMap.end()){
        Bank::fundMap.insert({fund->GetOwnerId(), fund});
        return true;
    }
    return false;
}
