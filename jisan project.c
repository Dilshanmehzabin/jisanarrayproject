#include<stdio.h>
int main()
{
    int array[200],ch,choice,num,i,j,more,ind,found=0,pos,size,value,newValue;
    do
    {
        system("cls");
        printf("--------------------------------------------\n");
        printf("--> Choose Your operation:\n");
        printf("--------------------------------------------\n");
        printf("1. INSERT ELEMENT\n");
        printf("2. DISPLAY ELEMENTS\n");
        printf("3. APPEND ELEMENTS\a\n");
        printf("4. SEARCH ELEMENT BY VALUE\n");
        printf("5. UPDATE ELEMENT\n");
        printf("6. DELETE ELEMENT\n");
        printf("7. REVERSE ELEMENTS\n");
        printf("8. SORT ELEMENTS IN ASCENDING\n");
        printf("9. SORT ELEMENTS IN DESCENDING\n");
        printf("10.LARGEST NUMBER IN ARRAY\n");
        printf("11.SMALLEST NUMBER IN ARRAY\n");
        printf("0. EXIT\n");
        printf("--------------------------------------------\n");
        printf("-->Enter operation number you want to do:");
        scanf("%d",&choice);
        printf("--------------------------------------------\n");
        switch(choice)
        {
        case 1:
            printf("Enter how many numbers you want in array:");
            scanf("%d",&num);
            size=200;
            if(num>size)
            {
                printf("\nEnter element under array size.");
                break;
            }
            for(i=0; i<num; i++)
            {
                printf("Enter value at index %d :",i);
                scanf("%d",&array[i]);
            }
            break;

        case 2:
            printf("\nYour Given Elements:\n");
            for(i=0; i<num; i++)
            {
                printf("%d ",array[i]);
            }
            break;

        case 3:
            printf("Enter how many more numbers you want in array:");
            scanf("%d",&more);

            for(i=num; i<num+more; i++)
            {
                printf("Enter number:");
                scanf("%d",&array[i]);
            }
            num+=more;
            break;
        case 4:
            printf("Enter value you want to search:");
            scanf("%d",&value);
            printf("\n");
            for (i=0; i<num; i++)
            {
                if (array[i] == value)
                {
                    printf("Value %d found at index %d \n",value,i);
                    found = 1;
                }
            }
            if (!found)
            {
                printf("Given number is not an element of the array");
            }
            break;

        case 5:
            printf("Choose your comfort mode to update:\n\n 1.By giving value\n 2.By giving index no\n\nChoice:");
            scanf("%d",&ch);
            if (ch==1)
            {
                printf("\nValues are:");
                for(i=0; i<num; i++)
                {
                    printf("%d ",array[i]);
                }
                printf("\n\nEnter Your Value you want to update:");
                scanf("%d",&value);

                int ct=0;
                for (i=0; i<num; i++)
                {
                    if (array[i] == value)
                    {
                        printf("Value %d found at index %d \n",value,i);
                        ct++;
                        found=i;
                    }
                }
                if(ct==1)
                {
                    printf("\nEnter new value: ");
                    scanf("%d", &newValue);
                    array[found] = newValue;
                    printf("\n%d Updated successfully!\n",newValue);
                    break;
                }

                for (i=0; i<num; i++)
                {
                    if (array[i] == value)
                    {
                        found = 1;
                    }
                }
                if (!found)
                {
                    printf("Given number is not an element of the array");
                    break;
                }

                printf("\nWhich index to update?\nEnter index no:");
                scanf("%d",&ind);
                if (ind<0 || ind>num || array[ind]!=value)
                {
                    printf("Not valid\n");
                }
                else
                {
                    printf("\nEnter new value: ");
                    scanf("%d", &newValue);
                    array[ind] = newValue;
                    printf("\n%d Updated successfully!\n",newValue);
                }
            }
            else if(ch==2)
            {
                printf("\nIndex with Values:\n");
                for(i=0; i<num; i++)
                {
                    printf("Index=%d ",i);
                    printf("Value=%d\n",array[i]);
                }
                printf("\nWhich index to update?\nEnter index number:");
                scanf("%d",&ind);
                printf("Index at %d ,old value is %d\n", ind,array[ind]);
                if (ind<0 || ind>num )
                {
                    printf("Not valid\n");
                }
                else
                {
                    printf("\nEnter new value: ");
                    scanf("%d", &newValue);
                    array[ind] =newValue;
                    printf("\n%d Updated successfully!\n",newValue);
                }
            }
            else
            {
                printf("Not valid\n");
            }
            break;
        case 6:
            printf("Choose your comfort mode to delete:\n\n 1.By giving value\n 2.By giving index no\n\nChoice:");
            scanf("%d",&ch);
            if (ch==1)
            {
                printf("\nValues are:");
                for(i=0; i<num; i++)
                {
                    printf("%d ",array[i]);
                }
                printf("\n\nEnter Your Value:");
                scanf("%d",&value);

                int ct=0;
                for (i=0; i<num; i++)
                {
                    if (array[i] == value)
                    {
                        printf("Value %d found at index %d .\n",value,i);
                        ct++;
                        found=i;
                    }
                }
                if(ct==1)
                {
                    for(i=found; i<num-1; i++)
                    {
                        array[i]=array[i+1];
                    }
                    num--;
                    printf("\n%d Deleted successfully!\n",value);
                    break;
                }

                for (i=0; i<num; i++)
                {
                    if (array[i] == value)
                    {
                        found = 1;
                    }
                }
                if (!found)
                {
                    printf("Given number is not an element of the array");
                }
                else
                {
                    printf("\nWhich index to delete?\nEnter index no:");
                    scanf("%d", &ind);
                    if (ind < 0 || ind >= num || array[ind] != value)
                    {
                        printf("Not valid\n");
                    }
                    else
                    {
                        for (i = ind; i < num - 1; i++)
                        {
                            array[i] = array[i + 1];//shifting indax
                        }
                        num--; // Decrease the size after delete
                        printf("\n%d Deleted successfully!\n",value);
                    }
                }
            }
            else if (ch == 2)
            {
                printf("\nIndex with Values:\n");
                for(i=0; i<num; i++)
                {
                    printf("Index=%d ",i);
                    printf("Value=%d\n",array[i]);
                }
                printf("\nWhich index to delete?\nEnter index no:");
                scanf("%d", &ind);
                printf("Index at %d ,value is %d ", ind,array[ind]);
                if (ind < 0 || ind >= num)
                {
                    printf("Not valid\n");
                }
                else
                {
                    for (i = ind; i < num - 1; i++)
                    {
                        array[i] = array[i + 1];
                    }
                    num--; // Decrease the size after delete
                    printf("\n\nDeleted successfully!\n");
                }
            }
            else
            {
                printf("Not valid\n");
            }
            break;

        case 7:
            printf("Reversed Elements: ");
            for (i = num-1; i >= 0; i--)
            {
                printf("%d ", array[i]);
            }
            break;

        case 8:
            for ( i = 0; i < num; i++)
            {
                for (j = i+1; j < num; j++)
                {
                    if (array[i] > array[j])   // Swap elements 1st num> 2nd number thn store in temp
                    {
                        int temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                }
            }
            printf("Sorted Element: ");
            for (int i = 0; i<num; i++)
            {
                printf("%d ", array[i]);
            }
            break;

        case 9:
            for ( i = 0; i < num; i++)//1st number
            {
                for (j = i+1; j < num; j++)//2nd number
                {
                    if (array[i] < array[j])   // Swap elements 1st num< 2nd number thn store in temp
                    {
                        //i=10.j=20
                        int temp = array[i]; //temp=10
                        array[i] = array[j];//i=20
                        array[j] = temp;//j=10
                    }
                }
            }
            printf("Sorted Element: ");
            for (int i = 0; i <num; i++)
            {
                printf("%d ", array[i]);
            }
            break;

        case 10:
        {
            int max = array[0];//if , array={10,20}        ...then   max=10

            for ( i = 1; i < num; i++)
            {
                if (array[i] > max)//20>10, true
                {
                    max = array[i];//max=20
                }
            }
            printf("Largest element: %d\n", max);
            break;
        }

        case 11:
        {
            int min = array[0]; //if, array={10,20} then min=10

            for ( i = 1; i < num; i++)
            {
                if (array[i] < min)//condition false 20<10. not execute if statement
                {
                    min = array[i];
                }
            }
            printf("Smallest element: %d\n", min);
            break;
        }
        }
        printf("\n\n");
        system("pause");
    }
    while(choice!=0);
}
