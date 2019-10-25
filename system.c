/*
	Ice Cream Parler System

	@Author: Vichitr

*/

#include <stdio.h>

struct ice
{
	int id, price;
	char name[100], type[100];
} icecream[100], temp;

void add(int, struct ice []);
void display(int, struct ice []);
void search(int , struct ice []);
void delete(int *, struct ice[]);
void update(int , struct ice[]);
void view(int, struct ice []);
void bill(int, struct ice[]);

int main()
{
	int c, n = 0;
	icecream[0].id = 1;
	icecream[0].name[100] = "Strawberry\0";
	icecream[0].price = 35;
	icecream[0].type[100] = "cone\0";
	printf("Welcome to the parler!\nPlease choose your choice:\n");
	printf("1.Add Ice-cream\n");
	printf("2.Display All Ice-cream\n");
	printf("3.Search Available Ice-cream\n");
	printf("4.Delete Ice-cream Data\n");
	printf("5.Update the Ice-cream Price\n");
	printf("6.View Ice-cream According to Price\n");
	printf("7.Generate Bill\n");
	printf("8.Exit\n");
	do
	{
		printf("______________________________________________________\n");
		printf("Enter your choice: ");
		scanf("%d", &c);
		switch(c)
		{
			case 1: add(n, icecream); n++; break;
			case 2: display(n, icecream); break;
			case 3: search(n, icecream); break;
			case 4: delete(&n, icecream); break;
			case 5: update(n, icecream); break;
			case 6: view(n, icecream); break;
			case 7: bill(n, icecream); break;
			case 8: printf("Thank u for visiting!\n"); exit(1); break;
			default: printf("Please enter valid choice!\n");
		}
	}
	while(1);
	return 0;
}

void add(int n, struct ice icecream[])
{
	printf("Enter the Ice-cream id: ");
	scanf("%d", &icecream[n+1].id);getchar();
	printf("Enter the ice-cream name: ");
	gets(icecream[n+1].name);
	printf("Enter the price: ");
	scanf("%d", &icecream[n+1].price); getchar();
	printf("Enter the type: ");
	gets(icecream[n+1].type);
}

void display(int n, struct ice icecream[])
{
	int i;
	printf("Ice-cream id\tName\t\tType\tPrice\n");
	for(i = 0; i <= n; i++)
	{
		printf("%d\t\t%s\t%s\t%d\n", i + 1, icecream[i].name, icecream[i].type, icecream[i].price);
	}
}

void search(int n, struct ice icecream[])
{
	int i, iid;
	printf("Enter the ice-cream id you want to search: ");
	scanf("%d",&iid);
	for(i = 0; i <= n; i++)
	{
		if(icecream[i].id == iid)
		{
			printf("ice-cream id: %d\n", icecream[i].id);
			printf("Name: %s\n", icecream[i].name);
			printf("Price: %d\n", icecream[i].price);
			printf("Type: %s\n", icecream[i].type);
		}
	}
}

void delete(int *n, struct ice icecream[])
{
	int i, iid;
	printf("Enter the ice-cream you wantto delete: ");
	scanf("%d", &iid);
	for(i = 0; i <= *n; i++)
	{
		if(icecream[i].id == iid)
		{
			--(*n);
			printf("RECORDS DELETED\n");
			break;
		}
	}
}

void update(int n, struct ice icecream[])
{
	int i, iid;
	printf("Enter id you want to update: ");
	scanf("%d", &iid);
	for(i = 0; i <= n; i++)
	{
		if(icecream[i].id == iid)
		{
			printf("Enter new price: ");
			scanf("%d", &icecream[i].id);
			printf("Records Updated\n");
			getchar();
			break;
		}
	}
}

void view(int n, struct ice icecream[])
{
	int i, j;
	for(j = 0; j <= n; j++)
	{
		for(i = 0; i <= n-1; i++)
		{
			if(icecream[i].price >= icecream[i+1].price)
			{
				temp = icecream[i];
				icecream[i] = icecream[i+1];
				icecream[i+1] = temp;
			}
		}
	}
	printf("Ice-cream id\tName\tType\tPrice\n");
	for(i = 0; i <= n; i++)
		printf("%d\t\t%s\t%s\t%d\n", icecream[i].id, icecream[i].name,icecream[i].type, icecream[i].price);
}

void bill(int n, struct ice icecream[])
{
	int i, c, b = 0, iid, q;
	printf("Select from the following available ice-cream\n");
	printf("Icecream id\tName\tType\tPrice\n");
	for(i = 0; i <= n; i++)
		printf("%d\t\t%s\t%s\t%d\n",icecream[i].id, icecream[i].name, icecream[i].type, icecream[i].price);
	do
	{
		printf("enter the id: ");
		scanf("%d", &iid);
		printf("enter the quantity: ");
		scanf("%d", &q);
		for(i = 0; i <= n; i++)
		{
			if(icecream[i].id == iid)
			{
				b += q * icecream[i].price;
			}
		}
		printf("Want to buy more icecream? Press 0 else press 9:");
		do
		{
			scanf("%d", &c);
			if(c==0||c==9)
				break;
			else
				printf("Enter valid choice: ");
		}
		while(1);
	}
	while(c == 0);
	printf("Your bill is: %d\n", b);
}
