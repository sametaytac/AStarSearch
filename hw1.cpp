#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;
//011
vector<int> R11(vector<int> inp)
{

    int temp=inp[1];
    inp[1]=inp[0];
    inp[0]=inp[3];
    inp[3]=inp[4];
    inp[4]=temp;
    inp.push_back(011);
    return inp;
}

//012
vector<int> R12(vector<int> inp)
{

    int temp=inp[2];
    inp[2]=inp[1];
    inp[1]=inp[4];
    inp[4]=inp[5];
    inp[5]=temp;
    inp.push_back(012);

    return inp;
}


//021
vector<int> R21(vector<int> inp)
{

    int temp=inp[4];
    inp[4]=inp[3];
    inp[3]=inp[6];
    inp[6]=inp[7];
    inp[7]=temp;
        inp.push_back(021);

    return inp;
}

//022
vector<int> R22(vector<int> inp)
{

    int temp=inp[5];
    inp[5]=inp[4];
    inp[4]=inp[7];
    inp[7]=inp[8];
    inp[8]=temp;
        inp.push_back(022);

    return inp;
}

//101
vector<int> C01(vector<int> inp)
{

    int temp=inp[0];
    inp[0]=inp[3];
    inp[3]=temp;

     temp=inp[1];
    inp[1]=inp[4];
    inp[4]=temp;

     temp=inp[2];
    inp[2]=inp[5];
    inp[5]=temp;
        inp.push_back(101);

    return inp;
}

//112
vector<int> C12(vector<int> inp)
{

    int temp=inp[3];
    inp[3]=inp[6];
    inp[6]=temp;

     temp=inp[4];
    inp[4]=inp[7];
    inp[7]=temp;

     temp=inp[5];
    inp[5]=inp[8];
    inp[8]=temp;
        inp.push_back(112);

    return inp;
}

int mutlak(int i){
if(i<0)
    return -i;
else
    return i;

}

//2 vector al,manhattan distancelarýný bul,her eleman için toplamýný çýkar
int mandist(vector<int> source,vector<int> target)
{
    int dist=0;
    int s1;
    int pos1[2];
    int pos2[2];
    int j=0;
for(int i=0;i<9;i++)
{
    s1=source[i];
    for(int k=0;k<9;k++)
        {
        if(s1==target[k])
           {
            j=k;
            break;
           }

        }
    pos1[0]=i/3;
    pos1[1]=(i-(3*pos1[0]));

    pos2[0]=j/3;
    pos2[1]=j-3*pos2[0];
    dist+=mutlak(pos1[0]-pos2[0])+mutlak(pos1[1]-pos2[1]);

}

return dist;
}
int ust(int a)
{
    return a*a;
}
/*
int euclid(vector<int> source,vector<int> target)
{
    int dist=0;
    int s1;
    int pos1[2];
    int pos2[2];
    int j=0;
for(int i=0;i<9;i++)
{
    s1=source[i];
    for(int k=0;k<9;k++)
        {
        if(s1==target[k])
           {
            j=k;
            break;
           }

        }
    pos1[0]=i/3;
    pos1[1]=(i-(3*pos1[0]));

    pos2[0]=j/3;
    pos2[1]=j-3*pos2[0];


    dist+=sqrt(ust(pos1[0]-pos2[0])+ust(pos1[1]-pos2[1]));

}

return dist*2;
}

int humming(vector<int> source,vector<int> target)
{
    int hum=0;
    for(int i=0;i<9;i++)
      {
                if(source[i]!=target[i])
                    hum++;


      }
      return hum;
}

*/

