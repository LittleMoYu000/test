#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string.h>


using namespace std;

int random(int i);

class Group
{protected: 
	int Total_number,Group_number,departs;
	string name[100];
 public:
 	Group(int a,int b,int c):Total_number(a),Group_number(b),departs(c){}
 	
	void name_get()
	{
		for(int i=0;i<Total_number;i++)
			cin>>name[i];
	}
	
	void mumber_reset()
	{
		cout<<"����������ÿ������:"<<endl;
		cin>>Group_number>>departs;
	}
	void name_reset()
	{
		cout<<"������������������ÿ������"<<endl;
		cin>>Total_number>>Group_number>>departs;
		cout<<"�����ǳ�:"<<endl;
		name_get();
	} 
	void name_add()
	{	int a=0;
		cout<<"������������:"<<endl;
		cin>>a;
		for(int i=Total_number;i<Total_number+a;i++)
			cin>>name[i];
		Total_number+=a;
		mumber_reset();
	}
	void name_delete()
	{
		/*int a,b,c=Total_number;
		cout<<"����ɾ������:"<<endl;
		cin>>a;
		int bb[100]; 
		cout<<"����ɾ����Աλ�ã����򣡣���0�ǵ�һ����"<<endl;
		for(int i=0;i<a;i++)
		{
			cin>>bb[i];
		}
		for(int i=0;i<a;i++)
		{
			for(int j=bb[i];j<c;j++)
			{
				name[j]=name[j+1];
			}
			c--;
			for(int k=i;k<a;k++)
			{
				bb[k]--;
			}
		}
		Total_number-=a;
		mumber_reset();*/
		int a=0,node=0;
		char b;
		while(node==0)
		{
			string name_search[100];
			cout<<"����ɾ������:"<<endl;
			cin>>a;
			cout<<"����ɾ����Ա����(ע���Сд��):"<<endl;
			for(int i=0;i<a;i++)
				cin>>name_search[i];
			for(int j=0;j<a;j++)
			{
					for(int i=0;i<Total_number;i++)
				{
					if(name_search[j].compare(name[i]) == 0)
					{
						for(int k=i;k<Total_number;k++)
							name[k]=name[k+1];
						Total_number--;
					}
					else
					{
						cout<<"δ�ҵ�"<<name_search[j]<<",�����Ƿ���ȷ��"<<endl;
						break;
					}
				}
			}
			cout<<"ɾ����ɡ�����ɾ��[y/n]"<<endl;
		d0:	cin>>b;
			if(b=='y')
				node=0;
			else if(b=='n')
				node=1;
			else
			{
				cout<<"error!please reinput!"<<endl;
				goto d0;
			}
		}
		 
	}
};

class Group_depart:public Group
{private:
	int i,j,k;
	string name_store[100];
 public:
 	Group_depart(int a,int b,int c):Group(a,b,c){}
 	
	void Group_depart_set()
	{
		i=0;j=Total_number;k=0;
	for(int a=0;a<Total_number;a++)
		{
			name_store[a]=name[a];
		}
	}
 	void depart()
	{
		for(int a=0,ss=0;a<Total_number;a++)
		{
		
			if(a%departs==0) 
			{
				ss=a/departs+1; 
				cout<<'\n';
				cout<<"group"<<ss<<":"<<" ";
			}
			k=random(j);
			cout<<name_store[k]<<" ";
			for(int b=k;b<j;b++)
			{
				name_store[b]=name_store[b+1];
			}
			j--;
		}
	}

};


int random(int i)
{
	srand((unsigned int)time (0));
	if(i>0) return rand()%i;
	if(i==0) return 0;
}

int system_order()
{
	string sign00;
a0:	cout<<"�Ƿ������һ�η���[y/n]:"<<endl; 
	cin>>sign00;
	if(sign00=="y") return 1;
	if(sign00=="n")
	{
		string sign0;
	a1:	cout<<"�������ý�����˳�����[y/n]:"<<endl;
		cin>>sign0;
		if(sign0=="y")  return 2;
		if(sign0=="n")  return 0;
		if(sign0!="y"&&sign0!="n")
		{
			cout<<"error!please reinput!"<<endl;
			goto a1;
		}
	}
	if(sign00!="y"&&sign00!="n")
	{
		cout<<"error!please reinput!"<<endl;
			goto a0;
	}
}


void system_set(int &sign,Group& g0)
{
	if(sign==0||sign==1) return;
	if(sign==2)
	{	string sign1;
	a2:	cout<<"��������ÿ������[m];�޸�������[n]:"<<endl;
		cin>>sign1;
		if(sign1=="m") g0.mumber_reset();
		if(sign1=="n")
		{
			string sign2;
		a3:	cout<<"��ӳ�Ա[a]ɾ����Ա[d]���ó�Ա[r]:"<<endl;
			cin>>sign2;
			if(sign2=="a")  g0.name_add();
			if(sign2=="d")  g0.name_delete();
			if(sign2=="r")  g0.name_reset();
			if(sign2!="a"&&sign2!="d"&&sign2!="r")
			{
				cout<<"error!please reinput!"<<endl;
				goto a3;
			}
		}
		if(sign1!="m"&&sign1!="n")
		{
			cout<<"error!please reinput!"<<endl;;
			goto a2;
		}
	}
}



int main()
{
	int a,b,c;
	cout<<"������������������ÿ������"<<endl;
	cin>>a>>b>>c; 
	Group_depart g0(a,b,c);
	
	cout<<"�����ǳ�:"<<endl;
	g0.name_get();
	
	int sign=1,round=0;
	while(sign!=0)
	{
		round++;
		cout<<"round"<<round<<":"<<endl;
		g0.Group_depart_set();
		g0.depart();
		cout<<'\n'<<'\n';
		do
		{
			sign=system_order();
			system_set(sign,g0);
		}while(sign!=0&&sign!=1);
	}
	getchar();
	return 0;
};

