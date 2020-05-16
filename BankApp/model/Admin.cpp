#include "Admin.h"

int Admin::idProvider = 0;
std::map<int, LogInData> Admin::usersMap = std::map<int, LogInData>();

Admin::Admin(const LogInData &data) : LogInData(data) {}

Admin::~Admin() {
    OnLogOut();
}

/*
 *  Method which creates user and adds him to user map
 */
bool Admin::CreateUser(std::string p_login, std::string p_password, std::string p_email) {
    LogInData data(idProvider++, p_login, p_password, p_email);
    if(data.IsValid()) {
        if(!FindExistingUser(data)){
            std::cerr << "User " << data.GetLogin() << " created" << std::endl;
            usersMap.insert(std::make_pair(data.GetID(), data));
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
bool Admin::CreateAccount(int ownerID, std::string number, double balance) {
    Account newAcc(number, balance, ownerID);
    return AddAccountToMap(std::make_unique<Account>(newAcc));
}

/*
 * Add Child Account with a supervisor and daily limit
*/
bool Admin::CreateAccount(int supervisorID, int childID, std::string number, double balance,
                       double dailyTransactionLimit) {
    ChildAccount newAcc(number, balance, supervisorID, dailyTransactionLimit, childID);
    return AddAccountToMap(std::make_unique<Account>(newAcc));
}

/*
 * Familly account with one supervisor and memebers of an account
*/
bool Admin::CreateAccount(int supervisorID, std::string number, double balance, std::list<int> memberIdList) {
    FamillyAccount newAcc(number, balance, supervisorID, memberIdList);
    return AddAccountToMap(std::make_unique<Account>(newAcc));
}

/*
 * Savings account with interest multiplying balance in detailed amount of time
 */
bool Admin::CreateAccount(int ownerID, std::string number, double balance, double interest) {
    SavingsAccount newAcc(number, balance, ownerID, interest);
    return AddAccountToMap(std::make_unique<Account>(newAcc));
}

/*
 * Savings account with interest multiplying balance in detailed amount of time
 */
bool Admin::AddCard(std::string accountNumber, std::string number, int ccv, double transactionLimit) {
    Card newCard(accountNumber, number, ccv, transactionLimit);
    return AddCardToMap(std::make_unique<Card>(newCard));
}

/*
 * Basic fund with ownerID, minimal amount, maximal rate, fee and balance
 */
bool Admin::AddFund(int ownerID, double minAmount, double maxRate, double fee, double balance) {
    Fund newFund(minAmount, maxRate, fee, balance, ownerID);
    return AddFundToMap(std::make_unique<Fund>(newFund));
}

/*
 * Retirement fund with monthly in amount and is person retired informations
 */
bool Admin::AddFund(int ownerID, double minAmount, double maxRate, double fee, double balance,
                    bool isRetired, double monthlyIn) {
    RetirementFund newFund(minAmount, maxRate, fee, balance, isRetired, monthlyIn, ownerID);
    return AddFundToMap(std::make_unique<Fund>(newFund));
}

/*
 * Savings fund with starting and ending date
 */
bool Admin::AddFund(int ownerID, double minAmount, double maxRate, double fee, double balance,
                    std::string startDate, std::string endDate) {
    SavingsFund newFund(minAmount, maxRate, fee, balance, startDate, endDate, ownerID);
    return AddFundToMap(std::make_unique<Fund>(newFund));
}

void Admin::OnLogIn() {
    std::cerr << "Admin logged" << std::endl;
    FillUserMap();
}

void Admin::OnLogOut() {
    SaveUserMap();
}

void Admin::FillUserMap() {
    std::fstream file;
    file.open(Config::logInDataPath, std::ios::in | std::ios::app);
    if(file.is_open()){
        file.exceptions( std::fstream::badbit );
        try {
            std::string line;
            while(std::getline(file, line)){
                LogInData logInDataFromLine = Authorization::proccesedData(line);
                usersMap.insert(std::make_pair(logInDataFromLine.GetID(), logInDataFromLine));
                std::cerr << usersMap[logInDataFromLine.GetID()];
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
            for(map<int, LogInData>::iterator it = usersMap.begin(); it != usersMap.end(); ++it ){
                file  << it->second;
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
    for(map<int, LogInData>::iterator it = usersMap.begin(); it != usersMap.end(); ++it ){
        if(it->second == data){
            return true;
        }
    }
    return false;
}

bool Admin::AddAccountToMap(std::unique_ptr<Account> acc) {
    if(Bank::accountMap.find(acc->GetNumber()) == Bank::accountMap.end()){
        Bank::accountMap.insert(std::make_pair(acc->GetNumber(), acc.get()));//
        return true;
    }
    return false;
}

bool Admin::AddCardToMap(std::unique_ptr<Card> card) {
    if(Bank::cardMap.find(card->GetAccountNumber()) == Bank::cardMap.end()){
        Bank::cardMap.insert(std::make_pair(card->GetAccountNumber(), *card.get()));
        return true;
    }
    return false;
}

bool Admin::AddFundToMap(std::unique_ptr<Fund> fund) {
    if(Bank::fundMap.find(fund->GetOwnerId()) == Bank::fundMap.end()){
        Bank::fundMap.insert(std::make_pair(fund->GetOwnerId(), *fund.get()));
        return true;
    }
    return false;
}
