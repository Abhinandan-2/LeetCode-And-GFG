// Let's try it with an example
​
[1,  3,  4,  2,  5]
__  __  __  __  __
0   1   2   3   4
​
what is max in left side of 0th element nothing, so it should have just above value
1   __  __  __  __
0   1   2   3   4
​
for 1th element, we have two choices, {above - 0, 0th - (1 - 0) }
0th = left[0]
left[1] = max { 3, 1 - 1 } = 3
1   3  __  __  __
0   1   2   3   4
​
for 2nd element, we have three choices, {above - 0, 0th - (2 - 0), 1st - (2 - 1) }
max of  0th - (1 - 0), 1st - (0)  = left[1]
max of  0th - (1 - 0) - 1, 1st - (0) - 1  = left[1] - 1
left[1] = max { 4, 3 - 1 } = 4
1   3   4  __  __
0   1   2   3   4
​
for 3rd element, we have four choices, {above - 0, 0th - (3 - 0), 1st - (3 - 1), 2nd - (3 - 2) }
0th - (2 - 0), 1st - (2 - 1), 2nd - (0)  = left[2]
max of  0th - (2 - 0) - 1, 1st - (2 - 1) - 1, 2nd - (0) - 1  = left[2] - 1
left[1] = max { 2, 4 - 1 } = 3
1   3   4   3  __
0   1   2   3   4
​
continue this, and now you will understand why left gives the max of all left elements