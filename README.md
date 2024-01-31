<h1 align="center">Pipex</h1>
<p align="center">Project from 42 school</p>

## WELCOME!
> _Hi, Hope you are doing great!
This is my 5th project in the 42's common core. 
The main proposal of this project is to replicate the "PIPE" '|' operator from UNIX systems. We have to learn about some System Calls, like fork(), pipe() and execve(), to be able to execute this project.

## Usage:
First you need to clone this rep.
Paste the command bellow in your terminal:
```Shell
git clone https://github.com/PradoAllan/pipex.git
```

Now, enter the directory:
```Shell
cd pipex
```

To use it, first you have to type "make" to compile all the files and create the executable named "pipex".
So, just type "make" in your terminal:
```Shell
make
```

To use it, you have to input the files and commands you want. Input example:

> _"inputfile cmd1 cmd2 outputfile".

```Shell
./pipex file.txt sort "grep 'Temos nosso'" outfile
```
This must behave like this: 

```Shell
< file.txt sort | grep 'Temos nosso' > outfile2
```

To make sure that it worked, compare both outfiles.
Type:
```Shell
cat outfile
cat outfile2
```

Hope this little guide can help you to use my Pipex. Feel welcome to get in touch with me on my social medias. I'll be happy to help you with some code!

#BYE!
