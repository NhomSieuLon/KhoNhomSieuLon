// DuyetLienThong.cpp : Defines the entry point for the console application.
//Chuong trinh minh hoa duyet cac thanh phan lien thong cua do thi

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "io.h"
#define MAX 100
#define TRUE 1
#define FALSE 0
using namespace std;
void Init(int G[][MAX], int *n, int *solt, int *chuaxet){
	FILE *fp; int i, j;
	fp=fopen("lienthong.IN", "r");
	if(fp==NULL){
		cout<<"\n Khong co file input";
		return;
	}
	fscanf(fp, "%d", n);
	cout<<"\n So dinh do thi:"<<*n;
	cout<<"\n Ma tran ke cua do thi:";
	for(i=1; i<=*n; i++){
		cout<<endl;
		for(j=1; j<=*n; j++){
			fscanf(fp, "%d", &G[i][j]);
			cout<<"  "<<G[i][j];
		}
	}
	for(i=1; i<=*n; i++)
		chuaxet[i]=0;
	*solt=0;
	fclose(fp);
}
void Result(int *chuaxet, int n, int solt){
	cout<<"\n\n";
	if(solt==1){
		cout<<"\n Do thi la lien thong";
		getch;
		return;
	}
	for(int i=1; i<=solt; i++){
		cout<<"Thanh phan lien thong thu: "<<i;
		for(int j=1; j<=n; j++){
			if(chuaxet[j]==i)
				cout<<"  "<<j;
		}
	}
}
void BFS(int G[][MAX], int n, int i, int *solt, int chuaxet[], int QUEUE[MAX]){
	int u, dauQ, cuoiQ, j;
	dauQ=1;
	cuoiQ=1;
	QUEUE[cuoiQ]=i;
	chuaxet[i]=*solt;
	while(dauQ<=cuoiQ){
		u=QUEUE[dauQ];
		cout<<"  "<<u;
		dauQ=dauQ+1;
		for(j=1; j<=n; j++){
			if(G[u][j]==1 && chuaxet[j]==0){
				cuoiQ=cuoiQ+1;
				QUEUE[cuoiQ]=j;
				chuaxet[j]=*solt;
			}
		}
	}
}
void Lien_Thong(void){
	int G[MAX][MAX], n, chuaxet[MAX], QUEUE[MAX], solt, i;
	Init(G, &n, &solt, chuaxet);
	cout<<"\n\n";
	for(i=1; i<=n; i++)
		if(chuaxet[i]==0){
			solt=solt+1;
			BFS(G, n, i, &solt, chuaxet, QUEUE);
		}
		Result(chuaxet, n, solt);
		getch;
}
void main(void){
	Lien_Thong();
	getch();
}
