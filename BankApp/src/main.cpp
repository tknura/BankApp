#include "controller/MainWindow.h"

#include "model/Bank.h"
#include "model/Authorization.h"
#include "model/JsonManager.h"
#include "model/RetirementFund.h"
#include <map>
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    Bank::Start();
    JsonManager test(3);
   // test.ParseFriendsData();
   // test.ParseAccountData();
    std::multimap<int,Fund*> mapka{};
   // RetirementFund m{5,5,6,7,false,555};
  //  Fund* p = &m;
   // std::cout<<*p;
   // return 0;
    test.ParseFundData(mapka);
    for(const auto &fundusz: mapka)
    {
        //Fund* pTmp = (fundusz.second);
       // std::cout<<*(pTmp);
        std::cout<<fundusz.first<<":"<<*(fundusz.second)<<"\n";
    }
    return 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
