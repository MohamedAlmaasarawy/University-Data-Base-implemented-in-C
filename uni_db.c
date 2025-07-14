/********************************************* Start of Including Header Files *****************************************************/
#include "uni_db.h"
/********************************************* End of Including Header Files *******************************************************/

/***********************************************************************************************************************************/

/********************************************* Start of Function Definition ********************************************************/
void Menu(void)
{
    printf("____________________________________________________________\n");
    printf("|                                                           |\n");
    printf("|               WELCOM TO MY UNIVERSITY                     |\n");
    printf("|                                                           |\n");
    printf("|     ENTER YOUR CHOICE                                     |\n");
    printf("|     1.ADD STUDENT                                         |\n");
    printf("|     2.REMOVE STUDENT                                      |\n");
    printf("|     3.SEARCHING ABOUT STUDENT                             |\n");
    printf("|     4.NUMBER OF STUDENT                                   |\n");
    printf("|     5.DISPLAY ALL STUDENT                                 |\n");
    printf("|     6.Exit                                                |\n");
    printf("____________________________________________________________\n");
}

void Main_Function(uint8 Choice,Student_Info_t *std_obj)
{
    DB_status Ret_status = DB_NOK;
    switch(Choice)
    {
    case 1:
        Ret_status = Add_Student(std_obj);
        if(DB_FULL == Ret_status)
        {
            printf("The data base is empty \n");
        }
        break;
    case 2:
        Ret_status = Remove_Student(std_obj);
        if(DB_EMPTY == Ret_status)
        {
            printf("The data base is empty \n");
        }
        break;
    case 3:
        Ret_status = Student_Exist(std_obj);
        if(DB_EMPTY == Ret_status)
        {
            printf("The data base is empty \n");
        }
        break;
    case 4:
        Get_Count_DB();
        break;
    case 5:
        Ret_status = Display_DB(std_obj);
        if(DB_EMPTY == Ret_status)
        {
            printf("The data base is empty \n");
        }
        break;
    case 6:
        exit(0);
    default:
        printf("Invalid operation !! \n");
    }
}
static DB_Count = ZERO_INTI;
static uint8 DB_Is_Full (void);
static uint8 DB_Is_Empty (void);

DB_status Add_Student(Student_Info_t *std_obj)
{
    DB_status Ret = DB_NOK;
    if(NULL == std_obj)
    {
        Ret = DB_NULL_POINTER;
    }
    else
    {
        if(DB_Is_Full())
        {
            Ret = DB_FULL;
        }
        else
        {
            fflush(stdin);
            printf("Enter the student name : ");
            gets(std_obj[DB_Count].Student_Name);
            fflush(stdin);
            printf("Enter the student phone : ");
            gets(std_obj[DB_Count].Student_Phone);
            fflush(stdin);
            printf("Enter the student gmail : ");
            gets(std_obj[DB_Count].Student_Gmail);
            fflush(stdin);
            printf("Enter the student address : ");
            gets(std_obj[DB_Count].Student_Address);
            fflush(stdin);
            printf("Enter the student major : ");
            gets(std_obj[DB_Count].Student_Major);
            fflush(stdin);
            printf("Enter the student age : ");
            scanf("%i", &(std_obj[DB_Count].Student_Age));
            fflush(stdin);
            printf("Enter the student id: ");
            scanf("%i", &(std_obj[DB_Count].Student_Id));
            DB_Count++; /* Added student */
            Ret = DB_OK;
        }
    }
    return Ret;
}

DB_status Remove_Student(Student_Info_t *std_obj)
{
    DB_status Ret = DB_NOK;
    uint32 Id_Research = ZERO_INTI;
    uint32 Temp_Index = ZERO_INTI;
    uint32 Index = ZERO_INTI;
    if(NULL == std_obj)
    {
        Ret = DB_NULL_POINTER;
    }
    else
    {
        if(DB_Is_Empty())
        {
            Ret = DB_EMPTY;
        }
        else
        {
            printf("Enter student id to remove it : ");
            scanf("%i", &Id_Research);
            for(Index = 0; Index < DB_Count; Index++)
            {
                if(Id_Research == std_obj[Index].Student_Id)
                {
                    strcpy(std_obj[Index].Student_Name, " ");
                    strcpy(std_obj[Index].Student_Phone, " ");
                    strcpy(std_obj[Index].Student_Gmail, " ");
                    strcpy(std_obj[Index].Student_Address, " ");
                    strcpy(std_obj[Index].Student_Major, " ");
                    std_obj[Index].Student_Age = 0;
                    Temp_Index = Index;
                    break;
                }
                else
                {
                    printf("The student you wont to remove it is not exist \n");
                }
            }
            /* Check if the student has been remove is the last one added or not */
            if(Temp_Index == DB_Count)
            {
                /* No thing */
            }
            else
            {
                while(Temp_Index < DB_Count)
                {
                    std_obj[Temp_Index] = std_obj[Temp_Index+1];
                    Temp_Index++;
                }
            }
            DB_Count--; /* Removed student */
            Ret = DB_OK;
        }
    }
    return Ret;
}

DB_status Student_Exist(Student_Info_t *std_obj)
{
    DB_status Ret = DB_NOK;
    uint32 Id_Research = ZERO_INTI;
    uint32 Index = ZERO_INTI;
    if(NULL == std_obj)
    {
        Ret = DB_NULL_POINTER;
    }
    else
    {
        if(DB_Is_Empty())
        {
            Ret = DB_EMPTY;
        }
        else
        {
            printf("Enter student id to searching about it : ");
            scanf("%i", &Id_Research);
            for(Index = 0; Index < DB_Count; Index++)
            {
                if(Id_Research == std_obj[Index].Student_Id)
                {
                    printf("The student you searching about it is exist \n");
                    break;
                }
                else
                {
                    /* No thing */
                }
                Ret = DB_OK;
            }
            printf("The student you searching about it is not exist \n");
        }
    }
    return Ret;
}

void Get_Count_DB(void)
{
    printf("The number of student in the university : %i\n", DB_Count);
}

DB_status Display_DB(Student_Info_t *std_obj)
{
    DB_status Ret = DB_NOK;
    uint32 Index = ZERO_INTI;

    if(NULL == std_obj)
    {
        Ret = DB_NULL_POINTER;
    }
    else
    {
        if(DB_Is_Empty())
        {
            Ret = DB_EMPTY;
        }
        else
        {
            for(Index = 0 ; Index < DB_Count ; Index++)
            {
                printf("Name    : %s\n", std_obj[Index].Student_Name);
                printf("Phone   : %s\n", std_obj[Index].Student_Phone);
                printf("Gmail   : %s\n", std_obj[Index].Student_Gmail);
                printf("Address : %s\n", std_obj[Index].Student_Address);
                printf("Major   : %s\n", std_obj[Index].Student_Major);
                printf("Age     : %i\n", std_obj[Index].Student_Age);
                printf("Id     : %i\n", std_obj[Index].Student_Id);
                printf("\n============================================\n");
            }
        }
        Ret = DB_OK;
    }
    return Ret;
}

static uint8 DB_Is_Full (void)
{
    return (DB_Count == DB_MAX_SIZE-1);
}

static uint8 DB_Is_Empty (void)
{
    return (DB_Count == 0);
}
/********************************************* End of Function Definition ********************************************************/


