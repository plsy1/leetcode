**62. 不同路径**

> 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
>
> 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
>
> 问总共有多少条不同的路径？
>
> 示例 1:
>
> ```
> 输入: m = 3, n = 2
> 输出: 3
> 解释:
> 从左上角开始，总共有 3 条路径可以到达右下角。
> 
> 1. 向右 -> 向右 -> 向下
> 2. 向右 -> 向下 -> 向右
> 3. 向下 -> 向右 -> 向右
> ```
>
> 示例 2:
>
> ```
> 输入: m = 7, n = 3
> 输出: 28
> ```
>
> 
>
> 提示：
>
> * 1 <= m, n <= 100
> * 题目数据保证答案小于等于 2 * 10 ^ 9



**解题思路**

简单dp题，先把最下一行与最右一列填上，然后再从右下到左上逐行dp就可以了。