#ifndef GLOBAL_H
#define GLOBAL_H

#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include"init.h"


#endif

using namespace std;
typedef long long ll;

enum TimePeriod {MORNING,AFTERNOON,EVENING,MIDNIGHT};//0,1,2,3



//价格配置
struct Price
{
    double vip_price[4];
    double normal_price[4];

    Price()
    {
        vip_price[MORNING]=2.5;
        normal_price[MORNING]=4.0;

        vip_price[AFTERNOON]=3.0;
        normal_price[AFTERNOON]=5.0;

        vip_price[EVENING]=4.0;
        normal_price[EVENING]=6.0;

        vip_price[MIDNIGHT]=3.5;
        normal_price[MIDNIGHT]=5.5;
    }

    Price(const Price& other)
    {
        for(int i=0; i<4;i++)
        {
            vip_price[i]=other.vip_price[i];
            normal_price[i]=other.normal_price[i];
        }
    }

};

//价格修改记录
struct PriceChangeRecord
{
    time_t changeTime;
    Price oldConfig;
    Price newConfig;
    string operatorName;
};


struct ConsumptionRecord//消费记录
{
    string cardNum;
    string name;
    time_t startTime;
    time_t endTime;
    double hours;
    double amount;
    TimePeriod period;
    string date;//消费日期
    Price priceAtThatTime;//记录当时的计费价格
};

struct card//卡结构体
{
    string num,name;
    int condition;//状态 0已注销,1正常,2上机中
    time_t start_time,end_time;
    double has_used_money;
    int has_used_count;
    double remained_money;
    bool vip;
    double total_consumption;
    double total_hours;
    vector<ConsumptionRecord> history;

    card():condition(1),has_used_money(0),has_used_count(0),remained_money(0),vip(false),start_time(0),end_time(0),total_consumption(0),total_hours(0){}//初始化
};

//存储所有卡容器
vector<card> cards;
Price current_price;
vector<PriceChangeRecord> priceHistory; //价格修改历史
//初始密码
string adminPassword="123456";
string userPassword ="123456";


//文件
const string DATA_FILE="cards_data.txt";
const string RECORDS_FILE = "consumption_records.txt";
const string PRICE_FILE="price_config.txt";
const string PRICE_HISTORY_FILE="price_history.txt";
const string PASSWORD_FILE="password.txt";
const string USER_PASSWORD_FILE="user_password.txt";  


//函数声明
void init();
void userMenu();
void adminMenu();
void insert(); 
void inq(); 
void start_s(); 
void end_s();
void recharge();
void refund();
void statistics();  
void cancel();
void modifyPrice(); 
void showPrice();
void showPriceHistory();
void saveToFile();//保存数据到文件
void loadFromFile();//从文件获取数据
void saveRecords();//保存消费记录
void loadRecords();//获取消费记录
void savePriceConfig(); //保存价格配置
void loadPriceConfig(); //获取价格配置
void savePriceHistory(); //保存价格修改历史
void loadPriceHistory(); //获取价格修改历史
string getTimePeriod(time_t t); //获取时间段
TimePeriod getPeriodEnum(time_t t); //获取时间段枚举
double calculateCost(time_t start,time_t end,bool isVip, const Price& price); //计算费用
void showVIPWelcome(); //显示VIP欢迎语
void showCardDetails(const card&c); //显示卡详细信息
void showTopConsumers(); //显示消费排行
void showTimeDistribution(); //显示时间分布
bool checkAdminPassword();
bool checkUserPassword();
void changeAdminPassword();
void changeUserPassword();
void savePasswords();
void loadPasswords();
void clearAllData();
void showConfirmDialog(); //显示清空数据确认对话框



void userMenu()
{
    cout<<"\n-----*****用户模式*****-----"<<endl;
    cout<<"3.上机"<<endl;
    cout<<"4.下机"<<endl;
    cout<<"0.退出"<<endl;
    cout<<"请输入选项: "<<endl;
}

void adminMenu()
{
    cout<<"\n-----*****管理员模式*****-----"<<endl;
    cout<<"1.添加卡"<<endl;
    cout<<"2.查询卡"<<endl;
    cout<<"3.上机"<<endl;
    cout<<"4.下机"<<endl;
    cout<<"5.充值"<<endl;
    cout<<"6.退费"<<endl;
    cout<<"7.查询统计"<<endl;
    cout<<"8.注销卡"<<endl;
    cout<<"9.修改价格"<<endl;
    cout<<"10.显示当前价格"<<endl;
    cout<<"11.价格修改历史"<<endl;
    cout<<"12.修改管理员密码"<<endl;
    cout<<"13.修改用户密码"<<endl;
    cout<<"14.清空所有数据"<<endl;
    cout<<"0.退出"<<endl;
    cout<<"请输入选项: "<<endl;
}


void init()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

//内部查询
int find_card(const string& num)
{
    for(int i=0;i<cards.size();i++)
    {
        if(cards[i].num==num) return i;
    }

    return -1;
}


string getTimePeriod(time_t t)//前端时间
{
    struct tm* timeinfo=localtime(&t);
    int hour=timeinfo->tm_hour;   //从时间戳中提取出小时数

    if(hour>=6&&hour<12) return"早上(6-12点)";
    else if(hour>=12&&hour<18) return"下午(12-18点)";
    else if(hour>=18&&hour<24) return"晚上(18-24点)";
    else return"凌晨(0-6点)";
}

