#include<iostream>
#include<iomanip>
#include<cstring> 
#include<fstream>
#include<stdio.h>
#include<algorithm>
#define max 100
using namespace std;
struct singlegoods//���嵥����Ʒ�Ľṹ�� 
		{
			string type;//��Ʒ���� 
			string name;//��Ʒ���� 
			string maker;//�������� 
			string pinpai;//Ʒ�� 
			float inprice;//�����۸� 
			float outprice;//�ۼ� 
			float kucun;//����� 
		};
struct allgoods//����ֿ�Ľṹ�� 
		{
			struct singlegoods xinxi[max];//�ڲֿ�Ľṹ���ж���max����Ʒ�Ľṹ�� 
			int num;//��Ʒ���� 
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

