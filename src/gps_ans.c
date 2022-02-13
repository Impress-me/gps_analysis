//
// Created by fanzh on 2022/2/12.
//

#include "gps_ans.h"
#include <stdlib.h>
#include <string.h>

int gps_ans(char *data, struct gps_pos pos)
{

    char *splited_data = (char *)malloc(100 * sizeof(char));    //为分割后的字符串容器分配内存
    if(splited_data == NULL)
    {
        return 0;
    }
    memset(splited_data, '\0', sizeof(*splited_data));      //向容器里写 ‘\0’


    //对输入的数据进行分割
    int k = 0;
    for (int i = 0; i < strlen(data) - 1; i++)
    {

        splited_data[k] = data[i];
        if(data[i+1] == '\n')
        {
            if(memcmp(splited_data, "$GPGGA", 6) == 0)  //匹配分割的字段
            {
                insert_NA(splited_data);
                if(splited_data != NULL)
                {
                    set_gps_pos(splited_data, pos);
                    free(splited_data);
                    splited_data = NULL;
                    return 0;
                }
            }
            k = 0;

        }
        k++;
    }
    return 0;
}

//向分割的字段中午数据的位置插入 "NA"
void insert_NA(char *spd_data)
{
    if (spd_data == NULL)
    {
        return;
    }
    char* temp_data = (char*)malloc(strlen(spd_data)*sizeof(char));
    int i=0,j=0;
    for (i = 0; i < strlen(spd_data) - 1; i++)
    {
        temp_data[j] = spd_data[i];
        if(spd_data[i] == ',' && spd_data[i+1] == ',')
        {
            temp_data[j+1] = 'N';
            temp_data[j+2] = 'A';
            j = j + 2;
        }
        j++;
    }
    temp_data[j] = '\0';
    strcpy(spd_data, temp_data);
    free(temp_data);
    temp_data = NULL;
}

//从分割的字段中获取gps数据
void set_gps_pos(char* data, struct gps_pos pos)
{
    int counts = 0;
    char* temp_data = NULL;
    temp_data = strtok(data, ",");
    while(temp_data != NULL)
    {
        ++counts;
        switch (counts)
        {
            case 3:
                strcpy(pos.latitude, temp_data);
                break;
            case 4:
                strcpy(pos.la_bearing, temp_data);
                break;
            case 5:
                strcpy(pos.longitude, temp_data);
                break;
            case 6:
                strcpy(pos.lo_bearing, temp_data);
            default:
                break;
        }
        temp_data = strtok(NULL, ",");
    }
}