TimePeriod getPeriodEnum(time_t t)//后端时间
{
    struct tm*timeinfo=localtime(&t);
    int hour=timeinfo->tm_hour;
    
    if(hour>=6&&hour<12) return MORNING;
    else if(hour>=12&&hour<18) return AFTERNOON;
    else if(hour>=18&&hour<24) return EVENING;
    else return MIDNIGHT;
}


double calculateCost(time_t start, time_t end, bool isVip, const Price& price)
{
    double totalCost=0;
    time_t current=start;

    while(current<end)
    {
        struct tm* timeinfo=localtime(&current);
        int hour=timeinfo->tm_hour;
        TimePeriod period=getPeriodEnum(current);//分析时间断

        // 计算当前时间段的下一个小时是否还在同一个时间段
        time_t nextHour=current+3600;
        struct tm* nextTimeinfo=localtime(&nextHour);


        //如果跨时间段只计算到当前时间段结束
        if(getPeriodEnum(nextHour)!=period)
        {
            if(period==MORNING)//到12点
            {
                struct tm target=*timeinfo;
                target.tm_hour=12;
                target.tm_min=0;
                target.tm_sec=0;
                nextHour=mktime(&target);
            }
            else if(period==AFTERNOON)//到18点
            {
                struct tm target=*timeinfo;
                target.tm_hour=18;
                target.tm_min=0;
                target.tm_sec=0;
                nextHour=mktime(&target);
            }
            else if(period == EVENING)//到24点
            {
                struct tm target=*timeinfo;
                target.tm_hour=24;
                target.tm_min=0;
                target.tm_sec=0;
                nextHour=mktime(&target);
            }
            else // MIDNIGHT 到6点
            {
                struct tm target=*timeinfo;
                target.tm_hour=6;
                target.tm_min=0;
                target.tm_sec=0;

                if(target.tm_hour<timeinfo->tm_hour) // 跨天了              
                target.tm_mday+=1;

                nextHour=mktime(&target);
            }

        }

        if(nextHour>end) nextHour=end;//防止超过实际结束时间(因为是加一个小时计算)

        double hours=difftime(nextHour,current)/3600.0;
        double used_price;

        if(isVip) used_price=price.vip_price[period];
        else   used_price=price.normal_price[period];

        totalCost+=hours*used_price;
        current=nextHour;
    }

    return totalCost;
}


// 显示当前价格
void showPrice()
{
    cout<<"\n*****当前价格配置*****"<<endl;
    cout<<"时段\t\t普通价格\tVIP价格"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"早上(6-12点) \t"<<fixed<<setprecision(2)<<current_price.normal_price[MORNING]<<"元/小时\t"<<current_price.vip_price[MORNING] << "元/小时" << endl;
    cout<<"下午(12-18点)\t"<<current_price.normal_price[AFTERNOON]<<"元/小时\t"<<current_price.vip_price[AFTERNOON]<<"元/小时"<<endl;
    cout<<"晚上(18-24点)\t"<<current_price.normal_price[EVENING]<<"元/小时\t"<<current_price.vip_price[EVENING]<<"元/小时"<<endl;
    cout<<"凌晨(0-6点)  \t"<<current_price.normal_price[MIDNIGHT]<<"元/小时\t"<<current_price.vip_price[MIDNIGHT]<<"元/小时"<<endl;
}

void showPriceHistory()
{
    if(priceHistory.empty())
    {
        cout<<"暂无价格修改记录"<<endl;
        return;
    }

    cout<<"\n*****价格修改历史*****"<<endl;
    for(const auto&record:priceHistory)
    {
        cout<<"修改时间: "<<ctime(&record.changeTime);
        cout<<"操作员: "<<record.operatorName<<endl;


        cout<<"旧价格:"<<endl;
        cout<<"  早上: 普通"<<fixed<<setprecision(2)<<record.oldConfig.normal_price[MORNING]<<"元, VIP"<<record.oldConfig.vip_price[MORNING]<<"元"<<endl;
        cout<<" 下午: 普通"<<record.oldConfig.normal_price[AFTERNOON]<<"元, VIP"<<record.oldConfig.vip_price[AFTERNOON]<<"元"<<endl;
        cout<<"  晚上: 普通"<<record.oldConfig.normal_price[EVENING]<<"元, VIP"<<record.oldConfig.vip_price[EVENING]<<"元"<<endl;
        cout<<"  凌晨: 普通"<<record.oldConfig.normal_price[MIDNIGHT]<<"元, VIP"<<record.oldConfig.vip_price[MIDNIGHT]<<"元"<<endl;
        

        cout<<"新价格:"<<endl;
        cout<<"  早上: 普通" <<record.newConfig.normal_price[MORNING]<<"元, VIP"<<record.newConfig.vip_price[MORNING]<<"元"<<endl;
        cout<<"  下午: 普通" <<record.newConfig.normal_price[AFTERNOON]<<"元, VIP"<<record.newConfig.vip_price[AFTERNOON]<<"元"<<endl;
        cout<<"  晚上: 普通" <<record.newConfig.normal_price[EVENING]<<"元, VIP"<<record.newConfig.vip_price[EVENING]<<"元"<<endl;
        cout<<"  凌晨: 普通" <<record.newConfig.normal_price[MIDNIGHT]<<"元, VIP"<<record.newConfig.vip_price[MIDNIGHT]<<"元"<<endl;
        
        cout << "----------------------------------------" << endl;
    }
}



