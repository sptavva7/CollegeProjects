#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 5
int front=-1, rear=-1;
struct queue
{
 int orders[3];
}delivery[5];
struct PType{
int
smallQ,mediumQ,largeQ,others,freshPan,cheeseBurst,thinCrust,time,totaltime,s
tatus;
};
struct PCost{
int smallC,mediumC,largeC,FPcost,CBcost,TCcost;
};
void ShowOrder(struct PType Cart[10][100],struct PCost SizeCost[12],char
itemNames[12][100],int sidesCost[4], int order_id);
void pay()
{
 int a;
 char address[200];
 printf("\n\t\t\t\tWelcome To The Payment Gateway!");
 printf("\n\nEnter your full address: ");
 gets(address);
 printf("\n\n\tPay Using:\n\t1.Card(VISA, MasterCard or Maestro)\n\t2.Cash
On Delivery\n\t3.Pick-Up\n");
 printf("\n\tEnter your choice: ");
 scanf("%d",&a);
 switch(a)
 {
 case 1: card_payment();
 break;
 case 2: cash_on_delivery();
 break;
 case 3: pickup();
 break;
 }
 return;
}
void cash_on_delivery()
{
 printf("\n\tOrder successful! Please keep the cash ready with you.");
 getch();
 return;
}
void pickup()
{
 printf("\n\tOrder successful!");
 getch();
 return;
}
void card_payment()
{
 char no[17],date[6],name[40],cvv[4];
 int a=0;
 printf("Enter the card number: ");
 scanf("%s",no);
 printf("\nEnter the expiry date(mm/yy format): ");
 scanf("%s",date);
 printf("\nEnter Holder's name: ");
 scanf("%s",name);
 printf("\nEnter CVV: ");
 while(a!=3)
 {
 cvv[a]=getch();
 printf("*");
 }
 getch();
 printf("\n\nProcessing....");
 printf("\n\nPayment Successful!");
 getch();
 return;
}
void addOrder(struct PType x[10][100], int id)
{
 int i=0,j=0;
 if(rear==-1)
 {
 front=rear=0;
 delivery[rear].orders[0]=id;
 }
 else
 {
 int pos=(rear+1)%maxsize;
 if(pos==front)
 {
 for(i=0;i<id;i++)
 {
 if(x[i][0].status!=1)
 {
 if(x[i][0].totaltime-x[id][0].totaltime<=10)
 {
 for(j=0; j<3;j++)
 {
 if(delivery[pos].orders[j]==NULL)
 { delivery[pos].orders[j]=id;
 x[i][0].status=1;
 break;
 }
 }
 }
 }
 }
 }
 else
 {
 rear=pos;
 for(i=0;i<id;i++)
 {
 if(x[i][0].status!=1)
 {
 if(x[i][0].totaltime-x[id][0].totaltime<=10)
 {
 for(j=0; j<3;j++)
 {
 if(delivery[pos].orders[j]==NULL)
 { delivery[pos].orders[j]=id;
 x[i][0].status=1;
 break;
 }
 }
 }
 }
 }
 }
 }
}
void placeorder(struct PType x[][100]);
main()
{
int
i=0,c=1,j=0,k=0,mainChoice,cost[24]={99,195,395,155,295,445,155,295,445,1
95,365,545,155,295,445,225,425,635,235,455,685,235,455,685},totalCost=0,a[
10];
int time[3]={2,3,4}, sides_time=3,order_id=1;
char name[20];
char s;
char itemNames[12][100]={
 "Margherita(Veg)",
 "Spicy Triple Tango(Veg)",
 "Double Cheese Margherita(Veg)",
 "Farm House(Veg)",
 "Cheese and Barbeque Chicken(Non Veg)",
 "Chicken Fiesta(Non Veg)",
 "Chicken Mexican(Non Veg)",
 "Chicken Golden Delight(Non Veg)",
 "Zingy Parcel Veg",
 "Zingy Parcel Non Veg",
 "Taco Mexicana Veg",
 "Taco Mexicana Non Veg"
};
int sidesCost[4]={29,35,119,129};
struct PType Cart[10][100];
struct PCost SizeCost[12];
for(k=1;k<10;k++)
{
for(i=0;i<12;i++)
{
 Cart[k-1][i].smallQ=0;
 Cart[k-1][i].mediumQ=0;
 Cart[k-1][i].largeQ=0;
 Cart[k-1][i].freshPan=0;
 Cart[k-1][i].thinCrust=0;
 Cart[k-1][i].cheeseBurst=0;
 Cart[k-1][i].others=0;
}
 Cart[k-1][0].status=0;
}
i=0;
while(i<24)
{
 SizeCost[j].smallC=cost[i++];
 SizeCost[j].mediumC=cost[i++];
 SizeCost[j].largeC=cost[i++];
 SizeCost[j].FPcost=30;
 SizeCost[j].CBcost=95;
 SizeCost[j].TCcost=40;
 j++;
}
do{
 if(c==1){
 mainmenu:
 printf("Enter\n1 - Pizzas (Veg)\n2 - Pizza (Non Veg)\n3 - Side dishes\n4 -
Exit\n");
 scanf("%d",&mainChoice);
 switch(mainChoice)
 {
 case 1:
 {
 int subChoice;
 printf("Enter\n1 - Margherita\n2 - Spicy Triple Tango\n3 - Double Cheese
Margherita\n4 - Farm House\n5 - Exit\n");
 scanf("%d",&subChoice);
 if(subChoice!=5){
 int sizeChoice;
 printf("Enter\n1 - Small\n2 - Medium\n3 - Large\n");
 scanf("%d",&sizeChoice);
 if(sizeChoice==1)
 Cart[order_id-1][subChoice-1].smallQ++;
 if(sizeChoice==2)
 Cart[order_id-1][subChoice-1].mediumQ++;
 if(sizeChoice==3)
 Cart[order_id-1][subChoice-1].largeQ++;
 printf("Need Special Crusts\n1 - Fresh Pan\n2 - Cheese Burst\n3 - Wheat
thin Crust\n4 - No Need\n");
 int extraCrust;
 scanf("%d",&extraCrust);
 if(extraCrust==1)
 Cart[order_id-1][subChoice-1].freshPan++;
 else if(extraCrust==2)
 Cart[order_id-1][subChoice-1].cheeseBurst++;
 else if(extraCrust==3)
 Cart[order_id-1][subChoice-1].thinCrust++;
 if(subChoice!=5)
 printf("Pizza Added to Cart Successfully\n");
 }
 break;
 }
 case 2:
 {
 int subChoice;
 printf("Enter\n1 - Cheese and Barbeque Chicken\n2 - Chicken Fiesta\n3 -
Chicken Mexican\n4 - Chicken Golden Delight\n5 - Exit\n");
 scanf("%d",&subChoice);
 if(subChoice!=5){
 int sizeChoice;
 printf("Enter\n1 - Small\n2 - Medium\n3 - Large\n");
 scanf("%d",&sizeChoice);
 if(sizeChoice==1)
 Cart[order_id-1][subChoice+4-1].smallQ++;
 if(sizeChoice==2)
 Cart[order_id-1][subChoice+4-1].mediumQ++;
 if(sizeChoice==3)
 Cart[order_id-1][subChoice+4-1].largeQ++;
 printf("Need Special Crusts\n1 - Fresh Pan\n2 - Cheese Burst\n3 - Wheat
thin Crust\n4 - No Need\n");
 int extraCrust;
 scanf("%d",&extraCrust);
 if(extraCrust==1)
 Cart[order_id-1][subChoice+4-1].freshPan++;
 else if(extraCrust==2)
 Cart[order_id-1][subChoice+4-1].cheeseBurst++;
 else if(extraCrust==3)
 Cart[order_id-1][subChoice+4-1].thinCrust++;
 if(subChoice!=5)
 printf("Pizza Added to Cart Successfully\n");
 }
 break;
 }
 case 3:
 {
 int subChoice;
 printf("Enter\n1 - Zingy Parcel Veg\n2 - Zingy Parcel Non Veg\n3 - Taco
Mexican Veg\n4 - Taco Mexican Non Veg\n5 - Exit\n");
 scanf("%d",&subChoice);
 if(subChoice<5 && subChoice>0)
 Cart[order_id-1][subChoice+8-1].others++;
 if(subChoice!=5)
 printf("Added to Cart Successfully\n");
 break;
 }
 case 4: break;
 default:
 {
 printf("Invalid Choice\n");
 break;
 }
 }
 }
 if(c==2)
 {
 int id,PizzaQ,CrustQ,quantity,wrongIdFlag=1;
 printf("Enter Id to change Quantity\n");
 scanf("%d",&id);
 if(id>=0 && id<=11)
 {
 if(id>=0&&id<=7)
 {
 if(Cart[order_id-1][i].smallQ>0||Cart[order_id1][i].mediumQ>0||Cart[order_id-1][i].largeQ||Cart[order_id1][i].others>0||Cart[order_id-1][i].freshPan>0||Cart[order_id1][i].cheeseBurst||Cart[order_id-1][i].thinCrust>0){
 printf("Enter\n1 - To Change Small Pizza Quantity\n2 -Change Quantity for
Medium Pizza\n3 -Change Quantity for Large Pizza\n4 -Change Quantity for
Crust\n5 - Exit\n");
 scanf("%d",&PizzaQ);
 printf("Enter quantity to change and to delete Enter 0\n");
 scanf("%d",&quantity);
 if(quantity>=0){
 if(PizzaQ==1)
 Cart[order_id-1][id].smallQ=quantity;
 if(PizzaQ==2)
 Cart[order_id-1][id].mediumQ=quantity;
 if(PizzaQ==3)
 Cart[order_id-1][id].largeQ=quantity;
 if(PizzaQ==4)
 {
 printf("Enter\n1 - To Change Fresh Pan\n2 - Cheese Burst\n3 - Wheat
Thin Crust\n4 - Exit\n");
 scanf("%d",&CrustQ);
 if(CrustQ==1)
 Cart[order_id-1][id].freshPan=quantity;
 if(CrustQ==2)
 Cart[order_id-1][id].cheeseBurst=quantity;
 if(CrustQ==3)
 Cart[order_id-1][id].thinCrust=quantity;
 }
 }
 else{
 printf("Enter Quantity greater than or equal to zero\n");
 }
 }
 else{
 printf("Id Not Found\n");
 wrongIdFlag=0;
 }
 }
 else{
 printf("Enter\n1 - To Change Quantity of Zingy Parcel(Veg)\n2 - To Change
Quantity of Zingy Parcel(Non Veg)\n3 - To Change Quantity of Taco
Mexicana(Veg)\n4 - To Change Quantity of Taco Mexicana(Non Veg)\n5 - To
Change Quantity of - Exit\n");
 scanf("%d",&PizzaQ);
 if(PizzaQ>=1 && PizzaQ<=4)
 {
 printf("Enter quantity\n");
 scanf("%d",&quantity);
 Cart[order_id-1][id].others=quantity;
 }
 }
 if(wrongIdFlag==1)
 {
 printf("Quantity Changed Successfully\nRearranged Order is\n");
 ShowOrder(Cart,SizeCost,itemNames,sidesCost, order_id);
 }
 }
 else{
 printf("Please Enter Valid Id\n");
 }
 }
 if(c==4)
 {
 int id;
 printf("Enter Id to delete from Cart\n");
 scanf("%d",&id);
 Cart[order_id-1][id].smallQ=0;
 Cart[order_id-1][id].mediumQ=0;
 Cart[order_id-1][id].largeQ=0;
 Cart[order_id-1][id].others=0;
 Cart[order_id-1][id].freshPan=0;
 Cart[order_id-1][id].cheeseBurst=0;
 Cart[order_id-1][id].thinCrust=0;
 printf("Item Deleted Successfully\nRearranged Order is\n");
 ShowOrder(Cart[order_id-1],SizeCost,itemNames,sidesCost, order_id);
 }
 if(c==3)
 {
 ShowOrder(Cart[order_id-1],SizeCost,itemNames,sidesCost, order_id);
 }
 printf("Enter\n1 - Add Item\n2 - Change Quantity\n3 - View Cart\n4 -
Delete from Cart\n5 - Check Details of Previous Orders\n Else any number to
Confirm your order.\n");
 scanf("%d",&c);
}while(c==1 || c==2 || c==3 || c==4);
printf("Final Order \n");
ShowOrder(Cart[order_id-1],SizeCost,itemNames,sidesCost, order_id);
 { {
 int i=0;
 for(i=0;i<11;i++)
 {
 Cart[order_id-1][i].time=0;
 Cart[order_id-1][i].time+=Cart[order_id-1][i].smallQ*time[0];
 Cart[order_id-1][i].time+=Cart[order_id-1][i].mediumQ*time[1];
 Cart[order_id-1][i].time+=Cart[order_id-1][i].largeQ*time[2];
 Cart[order_id-1][i].time+=Cart[order_id-1][i].others*sides_time;
 Cart[order_id-1][0].totaltime+=Cart[order_id-1][i].time;
 }
 printf("Total time for your order is: %d minutes ",Cart[order_id1][0].totaltime);
 }
 pay();
 addOrder(Cart[order_id-1],order_id);
 printf("\nYour order No. is %d.",order_id);
 printf("\nYour order is with delivery boy %d.",rear+1);
 order_id++;
 printf("\nThanks for Shopping with us!\n\n");
 for(i=0;i<12;i++)
{
 Cart[order_id-1][i].smallQ=0;
 Cart[order_id-1][i].mediumQ=0;
 Cart[order_id-1][i].largeQ=0;
 Cart[order_id-1][i].freshPan=0;
 Cart[order_id-1][i].thinCrust=0;
 Cart[order_id-1][i].cheeseBurst=0;
 Cart[order_id-1][i].others=0;
}
 goto mainmenu;
 }
}
void ShowOrder(struct PType Cart[10][100],struct PCost SizeCost[12],char
itemNames[12][100],int sidesCost[4], int order_id)
{
int totalCost=0,i;
printf("---------------------List in Cart-------------------------\n");
for(i=0;i<11;i++)
{
 if(Cart[order_id-1][i].smallQ>0||Cart[order_id1][i].mediumQ>0||Cart[order_id-1][i].largeQ>0||Cart[order_id1][i].others>0||Cart[order_id-1][i].freshPan>0||Cart[order_id1][i].cheeseBurst>0||Cart[order_id-1][i].thinCrust>0)
 {
 if(i>=0&&i<=7){
 printf("Id : %d\n",i);
 printf("Item Name : %s\n",itemNames[i]);
 if(Cart[order_id-1][i].smallQ>0)
 printf("Small Size Quantity: %d -> Cost : %d\n",Cart[order_id1][i].smallQ,SizeCost[i].smallC*Cart[order_id-1][i].smallQ);
 if(Cart[order_id-1][i].mediumQ>0)
 printf("Medium Size Quantity: %d -> Cost : %d\n",Cart[order_id1][i].mediumQ,SizeCost[i].mediumC*Cart[order_id-1][i].mediumQ);
 if(Cart[order_id-1][i].largeQ>0)
 printf("Large Size Quantity: %d -> Cost : %d\n",Cart[order_id1][i].largeQ,SizeCost[i].largeC*Cart[order_id-1][i].largeQ);
 if(Cart[order_id-1][i].freshPan>0)
 printf("Fresh Pan Quantity: %d -> Cost : %d\n",Cart[order_id1][i].freshPan,SizeCost[i].FPcost*Cart[order_id-1][i].freshPan);
 if(Cart[order_id-1][i].thinCrust>0)
 printf("Wheat Thin Crust Quantity: %d -> Cost : %d\n",Cart[order_id1][i].thinCrust,SizeCost[i].TCcost*Cart[order_id-1][i].thinCrust);
 if(Cart[order_id-1][i].cheeseBurst>0)
 printf("Cheese Burst Quantity: %d -> Cost : %d\n",Cart[order_id1][i].cheeseBurst,SizeCost[i].CBcost*Cart[order_id-1][i].cheeseBurst);
 totalCost+=Cart[order_id-1][i].smallQ*SizeCost[i].smallC;
 totalCost+=Cart[order_id-1][i].mediumQ*SizeCost[i].mediumC;
 totalCost+=Cart[order_id-1][i].largeQ*SizeCost[i].largeC;
 totalCost+=Cart[order_id-1][i].freshPan*SizeCost[i].FPcost;
 totalCost+=Cart[order_id-1][i].cheeseBurst*SizeCost[i].CBcost;
 totalCost+=Cart[order_id-1][i].thinCrust*SizeCost[i].TCcost;
 }
 else{
 printf("Id : %d\n",i);
 printf("Item Name : %s\n",itemNames[i]);
 printf("Quantity : %d\n",Cart[order_id-1][i].others);
 printf("Cost : %d\n",Cart[order_id-1][i].others*sidesCost[i-8]);
 totalCost+=(Cart[order_id-1][i].others)*sidesCost[i-8];
 }
}
 }
 printf("-------------------Total Cost : %d-----------------------\n",totalCost);
}
