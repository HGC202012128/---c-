#include<iostream>
#include"head.h"
using namespace std;
void show()                                                         //��ʾ�˵�ҳ�� 
{
	cout<<"                                    * * * * * * * ��ӭʹ�� * * * * * * * *                          "<<endl;
	cout<<"                                    *           1.��ӹ���                *"<<endl;
	cout<<"                                    *           2.��ѯ����                *"<<endl;
	cout<<"                                    *           3.�޸Ĺ���                *"<<endl;
	cout<<"                                    *           4.ɾ������                *"<<endl;
	cout<<"                                    *           5.ͳ�ƹ���                *"<<endl;
	cout<<"                                    *           6.���۹���                *"<<endl;
	cout<<"                                    *           7.�˳�                    *"<<endl;
	cout<<"                                    * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<"                                       * * *����������ȷ�Ĺ��ܱ�� * * *                                      \n";
}
void numshow(allgoods *cangku)                                       //����������ɾ�����޸ġ����۹��ܵ���Ʒչʾ 
{
	int i;
		cout<<"��ǰ������Ʒ����"<<endl;
		cout<<setw(7)<<"��Ʒ���"<<setw(7)<<"��Ʒ����"<<setw(10)<<"��Ʒ����"<<setw(10)<<"��������"<<setw(8)<<"Ʒ��"<<setw(8)<<"����"<<setw(8)<<"�ۼ�"<<setw(8)<<"�����"<<endl;
	for(i=1;i<=cangku->num;i++)
	{
			cout<<setw(5)<<i<<setw(5)<<cangku->xinxi[i].type<<setw(14)<<cangku->xinxi[i].name<<
				setw(8)<<cangku->xinxi[i].maker<<setw(8)<<
				cangku->xinxi[i].pinpai<<setw(8)<<cangku->xinxi[i].inprice<<
				setw(8)<<cangku->xinxi[i].outprice<<setw(8)<<cangku->xinxi[i].kucun<<endl; 
	}
}
void store(allgoods *cangku)                                       //������������Ʒ��Ϣ�Ĵ��� 
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
void renew(allgoods *cangku)                                        //������������Ʒ��Ϣ���޸ġ�ɾ����������֮��ʵ����txt�ļ��ڵĸ��� 
{
	//�ڴ�����ɾ��txt�ļ��е�ȫ�����ݣ��ٴ���ɴ洢
	 fstream infile("storage.txt", ios::out);
	 store(cangku);
}
void addgoods(allgoods *cangku)                            //���������������Ʒ 
{
	fstream infile("storage.txt", ios::out);//�����ʱӲ���е���Ϣ�Ѿ���ȡ�����ڴ��У������Ʒʱ �ڴ�����ļ��ɷ�ֹ����һ��ִ�д��溯��ʱ����ǰ�������ظ��洢 
	cangku->num++;
	string type;
	string name;
	string maker;
	string pinpai;
	float inprice;//�����۸� 
	float outprice;//�ۼ� 
	int kucun;//����� 
	//������Ʒ����
	cout<<"                                             * * *��������Ʒ����* * *"<<endl; 
	cin>>type;
	cangku->xinxi[cangku->num].type=type;
	//������Ʒ����
	cout<<"                                             * * *��������Ʒ������* * *"<<endl; 
	cin>>name;
	cangku->xinxi[cangku->num].name=name; 
	 
	 //�������� 
	 cout<<"                                             * * *��������������* * *"<<endl; 
	 cin>>maker;
	 cangku->xinxi[cangku->num].maker=maker;
	 //Ʒ��
	 cout<<"                                             * * *������Ʒ��* * *"<<endl;
	 cin>>pinpai;
	 cangku->xinxi[cangku->num].pinpai=pinpai; 
	  //�����۸�
	  cout<<"                                             * * *����������۸�* * *"<<endl; 
	 cin>>inprice;
	 cangku->xinxi[cangku->num].inprice=inprice;
	 //�ۼ�
	 cout<<"                                             * * *�������ۼ�* * *"<<endl;
	 cin>>outprice;
	 cangku->xinxi[cangku->num].outprice=outprice; 
	 //����� 
	 cout<<"                                             * * *����������* * *"<<endl;
	 cin>>kucun;
	 cangku->xinxi[cangku->num].kucun=kucun; 
	 cout<<"                                             * * *��Ʒ��Ϣ�������* * *"<<endl; 
	 system("pause");
	 system("cls");
	 show();
}
void showgoods(allgoods *cangku)              //*****������������Ʒ��ͳ�ƣ��ɰ��ս��ۣ��ۼۣ���棬�������ҽ���ͳ�� 
{
	if(cangku->num==0)cout<<"                                             * * *���е�ǰû���κ���Ʒ!* * *                                  \n";
	else
	{
	cout<<"                                             * * *��������ͳ�Ʒ�ʽ* * *\n                                              * * *1.����* * *\n                                              * * *2.�ۼ�* * *\n                                              * * *3.�����* * *\n                                              * * *4.��������* * *\n";
	int m,i;
	cin>>m;                           //�û�ѡ��ͳ�Ʒ�ʽ 
	int a[cangku->num+1];
	string b[cangku->num+1];
	cout<<setw(14)<<"��Ʒ���"<<setw(14)<<"��Ʒ����"<<setw(15)<<"��Ʒ����"<<setw(15)<<"��������"<<setw(14)<<"Ʒ��"<<setw(14)<<"����"<<setw(14)<<"�ۼ�"<<setw(14)<<"�����"<<endl;
		if(m==1) 
		{
		for(i=1;i<=cangku->num;i++)                     // ���ս������� 
		{
			a[i]=cangku->xinxi[i].inprice;              //��������Ʒ�Ľ��۸�ֵ������a��֮��������sort����������a���оֲ����� 
		}
		sort(a+1,a+(cangku->num));
		for(i=cangku->num;i>0;i--)
		{
			int t;
			for(t=1;t<=cangku->num;t++)                  //���մӴ�С��˳��ȡ�� a�е�Ԫ�أ�֮��������ṹ���е����ݱȽϣ�Ѱ����ͬ������ͬ����� 
			{
				if(cangku->xinxi[t].inprice==a[i])
				cout<<setw(14)<<t<<setw(14)<<cangku->xinxi[t].type<<setw(14)<<cangku->xinxi[t].name<<setw(14)<<cangku->xinxi[t].maker<<setw(14)<<cangku->xinxi[t].pinpai<<setw(14)<<cangku->xinxi[t].inprice<<setw(14)<<cangku->xinxi[t].outprice<<setw(14)<<cangku->xinxi[t].kucun<<endl;
			}
		}
	
	}
		else if(m==2)
		{for(i=1;i<=cangku->num;i++)                     //�����ۼ�������� 
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
			a[i]=cangku->xinxi[i].kucun;                          //���տ����������� 
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
			b[i]=cangku->xinxi[i].maker;                              //���������̽���������� 
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
		cout<<"                                             * * *������Ĺ��ܱ�Ų���ȷ��������������* * *                                  \n";
		cin>>m;
		}
	}
}
void chaxun(allgoods *cangku)                           //��ѯ���� 
{
	cout<<"                                             * * *��ѡ���ѯ��ʽ* * *                                  "<<endl;
	cout<<"                                             * * *1-��Ʒ���* * *                                      "<<endl;
	cout<<"                                             * * *2-��Ʒ����* * *                                      "<<endl;
	cout<<"                                             * * *3-��������* * *                                      "<<endl;
	int i,t;
	cin>>i;
	cout<<"                           ���������Ĳ�ѯ����"<<endl;
	string x;                                       //�û������ѯ���� 
	cin>>x;
		cout<<"                                             * * *��ѯ�������* * *                                      \n";
		cout<<setw(7)<<"��Ʒ���"<<setw(7)<<"��Ʒ����"<<setw(10)<<"��Ʒ����"<<setw(10)<<"��������"<<setw(8)<<"Ʒ��"<<setw(8)<<"����"<<setw(8)<<"�ۼ�"<<setw(8)<<"�����"<<endl;
	switch(i)
	{                                                             //���տͻ������������ 
	
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
			cout<<"                                             * * *��Ʒ������* * *                                      "<<endl;break; 
	}
	 system("pause");
	 system("cls");
	 show();
}
void xiugai(allgoods *cangku)                                   //�޸ĺ�����������Ʒ��Ϣ�޸� 
{
	if(cangku->num==0)                                           //�����жϳ�����Ʒ��Ŀ�Ƿ�Ϊ�� 
	{
		cout<<"                                             * * * ��ǰ��������Ʒ* * *                                      "<<endl; 
		renew(cangku); 
	system("pause");
	 system("cls");
	 show();
	 } 
	 else
{	 
	while(true)
	{
	int t,k;                                //tΪforѭ��ר�ñ�����k�����ж��û������Ƿ���ȷ 
	cout<<"                                             * * *������Ʒ��Ϣ����* * *                                      "<<endl;
	numshow(cangku);
	cout<<"                                             * * *����������Ҫ�޸ĵ���Ʒ���* * *                                      "<<endl;
	int m;
	cin>>m;//�û�ѡ�� 
	for(t=1;t<=cangku->num;t++)
	{
		if(m==t)
		{
			k=1;break;                               //�����ж��û��������Ʒ����Ƿ���ȷ 
		}
	}
	if(k==1)
	{
	cout<<"����������Ҫ�޸ĵľ��巽��\n1.��Ʒ����\n2.��Ʒ����\n3.��������\n4.Ʒ��\n5.����\n6.�ۼ�\n7.�����\n";
	int p;
	cin>>p;                                       //�û�ѡ��
	if(p>=1&&p<=7)
	{
	cout<<"                                             * * *����Ҫ�޸�Ϊ * * *                                      \n"; 
	string d;                                //���ں����������͵����� 
	float g;                            //��������۸񣬿���������� 
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
	 cout<<"                                             * * *�޸���ɣ��޸ĺ�Ľ������ * * *                                      \n";
	numshow(cangku);
	renew(cangku);
	system("pause");
	 system("cls");
	 show();break;
}
	else
	{
		cout<<"                                             * * *���������Ʒ�����ڣ����������� * * *                                      \n";
	}
	
}
}
}
void shanchu(allgoods *cangku)                            //ɾ������ 
{
	if(cangku->num==0)                                      //�����жϳ�����Ʒ��Ŀ�Ƿ�Ϊ�� 
	{
		cout<<"                                             * * *��ǰ����û����Ʒ * * *                                      \n";
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
	cout<<"                                             * * *��������Ҫɾ������Ʒ�ı�� * * *                                      \n";
	int m;
	int t,i=0;                           //t����forѭ��  i�����ж��û��������Ʒ�������Ƿ���ȷ 
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
		int e;                            //e���ڶ���forѭ�����ƣ�����һλ��Ʒ��Ϣ��ǰ�� 
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
	
		cout<<"                                             * * *ɾ����� * * *                                      \n";break;
	}
	else
	{
		cout<<"                                             * * *���������Ʒ�����ڣ����������� * * *                                      \n";
	}
}
	renew(cangku); 
	system("pause");
	 system("cls");
	 show();
}
}
void sell(allgoods *cangku)                                //���۹��ܺ��� 
{
	string lei,name;
	numshow(cangku);
	cout<<"                                             * * *��ǰ������Ʒ���� * * *\n                                             * * *��������Ʒ����� * * *                                      \n"; 
	cin>>lei;
	int t,m=0;                                  //t����for����  m�����ж��û������Ƿ���ȷ 
	for(t=1;t<=cangku->num;t++)
	{
		if(lei==cangku->xinxi[t].type)
		{
			m=1;break;                            //���û�����������ȷ��mΪ1������Ϊ�� 
		 } 
	} 
	if(m==1)
	{ 
	cout<<"                                             * * *�����빺�����Ʒ������ * * *\n";
	cin>>name;
	int x=0;//x���ڼ�¼�����ж���ȷ���
	 	for(t=1;t<=cangku->num;t++)
	 	{
	 		if(name==cangku->xinxi[t].name)
	 		{
	 			x=1;break;                         //ͬ��������жϣ������ڴ�����x=1 
			 }
		 }
		 if(x==1)
		 {
		 	for(t=1;t<=cangku->num;t++)
		 	{
		 		if(lei==cangku->xinxi[t].type&&name==cangku->xinxi[t].name)
		 		{
		 			cout<<"                            * * *����Ʒ��ǰ�����Ϊ��"<<cangku->xinxi[t].kucun<<endl;
					 cout<<"                           * * *����������Ҫ��������� * * *\n";
					 int e;
					cin>>e;
					if(cangku->xinxi[t].kucun>=e)
					{
						cangku->xinxi[t].kucun-=e;
						cout<<"                        * * *����ɹ� * * *\n";
					 } 
					 else{ 
					 cout<<"                           * * *��������� * * *";break;} 
				}
			 }
		 }
		 else
		 cout<<"                                       * * *���������Ʒ������ * * *\n"; 
	}
	else cout<<"                                       * * *���������Ʒ������ * * *\n";
	renew(cangku);
	system("pause");
	 system("cls");
	 show();
}
void getdata(allgoods *cangku)                       //���ڳ������к�����ж�ȡ���� 
{
	cangku->num=0;                                     //���ȼ���Ʒ��ĿΪ�� 
	ifstream infile("storage.txt",ios::in);
	if(!infile)
	{
		cerr<<"open error"<<endl;
		exit(1);
	}
	int t;//t��һ���������ݣ���������ű�ŵģ�����num�Ѿ�����˱�ţ�������t����ʱ��ű�ţ���ֹ�������ݶ�ȡ���� 

	string type;
	while(infile>>t!=0&&infile>>type!=0)                 //��while�ж�ȡ������Ϣ����������Ϣͬʱ��Ϊ��ʱ��ִ�к��� 
	{                                                     //��������Ϊ�˽��infileֱ�Ӷ��ܻ������һ�У�������Ʒ��Ϣ���ǻ���һ���� 
		cangku->num=cangku->num+1;                           //ÿ����һ�γ�����Ʒ��Ŀ��1 
		cangku->xinxi[cangku->num].type=type;                  //t�������ã�ֻ��Ϊ�˷�ֹ��Ʒ��Ŷ�������Ϣ�ĸ��� 
		infile>>cangku->xinxi[cangku->num].name;
		infile>>cangku->xinxi[cangku->num].maker;
		infile>>cangku->xinxi[cangku->num].pinpai; 
		infile>>cangku->xinxi[cangku->num].inprice;
		infile>>cangku->xinxi[cangku->num].outprice;
		infile>>cangku->xinxi[cangku->num].kucun;
	}
	cout<<"                                       * * *��Ʒ��Ϣ�Ѷ�ȡ�ɹ� * * *                                      \n";
}