void modifyPrice()
{
    cout<<"-----修改价格配置-----"<<endl;
    showPrice();

    Price new_price = current_price;  //复制当前价格作为基础

    cout<<"\n请输入新的价格(输入-1保持原价不变):"<<endl;

    double temp;

    //修改早上价格
    cout<<"早上普通价格 (当前: "<<current_price.normal_price[MORNING]<<"): ";
    cin>>temp;
    if(temp>=0) new_price.normal_price[MORNING]=temp;
    
    cout<<"早上VIP价格 (当前: "<<current_price.vip_price[MORNING]<<"): ";
    cin>>temp;
    if(temp>=0) new_price.vip_price[MORNING]=temp;
    
    //修改下午价格
    cout<<"下午普通价格 (当前: "<<current_price.normal_price[AFTERNOON]<<"): ";
    cin>>temp;
    if(temp>=0) new_price.normal_price[AFTERNOON]=temp;
    
    cout<<"下午VIP价格 (当前: "<<current_price.vip_price[AFTERNOON]<<"): ";
    cin>>temp;
    if(temp>=0) new_price.vip_price[AFTERNOON]=temp;
    
    //修改晚上价格
    cout<<"晚上普通价格 (当前: "<<current_price.normal_price[EVENING]<<"): ";
    cin>>temp;
    if(temp>=0) new_price.normal_price[EVENING]=temp;
    
    cout<<"晚上VIP价格 (当前: "<<current_price.vip_price[EVENING]<<"): ";
    cin>>temp;
    if(temp>=0) new_price.vip_price[EVENING]=temp;
    
    // 修改凌晨价格
    cout<<"凌晨普通价格 (当前: "<<current_price.normal_price[MIDNIGHT]<<"): ";
    cin>>temp;
    if(temp>=0)new_price.normal_price[MIDNIGHT]=temp;
    
    cout<<"凌晨VIP价格 (当前: "<<current_price.vip_price[MIDNIGHT]<<"): ";
    cin>>temp;
    if(temp>=0) new_price.vip_price[MIDNIGHT]=temp;


    cout<<"\n新价格配置:"<<endl;
    cout<<"早上: 普通"<<new_price.normal_price[MORNING]<<" VIP"<<new_price.vip_price[MORNING]<<endl;
    cout<<"下午: 普通"<<new_price.normal_price[AFTERNOON]<<" VIP"<<new_price.vip_price[AFTERNOON]<<endl;
    cout <<"晚上: 普通" << new_price.normal_price[EVENING]<<" VIP"<<new_price.vip_price[EVENING]<<endl;
    cout <<"凌晨: 普通" << new_price.normal_price[MIDNIGHT]<<" VIP"<<new_price.vip_price[MIDNIGHT]<<endl;


    cout<<"确认修改？(y/n): ";
    char confirm;  cin >>confirm;

    if(confirm=='y'||confirm=='Y')
    {
        PriceChangeRecord record;
        record.changeTime=time(nullptr);
        record.oldConfig=current_price;
        record.newConfig=new_price;
        cout<<"请输入操作员姓名: ";
        cin>>record.operatorName;
        
        priceHistory.push_back(record);
        
        // 更新当前价格
        current_price=new_price;
        
        // 保存到文件
        savePriceConfig();
        savePriceHistory();

        cout<<"价格修改成功！新价格将从下一次上机开始生效。"<<endl;
        cout<<"之前的消费记录仍按旧价格计算。"<<endl;
    }
    else
    {
        cout<<"修改已取消"<<endl;
    }
}


// 保存价格配置
void savePriceConfig()
{
    ofstream outFile(PRICE_FILE);
    if(!outFile) return;
    
    for(int i=0; i<4;i++)
    {
        outFile<<fixed<<setprecision(2)<<current_price.normal_price[i]<<endl;
        outFile<<fixed<<setprecision(2)<<current_price.vip_price[i]<<endl;
    }
    
    outFile.close();
}

// 加载价格配置
void loadPriceConfig()
{
    ifstream inFile(PRICE_FILE);
    if(!inFile)
    {
        //文件不存在，使用默认价格
        current_price=Price();
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        inFile>>current_price.normal_price[i];
        inFile>>current_price.vip_price[i];
    }
    
    inFile.close();
}



// 保存价格修改历史
void savePriceHistory()
{
    ofstream outFile(PRICE_HISTORY_FILE);
    if(!outFile) return;
    
    outFile<<priceHistory.size()<<endl;
    
    for(const auto& record : priceHistory)
    {
        outFile<<record.changeTime<<endl;
        outFile<<record.operatorName<<endl;
        
        // 保存旧价格
        for(int i=0;i<4;i++)
        {
            outFile<<fixed<<setprecision(2)<<record.oldConfig.normal_price[i]<<endl;
            outFile<<fixed<<setprecision(2)<<record.oldConfig.vip_price[i]<<endl;
        }
        
        // 保存新价格
        for(int i=0; i < 4;i++)
        {
            outFile<<fixed<<setprecision(2)<<record.newConfig.normal_price[i]<<endl;
            outFile<<fixed<<setprecision(2)<<record.newConfig.vip_price[i]<<endl;
        }
    }
    
    outFile.close();
}

//获取价格修改历史
void loadPriceHistory()
{
    ifstream inFile(PRICE_HISTORY_FILE);
    if(!inFile) return;
    
    int size;
    inFile>>size;
    inFile.ignore();
    
    for(int i=0;i<size;i++)
    {
        PriceChangeRecord record;
        inFile>>record.changeTime;
        inFile.ignore();
        getline(inFile,record.operatorName);
        
        // 加载旧价格
        for(int j = 0; j < 4; j++)
        {
            inFile>>record.oldConfig.normal_price[j];
            inFile>>record.oldConfig.vip_price[j];
        }
        
        // 加载新价格
        for(int j = 0; j < 4; j++)
        {
            inFile>>record.newConfig.normal_price[j];
            inFile>>record.newConfig.vip_price[j];
        }
        
        priceHistory.push_back(record);
    }
    
    inFile.close();
}

