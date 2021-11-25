/*
已知一个整数序列A, A中的n个元素全部保存在一个一维数组中.
设计一个尽可能高效的算法, 寻找到其主元素
主元素: 元素数目占一半以上的元素
*/

#include <iostream>
#include <stdlib.h>

/*
设置一个计数器sum, 一个暂存器number
将读取到的第一个数存入number中,遍历A, 遇到相同的数就sum++, 否则sum--
当sum为0时, 将下一个遇到的数存入number中, 从中断处继续遍历
重复上述步骤直至遍历完成. 
再次遍历A, sum置为0, 遇到与number相同的数sum++, 若最后sum>n/2, 则number为主元素
*/