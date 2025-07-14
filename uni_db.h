/********************************************* Start of Guard File *****************************************************************/
#ifndef UNI_DB_H
#define UNI_DB_H
/********************************************* End of Guard file *******************************************************************/


/***********************************************************************************************************************************/


/********************************************* Start of Including libraries ********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Platform_Types.h"
/********************************************* End of Including libraries **********************************************************/

/***********************************************************************************************************************************/

/********************************************* Start of Define Macros **************************************************************/
#define ZERO_INTI 0
#define DB_MAX_SIZE 10
/********************************************* End of Define Macros ****************************************************************/

/***********************************************************************************************************************************/

/********************************************* Start of Function Declaration *******************************************************/

typedef struct
{
    uint8  Student_Name[30];
    uint8  Student_Phone[12];
    uint8  Student_Gmail[40];
    uint8  Student_Address[50];
    uint8  Student_Major[30];
    uint32 Student_Age;
    uint32 Student_Id;
}Student_Info_t;

typedef enum
{
    DB_NOK,
    DB_OK,
    DB_FULL,
    DB_EMPTY,
    DB_NULL_POINTER
}DB_status;

/** \brief This function to add a new student in the data base
 * \param (std_obj) is a pointer to structure to access it
 * \return DB_status to know which type of error happen
 */

DB_status Add_Student(Student_Info_t *std_obj);

/** \brief This function to remove a student in the data base by his id
 * \param (std_obj) is a pointer to structure to access it
 * \return DB_status to know which type of error happen
 */
DB_status Remove_Student(Student_Info_t *std_obj);

/** \brief This function to searching about student in the data base by his id
 * \param (std_obj) is a pointer to structure to access it
 * \return DB_status to know which type of error happen
 */
DB_status Student_Exist(Student_Info_t *std_obj);

/** \brief This function to know how many student at this data base
 */
void Get_Count_DB(void);

/** \brief This function to display all student at this data base
 * \param (std_obj) is a pointer to structure to access it
 * \return DB_status to know which type of error happen
 */
DB_status Display_DB(Student_Info_t *std_obj);

/********************************************* End of Function Declaration**********************************************************/


#endif // UNI_DB_H