void loadPasswords()
{
    ifstream adminFile(PASSWORD_FILE);//尝试打开密码文件

    if(!adminFile)  adminPassword="123456"; //如果不存在使用默认密码
    else
    {
        getline(adminFile, adminPassword);
        adminFile.close();
    }

    ifstream userFile(USER_PASSWORD_FILE);
    if(!userFile) userPassword="123456";
    else
    {
        getline(userFile, userPassword);
        userFile.close();
    }
}

void savePasswords()
{
    ofstream adminFile(PASSWORD_FILE);
    if(adminFile)
    {
        adminFile<<adminPassword<<endl;
        adminFile.close();
    }
    
    ofstream userFile(USER_PASSWORD_FILE);
    if(userFile)
    {
        userFile<<userPassword<<endl;
        userFile.close();
    }
}

bool checkAdminPassword()
{
    string input;
    int attempts=3;
    
    while(attempts>0)
    {
        cout<<"\n请输入管理员密码: "<<endl;
        
        char ch;
        input="";
        
        while((ch=_getch())!='\r')
        {
            if(ch=='\b')
            {
                if(input.length()>0)
                {
                    input.pop_back();//删除最后一个字符
                    cout<<"\b \b";//屏幕上删除一个星号
                }
            }
            else
            {
                input += ch;
                cout<<"*";
            }
        }
        cout<<endl;
        
        if(input==adminPassword)
        {
            cout<<"管理员密码正确！"<<endl;
            return true;
        }
        else
        {
            attempts--;
            if(attempts > 0)
            {
                cout<<"密码错误！还剩 "<<attempts<<" 次机会。"<<endl;
            }
            else
            {
                cout<<"管理员密码错误次数过多！"<<endl;
            }
        }
    }
    
    return false;
}


bool checkUserPassword()
{
    string input;
    int attempts=3;
    
    while(attempts>0)
    {
        cout<<"\n请输入用户密码: "<<endl;
        
        char ch;
        input="";
        
        while((ch=_getch())!='\r')
        {
            if(ch=='\b')
            {
                if(input.length()>0)
                {
                    input.pop_back();
                    cout<<"\b \b";
                }
            }
            else
            {
                input+=ch;
                cout<<"*";
            }
        }
        cout<<endl;
        
        if(input==userPassword)
        {
            cout<<"用户密码正确！"<<endl;
            return true;
        }
        else
        {
            attempts--;
            if(attempts>0)
            {
                cout<<"密码错误！还剩 "<<attempts<<" 次机会。"<<endl;
            }
            else
            {
                cout<<"用户密码错误次数过多！"<<endl;
            }
        }
    }
    
    return false;
}


void changeAdminPassword()
{
    //先验证旧密码
    string oldPass;
    cout<<"请输入原管理员密码: "<<endl;
    
    char ch;
    oldPass="";
    while((ch=_getch())!='\r')
    {
        if(ch=='\b')
        {
            if(oldPass.length()>0)
            {
                oldPass.pop_back();
                cout<<"\b \b";
            }
        }
        else
        {
            oldPass += ch;
            cout<<"*";
        }
    }
    cout<<endl;
    
    if(oldPass!=adminPassword)
    {
        cout<<"原密码错误！"<<endl;
        return;
    }
    
    // 输入新密码
    string newPass1,newPass2;
    
    cout<<"请输入新管理员密码: "<<endl;
    newPass1="";
    while((ch=_getch())!='\r')
    {
        if(ch=='\b')
        {
            if(newPass1.length()>0)
            {
                newPass1.pop_back();
                cout<<"\b \b";
            }
        }
        else
        {
            newPass1+=ch;
            cout<<"*";
        }
    }
    cout<<endl;
    
    cout<<"请再次输入新管理员密码: "<<endl;
    newPass2="";
    while((ch=_getch())!='\r')
    {
        if(ch=='\b')
        {
            if(newPass2.length()>0)
            {
                newPass2.pop_back();
                cout<<"\b \b";
            }
        }
        else
        {
            newPass2+=ch;
            cout<<"*";
        }
    }
    cout<<endl;
    
    if(newPass1!=newPass2)
    {
        cout<<"两次输入的密码不一致！"<<endl;
        return;
    }
    
    if(newPass1.empty())
    {
        cout<<"密码不能为空！"<<endl;
        return;
    }
    
    adminPassword = newPass1;
    savePasswords();
    cout<<"管理员密码修改成功！"<<endl;
}


void changeUserPassword()
{
    //先验证旧密码
    string oldPass;
    cout<<"请输入原用户密码: "<<endl;
    
    char ch;
    oldPass="";
    while((ch=_getch())!='\r')
    {
        if(ch=='\b')
        {
            if(oldPass.length()>0)
            {
                oldPass.pop_back();
                cout<<"\b \b";
            }
        }
        else
        {
            oldPass+=ch;
            cout<<"*";
        }
    }
    cout<<endl;
    
    if(oldPass!=userPassword)
    {
        cout<<"原密码错误！"<<endl;
        return;
    }
    
    // 输入新密码
    string newPass1,newPass2;
    
    cout<<"请输入新用户密码: "<<endl;
    newPass1="";
    while((ch=_getch())!='\r')
    {
        if(ch=='\b')
        {
            if(newPass1.length()>0)
            {
                newPass1.pop_back();
                cout<<"\b \b";
            }
        }
        else
        {
            newPass1+=ch;
            cout<<"*";
        }
    }
    cout<<endl;
    
    cout<<"请再次输入新用户密码: "<<endl;
    newPass2="";
    while((ch=_getch())!='\r')
    {
        if(ch=='\b')
        {
            if(newPass2.length()>0)
            {
                newPass2.pop_back();
                cout<<"\b \b";
            }
        }
        else
        {
            newPass2+=ch;
            cout<<"*";
        }
    }
    cout<<endl;
    
    if(newPass1!=newPass2)
    {
        cout<<"两次输入的密码不一致！"<<endl;
        return;
    }
    
    if(newPass1.empty())
    {
        cout<<"密码不能为空！"<<endl;
        return;
    }
    
    userPassword=newPass1;
    savePasswords();
    cout<<"用户密码修改成功！"<<endl;
}



