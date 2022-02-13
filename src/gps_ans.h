//
// Created by fanzh on 2022/2/12.
//

#ifndef GPS_ANS_H
#define GPS_ANS_H

struct gps_pos     //GPS经度和纬度坐标
{
    char* longitude;
    char* lo_bearing;
    char* latitude;
    char* la_bearing;
};

int gps_ans(char* data, struct gps_pos pos);     //待分析gps数据，gps坐标容器，gps语句条数
void insert_NA(char *spd_data);
void set_gps_pos(char* data, struct gps_pos pos);

#endif //GPS_ANS_H
