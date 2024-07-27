# Task 

<ol> 
<li>What does kernel mean ?</li>

- It is a layer that manage resources and abstract application layer.

<li>What does Operating System mean?</li>

- Operating system OS is comination of kernel and application.

<li>Is Linux a kernel OR operating system?</li>

- linux is a kernel.

<li>What is an Architecture Layer Diagram ?</li>

- it is a layer that describes how a system work and how the system layers work and communicate together. Show the structure and organization of the system.

<li>What is user space ?</li>

- UserSpace is general purpose space for the enduser.

<li>What is kernel Space ?</li>

- Kernel space is the layer at which resources are managed and abstract application.

<li>Describe Main Layers for Linux kernel.</li>

- system file ,memory management, network and process. 

<li>Identify the Purpose for each Layer.</li>

- Userspace: for the application by the enduser.

- Kernel space: to abstract apllication and manage resources.

<li>Identify how each layer interacts with the lower one.</li>

- UserSpace interact with kernel through glibc, but kernel interacts with HW via memory mapping and port i/o.

<li>What is Glibc Library ?</li>

- It is GNU C library. Provide many commands and functions to interact with the kernel space.

<li>What does command mean ?</li>

- Command a is an application run in userspace ,allow the user to interact with the system and programs and has a name, location , input and output, but doesnt have GUI.

<li>Describe command in-terms of the following:</li>

- name: is unique for every application. And can call the application to run using it.

- Location: it 

- version: last released software modification for the application. 

- input: takes parameters to decide the output.

- output: gives information about the system. it may include textual information, error messages, status updates, or changes to the system's state. The output is typically displayed in the command-line interface or returned to the calling program for further processing.

</ol>

![ Result  ](Layered_linux_Arch.png "dd")
