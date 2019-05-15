# read the specific line of a file
if the file is not big, using fgets() read, just like,  

<pre>
int row=0;  
while(fgets(file, buf, len)){
	row++;
	if(row == specific_line)
		break;
}
</pre>

but the file is very large with large lines, and the file is read constantly!  
this project is a solution!  
