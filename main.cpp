#include"head.h"
using namespace std;
int main() 
{
	show();
	struct allgoods cangku;
	getdata(&cangku);//���������Զ���ȡ��Ϣ 
			
		while(true)
	{       int x;
			cin>>x;
		if(x>=1&&x<10)
	{
		switch(x)
		{
			case 1: //1.��ӹ���
				addgoods(&cangku);
				store(&cangku);
				break;
			case 2: //2.��ѯ����
				chaxun(&cangku);
				break;
			case 3: //3.�޸Ĺ���
				xiugai(&cangku); 
				break;	
			case 4: //4.ɾ������
				shanchu(&cangku);
				break;	
			case 5: //5.ͳ�ƹ���
				showgoods(&cangku);
				system("pause");
	 			system("cls");
	 			show();
				break;	
			case 6: //6.���۹��� 
				sell(&cangku);
				break;	
			case 7: //7.�˳�  
		cout<<"                                       * * *�����˳�����ӭ�´�ʹ�� * * *                                      "<<endl;
			 exit(0);
			 	break;
		}
	}
	else
	{
		cout<<"                                       * * *��������ȷ�Ĺ��ܱ�� * * *                                      "<<endl;
		cin>>x;
	}
}
}