void showVIPWelcome()
{
    cout<<"\n******************"<<endl;
    cout<<"恭喜成为尊贵的VIP用户!"<<endl;
    cout<<"享受全天优惠价格！"<<endl;
    cout<<"******************"<<endl;
}


void showCardDetails(const card& c)// 显示卡详细信息
{
    cout<<"\n════════════ 卡详细信息 ════════════"<<endl;
    cout<<"卡号: "<<c.num<<endl;
    cout<<"姓名: "<< c.name<<endl;

    cout<<"状态: "<<(c.condition==1 ? "正常" : (c.condition==2 ? "上机中^^" : "已注销X"))<< endl;
    cout<<"会员等级:"<<(c.vip ? "***VIP***" : "普通")<<endl;
    cout<<"当前余额:"<<fixed<<setprecision(2)<<c.remained_money<<"元"<< endl;//保留两位小数

    cout<<"════════════ 累计统计 ════════════"<< endl;
    cout<<"累计消费金额: "<<c.total_consumption<<"元"<<endl;
    cout<<"累计上机时长: "<<c.total_hours<<"小时"<<endl;
    cout<<"累计上机次数: "<<c.has_used_count<<"次" <<endl;

    cout<<"平均每次消费: "<<(c.has_used_count > 0 ? c.total_consumption / c.has_used_count : 0) <<"元"<< endl;
    cout<<"平均每次时长: "<<(c.has_used_count > 0 ? c.total_hours / c.has_used_count : 0) <<"小时"<< endl;


    if(c.condition==2)
    {
        cout << "════════════ 当前上机 ════════════" << endl;
        cout << "上机开始时间: "<<ctime(&c.start_time);
        time_t now=time(nullptr);//获取当前时间戳
        double currentHours=difftime(now,c.start_time)/3600.0;
        cout << "已上机时长: " << currentHours <<"小时"<<endl;
        cout << "预计消费: " << calculateCost(c.start_time,now,c.vip,current_price)<<"元"<<endl;
    }


    // 显示最近5条消费记录
    if(!c.history.empty())
    {
        cout << "════════════ 最近消费记录 ════════════"<<endl;
        int count=0;
        for(auto it=c.history.rbegin();it!=c.history.rend()&&count<5;it++,count++)
        {
            cout<<"时间: "<<ctime(&it->startTime);
            cout<<"时长: "<<it->hours<<"小时,金额:"<<it->amount<<"元"<<endl;
            cout<<"时间段: "<<getTimePeriod(it->startTime)<<endl;
            cout<<"----------------------------"<<endl;
        }
    }

    cout<<"═══════════════════════════════════"<<endl;
}


// 保存数据到文件
void saveToFile()
{
    ofstream outFile(DATA_FILE);
    if(!outFile)
    {
        cout<<"无法打开文件保存数据"<<endl;
        return;
    }

    outFile<<cards.size()<<endl;

    for(const auto& c:cards)
    {
        outFile<<c.num<<endl;
        outFile<<c.name<<endl;
        outFile<<c.condition<<endl;
        outFile<<c.start_time<<endl;
        outFile<<c.end_time<<endl;
        outFile<<fixed<<setprecision(2)<<c.has_used_money<<endl;
        outFile<<c.has_used_count << endl;
        outFile<<fixed<<setprecision(2)<<c.remained_money<<endl;
        outFile<<c.vip<<endl;
        outFile<<fixed<<setprecision(2)<<c.total_consumption<<endl;
        outFile<<fixed<<setprecision(2)<<c.total_hours<<endl;
    }

    outFile.close();
    saveRecords(); //保存消费记录
}

//从文件获取数据
void loadFromFile()
{
    ifstream inFile(DATA_FILE);
    if(!inFile)
    {
        cout<<"未找到数据文件，将创建新数据文件"<< endl;
        return;
    }

    cards.clear();

    int size;
    inFile>>size;
    inFile.ignore();//跳过换行

    for(int i=0;i<size;i++)
    {
        card c;
        getline(inFile,c.num);
        getline(inFile,c.name);
        inFile>>c.condition;
        inFile>>c.start_time;
        inFile>>c.end_time;
        inFile>>c.has_used_money;
        inFile>>c.has_used_count;
        inFile>>c.remained_money;
        inFile>>c.vip;
        inFile>>c.total_consumption;
        inFile>>c.total_hours;
        inFile.ignore();
        
        cards.push_back(c);
    }

    inFile.close();
    loadRecords(); //获取消费记录

    cout<<"数据加载成功！共加载"<<cards.size()<<"张卡"<<endl;

}


