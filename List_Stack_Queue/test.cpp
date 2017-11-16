#include<iostream>
#include<queue>
#include<cstdio>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std ;

typedef struct barber {
    char name[20] ;
    int level, pirce, all, status, id;
} ;

typedef struct customer {
    int id, ask;
} ;

int cmp(barber a, barber b){
    return a.all > b.all ;
}

vector<barber> barbers ;
vector<queue<customer> > customers ;
int flag = 1 ;
int sum = 0 ;

void show_barber(){
    system("clear") ;
    sort(barbers.begin(),barbers.end(),cmp) ;
    int one = 0, two = 0, three = 0 ;
    cout << "\n" << endl ;
    cout << "                  累计一天各位理发师的销售量\n" << endl ;
    cout << "        姓名       服务费      顾客量       理发师等级" << endl ;
    for ( int i = 0 ; i < 12 ; i++ ){
        cout << "        " << barbers[i].name << "       " << barbers[i].all << "         " << barbers[i].all/barbers[i].pirce ;
        if ( barbers[i].id <= 2 ) { cout << "             一" << endl ; one += barbers[i].all ; }
        else if ( barbers[i].id <= 6 ) { cout <<  "             二" << endl ; two += barbers[i].all ; }
        else { cout <<  "             三" << endl ; three += barbers[i].all ; }
        sum += barbers[i].all ;
    }
    cout << "\n" << endl ;
    cout << "        理发店一天营业额为" << sum << "(元)" <<  "，一共服务了" << 77 << "个顾客" << endl ;
    cout << "        其中，一级理发师服务了" << one/60 << "个顾客，销售额为" << one << "（元）;" << endl ;
    cout << "        其中，二级理发师服务了" << two/40 << "个顾客，销售额为" << two << "（元）;" << endl ;
    cout << "        其中，三级理发师服务了" << three/20 << "个顾客，销售额为" << three << "（元）;" << endl ;
}

void show_customer(){
    for ( int i = 0 ; i < 12 ; i++ ){
        cout << "当前有" << customers[i].size() << "个顾客正在等待" << barbers[i].name <<  "(" << i+1 << "号理发师" << ")"  << endl ;
    }
}

void haircut(){
    cout << "\n" <<  endl ;
    int f = 0 ;
    system("clear") ;
    for(int i = 0 ; i < 12 ; i++ ){
        if ( customers[i].size() != 0 ){
            customer tmp = customers[i].front() ;
            barbers[i].all += barbers[i].pirce ;
            customers[i].pop() ;
            cout << barbers[i].name << "正在为（" << tmp.id << "）号顾客服务 ;" << endl ;
            if ( customers[i].size() != 0 ) barbers[i].status = 0 ;
            f++ ;
        }
        else {
            cout << barbers[i].name << "理发师空闲，没有顾客" << endl ;
        }
    }
    if ( f == 0 ){
        flag = 0 ;
    }
    cout << endl ;
}
int main(){
    int n ;
    cout << endl ;
    cout << "          店内现有一级两名，二级四名，三级理发师各六名；"  << endl ;
    cout << "          一级理发师分别是张伟（1号），刘伟（2号）；" << endl ;
    cout << "          二级理发师分别是张磊（3号），刘磊（4号），王磊（5号），黄磊（6号）；" << endl ;
    cout << "          三节理发师分别是张强（7号），刘强（8号），王强（9号），黄强（10号），赵强（11号），李强（12号）." << endl ;
    cout << "          一级理发师的服务费是60元，二级理发师的服务费是40元，三级理发师的服务费是20元\n" << endl ;
    cout << endl ;
    cout << "          开始营业请按k " << endl ;
    char k ;
    cin >> k ;
    while ( k != 'k' ){
        cout << "          开始营业请按k " << endl ;
        cin >> k ;
    }

    ifstream data ;
    data.open("barber.txt") ;
    for ( int i = 0 ; i < 12 ; i++ ){
        barber tmp;
        data >>  tmp.level >> tmp.id >>  tmp.pirce >> tmp.name ;
        tmp.all = 0 ;
        tmp.status = 1 ;
        barbers.push_back(tmp) ;
    }

    ifstream data1 ;
    data1.open("customer.txt") ;
    customers.resize(12) ;
    for ( int i = 0 ; i < 77 ; i++ ){
        customer tmp ;
        tmp.id = i+1 ;
        data1 >> tmp.ask ;
        customers[tmp.ask-1].push(tmp) ;
    }
    show_customer();
    while ( true ){
        cout << endl ;
        cout << endl ;
        if ( flag == 0 ){
            cout << endl ;
            cout << "一天营业已经结束，没有顾客在等待." << endl ;
            cout << endl ;
            break ;
        }
        cout << "继续输入j" << endl ;
        char tmp ;
        cin >> tmp ;
        if ( tmp == 'j' ){
            haircut();
            show_customer();
        }
    }
    cout << "\n       一天营业已经结束，显示一天销售额按t" << endl ;
    char tmp ;
    cin >> tmp ;
    while ( tmp != 't' ){
        cout << "        一天营业已经结束，显示一天的销售额按t" << endl ;
        cin >> tmp ;
    }
    show_barber() ;
    return 0 ;
}
