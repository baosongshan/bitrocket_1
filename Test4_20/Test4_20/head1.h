//#ifndef _HEAD_1_H_ //条件编译  预防头文件被重复引入  if not  define 
//#define _HEAD_1_H_

#pragma once

int Max(int a, int b)
{
	return a > b ? a : b;
}

//#endif /* _HEAD_1_H_ */