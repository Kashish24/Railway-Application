# Railway-Application
Problem Statement : Good news , You have a chance to work in IRCTC as a software developer . Applications are required with a program for railway sites . sid of a station is a something which uniquely defines it . Given N station's sid from 1 to N and distance between any two stations , if any person wants to go from station having sid A to another station C via station B as early as possible , where time is directly proportional to distance . What you have to do is to print the total distance and path to be 
covered by train if it exists , otherwise print "No Train Found.". If a railway line connects station A to B with distance d than it means it will also connects station B to station A with same distance d.

Input :
First line of the input contains the number of test cases T. It is followed by T tests cases. Each test case's first line contains two integers N and k , where N is the number of stations having sid from 1 to N and k is the number of railway lines which connects stations. Following k lines each contain three numbers a , b and d which represents station having sid a connects station b and distance between them is d . After that a line follows with number A , B , C , where A represents sid of the source station , C the destination station and B is the station via which person wants to go. 

Output:
For each test case , If there exists no paths as described in problem print "No Train Found." otherwise in first line print the total distance and in second line path to be covered . 

Constraints:
1 <= t <= 100 
1 <= k <= 100000 
3 <= N <= 100000 
1 <= A,B,C <= N 
1 <= d <= 10000000