// 保存全店消费记录
void saveRecords()
{
    ofstream outFile(RECORDS_FILE);
    if(!outFile) return;

    int totalRecords=0;
    for(const auto&c:cards) totalRecords+=c.history.size();

    outFile<<totalRecords<<endl;

    for(const auto& c:cards)//遍历每一张卡
    {
        for(const auto&record:c.history)//遍历每一张卡的消费记录
        {
            outFile<<record.cardNum<<endl;
            outFile<<record.name<<endl;
            outFile<<record.startTime<<endl;
            outFile<<record.endTime<<endl;
            outFile<<fixed<<setprecision(2)<<record.hours<<endl;
            outFile<<fixed<<setprecision(2)<<record.amount<<endl;
            outFile<<record.period<<endl;
            outFile<<record.date<<endl;
        }
    }

    outFile.close();
}

//获取全店消费记录
void loadRecords()
{
    ifstream inFile(RECORDS_FILE);
    if(!inFile) return;

    int totalRecords;
    inFile>>totalRecords;
    inFile.ignore();

    for(int i=0; i<totalRecords;i++)
    {
        ConsumptionRecord record;
        getline(inFile,record.cardNum);
        getline(inFile,record.name);
        inFile>>record.startTime;
        inFile>>record.endTime;
        inFile>>record.hours;
        inFile>>record.amount;

        int periodInt;
        inFile>>periodInt;
        record.period=static_cast<TimePeriod>(periodInt);//整数转换为枚举类型

        inFile.ignore();
        getline(inFile,record.date);

        for(int j=0; j<4;j++)
        {
            inFile>>record.priceAtThatTime.normal_price[j];
            inFile>>record.priceAtThatTime.vip_price[j];
        }


        //找到对应的卡并添加记录
        int pos=find_card(record.cardNum);
        if(pos!=-1) cards[pos].history.push_back(record);
        
    }

    inFile.close();
}

// 显示消费排行
void showTopConsumers()
{
    if(cards.empty())
    {
        cout <<"暂无消费记录!"<<endl;
        return;
    }
    
    vector<card> sortedByAmount=cards;
    sort(sortedByAmount.begin(), sortedByAmount.end(),[](const card& a, const card& b){return a.total_consumption>b.total_consumption;});
    
    cout << "$$$$$消费金额排行榜$$$$$"<<endl;
    for(int i=0; i<min(5,(int)sortedByAmount.size());i++)
    {
        cout<<"第"<< i+1 <<"名:"<< sortedByAmount[i].name<<"(卡号:"<<sortedByAmount[i].num << ")"<<endl;
        cout<<" 累计消费: "<<fixed<<setprecision(2)<<sortedByAmount[i].total_consumption<<"元"<<endl;
    }
}

void showTimeDistribution()
{
    int morningCount=0,afternoonCount=0,eveningCount=0,midnightCount=0;
    double morningAmount=0,afternoonAmount=0,eveningAmount=0,midnightAmount=0;

    for(const auto&c:cards)
    {
        for(const auto&record:c.history)
        {
            switch(record.period)
            {
                case MORNING:
                    morningCount++;
                    morningAmount+=record.amount;
                    break;
                case AFTERNOON:
                    afternoonCount++;
                    afternoonAmount+=record.amount;
                    break;
                case EVENING:
                    eveningCount++;
                    eveningAmount+=record.amount;
                    break;
                case MIDNIGHT:
                    midnightCount++;
                    midnightAmount+=record.amount;
                    break;
            }
        }
    }

    int total=morningCount+afternoonCount+eveningCount+midnightCount;

    cout<<"\n& & &消费时间分布& & &"<<endl;
    if(total>0)
    {
        cout<<"早上(6-12点): "<<morningCount<<"次, "<<fixed<<setprecision(1)<<(morningCount* 100.0/total)<<"%"<<endl;
        cout<<"  消费金额: "<<morningAmount<<"元"<<endl;
        
        cout<<"下午(12-18点): "<<afternoonCount<<"次, "<<(afternoonCount*100.0/total)<<"%"<<endl;
        cout<<"  消费金额: "<<afternoonAmount<<"元"<<endl;
        
        cout<<"晚上(18-24点): "<<eveningCount<<"次, "<<(eveningCount*100.0/total)<<"%"<<endl;
        cout<<"  消费金额: "<<eveningAmount<<"元"<<endl;
        
        cout<<"凌晨(0-6点): "<<midnightCount<<"次, "<<(midnightCount*100.0/total)<<"%"<<endl;
        cout<<"  消费金额: "<<midnightAmount<<"元"<<endl;
    }

    else cout<<"暂无消费记录！"<<endl;
}


void insert()
{
    card newCard;
    cout<<"请输入卡号: "<<endl;
    cin>>newCard.num;

    if(find_card(newCard.num)!=-1)
    {
        cout<<"卡号已存在！"<<endl;
        return;
    }

    cout<<"请输入姓名: "<<endl;
    cin>>newCard.name;
    cout<<"请输入初始金额: "<<endl;
    cin>>newCard.remained_money;
    cout<<"是否VIP(1-是,0-否): "<<endl;
    cin>>newCard.vip;

    if(newCard.vip) showVIPWelcome();

    newCard.condition=1;
    cards.push_back(newCard);

    cout<<"添加成功！卡号: "<<newCard.num<<endl;
    saveToFile();
}


void inq()
{
    string num;
    cout<<"请输入要查询的卡号: "<<endl;
    cin>>num;
    
    int pos=find_card(num);
    if(pos == -1)
    {
        cout << "未找到该卡！"<<endl;
        return;
    }
    
    showCardDetails(cards[pos]);
}

