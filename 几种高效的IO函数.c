1.pipe函数

pipe函数可以创建一个管道，以实现进程间的通信。
#include<unistd.h>
int pipe(int fd[2]);
fd[0]负责从管道读出数据，f[1]负责从管道写入数据

2.dup和dup2函数

有时候我们希望将标准输入重定向到一个文件，或者把标准输出重定向到一个网络连接，我们可以通过dup函数来实现。
#include<unistd.h>
int dup(int file_descriptor);
int dup2(int file_descriptor,int file_descriptor_two);
dup函数创建一个新的文件描述符,该文件描述符和原有的文件描述符file_descriptor指向相同的文件、管道或者是网络连接，并且
dup返回的文件描述符总是取得系统当前可用的最小整数值。
dup2函数与dup函数类似，返回第一个不小于file_descriptor_two的文件描述符


3.readv函数和writev函数

readv函数将数据从文件描述符读到分散的内存块中，即分散读；writev函数将多块分散的内存数据写入到文件描述符中，即集中写。
#include<sys/uio.h>
ssize_t readv(int fd,const struct iovec *vector,int count);
ssize_t writev(int fd,const struct iovec *vector,int count);
其中结构体struct iovec描述一段内存区


4.sendfile函数

sendfile在两个文件描述符之间直接传递数据（完全在内核中操作）从而避免了内核缓冲区和用户缓冲区之间的数据拷贝，效率很高，被称为零拷贝。
#include<sys/sendfile.h>
ssize_t sendfile(int out_fd,int in_fd,off_t *offset,size_t count);
参数offset指定了从读入文件流的那个地方开始读，count指出在in_fd和out_fd之间传递的字节数。
注意：in_fd必须是一个支持类似mmap函数的文件描述符，即它必须是指向真实的文件，不能是socket和管道，而out_fd必须是socket。由此可见，sendfile几乎专门
为在网络上传输文件而设计的。


5.mmap函数和munmap函数

mmap函数用于申请一段内存空间，我们可以将这一段内存作为进程间通信的共享内存，可以将文件直接映射到其中。munmap则是释放由mmap创建的这段内存空间。



6.splice函数

splice函数用于两个文件描述符之间移动数据，也是零拷贝操作。



7.tee函数

tee函数在两个管道文件描述符之间复制数据，也是零拷贝操作，它不消耗数据。


8.fcntl函数

正如其名，是用来提供对文件描述符的各种控制操作，另外一个常见的控制文件描述符属性和行为的系统调用是ioctl
#include<fcntl.h>
int fcntl(int fd,int cmd,...);


