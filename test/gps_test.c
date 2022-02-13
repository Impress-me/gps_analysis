//
// Created by fanzh on 2022/2/12.
//

#include <stdio.h>
#include <gps_ans.h>
#include <stdlib.h>

#include <Windows.h>

int main(void)
{
    char* datas = "$GPGGA,070343.90,2236.360900,N,11352.021690,E,1,04,68.82,-72.83,M,-1.00,M,,*68\n$GPRMC,084103.00,A,2233.395441,N,11356.556656,E,0.035,,220618,,,A*7A";


    struct gps_pos pos;
    pos.latitude = (char*)malloc(11 * sizeof(char));
    pos.la_bearing = (char*)malloc(2 * sizeof(char));
    pos.longitude = (char*)malloc(12 * sizeof(char));
    pos.lo_bearing = (char*)malloc(2 * sizeof(char));


    int status = gps_ans(datas, pos);

    printf("status = %d\n", status);

    printf("%s\n", pos.latitude);
    printf("%s\n", pos.la_bearing);
    printf("%s\n", pos.longitude);
    printf("%s\n", pos.lo_bearing);

    free(pos.latitude);
    free(pos.la_bearing);
    free(pos.longitude);
    free(pos.lo_bearing);


    return 0;
}

BOOL com_test()
{
    HANDLE hComm;
    hComm = CreateFile("COM1",
                       GENERIC_READ|GENERIC_WRITE,
                       0,
                       NULL,
                       OPEN_EXISTING,
                       FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED,
                       NULL);

    if(hComm == INVALID_HANDLE_VALUE)
    {
        CloseHandle(hComm);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
    
}