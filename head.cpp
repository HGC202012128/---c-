#include<iostream>
#include"head.h"
using namespace std;
void show()                                                         //显示菜单页面 
{
	cout<<"                                    * * * * * * * 欢迎使用 * * * * * * * *                          "<<endl;
	cout<<"                                    *           1.添加功能                *"<<endl;
	cout<<"                                    *           2.查询功能                *"<<endl;
	cout<<"                                    *           3.修改功能                *"<<endl;
	cout<<"                                    *           4.删除功能                *"<<endl;
	cout<<"                                    *           5.统计功能                *"<<endl;
	cout<<"                                    *           6.销售功能                *"<<endl;
	cout<<"                                    *           7.退出                    *"<<endl;
	cout<<"                                    * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<"                                       * * *请您输入正确的功能编号 * * *                                      \n";
}
void numshow(allgoods *cangku)                                       //本函数用于删除、修改、销售功能的商品展示 
{
	int i;
		cout<<"当前超市商品如下"<<endl;
		cout<<setw(7)<<"商品编号"<<setw(7)<<"商品类型"<<setw(10)<<"商品名称"<<setw(10)<<"生产厂家"<<setw(8)<<"品牌"<<setw(8)<<"进价"<<setw(8)<<"售价"<<setw(8)<<"库存量"<<endl;
	for(i=1;i<=cangku->num;i++)
	{
			cout<<setw(5)<<i<<setw(5)<<cangku->xinxi[i].type<<setw(14)<<cangku->xinxi[i].name<<
				setw(8)<<cangku->xinxi[i].maker<<setw(8)<<
				cangku->xinxi[i].pinpai<<setw(8)<<cangku->xinxi[i].inprice<<
				setw(8)<<cangku->xinxi[i].outprice<<setw(8)<<cangku->xinxi[i].kucun<<endl; 
	}
}
void store(allgoods *cangku)                                       //本函数用于商品信息的存盘 
{
	ofstream outfile;
	outfile.open("storage.txt",ios::app);
	int i;
	for(i=1;i<=cangku->num;i++)
	{
		outfile<<"        "<<i<<"           "<<cangku->xinxi[i].type<<"        "<<cangku->xinxi[i].name<<"          "<<cangku->xinxi[i].maker<<"          "<<cangku->xinxi[i].pinpai<<"           "<<cangku->xinxi[i].inprice<<"           "<<cangku->xinxi[i].outprice<<"        "<<cangku->xinxi[i].kucun<<endl;
	}
	outfile.close();
}
void renew(allgoods *cangku)                                        //本函数用于商品信息在修改、删除或者销售之后，实现在txt文件内的更新 
{
	//在此重新删除txt文件中的全部数据，再次完成存储
	 fstream infile("storage.txt", ios::out);
	 store(cangku);
}
void addgoods(allgoods *cangku)                            //本函数用于添加商品 
{
	fstream infile("storage.txt", ios::out);//程序打开时硬盘中的信息已经读取到了内存中，添加商品时 在此清空文件可防止在下一步执行储存函数时将以前的数据重复存储 
	cangku->num++;
	string type;
	string name;
	string maker;
	string pinpai;
	float inprice;//进货价格 
	float outprice;//售价 
	int kucun;//库存量 
	//输入商品类型
	cout<<"                                             * * *请输入商品类型* * *"<<endl; 
	cin>>type;
	cangku->xinxi[cangku->num].type=type;
	//输入商品名称
	cout<<"                                             * * *请输入商品的名称* * *"<<endl; 
	cin>>name;
	cangku->xinxi[cangku->num].name=name; 
	 
	 //生产厂家 
	 cout<<"                                             * * *请输入生产厂家* * *"<<endl; 
	 cin>>maker;
	 cangku->xinxi[cangku->num].maker=maker;
	 //品牌
	 cout<<"                                             * * *请输入品牌* * *"<<endl;
	 cin>>pinpai;
	 cangku->xinxi[cangku->num].pinpai=pinpai; 
	  //进货价格
	  cout<<"                                             * * *请输入进货价格* * *"<<endl; 
	 cin>>inprice;
	 cangku->xinxi[cangku->num].inprice=inprice;
	 //售价
	 cout<<"                                             * * *请输入售价* * *"<<endl;
	 cin>>outprice;
	 cangku->xinxi[cangku->num].outprice=outprice; 
	 //库存量 
	 cout<<"                                             * * *请输入库存量* * *"<<endl;
	 cin>>kucun;
	 cangku->xinxi[cangku->num].kucun=kucun; 
	 cout<<"                                             * * *商品信息输入完毕* * *"<<endl; 
	 system("pause");
	 system("cls");
	 show();
}
void showgoods(allgoods *cangku)              //*****本函数用于商品的统计，可按照进价，售价，库存，生产厂家进行统计 
{
	if(cangku->num==0)cout<<"                                             * * *超市当前没有任何商品!* * *                                  \n";
	else
	{
	cout<<"                                             * * *请您输入统计方式* * *\n                                              * * *1.进价* * *\n                                              * * *2.售价* * *\n                                              * * *3.库存量* * *\n                                              * * *4.生产厂家* * *\n";
	int m,i;
	cin>>m;                           //用户选择统计方式 
	int a[cangku->num+1];
	string b[cangku->num+1];
	cout<<setw(14)<<"商品编号"<<setw(14)<<"商品类型"<<setw(15)<<"商品名称"<<setw(15)<<"生产厂家"<<setw(14)<<"品牌"<<setw(14)<<"进价"<<setw(14)<<"售价"<<setw(14)<<"库存量"<<endl;
		if(m==1) 
		{
		for(i=1;i<=cangku->num;i++)                     // 按照进价排序 
		{
			a[i]=cangku->xinxi[i].inprice;              //将所有商品的进价赋值给数组a，之后再利用sort函数对数组a进行局部排序 
		}
		sort(a+1,a+(cangku->num));
		for(i=cangku->num;i>0;i--)
		{
			int t;
			for(t=1;t<=cangku->num;t++)                  //按照从大到小的顺序取出 a中的元素，之后依次与结构体中的数据比较，寻找相同，若相同则输出 
			{
				if(cangku->xinxi[t].inprice==a[i])
				cout<<setw(14)<<t<<setw(14)<<cangku->xinxi[t].type<<setw(14)<<cangku->xinxi[t].name<<setw(14)<<cangku->xinxi[t].maker<<setw(14)<<cangku->xinxi[t].pinpai<<setw(14)<<cangku->xinxi[t].inprice<<setw(14)<<cangku->xinxi[t].outprice<<setw(14)<<cangku->xinxi[t].kucun<<endl;
			}
		}
	
	}
		else if(m==2)
		{for(i=1;i<=cangku->num;i++)                     //按照售价排序并输出 
		{
			a[i]=cangku->xinxi[i].outprice;
		}
		sort(a+1,a+(cangku->num));
		for(i=cangku->num;i>0;i--)
		{
			int t;
			for(t=1;t<=cangku->num;t++)
			{
				if(cangku->xinxi[t].outprice==a[i])
				cout<<setw(14)<<t<<setw(14)<<cangku->xinxi[t].type<<setw(14)<<cangku->xinxi[t].name<<setw(14)<<cangku->xinxi[t].maker<<setw(14)<<cangku->xinxi[t].pinpai<<setw(14)<<cangku->xinxi[t].inprice<<setw(14)<<cangku->xinxi[t].outprice<<setw(14)<<cangku->xinxi[t].kucun<<endl;
			}		
		}
		}
	

		else if(m==3)
		{
		for(i=1;i<=cangku->num;i++)
		{
			a[i]=cangku->xinxi[i].kucun;                          //按照库存量排序并输出 
		}
		sort(a+1,a+(cangku->num));
		for(i=cangku->num;i>0;i--)
		{
			int t;
			for(t=1;t<=cangku->num;t++)
			{
				if(cangku->xinxi[t].kucun == a[i])
				cout<<setw(14)<<t<<setw(14)<<cangku->xinxi[t].type<<setw(14)<<cangku->xinxi[t].name<<setw(14)<<cangku->xinxi[t].maker<<setw(14)<<cangku->xinxi[t].pinpai<<setw(14)<<cangku->xinxi[t].inprice<<setw(14)<<cangku->xinxi[t].outprice<<setw(14)<<cangku->xinxi[t].kucun<<endl;
			}		
		}
		
		}
		else if(m==4)
		{for(i=1;i<=cangku->num;i++)
		{
			b[i]=cangku->xinxi[i].maker;                              //按照生产商进行排序并输出 
		}
		sort(b+1,b+(cangku->num));
		for(i=cangku->num;i>0;i--)
		{
			int t;
			for(t=1;t<=cangku->num;t++)
			{
				if(cangku->xinxi[t].maker==b[i])
				cout<<setw(14)<<t<<setw(14)<<cangku->xinxi[t].type<<setw(14)<<cangku->xinxi[t].name<<setw(14)<<cangku->xinxi[t].maker<<setw(14)<<cangku->xinxi[t].pinpai<<setw(14)<<cangku->xinxi[t].inprice<<setw(14)<<cangku->xinxi[t].outprice<<setw(14)<<cangku->xinxi[t].kucun<<endl;
			}		
		}
		} 
		else
		{
		cout<<"                                             * * *您输入的功能编号不正确，请您重新输入* * *                                  \n";
		cin>>m;
		}
	}
}
void chaxun(allgoods *cangku)                           //查询功能 
{
	cout<<"                                             * * *请选择查询方式* * *                                  "<<endl;
	cout<<"                                             * * *1-商品类别* * *                                      "<<endl;
	cout<<"                                             * * *2-商品名称* * *                                      "<<endl;
	cout<<"                                             * * *3-生产厂家* * *                                      "<<endl;
	int i,t;
	cin>>i;
	cout<<"                           请输入您的查询内容"<<endl;
	string x;                                       //用户输入查询内容 
	cin>>x;
		cout<<"                                             * * *查询结果如下* * *                                      \n";
		cout<<setw(7)<<"商品编号"<<setw(7)<<"商品类型"<<setw(10)<<"商品名称"<<setw(10)<<"生产厂家"<<setw(8)<<"品牌"<<setw(8)<<"进价"<<setw(8)<<"售价"<<setw(8)<<"库存量"<<endl;
	switch(i)
	{                                                             //按照客户需求依次输出 
	
		case 1:for(t=1;t<=cangku->num;t++)
		{
			if(x==(cangku->xinxi[t].type))
			{
				
				cout<<setw(5)<<t<<setw(5)<<cangku->xinxi[t].type<<setw(14)<<cangku->xinxi[t].name<<
				setw(10)<<cangku->xinxi[t].maker<<setw(8)<<
				cangku->xinxi[t].pinpai<<setw(8)<<cangku->xinxi[t].inprice<<
				setw(8)<<cangku->xinxi[t].outprice<<setw(8)<<cangku->xinxi[t].kucun<<endl; 
			}
		}break;
		case 2:for(t=1;t<=cangku->num;t++)
		{
			if(x==cangku->xinxi[t].name)
			{
				cout<<setw(5)<<t<<setw(5)<<cangku->xinxi[t].type<<setw(14)<<cangku->xinxi[t].name<<
				setw(8)<<cangku->xinxi[t].maker<<setw(8)<<
				cangku->xinxi[t].pinpai<<setw(8)<<cangku->xinxi[t].inprice<<
				setw(8)<<cangku->xinxi[t].outprice<<setw(8)<<cangku->xinxi[t].kucun<<endl; 
			}
		}break;
		case 3:for(t=1;t<=cangku->num;t++)
		{
			if(x==cangku->xinxi[t].maker)
			{
				cout<<setw(5)<<t<<setw(5)<<cangku->xinxi[t].type<<setw(14)<<cangku->xinxi[t].name<<
				setw(8)<<cangku->xinxi[t].maker<<setw(8)<<
				cangku->xinxi[t].pinpai<<setw(8)<<cangku->xinxi[t].inprice<<
				setw(8)<<cangku->xinxi[t].outprice<<setw(8)<<cangku->xinxi[t].kucun<<endl; 
			}
		}break;
		default:
			cout<<"                                             * * *商品不存在* * *                                      "<<endl;break; 
	}
	 system("pause");
	 system("cls");
	 show();
}
void xiugai(allgoods *cangku)                                   //修改函数，用于商品信息修改 
{
	if(cangku->num==0)                                           //首先判断超市商品数目是否为零 
	{
		cout<<"                                             * * * 当前超市无商品* * *                                      "<<endl; 
		renew(cangku); 
	system("pause");
	 system("cls");
	 show();
	 } 
	 else
{	 
	while(true)
	{
	int t,k;                                //t为for循环专用变量，k负责判定用户输入是否正确 
	cout<<"                                             * * *当下商品信息如下* * *                                      "<<endl;
	numshow(cangku);
	cout<<"                                             * * *请输入您想要修改的商品编号* * *                                      "<<endl;
	int m;
	cin>>m;//用户选择 
	for(t=1;t<=cangku->num;t++)
	{
		if(m==t)
		{
			k=1;break;                               //用于判断用户输入的商品编号是否正确 
		}
	}
	if(k==1)
	{
	cout<<"请输入您想要修改的具体方面\n1.商品类型\n2.商品名称\n3.生产厂家\n4.品牌\n5.进价\n6.售价\n7.库存量\n";
	int p;
	cin>>p;                                       //用户选择
	if(p>=1&&p<=7)
	{
	cout<<"                                             * * *您想要修改为 * * *                                      \n"; 
	string d;                                //用于后续输入类型等内容 
	float g;                            //用于输入价格，库存量等内容 
			switch(p)
			{
				case 1:
					cin>>d;
					cangku->xinxi[t].type=d;break;
				case 2:
					cin>>d;
					cangku->xinxi[t].name=d;break;
				case 3:
					cin>>d;
					cangku->xinxi[t].maker=d;break;
				case 4:
					cin>>d;
					cangku->xinxi[t].pinpai=d;break;
				case 5:
					cin>>g;
					cangku->xinxi[t].inprice=g;break;
				case 6:
					cin>>g;
					cangku->xinxi[t].outprice=g;break;
				case 7:
					cin>>g;
					cangku->xinxi[t].kucun=g;break;
			}	 
}
	 cout<<"                                             * * *修改完成！修改后的结果如下 * * *                                      \n";
	numshow(cangku);
	renew(cangku);
	system("pause");
	 system("cls");
	 show();break;
}
	else
	{
		cout<<"                                             * * *您输入的商品不存在，请重新输入 * * *                                      \n";
	}
	
}
}
}
void shanchu(allgoods *cangku)                            //删除功能 
{
	if(cangku->num==0)                                      //首先判断超市商品数目是否为零 
	{
		cout<<"                                             * * *当前超市没有商品 * * *                                      \n";
		renew(cangku); 
	system("pause");
	 system("cls");
	 show();
	} 
	 else
{
	while(cangku->num!=0)
	{ 
	numshow(cangku);
	cout<<"                                             * * *请输入想要删除的商品的编号 * * *                                      \n";
	int m;
	int t,i=0;                           //t用于for循环  i用于判定用户输入的商品的名称是否正确 
	cin>>m;
	for(t=1;t<=cangku->num;t++)
	{
		if(m==t)
		{
			i=1;break; 
		}
	}
	if(i==1)
	{
		int e;                            //e用于二次for循环控制，将后一位商品信息向前提 
		for(t=1;t<=cangku->num;t++)
		{
				if(m==t)
			{
			 	cangku->num--;
				for(e=t;e<=cangku->num-1;e++)
				{
			cangku->xinxi[e].type=cangku->xinxi[e+1].type;
			cangku->xinxi[e].name=cangku->xinxi[e+1].name;
			cangku->xinxi[e].kucun=cangku->xinxi[e+1].kucun;
			cangku->xinxi[e].inprice=cangku->xinxi[e+1].inprice;
			cangku->xinxi[e].outprice=cangku->xinxi[e+1].outprice;
			cangku->xinxi[e].pinpai=cangku->xinxi[e+1].pinpai;
			cangku->xinxi[e].maker=cangku->xinxi[e+1].maker;
				}
			}
		}
	
		cout<<"                                             * * *删除完成 * * *                                      \n";break;
	}
	else
	{
		cout<<"                                             * * *您输入的商品不存在，请重新输入 * * *                                      \n";
	}
}
	renew(cangku); 
	system("pause");
	 system("cls");
	 show();
}
}
void sell(allgoods *cangku)                                //销售功能函数 
{
	string lei,name;
	numshow(cangku);
	cout<<"                                             * * *当前超市商品如下 * * *\n                                             * * *请输入商品的类别 * * *                                      \n"; 
	cin>>lei;
	int t,m=0;                                  //t用于for控制  m用于判断用户输入是否正确 
	for(t=1;t<=cangku->num;t++)
	{
		if(lei==cangku->xinxi[t].type)
		{
			m=1;break;                            //若用户输入的类别正确，m为1，否则为零 
		 } 
	} 
	if(m==1)
	{ 
	cout<<"                                             * * *请输入购买的商品的名称 * * *\n";
	cin>>name;
	int x=0;//x用于记录二次判断正确情况
	 	for(t=1;t<=cangku->num;t++)
	 	{
	 		if(name==cangku->xinxi[t].name)
	 		{
	 			x=1;break;                         //同类别输入判断，若存在此名则x=1 
			 }
		 }
		 if(x==1)
		 {
		 	for(t=1;t<=cangku->num;t++)
		 	{
		 		if(lei==cangku->xinxi[t].type&&name==cangku->xinxi[t].name)
		 		{
		 			cout<<"                            * * *该商品当前库存量为："<<cangku->xinxi[t].kucun<<endl;
					 cout<<"                           * * *请输入您想要购买的数量 * * *\n";
					 int e;
					cin>>e;
					if(cangku->xinxi[t].kucun>=e)
					{
						cangku->xinxi[t].kucun-=e;
						cout<<"                        * * *购买成功 * * *\n";
					 } 
					 else{ 
					 cout<<"                           * * *库存量不足 * * *";break;} 
				}
			 }
		 }
		 else
		 cout<<"                                       * * *您输入的商品不存在 * * *\n"; 
	}
	else cout<<"                                       * * *您输入的商品不存在 * * *\n";
	renew(cangku);
	system("pause");
	 system("cls");
	 show();
}
void getdata(allgoods *cangku)                       //用于程序运行后从盘中读取数据 
{
	cangku->num=0;                                     //首先记商品数目为零 
	ifstream infile("storage.txt",ios::in);
	if(!infile)
	{
		cerr<<"open error"<<endl;
		exit(1);
	}
	int t;//t是一个无用数据，是用来存放编号的，由于num已经存放了编号，所以用t来临时存放编号，防止其他数据读取错误 

	string type;
	while(infile>>t!=0&&infile>>type!=0)                 //在while中读取两个信息，这两个信息同时不为零时再执行后续 
	{                                                     //此做法是为了解决infile直接读总会读到下一行，导致商品信息总是会有一空行 
		cangku->num=cangku->num+1;                           //每进入一次程序，商品数目加1 
		cangku->xinxi[cangku->num].type=type;                  //t并无作用，只是为了防止商品编号对其他信息的干扰 
		infile>>cangku->xinxi[cangku->num].name;
		infile>>cangku->xinxi[cangku->num].maker;
		infile>>cangku->xinxi[cangku->num].pinpai; 
		infile>>cangku->xinxi[cangku->num].inprice;
		infile>>cangku->xinxi[cangku->num].outprice;
		infile>>cangku->xinxi[cangku->num].kucun;
	}
	cout<<"                                       * * *商品信息已读取成功 * * *                                      \n";
}


