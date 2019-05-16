# read the specific line of a file
if the file is not big, using fgets() read, just like,  

<pre>
int row=0;  
while(fgets(file, buf, len)){
	fseek(file, 0, SEEK_SET);
	row++;
	if(row == specific_line)
		break;
}
</pre>

but the file is very large with large lines, and the file is read constantly!  
this project is a solution!  


## test
large txt file  
<pre>
wc /home/bleach/airack/wordlist_2.txt
14365003  14365003 156511269 /home/bleach/airack/wordlist_2.txt  
</pre>

running time compare    
<pre>
read the 10000000th line, time costs,  
switch_line_fgets() took 0.000022 seconds to execute  
mfgets() took 2.084951 seconds to execute  
</pre>