void start_s()
{
    string num;
    cout<<"请输入上机的卡号: "<<endl;
    cin>>num;

    int pos=find_card(num);
    if(pos==-1)
    {
        cout<<"未找到该卡！"<<endl;
        return;
    }

    card& c=cards[pos];
    if(c.condition!=1)
    {
        cout<<"该卡无法上机！"<<endl;
        return;
    }
    
    if(c.remained_money <= 0)
    {
        cout <<"余额不足，请充值"<<endl;
        return;
    }


    c.condition=2;
    c.start_time=time(nullptr);

    cout<<"上机成功！开始时间: "<<ctime(&c.start_time)<<endl;
    cout<<"当前时段: "<<getTimePeriod(c.start_time)<<endl;

    cout<<"当前价格: "<<(c.vip ? current_price.vip_price[getPeriodEnum(c.start_time)] : current_price.normal_price[getPeriodEnum(c.start_time)]) <<"元/小时"<<endl;

    saveToFile();
}


void end_s()
{
    string num;
    cout<<"请输入下机的卡号: "<<endl;
    cin>>num;

    int pos=find_card(num);
    if(pos == -1)
    {
        cout<<"未找到该卡！"<<endl;
        return;
    }


    card&c=cards[pos];
    if(c.condition!=2)
    {
        cout<<"该卡未在上机状态！"<<endl;
        return;
    }

    c.end_time=time(nullptr);

    double hours=difftime(c.end_time,c.start_time)/3600.0;
    double cost=calculateCost(c.start_time,c.end_time,c.vip,current_price);

    ConsumptionRecord record;
    record.cardNum=c.num;
    record.name=c.name;
    record.startTime=c.start_time;
    record.endTime=c.end_time;
    record.hours=hours;
    record.amount=cost;
    record.period=getPeriodEnum(c.start_time);
    record.priceAtThatTime=current_price;//保存当时的计费价格

    time_t now=time(nullptr);
    record.date=ctime(&now);

    c.history.push_back(record);

    // 更新累计数据
    c.has_used_money+=cost;
    c.total_consumption+=cost;
    c.total_hours+=hours;
    c.has_used_count++;
    c.remained_money-=cost;
    c.condition=1;


    cout<<"\n^^^下机成功!^^^"<<endl;
    cout<<"════════════ 消费详情 ════════════"<<endl;
    cout<<"上机时长: "<<fixed<<setprecision(2)<<hours<<"小时"<<endl;
    cout<<"消费金额: "<<cost<<"元"<<endl;
    cout<<"当前余额: "<<c.remained_money<<"元"<<endl;
    cout<<"本次时段: "<< getTimePeriod(c.start_time)<<endl;
    cout<<"═══════════════════════════════════"<<endl;

    saveToFile();
}

   
void recharge()
{
    string num;
    double money;
    cout<<"请输入要充值的卡号: "<<endl;
    cin>>num;
    cout<<"请输入充值金额: "<<endl;
    cin>>money;

    int pos=find_card(num);

    if(pos==-1)
    {
        cout<<"未找到该卡!"<<endl;
        return;
    }
    
    card& c=cards[pos];
    if(c.condition==0)
    {
        cout<<"该卡已注销，无法充值"<<endl;
        return;
    }

    c.remained_money += money;

    if(money>=100)
    {
        double bonus=10;
        c.remained_money+=bonus;
        cout<<"$$$$$充值满100元,赠送10元!$$$$$"<<endl;
    }
    
    cout<<"充值成功！当前余额: "<<fixed<<setprecision(2)<<c.remained_money<<"元"<<endl;
    saveToFile();
}


void refund()
{
    string num;
    double money;
    cout<<"请输入要退费的卡号: "<<endl;
    cin>>num;
    cout<<"请输入退费金额: "<<endl;
    cin>>money;
    
    int pos=find_card(num);
    if(pos==-1)
    {
        cout<<"未找到该卡！"<<endl;
        return;
    }
    
    card& c=cards[pos];
    if(c.condition == 0)
    {
        cout<<"该卡已注销，无法退费！"<<endl;
        return;
    }
    
    if(c.remained_money<money)
    {
        cout<<"余额不足，无法退费！"<<endl;
        return;
    }
    
    c.remained_money-=money;
    cout<<"退费成功！当前余额: "<<fixed<<setprecision(2)<<c.remained_money<<"元"<<endl;
    saveToFile();
}


void statistics()
{
    double total_income=0;
    int total_count=0;
    double total_balance=0;
    int vip_count=0;
    int normal_count=0;
    int online_count=0;
    int canceled_count=0;
    double total_hours_all=0;
    
    for(auto&c :cards)
    {
        total_income+=c.total_consumption;
        total_count+=c.has_used_count;
        total_balance+=c.remained_money;
        total_hours_all+=c.total_hours;

        if(c.vip) vip_count++;
        else normal_count++;
        
        if(c.condition==2) online_count++;
        else if(c.condition==0) canceled_count++;
    }
    
    cout<<"\n||||||营业统计报表||||||"<<endl;
    cout<<"════════════ 基础统计 ════════════"<<endl;
    cout<<"总卡数: "<<cards.size()<<"张"<<endl;
    cout<<"  - 正常卡: "<<(cards.size()-online_count-canceled_count)<<"张"<<endl;
    cout<<"  - 上机中: "<<online_count<<"张 "<<endl;
    cout<<"  - 已注销: "<<canceled_count<<"张 "<<endl;
    cout<<"VIP卡数: " <<vip_count<<"张 " <<endl;
    cout<<"普通卡数: " <<normal_count <<"张"<<endl;
    
    cout<<"\n════════════ 营收统计 ════════════"<<endl;
    cout<<"总营业额: " << fixed << setprecision(2)<<total_income<<"元"<<endl;
    cout<<"总上机次数: "<<total_count<<"次"<<endl;
    cout<<"总上机时长: "<<total_hours_all<<"小时 "<<endl;
    
    showTopConsumers();
    showTimeDistribution();
    showPrice(); //显示当前价格
    
    cout<<"\n═══════════════════════════════════"<<endl;
}

