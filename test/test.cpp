// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include <windows.h>
int _tmain(int argc, _TCHAR* argv[])
{
	SYSTEMTIME newTm;
	char buf[128]; 
	char *ptr = NULL;
	int len = 0;

	char bufZDAmsg[256];
	strcpy( bufZDAmsg, "$GPZDA,201530.12,04,07,2002,+00,00*60" );
	//$GPZDA,201530.00,04,07,2002,00,00*60
	//$GPZDA,201530.00,04,07,2002,+00,00*60

		//  $GPZDA,201530.00,04,07,2002,00,00*60
		//     0123456789012345678921234567893123
		//  verify valid ZDA string
		//if( (ptr = strstr( bufZDAmsg, "ZDA" )) && ptr[10] == '.' && ptr[13] == ',' && ptr[16] == ',' && ptr[19] == ',' && ptr[24] == ',' 
		//													&& ptr[27] == ',' && ptr[30] == '*' )
		//if( (ptr = strstr( bufZDAmsg, "ZDA" )) && ptr[10] == '.' && ptr[13] == ',' && ptr[16] == ',' && ptr[19] == ','  )
		//{

		// 2 digits for hrs, min, sec is expected

	
		if( (ptr = strstr( bufZDAmsg, "ZDA" )) && ptr[10] == '.'  )
		{			// hour
			buf[0] = ptr[4];
			buf[1] = ptr[5];
			buf[2] = 0;
			newTm.wHour = atoi(buf);

			// minute
			buf[0] = ptr[6];
			buf[1] = ptr[7];
			buf[2] = 0;
			newTm.wMinute = atoi(buf);

			// second
			buf[0] = ptr[8];
			buf[1] = ptr[9];
			buf[2] = 0;
			newTm.wSecond = atoi(buf);

			char *nexToken = NULL;

			// millisec
			char *ptrMsec = strtok_s( ptr+11, ",", &nexToken );
			newTm.wMilliseconds = atoi(ptrMsec);

			// day
			char *ptrDay = strtok_s( nexToken, ",", &nexToken );
			newTm.wDay = atoi(ptrDay);

			// month
			char *ptrMonth = strtok_s( nexToken, ",", &nexToken );
			newTm.wMonth = atoi(ptrMonth);

			// year
			char *ptrYear = strtok_s( nexToken, ",", &nexToken );
			newTm.wYear = atoi(ptrYear);
		}

	//char *ptr  = strtok( gpstr, "," );

	len = strlen(ptr) + 1;
	char *ptr1 = strtok( bufZDAmsg+len , "," );
	len += strlen(ptr1) + 1;
	char *ptr2 = strtok( bufZDAmsg+len, "," );
	len += strlen(ptr2) + 1;
	char *ptr3 = strtok( bufZDAmsg+len, "," );
	len += strlen(ptr3) + 1;
	char *ptr4 = strtok( bufZDAmsg+len, "," );

	return 0;
}

