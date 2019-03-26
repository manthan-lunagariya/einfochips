
typedef struct employee
{
	char *name;
	int salary;
	int age;
	struct employee *next;
}Emp;

Emp *head;

void add_emp(void)
{
	Emp *temp;
       	temp= malloc(sizeof(Emp));
	temp->name = malloc(20*sizeof(char));
	printf("\nName : ");
	scanf(" %[^\n]",temp->name);
	printf("%s's salary : ",temp->name);
	scanf("%d",&temp->salary);
	printf("%s's age : ",temp->name);
	scanf("%d",&temp->age);

	Emp *t=head;
	if(!head){
			temp->next=head;
			head = temp;
		}
	else {
		while(t->next)
			t=t->next;
		temp->next=t->next;
		t->next=temp;
	}	
}



void print_1_emp(Emp *t)
{
	//Emp *t=head;
	//while(t)
	//{
		printf("Name : %s\n",t->name);
		printf("Salary : %d\n",t->salary);
		printf("age : %d\n\n",t->age);

	//	t=t->next;
	//}
}


void delet_emp(void)
{
	Emp *prev=0,*t=head;
	char n[20],ch;
	int op,count=0;
	printf("choice..\n1. By Name 2. By Salary 3. By age\n\n");
	scanf("%d", &op);
	switch(op)
	{
		case 1: printf("Enter the Name\n");
			//gets(n);
			//fflush(stdin);
			scanf(" %[^\n]",n);
			while(t)
			{
				if(!strcmp(n,t->name))
				{
					print_1_emp(t);	
					printf("Want to delete?(y/n)");
					//fflush(stdin);
					scanf(" %c",&ch);			
					if(ch=='y' || ch=='Y')
						break;	
				}
				prev = t;
				t=t->next;

			}
			if(t==0)
			{
				printf("No match found!!\n");
				break;
			}
			if(t==head)
			head = t->next;
			if(prev)
			prev->next = t->next;
			free(t);	
			break;

		case 2: printf("Enter the Salary\n");
			scanf("%d",&count);
			while(t)
			{
				if(count == t->salary)
				{
					print_1_emp(t);	
					printf("Want to delete?(y/n)");
					scanf(" %c", &ch);
					if(ch=='y' || ch =='Y')
						break;	
				}
				prev = t;
				t=t->next;

			}
			
			if(t==0)
			{
				printf("No match found!!\n");
				break;
			}
			 if(t==head)
			head = t->next;
			if(prev)
			prev->next = t->next;
			free(t);	
			break;
		case 3: printf("Enter the age\n");
			scanf("%d",&count);
			while(t)
			{
				if(count == t->age)
				{
					print_1_emp(t);	
					printf("Want to delete?(y/n)");
					scanf(" %c", &ch);
					if(ch=='y' || ch =='Y')
						break;	
				}
				prev = t;
				t=t->next;

			}
			if(t==0)
			{
				printf("No match found!!\n");
				break;
			}
			 if(t==head)
			head = t->next;
			if(prev)
			prev->next = t->next;
			free(t);	
			break;
		default :
			printf("Invalid option");
			break;

	}

}


void print_emp(void)
{
	Emp *t=head;
	while(t)
	{
		printf("Name : %s\n",t->name);
		printf("Salary : %d\n",t->salary);
		printf("age : %d\n\n",t->age);

		t=t->next;
	}
}

