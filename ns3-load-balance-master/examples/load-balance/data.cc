#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/ipv4-conga-routing-helper.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/ipv4-static-routing-helper.h"
#include "ns3/ipv4-drb-routing-helper.h"
#include "ns3/ipv4-xpath-routing-helper.h"
#include "ns3/ipv4-tlb.h"
#include "ns3/ipv4-clove.h"
#include "ns3/ipv4-tlb-probing.h"
#include "ns3/link-monitor-module.h"
#include "ns3/traffic-control-module.h"
#include "ns3/tcp-resequence-buffer.h"
#include "ns3/ipv4-drill-routing-helper.h"
#include "ns3/ipv4-letflow-routing-helper.h"

#include <vector>
#include <map>
#include <utility>
#include <set>
#include <fstream> 
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	stringstream filename;
	//filename<<"/fuzaijunheng/ns3-load-balance-master/out/1/0-1-large-load-4X4-0.2-Tcp-ecmp-simulation-1-b600-link-utility.out";
	//filename<<"/home/guolab/fuzaijunheng/ns3-load-balance-master/examples/load-balance/test.txt";
	//ifstream fin(filename.str().c_str());
	ifstream fin("/home/guolab/fuzaijunheng/ns3-load-balance-master/out/8-0.5load-longtime/0-1-large-load-4X4-0.5-Tcp-tlb-180-40-1-50-64000-100-50-1-1-10-1-b600-link-utility.out");
	string str1;
	//getline(fin,str1);
	cout << "str1"<< endl;
	//getline(fin,str1);
	//cout << str1<< endl;
	//string str2;
	while (getline(fin,str1))
	{
		/*if (getline(fin,str1)) 
		{
		  break;
		}*/
		//getline(fin,str1);
		// if (str1[0]=='\0')
		// {
		// 	cout<<"return 0"<<endl;
		// 	return 0;//若读到末尾，则返回0
		// }
		//cout << "1 " << endl;
		//cout<<str1<<endl;
		string str2="123456789";
		int count=0;
		int flag=0;
		for(uint32_t i=0;i<str1.length();i++)
		{
			//cout << "2 " << endl;
			if(str1[i]=='\t')
			{
				cout<<"t"<<endl; 
				str2="";
            	count=0;
            	flag=0;
            	continue;
			} 
			if(str1[i]=='S'||str1[i]=='P'||str1[i]=='L')
			{
				break;
			}
			if(str1[i]=='/'&&flag==0)
			{
				//cout << "3 " << str1[i]<<endl;
				//cout<<str2<<endl;
				ofstream outfile;
          		outfile.open("/home/guolab/fuzaijunheng/ns3-load-balance-master/examples/load-balance/maxlinkunity/0.5our.txt",ios::app);
           		outfile<<endl;
            	outfile.close();
            	flag=1;
			}
			else if(flag==0)
			{
				//cout << "4 " << str2<<endl;
				str2[count]=str1[i];
				count++;
				ofstream outfile;
          		outfile.open("/home/guolab/fuzaijunheng/ns3-load-balance-master/examples/load-balance/maxlinkunity/0.5our.txt",ios::app);
           		outfile<<str1[i];
            	outfile.close();
				//cout << "4 " <<str1[i]<<"####"<< str2[count-1]<<"&&&"<<str2<<endl;
				//cout<<str2<<endl;
			}

		}

	}
	return 0;
}