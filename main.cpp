#include"head.h"
using namespace std;
int main() 
{
	show();
	struct allgoods cangku;
	getdata(&cangku);//程序开启后自动读取信息 
			
		while(true)
	{       int x;
			cin>>x;
		if(x>=1&&x<10)
	{
		switch(x)
		{
			case 1: //1.添加功能
				addgoods(&cangku);
				store(&cangku);
				break;
			case 2: //2.查询功能
				chaxun(&cangku);
				break;
			case 3: //3.修改功能
				xiugai(&cangku); 
				break;	
			case 4: //4.删除功能
				shanchu(&cangku);
				break;	
			case 5: //5.统计功能
				showgoods(&cangku);
				system("pause");
	 			system("cls");
	 			show();
				break;	
			case 6: //6.销售功能 
				sell(&cangku);
				break;	
			case 7: //7.退出  
		cout<<"                                       * * *程序退出，欢迎下次使用 * * *                                      "<<endl;
			 exit(0);
			 	break;
		}
	}
	else
	{
		cout<<"                                       * * *请输入正确的功能编号 * * *                                      "<<endl;
		cin>>x;
	}
}
}