void cancel()
{
    string num;
    cout<<"请输入要注销的卡号: "<<endl;
    cin>>num;
    
    int pos=find_card(num);
    if(pos==-1)
    {
        cout<<"未找到该卡！"<<endl;
        return;
    }
    
    card& c=cards[pos];
    if(c.condition==2)
    {
        cout<<"该卡正在上机中，请先下机！"<<endl;
        return;
    }
    
    if(c.condition==0)
    {
        cout <<"该卡已注销！"<<endl;
        return;
    }
    
    cout<<"\n用户消费总结:"<<endl;
    cout<<"累计消费: " <<c.total_consumption << "元"<<endl;
    cout<<"累计时长: " <<c.total_hours << "小时"<<endl;
    cout<<"累计次数: " <<c.has_used_count << "次"<<endl;
    
    c.condition=0;
    
    if(c.remained_money>0)
    {
        cout<<"卡内余额 "<<c.remained_money<<"元，已自动退费。"<<endl;
        c.remained_money=0;
    }
    
    cout <<"注销成功！感谢您的使用！"<<endl;
    saveToFile();
}

// 显示确认对话框
void showConfirmDialog()
{
    cout<<"\n!!!!!警告!!!!!"<<endl;
    cout<<"此操作将永久删除所有卡数据和消费记录！"<<endl;
    cout<<"包括：所有卡信息、消费记录、价格修改历史"<<endl;
    cout<<"此操作不可恢复！"<<endl;
    cout<<endl;
}


// 清空所有数据
void clearAllData()
{
    showConfirmDialog();
    
    cout<<"请输入管理员密码确认操作: "<<endl;
    string input;
    
    char ch;
    input="";
    while((ch=_getch())!='\r')
    {
        if(ch=='\b')
        {
            if(input.length()>0)
            {
                input.pop_back();
                cout<<"\b \b";
            }
        }
        else
        {
            input+=ch;
            cout<<"*";
        }
    }
    cout<<endl;
    
    if(input!=adminPassword)
    {
        cout<<"密码错误，操作取消！"<<endl;
        return;
    }
    
    cout<<"\n请再次确认是否清空所有数据?(y/n): "<<endl;
    char confirm;
    cin>>confirm;
    
    if(confirm=='y'||confirm=='Y')
    {
        cards.clear();
        priceHistory.clear();
        current_price = Price();
        
        remove(DATA_FILE.c_str());
        remove(RECORDS_FILE.c_str());
        remove(PRICE_HISTORY_FILE.c_str());
        
        savePriceConfig();
        
        cout<<"\n!所有数据已清空!"<<endl;
        cout<<"系统已恢复到初始状态。"<<endl;
    }
    else
    {
        cout<<"操作已取消。"<<endl;
    }
}



int main()
{
    
    untie();

    cout<<"^^^^^^欢迎使用网吧计费系统^^^^^^"<<endl;

     loadPasswords();//修改这里：加载所有密码
    loadPriceConfig();//获取价格配置
    loadPriceHistory(); //获取价格修改历史
    loadFromFile();//获取之前卡数据和消费记录

    cout<<"\n请选择登录模式:"<<endl;
    cout<<"1. 管理员模式"<<endl;
    cout<<"2. 用户模式"<<endl;
    cout<<"请输入选择: "<<endl;

    int mode; cin>>mode;

    if(mode==1)
    {
        if(!checkAdminPassword())
        {
            cout<<"管理员验证失败，程序退出！"<<endl;
            system("pause");
            return 0;
        }
        adminMenu(); //显示管理员菜单
    }
    else if(mode==2)
    {
        if(!checkUserPassword())
        {
            cout<<"用户验证失败，程序退出！"<<endl;
            system("pause");
            return 0;
        }
        userMenu(); //显示用户菜单
    }
    else
    {
        cout<<"无效选择，程序退出！"<<endl;
        return 0;
    }


    int x;
    while(cin>>x)
    {
        cout<<endl;

        switch (x)
        {
            case 0:
                cout<<"\n感谢使用,再见!"<<endl;
                saveToFile();
                savePriceConfig();
                savePriceHistory();
                savePasswords();
                return 0;
                
            //管理员和用户共享的功能
            case 3:
                start_s();
                break;
            case 4:
                end_s();
                break;
                
            //仅管理员功能
            default:
                if(mode==1)
                {
                    switch(x)
                    {
                        case 1:
                            insert();
                            break;
                        case 2:
                            inq();
                            break;
                        case 5:
                            recharge();
                            break;
                        case 6:
                            refund();
                            break;
                        case 7:
                            statistics();
                            break;
                        case 8:
                            cancel();
                            break;
                        case 9:
                            modifyPrice();
                            break;
                        case 10:
                            showPrice();
                            break;
                        case 11:
                            showPriceHistory();
                            break;
                        case 12:
                            changeAdminPassword();
                            break;
                        case 13:
                            changeUserPassword();
                            break;
                        case 14:
                            clearAllData();
                            break;
                        default:
                            cout<<"无效选项，请重新输入"<<endl;
                            break;
                    }
                }
                else//用户模式
                {
                    cout<<"无效选项，请重新输入"<<endl;
                }
                break;
        }
        
        cout<<endl;
        if(mode==1)
            adminMenu();
        else
            userMenu();
    }
   
    return 0;

}