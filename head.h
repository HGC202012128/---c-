#include<iostream>
#include<iomanip>
#include<cstring> 
#include<fstream>
#include<stdio.h>
#include<algorithm>
#define max 100
using namespace std;
struct singlegoods//定义单个商品的结构体 
		{
			string type;//商品种类 
			string name;//商品名称 
			string maker;//生产厂家 
			string pinpai;//品牌 
			float inprice;//进货价格 
			float outprice;//售价 
			float kucun;//库存量 
		};
struct allgoods//定义仓库的结构体 
		{
			struct singlegoods xinxi[max];//在仓库的结构体中定义max个商品的结构体 
			int num;//商品总数 
		};
void show();
void numshow(allgoods *cangku) ;
void store(allgoods *cangku)  ;
void renew(allgoods *cangku) ;
void addgoods(allgoods *cangku);
void showgoods(allgoods *cangku);
void chaxun(allgoods *cangku);
void xiugai(allgoods *cangku);
void shanchu(allgoods *cangku);
void sell(allgoods *cangku);
void getdata(allgoods *cangku);