int myheur(vector<int> source,vector<int> target)
{
    int first=0;
    int second=0;
    int third=0;
    int fourth=0;

            if(target[0]!=source[0])
            {
            first=1;

                if(target[0]!=source[3] and target[0]!=source[6])
                {

                        first=2;
                        goto checksecond;

                }
            }





            if(source[1]!=target[1])
            {
            first=1;

                if(source[0]!=target[1])
                {

                    if(source[4]!=target[1] and source[7]!=target[1])
                    {
                        first=2;
                        goto checksecond;
                    }
                }
            }


            if(source[3]!=target[3])
                {
                    first=1;

                    if(source[4]!=target[3])
                    {

                    if(source[6]!=target[3] and source[0]!=target[3])
                        {
                        first=2;
                        goto checksecond;
                        }
                    }
                }


                if(source[4]!=target[4])
                {
                    first=1;

                    if(source[1]!=target[4])
                    {

                    if(source[7]!=target[4] and  source[5]!=target[4])
                        {
                        first=2;
                        goto checksecond;
                        }
                    }
                }











checksecond:


             if(source[1]!=target[1])
                {
                    second=1;

                    if(source[4]!=target[1])
                    {


                    if(source[7]!=target[1] and source[0]!=target[1])
                        {
                        second=2;
                        goto thirdcheck;
                        }
                    }
                }


                 if(source[2]!=target[2])
                {
                    second=1;
                    if(source[1]!=target[2])
                    {


                    if(source[5]!=target[2] and source[8]!=target[2])
                        {
                        second=2;
                        goto thirdcheck;
                        }
                    }
                }


                  if(source[4]!=target[4])
                {
                    if(source[5]!=target[4])
                    {

                    second=1;
                    if(source[7]!=target[4] and source[1]!=target[4] and source[3]!=target[4])
                        {
                        second=2;
                        goto thirdcheck;
                        }
                    }
                }


                    if(source[5]!=target[5])
                {
                  second=1;

                    if(source[2]!=target[5])
                    {

                    if(source[8]!=target[5] and source[4]!=target[5])
                        {
                        second=2;
                        goto thirdcheck;
                        }
                    }
                }


       thirdcheck:


             if(source[3]!=target[3])
                {
             third=1;

                    if(source[6]!=target[3])
                    {

                    if(source[0]!=target[3])
                        {
                        third=2;
                        goto fourthcheck;
                        }
                    }
                }



            if(source[4]!=target[4])
                {
                    third=1;



                    if(source[1]!=target[4] and source[7]!=target[4] and source[5]!=target[4] and source[3]!=target[4])
                        {
                        third=2;
                        goto fourthcheck;
                        }

                }


              if(source[6]!=target[6])
                {                       third=1;

                    if(source[7]!=target[6])
                    {

                    third=1;
                    if(source[3]!=target[6] and source[0]!=target[6])
                        {
                        third=2;
                        goto fourthcheck;
                        }
                    }
                }


                if(source[7]!=target[7])
                {                    third=1;

                    if(source[4]!=target[7])
                    {

                    if(source[1]!=target[7] and source[8]!=target[7])
                        {
                        third=2;
                        goto fourthcheck;
                        }
                    }
                }




    fourthcheck:


                 if(source[4]!=target[4])
                {
                                        fourth=1;

                    if(source[7]!=target[4])
                    {

                    if(source[1]!=target[4] and source[5]!=target[4] and source[3]!=target[4])
                        {
                        fourth=2;
                        goto fin;
                        }
                    }
                }

                if(source[5]!=target[5])
                {
                                        fourth=1;

                    if(source[4]!=target[5])
                    {

                    if(source[2]!=target[5] and source[8]!=target[5])
                        {
                        fourth=2;
                        goto fin;
                        }
                    }
                }


                if(source[7]!=target[7])
                {
                                        fourth=1;

                    if(source[8]!=target[7])
                    {

                    if(source[1]!=target[7] and source[4]!=target[7])
                        {
                        fourth=2;
                        goto fin;
                        }
                    }
                }


                if(source[8]!=target[8])
                {
                                        fourth=1;

                    if(source[5]!=target[8])
                    {

                    if(source[2]!=target[8])
                        {
                        fourth=2;
                        goto fin;
                        }
                    }
                }



fin:

      return first+second+third+fourth;
}











//manhattan distanceý en kücük olan vektorun indexini bul
int findMin(vector< vector<int> > sira)
{
int temp=10000,j=0;
for(int i=0;i<sira.size();i++)
{
    if(temp>sira[i][9])
    {
        temp=sira[i][9];
        j=i;
    }
}
return j;
}





bool esitmi(vector<int> source,vector<int> dest)
{
    for(int i=0;i<9;i++)
        {if(source[i]!=dest[i])
            return false;
        }
    return true;
}
//true var,false yok demek
bool varmi(vector< vector<int> > source,vector<int> dest)
{
for(int i=0;i<source.size();i++)
{
    if(esitmi(source[i],dest))
        return true;
}
return false;
}

void printnode(vector<int> source)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
          {
              cout<<source[i*3+j]<<" ";
          }
            cout<<endl;
    }
}



