The shell is like a program that receives command inputs from the user’s keyboard and sends them to a machine to be executed by the kernel. It also checks to see if the user’s command inputs are correct. It could be a command-line interface, like the one we’ll create, or a graphical user interface, like normal software such as Microsoft Office or Adobe Suite.
A shell is a program that acts as an interface between the user and the operating system. A shell allows the user to interact with the operating system by accepting commands entered by the user from the keyboard, verifying if the inputs from the user are correct and executing them. Generally, a shell is a user interface that allows us to use computer resources such as memory. It can take two forms command-line interface such as Bash or graphical user interface such as Windows Office.
Let’s look at a shell from the top down. A shell does three main things in its lifetime.
Doing hard things

Initialize: In this step, a typical shell would read and execute its configuration files. These change aspects of the shell’s behavior.
Interpret: Next, the shell reads commands from stdin (which could be interactive, or a file) and executes them.
Terminate: After its commands are executed, the shell executes any shutdown commands, frees up any memory, and terminates.
These steps are so general that they could apply to many programs, but we’re going to use them for the basis for our shell. Our shell will be so simple that there won’t be any configuration files, and there won’t be any shutdown command. So, we’ll just call the looping function and then terminate. But in terms of architecture, it’s important to keep in mind that the lifetime of the program is more than just looping.
