
Developed by Iliya Iliev.
Developed on Microsoft Visual Studio.
Tecnology - C++14
Date - 26/09/2021

This is a small database program, perform Fill, Find and Delete matching records in the database container.
For the current case is used std::list due to allowing constant time insert and erase operations anywhere in
the sequence.

For the std::string comparison is used std::strstr, due to small amout of chars to compair (in this case).
The method std::find is removed due to high complexity, O(m*n).

In any further cases (like comparison of big amount of chars between strings) the pattern to use is
Boyer Moore Algorithm for Pattern Searching.

This algorithm has complexity: average - O(n), worst - O(m*n). 