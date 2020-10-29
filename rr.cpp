#include<iostream>
#include<conio.h>
using namespace std;

void SearchStack01(int pnt,int tm);
void SearchStack02(int pnt, int tm);
void AddQue(int pnt);
int at[50], bt[50], ct[50]={0}, qt, rqi[50]={0}, c=0, st, flg=0, tm=0, noe=0, pnt=0, btm[50]={0}, tt, wt;
float att, awt;

main(){

cout<<"ROUND ROBIN ALGO : INPUT 5 PROCESSES\n";
for(int x=0;x<5;x++){
    cout<<"\nProcess "<<x+1;
    cout<<"\nAT=";
    cin>>at[x];
    cout << "BT=";
    cin>>bt[x];
    btm[x]=bt[x];}

cout<<"\nEnter time quantum:";
cin>>qt;

system("CLS");

cout<<endl<<"GANTT CHART"<<endl<<at[0];
do{
    if(flg==0){
       st=at[0];
       //---ReduceBT
       if(btm[0]<=qt){
          tm=st+btm[0];
          btm[0]=0;
          SearchStack01(pnt,tm);}
       else{
          btm[0]=btm[0]-qt;
          tm=st+qt;
          SearchStack01(pnt,tm);
          AddQue(pnt);}
    }//if

    else{
       pnt=rqi[0]-1;
       st=tm;
       //---DeleteQue
       for(int x=0;x<noe && noe!=1;x++){
          rqi[x]=rqi[x+1];}
       noe--;
       //---ReduceBT
       if(btm[pnt]<=qt){
          tm=st+btm[pnt];
          btm[pnt]=0;
          SearchStack02(pnt, tm);}
       else{
         btm[pnt]=btm[pnt]-qt;
          tm=st+qt;
          SearchStack02(pnt, tm);
          AddQue(pnt);}
    }//else

    //AssignCTvalue
    if(btm[pnt]==0){
       ct[pnt]=tm;
    }//if

   flg++;
   cout<<"]-P"<<pnt+1<<"-["<<tm;

}while(noe!=0);

cout<<"\n\nPROCESS\t AT\t BT\t CT\t TT\t WT\n";
for(int x=0;x<5;x++){
    tt=ct[x]-at[x];
    wt=tt-bt[x];
    cout<<"P"<<x+1<<" \t "<<at[x]<<" \t "<<bt[x]<<" \t "<<ct[x]<<" \t "<<tt<<" \t "<<wt<<"\n";
    awt=awt+wt;
    att=att+tt;
}//for

cout<<"\nAVERAGE TT: "<<att/5<<"\nAVERAGE WT: "<<awt/5;

}//main

void SearchStack01(int pnt,int tm){
    for(int x=pnt+1;x<5;x++){
       if(at[x]<=tm){
          rqi[noe]=x+1;
          noe++;}
    }//for
}//void

void SearchStack02(int pnt, int tm){
    for(int x=pnt+1;x<5;x++){
       //---CheckQue
       int fl=0;
       for(int y=0;y<noe;y++){
          if(rqi[y]==x+1){
             fl++;}}
       if(at[x]<=tm && fl==0 && btm[x]!=0){
          rqi[noe]=x+1;
          noe++;}
    }//for
}//void

void AddQue(int pnt){
    rqi[noe]=pnt+1;
    noe++;
}
