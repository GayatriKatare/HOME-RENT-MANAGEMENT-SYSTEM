#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 15
struct home_rent
{
char type_of_flat[20];
char area[20] ;
char facilities[20];
char address[20] ;
char type_of_parking[20];
int price, i, j;
struct home_rent *connect;
struct home_rent *left;
struct home_rent *right;
} *start;
struct priceTree
{
int price;
struct priceTree *left1;
struct priceTree *right1;
};
struct priceTree *node1;
struct priceTree *root1;
struct priceTree *getTree();
void sortTree(int arr[],int n);
struct priceTree *getnode(int x);
struct priceTree *BalancedBst(int arr[],int s,int e);
struct home_rent *node ;
struct home_rent *root ;
struct home_rent *create(struct home_rent *start,char sarea[20]);
void display (struct home_rent *start);
struct home_rent *sort (struct home_rent *start);
void *search(struct home_rent *start,int sprice);
struct home_rent *insert(struct home_rent *start,char sarea[20]);
struct home_rent *del(struct home_rent *start,int sprice);
struct home_rent *modify(struct home_rent *start,int sprice,char sarea[20]);
void del_queue();
struct home_rent*front=NULL;
struct home_rent*rear=NULL;
void create_queue(char sarea[20]);
void display_queue();
void insert_queue(char sarea[20]) ;
struct home_rent *createt() ;
void print2D(struct home_rent *root) ;
void print2DUtil1(struct priceTree *root, int space);
void print2D1(struct priceTree *root) ;
void login();
void area();
int i,k ,n, j ,sprice ,ch,pos;
int a[20] ;
int choice;
char ans1,ans2;
int flag=0,chs=0;
char password[30]="homerent";
char pass[30];
char name[50];
char sarea[20];
struct home_rent *temp,*p,*q;
struct home_rent *start=NULL;
void main ()
{
login();
system("CLS");
area();
printf ("\n") ;
printf ("\n") ;
printf ("\n") ;
printf ("\n") ;
printf("\t\t\t\t**************************************************\n");
printf("\t\t\t\t//////////////////////////////////////////////////\n");
printf("\t\t\t\t<<<<<<<<           HELLO !          >>>>>>>>\n");
printf("\t\t\t\t<<<<<<<<  WELCOME To HAPPINESS HOME  >>>>>>>>\n");
printf("\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
printf("\n\t\t\t\t*************************************************\n");
while(1)
{
printf("..................................................................................\n");
printf("..................................................................................\n");
printf ("Select : \n" );
printf("1.create.\n");
printf("2.Display details.\n") ;
printf("3.Sort.\n") ;
printf("4.Search.\n") ;
printf("5.Insert.\n") ;
printf("6.Delete .\n") ;
printf("7. Modify .\n") ;
printf("8.create queue.\n") ;
printf("9.Display queue.\n") ;
printf("10.Delete queue.\n") ;
printf("11.Insert queue.\n") ;
printf("12.price TREE \n") ;
scanf ("%d",&ch ) ;
switch (ch)
{
case 1:

start =create(start,sarea);
break;
case 2 :
printf("\t*****before sorting*******\n\n");
display(start);
break;
case 3 :
sort(start);
printf("\t*******after sorting*******\n\n");
display(start) ;
break;
case 4 :
printf("Enter the price you want to search:");
scanf("%d",&sprice);
search (start,sprice) ;
break ;
case 5 :
start=insert(start,sarea);
n++;
break;
case 6 :
printf("//////////////////////////////////////////////////////////////////////////////////\n");
printf("Enter price you want to delete:");
scanf("%d",&sprice);
printf("//////////////////////////////////////////////////////////////////////////////////\n");
start=del(start,sprice);
n--;
break;
case 7:
printf("Enter price you want to modify:");
scanf("%d",&sprice);
start=modify(start,sprice,sarea);
break;
case 8:
create_queue(sarea);
break;
case 9:
display_queue();
break;
case 10:
del_queue();
break;
case 11 :
insert_queue(sarea) ;
break ;
case 12 :
print2D1(getTree(start));
break;
default :
printf("wrong choice");
exit(0);
}
}
}
struct home_rent *create(struct home_rent* start,char sarea[20])
{
printf ("Enter the number of flats : \n ");
scanf ("%d",&n) ;
temp = start;
for(i=0 ; i<n ; i++)
{
temp = (struct home_rent*)malloc(sizeof(struct home_rent));
printf("//////////////////////////////////////////////////////////////////////////////////\n");
if(start == NULL)
{
printf("\n \t Enter type of flat : ");
scanf(" \t\t%s",(temp->type_of_flat));
printf("\n \t Enter your price(price must be greater than 2000): ") ;
scanf ("\t\t%d",&(temp->price)) ;
while((temp->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(temp->price)) ;
}
printf("\n \t Enter address :");
scanf("\t \t%s",temp->address);
printf("\n \t Enter area(Area of flat must be in city): ");
scanf("\t \t%s",temp->area);
while(strcmp(temp->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(temp->area)) ;
}
printf("\n \t Enter facilities:");
scanf("\t \t%s",temp->facilities);
printf("\n \t Enter type of parking :");
scanf("\t \t%s",temp->type_of_parking);
start = temp;
temp->connect = NULL;

}
else
{
printf("\n \t Enter type of flat : ");
scanf(" \t\t%s",(temp->type_of_flat));
printf("\n \t Enter your price(price must be greater than 2000): ") ;
scanf ("\t\t%d",&(temp->price)) ;
while((temp->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(temp->price)) ;
}
printf("\n \t Enter address :");
scanf("\t \t%s",temp->address);
printf("\n \t Enter area(Area of flat must be in city) : ");
scanf("\t \t%s",temp->area);
while(strcmp(temp->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(temp->area)) ;
}
printf("\n \t Enter facilities:");
scanf("\t \t%s",temp->facilities);
printf("\n \t Enter type of parking :");
scanf("\t \t%s",temp->type_of_parking);
p=start;
while(p->connect!=NULL)
p=p->connect;
p->connect=temp;
temp->connect=NULL;
}
}

return start;
}
void display(struct home_rent *start)
{
printf("\ttype of flat  \t \tprice   \t\tfacilities   \t\taddress   \t\tarea   \t\ttype of parking \n");
printf("\n");
p = start;
while(p!=NULL)
{

printf("\t");
printf("%s\t\t",p->type_of_flat);
printf("%d\t\t",p->price);
printf("%s\t\t",p->facilities);
printf("%s\t\t",p->address);
printf("%s\t\t",p->area);
printf("%s\t\t",p->type_of_parking);
printf("\n");
p=p->connect;
}
printf("\n");
}
struct home_rent *sort(struct home_rent *start)
{
temp=(struct home_rent*)malloc(sizeof(struct home_rent)*5);
for(p=start; p->connect!=NULL; p=p->connect)
{
for(q=p->connect; q!=NULL; q=q->connect)
{
if(p->price > q->price)
{
temp->price=p->price;
p->price=q->price;
q->price=temp->price;
strcpy(temp->type_of_flat,p->type_of_flat);
strcpy(p->type_of_flat,q->type_of_flat);
strcpy(q->type_of_flat,temp->type_of_flat);
strcpy(temp->address,p->address);
strcpy(p->address,q->address);
strcpy(q->address,temp->address);
strcpy(temp->facilities,p->facilities);
strcpy(p->facilities,q->facilities);
strcpy(q->facilities,temp->facilities);
strcpy(temp->area,p->area);
strcpy(p->area,q->area);
strcpy(q->area,temp->area);
strcpy(temp->type_of_parking,p->type_of_parking);
strcpy(p->type_of_parking,q->type_of_parking);
strcpy(q->type_of_parking,temp->type_of_parking);
}
}
}
}
void *search(struct home_rent *start,int sprice)
{
if(start->price==sprice)
{
printf("\n*SEARCH IS FOUND\n");
printf("..................................................................................\n");
printf("\n\t\ttype of flat : ");
printf("%s\n",start->type_of_flat);
printf("\t\tprice : ");
printf("%d\n",start->price);
printf("\t\tfacilities : ");
printf("%s\n",start->facilities);
printf("\t\taddress : ");
printf("%s\n",start->address);
printf("\t\tarea : ");
printf("%s\n",start->area);
printf("\t\ttype of parking : ");
printf("%s\n",start->type_of_parking);
flag++;
}
p=start;
while(p->connect!=NULL)
{
if(p->connect->price==sprice)
{
printf("\n*SEARCH IS FOUND\n");
printf("..................................................................................\n");
printf("\n\t\ttype of flat : ");
printf("%s\n",p->connect->type_of_flat);
printf("\t\tprice : ");
printf("%d\n",p->connect->price);
printf("\t\tfacilities : ");
printf("%s\n",p->connect->facilities);
printf("\t\taddress : ");
printf("%s\n",p->connect->address);
printf("\t\tarea : ");
printf("%s\n",p->area);
printf("\t\ttype of parking : ");
printf("%s\n",p->type_of_parking);
printf("..................................................................................\n");
}
p=p->connect;
flag++;
}
if(flag==0)
printf("\n\nnot found\n\n");
}
struct home_rent *insert(struct home_rent *start,char sarea[20])
{
temp=(struct home_rent*)malloc(sizeof(struct home_rent)*1);
printf("Enter location you want to insert:");
scanf("%d",&pos);
if(pos==1)
{
printf("//////////////////////////////////////////////////////////////////////////////////\n");
printf("\t\t\nEnter  type of flat:");
scanf("%s",(temp->type_of_flat));
printf("\t\t\nEnter price(price must be greater than 2000):");
scanf("%d",&(temp->price));
while((temp->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(temp->price)) ;
}
printf("\t\t\nEnter facilities:");
scanf("%s",(temp->facilities));
printf("\t\t\nEnter address :");
scanf("%s",(temp->address ));
printf("\t\t\nEnter area(Area of flat must be in city):");
scanf("%s",(temp->area));
while(strcmp(temp->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(temp->area)) ;
}
printf("\t\t\nEnter type of parking:");
scanf("%s",(temp->type_of_parking));
temp->connect=start;
start=temp;
return start;
}
p=start;
for(i=1; i<pos-1 && p!=NULL; i++)
p=p->connect;
if(p==NULL)
printf("\n*EMPTY*\n\n");
else
{
printf("//////////////////////////////////////////////////////////////////////////////////\n");
printf("\t\t\nEnter  type of flat:");
scanf("%s",(temp->type_of_flat));
printf("\t\t\nEnter price(price must be greater than 2000):");
scanf("%d",&(temp->price));
while((temp->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(temp->price)) ;
}
printf("\t\t\nEnter facilities:");
scanf("%s",(temp->facilities));
printf("\t\t\nEnter address :");
scanf("%s",(temp->address));
printf("\t\t\nEnter area(Area of flat must be in city):");
scanf("%s",(temp->area));
while(strcmp(temp->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(temp->area)) ;
}
printf("\t\t\nEnter type of parking:");
scanf("%s",(temp->type_of_parking));
temp->connect=p->connect;
p->connect=temp;
}
return start;
}
struct home_rent *del(struct home_rent *start,int sprice)
{
if(start->price==sprice)
{
temp=start;
start=temp->connect;
free(temp);
return start;
}
p=start;
while(p->connect!=NULL)
{ if(p->connect->price==sprice)
{
temp=p->connect;
p->connect=temp->connect;
free(temp);
return start;
}
p=p->connect;
}
}
struct home_rent *modify(struct home_rent *start,int sprice,char sarea[20])
{
if(start->price==sprice)
{
printf("\n*price FOUND\n");
printf("..................................................................................\n");
printf("\n\t\ttype of flat : ");
printf("%s\n",start->type_of_flat);
printf("\t\tprice : ");
printf("%d\n",start->price);
printf("\t\tfacilities : ");
printf("%s\n",start->facilities);
printf("\t\taddress : ");
printf("%s\n",start->address);
printf("\t\tarea : ");
printf("%s\n",start->area);
printf("\t\ttype of parking : ");
printf("%s\n",start->type_of_parking);
printf("..................................................................................\n");
do
{
printf("enter:\n 1.to modify type of flat\n 2. to modify price: \n 3. To modify facilities\n 4. TO modify address\n 5. TO modify area\n 6. TO modify type of flat\n");
scanf("%d",&choice);
printf("//////////////////////////////////////////////////////////////////////////////////\n");
switch (choice)
{
case 1:
printf("\t\t\nEnter new  type of flat:");
scanf("%s",(start->type_of_flat));
break;
case 2:
printf("\t\t\nEnter new  price(price must be greater than 2000):");
scanf("%d",&(start->price));
while((start->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(start->price)) ;
}
break;
case 3:
printf("\t\t\nEnter new  facilities:");
scanf("%s",(start->facilities));
break;
case 4:
printf("\t\t\nEnter new  address:");
scanf("%s",(start->address));
break;
case 5:
printf("\t\t\nEnter new  area(Area of flat must be in city):");
scanf("%s",(start->area));
while(strcmp(start->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(start->area)) ;
}
break;
case 6:
printf("\t\t\nEnter new  type of parking:");
scanf("%s",(start->type_of_parking));
break;
default :
printf("Please enter correct choice to proceed \n");
break;
}
printf("\n\t\t Press 0 to return to main menu \n\t\t press 1 to continue modifying:");
scanf("%d",&chs);
}while(chs==1);
flag++;
return start;
}
p=start;
while(p->connect!=NULL)
{
if(p->connect->price==sprice)
{
printf("\n*price FOUND\n");
printf("..................................................................................\n");
printf("\n\t\ttype of flat : ");
printf("%s\n",p->connect->type_of_flat);
printf("\t\tprice : ");
printf("%d\n",p->connect->price);
printf("\t\tfacilities : ");
printf("%s\n",p->connect->facilities);
printf("\t\taddress : ");
printf("%s\n",p->connect->address);
printf("\t\tarea : ");
printf("%s\n",p->connect->area);
printf("\t\ttype of parking : ");
printf("%s\n",p->connect->type_of_parking);
printf("..................................................................................\n");
do
{
printf("enter:\n 1.to modify type of flat\n 2. to modify price: \n 3. To modify facilities\n 4. TO modify address\n 5. TO modify area\n 6. TO modify type of flat\n");
scanf("%d",&choice);
switch (choice)
{
case 1:
printf("\t\t\nEnter new type of flat:");
scanf("%s",(p->connect->type_of_flat));
break;
case 2:
printf("\t\t\nEnter new price(price must be greater than 2000):");
scanf("%d",&(p->connect->price));
while((p->connect->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(p->connect->price)) ;
}
break;
case 3:
printf("\t\t\nEnter new  facilities:");
scanf("%s",(p->connect->facilities));
break;
case 4:
printf("\t\t\nEnter new  address:");
scanf("%s",(p->connect->address));
break;
case 5:
printf("\t\t\nEnter new  area(Area of flat must be in city):");
scanf("%s",(p->connect->area));
while(strcmp(p->connect->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(p->connect->area)) ;
}
break;
case 6:
printf("\t\t\nEnter new  type of parking:");
scanf("%s",(p->connect->type_of_parking));
break;
default :
printf("Please enter correct choice to proceed \n");
break;
}printf("\n Press 0 to return to main menu \n press 1 to continue modifying:");
scanf("%d",&chs);
}while(chs==1);
}
p=p->connect;
flag++;
return start;
}
if(flag==0)
printf("\n\nnot found\n\n");
}
void create_queue(char sarea[20])
{
printf("Enter no. of flats :");
scanf("%d",&n);
for(i=0;i<n;i++)
{
if (rear==NULL)
{
rear=(struct home_rent*)malloc(sizeof(struct home_rent)*1000);
printf("..................................................................................\n");
printf("\n \tEnter your type of flat:");
scanf("\t\t%s",(rear->type_of_flat));
printf("\n \tEnter your price(price must be greater than 2000):");
scanf("\t\t%d",&(rear->price));
while((rear->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(rear->price)) ;
}
printf("\n \tEnter your facilities:");
scanf("\t\t%s",(rear->facilities));
printf("\n \tEnter your address:");
scanf("\t\t%s",(rear->address));
printf("\n \tEnter area(Area of flat must be in city):");
scanf("\t\t%s",(rear->area));
while(strcmp(rear->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(rear->area)) ;
}
printf("\n \tEnter type of parking:");
scanf("\t\t%s",(rear->type_of_parking));
printf("..................................................................................\n");
rear->connect=NULL;
front=rear;
}
else
{
temp=(struct home_rent*)malloc(sizeof(struct home_rent)*1000);
printf("..................................................................................\n");
printf("\n \tEnter your type of flat:");
scanf("\t\t%s",(temp->type_of_flat));
printf("\n \tEnter your price(price must be greater than 2000):");
scanf("\t\t%d",&(temp->price));
while((temp->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(temp->price)) ;
}
printf("\n \tEnter your facilities:");
scanf("\t\t%s",(temp->facilities));
printf("\n \tEnter your address:");
scanf("\t\t%s",(temp->address));
printf("\n \tEnter area(Area of flat must be in city):");
scanf("\t\t%s",(temp->area));
while(strcmp(temp->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(temp->area)) ;
}
printf("\n \tEnter type of parking:");
scanf("\t\t%s",(temp->type_of_parking));
printf("..................................................................................\n");
rear->connect=temp;
rear=temp;
}
}
}
void display_queue()
{
p=(struct home_rent*)malloc(sizeof(struct home_rent)*1000);

if(front==NULL)
{
printf("\n No price created yet\n");
}
else
{    p=front;
printf("\ttype_of_flat  \t \tprice   \t\tfacilities   \t\taddress   \t\tarea   \t\ttype of parking \n");
while(p!=NULL)
{
printf("\t");
printf("%s\t\t",p->type_of_flat);
printf("%d\t\t",p->price);
printf("%s\t\t",p->facilities);
printf("%s\t\t",p->address);
printf("%s\t\t",p->area);
printf("%s\t\t",p->type_of_parking);
printf("\n");
p=p->connect;
}
}
}
void del_queue()
{
if(front==NULL)
{
printf("\n*Queue Underflow*\n");
}
else
{
temp=front;
front=front->connect;
free(temp);
}
}
void insert_queue (char sarea[20])
{
printf("Enter no. of flat:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
if (rear==NULL)
{
rear=(struct home_rent*)malloc(sizeof(struct home_rent)*1000);
printf("\nEnter your type of flat:");
scanf("%s",(rear->type_of_flat));
printf("\nEnter your price(price must be greater than 2000):");
scanf("%d",&(rear->price));
while((rear->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(rear->price)) ;
}
printf("\nEnter your facilities:");
scanf("%s",(rear->facilities));
printf("\nEnter your address:");
scanf("%s",(rear->address));
printf("\nEnter area(Area of flat must be in city):");
scanf("%s",(rear->area));
while(strcmp(rear->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(rear->area)) ;
}
printf("\nEnter type of parking:");
scanf("%s",(rear->type_of_parking));
rear->connect=NULL;
front=rear;
}
else
{
temp=(struct home_rent*)malloc(sizeof(struct home_rent)*1000);
printf("\nEnter your type of flat:");
scanf("%s",(temp->type_of_flat));
printf("\nEnter your price(price must be greater than 2000):");
scanf("%d",&(temp->price));
while((temp->price)<2000)
{
printf("\n\t\tprice must be greater than 2000\n");
printf("\n\t\t Please re enter your price : ") ;
scanf ("\t\t%d",&(temp->price)) ;
}
printf("\nEnter your facilities:");
scanf("%s",(temp->facilities));
printf("\nEnter your address:");
scanf("%s",(temp->address));
printf("\nEnter area(Area of flat must be in city):");
scanf("%s",(temp->area));
while(strcmp(temp->area,sarea)!=0)
{
printf("\n\t\tArea of flat must be in city\n");
printf("\n\t\t Please re enter your area : ") ;
scanf ("\t\t%s",(temp->area)) ;
}
printf("\nEnter type of parking:");
scanf("%s",(temp->type_of_parking));
rear->connect=temp;
rear=temp;
}
}
}
struct home_rent *createt()
{
struct home_rent *p;
int x;
printf("Enter price (-1 to skip):");
scanf("%d",&x);
if(x==-1)
return NULL;
p=(struct home_rent*)malloc(sizeof(struct home_rent)*100);
p->price=x;
printf("Enter left child of %d:\n",x);
p->left=createt();
printf("Enter right child of %d:\n",x);
p->right=createt();
return p;
}
void print2DUtil(struct home_rent *root, int space)
{
if (root == NULL)
return;
space+=COUNT;
print2DUtil(root->right, space);
printf("\n");
for (i = COUNT; i < space; i++)
printf("");
printf("%d\n\n", root->price);
print2DUtil(root->left, space);
}
void print2D(struct home_rent *root)
{
print2DUtil(root, 0);
}
struct priceTree *getTree(struct home_rent *start)
{
int arr[n];
int point=0;
struct home_rent *temp=start;
while(temp!=NULL)
{
arr[point++]=temp->price;
temp=temp->connect ;
}
sortTree(arr,n);
return BalancedBst(arr,0,n-1);
}
void sortTree(int arr[],int n)
{
int temp,i,j;
for(i = 0; i < n; i++)
{
for(j = 0; j <= (n-1-i); j++)
{
if(arr[j] > arr[j+1]) //for decending order change "arr[j]<arr[j+1]"
{
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
}
struct priceTree *getnode1(int x)
{
struct priceTree *temp=(struct priceTree*)malloc(sizeof(struct priceTree));
temp->price=x;
temp->left1=temp->right1=NULL;
return temp;
}
struct priceTree *BalancedBst(int arr[],int s,int e)
{
if(s > e)
return NULL;
int mid=(s+e)/2;
struct priceTree *root1=getnode1(arr[mid]);
root1->left1=BalancedBst(arr,s,mid-1);
root1->right1=BalancedBst(arr,mid+1,e);
return root1;
}
void print2D1(struct priceTree *root1)
{
print2DUtil1(root1, 0);
}
void print2DUtil1(struct priceTree *root1, int space1)
{
if (root1 == NULL)
return;
space1+=COUNT;
print2DUtil1(root1->right1, space1);
printf("\n");
for (i = COUNT; i < space1; i++)
printf("");
printf("%d\n\n", root1->price);
print2DUtil1(root1->left1, space1);
}
void login()
{
printf("\nEnter your user name:");
scanf("%s",name);
printf("\nEnter the password:");
//scanf("%s",pass);
i=0;
while(ch!=13)
{
ch=getch();
pass[i]=ch;
printf("*");
i++;
}
pass[i-1]='\0';

if(strcmp(password,pass)==0)
{
printf("\n**********HAPPINESS HOME**********\n");
}
else
{
printf("\nYour system has been locked");
exit (0);
}
}

void area()
{
printf("\nEnter the area where you have flat:");
scanf("%s",sarea);
}