int main()
{
    vector<string> sam;
int kackere;
ofstream outfile;
ifstream infile;
infile.open("hw1.inp");
infile>>kackere;
while(kackere!=0)
{
kackere--;
char heur;
infile>>heur;



int counter=0;
// vectorun son elemani manhattan distancein degerini tutuyo(10.eleman)
vector<int> initial;
vector<int> goal;
int tempal;
for(int i=1;i<10;i++)
{
  //sam2.push_back(i);
infile>>tempal;
 goal.push_back(tempal);
}



for(int i=1;i<10;i++)
{
  //sam2.push_back(i);

 initial.push_back(i);
}
if(heur=='M')
initial.push_back(mandist(initial,goal));//man dist 9.elementte
if(heur=='Y')
    initial.push_back(myheur(initial,goal));
 //initial.push_back(humming(initial,goal));
//initial.push_back(findkomsu(initial,goal));
//A* algoritmasý baslýyor

vector< vector<int> > open;
open.push_back(initial);
// 1)Once initial nodeu opena at
//closedlarý tut,acacagýn nodlara bakacagýn zaman closed ile karsýlastýr,closed'da varsa acma
vector< vector<int> > closed;
bool issuccesful;
int enkucuk=0;
vector<int> bakilannode;
vector<int> tempnode;
while(true)
{
    //f,node a gidilmek icin gereken cost
    counter++;
    //3)open node yoksa basarýsýz
    if(open.size()==0){
        issuccesful=false;
        break;


    }

     //4)Open listten man disti en kucuk vektorun indexini cek,

enkucuk=findMin(open);
//enkucuk=0;
bakilannode=open[enkucuk];

//5)eger goal state e ulastýysak arama basarili
if(esitmi(bakilannode,goal))
{
        printnode(bakilannode);

   issuccesful=true;
        break;
}
//6)node u opendan sil,closea koy
  open.erase (open.begin()+ enkucuk);
  closed.push_back(bakilannode);


//7) bakilan nodein cocuklarii genisletip listeye sokmaya basla
tempnode=R11(bakilannode);
if(!(varmi(closed,tempnode)))
{
    if(heur=='M')
    tempnode[9]=mandist(tempnode,goal)+counter;
    else
    tempnode[9]=myheur(tempnode,goal)+counter;

    //tempnode[9]=humming(tempnode,goal)+counter;
    printnode(tempnode);
    open.push_back(tempnode);
}

tempnode=R12(bakilannode);
if(!(varmi(closed,tempnode)))
{
    if(heur=='M')
    tempnode[9]=mandist(tempnode,goal)+counter;
    else
   tempnode[9]=myheur(tempnode,goal)+counter;

    //tempnode[9]=humming(tempnode,goal)+counter;
    printnode(tempnode);
    open.push_back(tempnode);
}

tempnode=R21(bakilannode);
if(!(varmi(closed,tempnode)))
{
     if(heur=='M')
    tempnode[9]=mandist(tempnode,goal)+counter;
    else
   tempnode[9]=myheur(tempnode,goal)+counter;
    printnode(tempnode);
    //tempnode[9]=humming(tempnode,goal)+counter;

    open.push_back(tempnode);
}

tempnode=R22(bakilannode);
if(!(varmi(closed,tempnode)))
{
     if(heur=='M')
    tempnode[9]=mandist(tempnode,goal)+counter;
    else
    tempnode[9]=myheur(tempnode,goal)+counter;
    printnode(tempnode);
    //tempnode[9]=humming(tempnode,goal)+counter;

    open.push_back(tempnode);
}

tempnode=C01(bakilannode);
if(!(varmi(closed,tempnode)))
{
     if(heur=='M')
    tempnode[9]=mandist(tempnode,goal)+counter;
    else
tempnode[9]=myheur(tempnode,goal)+counter;
printnode(tempnode);
    //tempnode[9]=humming(tempnode,goal)+counter;

    open.push_back(tempnode);
}

tempnode=C12(bakilannode);
if(!(varmi(closed,tempnode)))
{
    if(heur=='M')
    tempnode[9]=mandist(tempnode,goal)+counter;
    else
    tempnode[9]=myheur(tempnode,goal)+counter;
    printnode(tempnode);
    //tempnode[9]=humming(tempnode,goal)+counter;

    open.push_back(tempnode);
}
}

if(issuccesful)
{

    for(int i=10;i<bakilannode.size();i++)
    {
        if(bakilannode[i]==011)
            sam.push_back("R11 ");
        else if(bakilannode[i]==012)
             sam.push_back("R12 ");
         else if(bakilannode[i]==021)
             sam.push_back("R21 ");
         else if(bakilannode[i]==022)
             sam.push_back("R22 ");
          else if(bakilannode[i]==101)
             sam.push_back("C01 ");
         else if(bakilannode[i]==112)
             sam.push_back("C12 ");
    }
     sam.push_back("bitir");
}


}
infile.close();
outfile.open ("hw1.out");


for(int i=0;i<sam.size();i++)
{
    if(sam[i]=="bitir")
        {outfile<< endl;
         continue;
        }
    outfile<<sam[i];

}

/*
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
    cout << sam2[j+3*i];
cout<<endl;
}*/
return 0;
}


